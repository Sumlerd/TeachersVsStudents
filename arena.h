#ifndef ARENA_H
#define ARENA_H

#include <vector>
#include "navigate.h"
#include "classify.h"
#include "object.h"
#include "cell.h"
#include "character.h"
#include "obstacle.h"
#include "wx/wx.h"

using navigate::Point;

class Arena : public wxPanel {
friend class Portal;
private:
	static Arena* arena;
	Point dimensions;
	Cell*** cells;

	std::vector<Cell*> portals;
	std::vector<Character*> characters;
	std::vector<Obstacle*> obstacles;


	Arena(const Arena& copy);
	Arena& operator=(const Arena& copy);

	void occupyCharacters(classify::Level, classify::Type,
		std::vector<navigate::Point>&);
	void occupyObstacles(std::vector<navigate::Point>&);

public:
    Arena(wxFrame* parent,navigate::Point);
	static Arena* getArena();

	void settings();
	int GetStudents();
	int GetTeachers();
	void shuffle();
	void occupy();
	void toShow(wxDC& dc);
	void empty();
	void cleanUp();
	void toShuffle();
	void drawGame();
	void paintEvent(wxPaintEvent& event);

	bool foundWinner();
	string getWinner();

	string toString();
	string icon;

	wxString grandStudentcount();
    wxString masterStudentcount();
    wxString darkStudentcount();
    wxString lightStudentcount();

    wxString grandTeachercount();
    wxString masterTeachercount();
    wxString darkTeachercount();
    wxString lightTeachercount();

	~Arena();

	DECLARE_EVENT_TABLE()
};

#endif


