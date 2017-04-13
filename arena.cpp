#include "arena.h"
#include "cell.h"
#include "object.h"
#include "character.h"
#include "student.h"
#include "teacher.h"
#include "obstacle.h"
#include "navigate.h"
#include "classify.h"
#include "settings.h"
#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <string>
#include <list>
#include <vector>
#include <algorithm>
#include <time.h>
#include <unistd.h>
#include <cstdlib>
#include "portal.h"
#include "wx/wx.h"
#include <wx/dcclient.h>
#include "arenagameplay.h"
#include "wx/dc.h"
#include <wx/bitmap.h>


using std::list;
using navigate::Point;

namespace Teams
{
int teachers = 0;
int students = 0;

int grandteacher;
int masterteacher;
int darkteacher;
int lightteacher;

int grandstudent;
int masterstudent;
int darkstudent;
int lightstudent;
}


BEGIN_EVENT_TABLE(Arena, wxPanel)
// catch paint events
EVT_PAINT(Arena::paintEvent)
END_EVENT_TABLE()

Arena::Arena(wxFrame* parent, navigate::Point dimensions) : wxPanel (parent,wxID_ANY, wxPoint(10,10), wxSize(dimensions.x*50,dimensions.y*50),wxBORDER_RAISED | wxCENTER)
{

    this->dimensions = dimensions;
    //wxClientDC dc(this);
}

Arena::~Arena() {}

void Arena::paintEvent(wxPaintEvent& event)
{
    wxPaintDC dc(this);
    toShow(dc);
}


void Arena::empty()
{
    //this->dimensions = arenaSettings::getDimensions();

    for(int x = 0; x < this->dimensions.x; x++)
    {
 //       for(int y = 0; y < this->dimensions.y; y++)
   //         delete this->cells[x][y];

        delete [] this->cells[x];
    }

    delete [] this->cells;

    for(unsigned int i = 0; i < this->characters.size(); i++)
    {
        Character* thisCharacter = this->characters[i];

        delete thisCharacter;
    }

    for(unsigned int i = 0; i < this->obstacles.size(); i++)
    {
        Obstacle* thisObstacle = this->obstacles[i];

        delete thisObstacle;
    }
}

void Arena::cleanUp()
{

}


int Arena::GetStudents()
{
    return Teams::students;
}

int Arena:: GetTeachers()
{
    return Teams::teachers;
}

void Arena::shuffle()
{

    Character* thisCharacter = this->characters.back();

    if(!thisCharacter->isDead())
    {
        for(int moves = 0; moves < thisCharacter->getSpeed();
                moves++)
        {

            Point thisPoint = thisCharacter->getPosition();
            Point thatPoint;
            thatPoint.x = (thisPoint.x
                           + (rand() % thisCharacter->getRange()))
                          % this->dimensions.x;
            thatPoint.y = (thisPoint.y
                           + (rand() % thisCharacter->getRange()))
                          % this->dimensions.y;

            Cell* thisCell = this->cells[thisPoint.x][thisPoint.y];
            Cell* thatCell = this->cells[thatPoint.x][thatPoint.y];

            if(thatCell->isVacant())
            {
                thatCell->occupy(thisCharacter);
                thisCell->vacate();
            }

            else
            {
                Object* thatObject = thatCell->getOccupant();

                if(thatObject->isAnimate())
                {
                    Character* thatCharacter = (Character*) thatObject;
                    thisCharacter->attack(thatCharacter);

                    if(thatCharacter->isDead())
                    {
                        thatCell->vacate();
                        thatCell->occupy(thisCharacter);
                        thisCell->vacate();

                        switch(thatCharacter->getType())
                        {
                        case classify::Student:
                            Teams::students--;
                            break;
                        case classify::Teacher:
                            Teams::teachers--;
                            break;
                        }
                    }
                }
            }
        }

        this->characters.insert(this->characters.begin(),
                                thisCharacter);
    }

    this->characters.pop_back();

    std::vector<Cell*>::iterator itr = this->portals.begin();

    for(; itr != this->portals.end(); itr++)
    {
        Portal* thisPortal = (Portal*) *itr;
        thisPortal->transportOccupant(this);
    }

}

void Arena::occupy()
{
    this->dimensions = arenaSettings::getDimensions();

    this->cells = new Cell**[this->dimensions.x];
    for(int x = 0; x < this->dimensions.x; x++)
    {
        this->cells[x] = new Cell*[this->dimensions.y];
        for(int y = 0; y < this->dimensions.y; y++)
        {
            Cell* thisCell;
            navigate::Point thisPoint;
            thisPoint.x = x;
            thisPoint.y = y;

            int randCell = rand() % 10;
            // 1/10 chance of cell being a portal
            if(randCell < 1)
            {
                thisCell = (Cell*) new Portal(thisPoint);
                this->portals.push_back(thisCell);
            }
            else
                thisCell = new Cell(thisPoint);

            this->cells[x][y] = thisCell;
        }
    }

    srand(time(NULL));

    using namespace characterSettings;

    std::vector<navigate::Point> randomPoints;

    for(int x = 0; x < this->dimensions.x; x++)
    {
        for(int y = 0; y < this->dimensions.y; y++)
        {
            Point thisPoint;
            thisPoint.x = x;
            thisPoint.y = y;

            randomPoints.push_back(thisPoint);
        }
    }

    std::random_shuffle(randomPoints.begin(), randomPoints.end());

    occupyCharacters(classify::Grand, classify::Teacher,
                     randomPoints);
    occupyCharacters(classify::Grand, classify::Student,
                     randomPoints);
    occupyCharacters(classify::Master, classify::Teacher,
                     randomPoints);
    occupyCharacters(classify::Master, classify::Student,
                     randomPoints);
    occupyCharacters(classify::Light, classify::Teacher,
                     randomPoints);
    occupyCharacters(classify::Light, classify::Student,
                     randomPoints);
    occupyCharacters(classify::Dark, classify::Teacher,
                     randomPoints);
    occupyCharacters(classify::Dark, classify::Student,
                     randomPoints);

    occupyObstacles(randomPoints);

    std::random_shuffle(this->characters.begin(),
                        this->characters.end());
}

void Arena::occupyCharacters(classify::Level level,
                             classify::Type type, std::vector<navigate::Point>& points)
{

    int numCharacters
        = characterSettings::getCharacterCount(level, type);

    for(int i = 0; i < numCharacters; i++)
    {
        navigate::Point thisPoint = points.back();

        Cell* thisCell = this->cells[thisPoint.x][thisPoint.y];

        Character* thisCharacter;

        switch(type)
        {
        case classify::Teacher:
            switch(level)
            {
            case classify::Grand:
                thisCharacter = new GrandTeacher(thisPoint);
                Teams::grandstudent++;
                break;
            case classify::Master:
                thisCharacter = new MasterTeacher(thisPoint);
                Teams::masterteacher++;
                break;
            case classify::Light:
                thisCharacter = new LightTeacher(thisPoint);
                Teams::lightteacher++;
                break;
            case classify::Dark:
                thisCharacter = new DarkTeacher(thisPoint);
                Teams::darkteacher++;
                break;
            }
            Teams::teachers++;
            break;
        case classify::Student:
            switch(level)
            {
            case classify::Grand:
                thisCharacter = new GrandStudent(thisPoint);
                Teams::grandstudent++;
                break;
            case classify::Master:
                thisCharacter = new MasterStudent(thisPoint);
                Teams::masterstudent++;
                break;
            case classify::Light:
                thisCharacter = new LightStudent(thisPoint);
                Teams::lightstudent++;
                break;
            case classify::Dark:
                thisCharacter = new DarkStudent(thisPoint);
                Teams::darkstudent++;
                break;
            }
            Teams::students++;
            break;
        }

        thisCell->occupy((Object*) thisCharacter);

        this->characters.push_back(thisCharacter);

        points.pop_back();
    }
}

void Arena::occupyObstacles(
    std::vector<navigate::Point>& points)
{

    int numObstacles = obstacleSettings::getObstacleCount();

    for(int i = 0; i < numObstacles; i++)
    {

        navigate::Point thisPoint = points.back();

        Cell* thisCell = this->cells[thisPoint.x][thisPoint.y];

        Obstacle* thisObstacle = new Obstacle(thisPoint);

        thisCell->occupy((Object*) thisObstacle);

        this->obstacles.push_back(thisObstacle);

        points.pop_back();
    }
}

bool Arena::foundWinner()
{
    return (Teams::teachers < 1 || Teams::students < 1);
}

string Arena::getWinner()
{
    if(Teams::teachers < 1)
        return "Students";
    else
        return "Teachers";
}

void Arena::drawGame()
{
    wxClientDC dc(this);
    toShow(dc);
}

void Arena::toShow(wxDC& dc)
{

    string str;

    for(uint8_t x = 0; x < this->dimensions.x; x++)
    {
        for(uint8_t y = 0; y < this->dimensions.y; y++)
        {
            if(this->cells[x][y]->isVacant())
            {
                if(this->cells[x][y]->isAnimate())
                {
                    Portal* thisPortal = (Portal*) this->cells[x][y];
                    str = thisPortal->toString();
                    wxString icon2(str.c_str(), wxConvUTF8);

                    wxBitmap bmp(icon2,wxBITMAP_TYPE_PNG);
                    dc.DrawBitmap(bmp,cells[x][y]->position.x*50,cells[x][y]->position.y*50,true);
                }

                else
                {
                    str = this->cells[x][y]->toString();
                    wxString icon2(str.c_str(), wxConvUTF8);
                    wxBitmap bmp(icon2,wxBITMAP_TYPE_PNG);
                    dc.DrawBitmap(bmp,cells[x][y]->position.x*50,cells[x][y]->position.y*50,true);
                }

            }
            else
            {
                str = this->cells[x][y]->getOccupant()->toString();
                wxString icon2(str.c_str(), wxConvUTF8);
                wxBitmap bmp(icon2,wxBITMAP_TYPE_PNG);
                dc.DrawBitmap(bmp,cells[x][y]->position.x*50,cells[x][y]->position.y*50,true);
            }
        }
    }
}


void Arena::toShuffle()
{

    Character* thisCharacter = this->characters.back();

    if(!thisCharacter->isDead())
    {
        for(int moves = 0; moves < thisCharacter->getSpeed();
                moves++)
        {

            Point thisPoint = thisCharacter->getPosition();
            Point thatPoint;
            thatPoint.x = (thisPoint.x
                           + (rand() % thisCharacter->getRange()))
                          % this->dimensions.x;
            thatPoint.y = (thisPoint.y
                           + (rand() % thisCharacter->getRange()))
                          % this->dimensions.y;

            Cell* thisCell = this->cells[thisPoint.x][thisPoint.y];
            Cell* thatCell = this->cells[thatPoint.x][thatPoint.y];

            if(thatCell->isVacant())
            {
                thatCell->occupy(thisCharacter);
                thisCell->vacate();
            }

            else
            {
                Object* thatObject = thatCell->getOccupant();

                if(thatObject->isAnimate())
                {
                    Character* thatCharacter = (Character*) thatObject;
                    thisCharacter->attack(thatCharacter);

                    if(thatCharacter->isDead())
                    {
                        thatCell->vacate();
                        thatCell->occupy(thisCharacter);
                        thisCell->vacate();

                        switch(thatCharacter->getType())
                        {
                        case classify::Student:
                            Teams::students--;
                            break;
                        case classify::Teacher:
                            Teams::teachers--;
                            break;
                        }
                    }
                }
            }
        }

        this->characters.insert(this->characters.begin(),
                                thisCharacter);
    }

    this->characters.pop_back();

    std::vector<Cell*>::iterator itr = this->portals.begin();

    for(; itr != this->portals.end(); itr++)
    {
        Portal* thisPortal = (Portal*) *itr;
        thisPortal->transportOccupant(this);
    }
}

wxString Arena::grandStudentcount()
{
    wxString sgrandstudent;
    sgrandstudent<<Teams::grandstudent;
    return sgrandstudent;
}

wxString Arena::masterStudentcount()
{
    wxString smasterstudent;
    smasterstudent<<Teams::masterstudent;
    return smasterstudent;
}

wxString Arena::darkStudentcount()
{
    wxString sdarkstudent;
    sdarkstudent<<Teams::darkstudent;
    return sdarkstudent;
}

wxString Arena::lightStudentcount()
{
    wxString slightstudent;
    slightstudent<<Teams::lightteacher;
    return slightstudent;
}

wxString Arena::grandTeachercount()
{
    wxString sgrandteacher;
    sgrandteacher<<Teams::grandteacher;
    return sgrandteacher;
}

wxString Arena::masterTeachercount()
{
    wxString smasterteacher;
    smasterteacher<<Teams::masterteacher;
    return smasterteacher;
}

wxString Arena::darkTeachercount()
{

    wxString sdarkteacher;
    sdarkteacher<<Teams::darkteacher;
    return sdarkteacher;
}

wxString Arena::lightTeachercount()
{
    wxString slightteacher;
    slightteacher<<Teams::lightteacher;
    return slightteacher;
}
