#include "arenagameplay.h"
#include "arena.h"
#include "Specs.h"
#include "navigate.h"
#include "settings.h"
#include <wx/msgdlg.h>
#include "wx/dc.h"
#include "wx/dcclient.h"
#include "json/json.h"
#include <iostream>
#include <fstream>
#include "classify.h"
#include "game.h"
#include "object.h"
#include "obstacle.h"
#include "character.h"
#include "wx/stopwatch.h"

//(*InternalHeaders(arenagameplay)
#include <wx/bitmap.h>
#include <wx/intl.h>
#include <wx/image.h>
#include <wx/string.h>
//*)




//(*IdInit(arenagameplay)
const long arenagameplay::ID_STATICBITMAP1 = wxNewId();
const long arenagameplay::ID_STATICBITMAP2 = wxNewId();
const long arenagameplay::ID_STATICBITMAP6 = wxNewId();
const long arenagameplay::ID_STATICBITMAP10 = wxNewId();
const long arenagameplay::ID_BUTTON1 = wxNewId();
const long arenagameplay::ID_STATICLINE1 = wxNewId();
const long arenagameplay::ID_CHOICE1 = wxNewId();
const long arenagameplay::ID_CHOICE2 = wxNewId();
const long arenagameplay::ID_BUTTON5 = wxNewId();
const long arenagameplay::ID_STATICTEXT1 = wxNewId();
const long arenagameplay::ID_STATICTEXT2 = wxNewId();
const long arenagameplay::ID_STATICTEXT3 = wxNewId();
const long arenagameplay::ID_STATICLINE2 = wxNewId();
const long arenagameplay::ID_TEXTCTRL1 = wxNewId();
const long arenagameplay::ID_TEXTCTRL2 = wxNewId();
const long arenagameplay::ID_STATICTEXT4 = wxNewId();
const long arenagameplay::ID_STATICTEXT5 = wxNewId();
const long arenagameplay::ID_TEXTCTRL3 = wxNewId();
const long arenagameplay::ID_STATICTEXT6 = wxNewId();
const long arenagameplay::ID_TEXTCTRL4 = wxNewId();
const long arenagameplay::ID_STATICTEXT7 = wxNewId();
const long arenagameplay::ID_PANEL2 = wxNewId();
const long arenagameplay::ID_STATUSBAR1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(arenagameplay,wxFrame)
    //(*EventTable(arenagameplay)
    //*)
END_EVENT_TABLE()

arenagameplay::arenagameplay(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
    //SetScrollbar(wxVERTICAL, 0, 16, 50);
    //(*Initialize(arenagameplay)
    Create(parent, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL|wxVSCROLL|wxHSCROLL, _T("wxID_ANY"));
    SetClientSize(wxSize(800,578));
    Panel2 = new wxPanel(this, ID_PANEL2, wxPoint(-56,0), wxSize(1600,500), wxTAB_TRAVERSAL, _T("ID_PANEL2"));
    StaticBitmap1 = new wxStaticBitmap(Panel2, ID_STATICBITMAP1, wxBitmap(wxImage(_T("/home/dylan/Documents/Cawledge/TeachersVsStudents (copy)/pic/bg.png")).Rescale(wxSize(800,578).GetWidth(),wxSize(800,578).GetHeight())), wxPoint(0,0), wxSize(800,578), wxSIMPLE_BORDER, _T("ID_STATICBITMAP1"));
    StaticBitmap2 = new wxStaticBitmap(Panel2, ID_STATICBITMAP2, wxBitmap(wxImage(_T("/home/dylan/Documents/Cawledge/TeachersVsStudents (copy)/pic/sa.png")).Rescale(wxSize(40,42).GetWidth(),wxSize(40,42).GetHeight())), wxPoint(608,8), wxSize(40,42), wxSIMPLE_BORDER, _T("ID_STATICBITMAP2"));
    StaticBitmap6 = new wxStaticBitmap(Panel2, ID_STATICBITMAP6, wxBitmap(wxImage(_T("/home/dylan/Documents/Cawledge/TeachersVsStudents (copy)/pic/ta.png")).Rescale(wxSize(40,42).GetWidth(),wxSize(40,42).GetHeight())), wxPoint(696,8), wxSize(40,42), wxSIMPLE_BORDER, _T("ID_STATICBITMAP6"));
    StaticBitmap10 = new wxStaticBitmap(Panel2, ID_STATICBITMAP10, wxBitmap(wxImage(_T("./VS.png")).Rescale(wxSize(56,48).GetWidth(),wxSize(56,48).GetHeight())), wxPoint(648,8), wxSize(56,48), wxSIMPLE_BORDER, _T("ID_STATICBITMAP10"));
    Button1 = new wxButton(Panel2, ID_BUTTON1, _("Run"), wxPoint(656,272), wxDefaultSize, wxTAB_TRAVERSAL, wxDefaultValidator, _T("ID_BUTTON1"));
    StaticLine1 = new wxStaticLine(Panel2, ID_STATICLINE1, wxPoint(530,0), wxSize(24,824), wxLI_VERTICAL|wxSUNKEN_BORDER, _T("ID_STATICLINE1"));
    Choice1 = new wxChoice(Panel2, ID_CHOICE1, wxPoint(656,112), wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE1"));
    Choice1->SetSelection( Choice1->Append(_("5")) );
    Choice1->Append(_("6"));
    Choice1->Append(_("7"));
    Choice1->Append(_("8"));
    Choice1->Append(_("9"));
    Choice1->Append(_("10"));
    Choice2 = new wxChoice(Panel2, ID_CHOICE2, wxPoint(656,160), wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE2"));
    Choice2->SetSelection( Choice2->Append(_("5")) );
    Choice2->Append(_("6"));
    Choice2->Append(_("7"));
    Choice2->Append(_("8"));
    Choice2->Append(_("9"));
    Choice2->Append(_("10"));
    Button5 = new wxButton(Panel2, ID_BUTTON5, _("Apply"), wxPoint(656,216), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON5"));
    StaticText1 = new wxStaticText(Panel2, ID_STATICTEXT1, _("Arena Settings"), wxPoint(632,80), wxDefaultSize, 0, _T("ID_STATICTEXT1"));
    StaticText2 = new wxStaticText(Panel2, ID_STATICTEXT2, _("Length"), wxPoint(600,120), wxDefaultSize, 0, _T("ID_STATICTEXT2"));
    StaticText3 = new wxStaticText(Panel2, ID_STATICTEXT3, _("Width"), wxPoint(600,168), wxDefaultSize, 0, _T("ID_STATICTEXT3"));
    StaticLine2 = new wxStaticLine(Panel2, ID_STATICLINE2, wxPoint(544,256), wxSize(248,0), wxLI_HORIZONTAL, _T("ID_STATICLINE2"));
    TextCtrl1 = new wxTextCtrl(Panel2, ID_TEXTCTRL1, wxEmptyString, wxPoint(664,344), wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
    TextCtrl2 = new wxTextCtrl(Panel2, ID_TEXTCTRL2, wxEmptyString, wxPoint(664,392), wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL2"));
    StaticText4 = new wxStaticText(Panel2, ID_STATICTEXT4, _("Students Alive:"), wxPoint(552,352), wxDefaultSize, 0, _T("ID_STATICTEXT4"));
    StaticText5 = new wxStaticText(Panel2, ID_STATICTEXT5, _("Teacher Alive:"), wxPoint(560,400), wxDefaultSize, 0, _T("ID_STATICTEXT5"));
    TextCtrl3 = new wxTextCtrl(Panel2, ID_TEXTCTRL3, wxEmptyString, wxPoint(664,464), wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL3"));
    StaticText6 = new wxStaticText(Panel2, ID_STATICTEXT6, _("Timer (ms)"), wxPoint(576,472), wxDefaultSize, 0, _T("ID_STATICTEXT6"));
    TextCtrl4 = new wxTextCtrl(Panel2, ID_TEXTCTRL4, wxEmptyString, wxPoint(664,504), wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL4"));
    StaticText7 = new wxStaticText(Panel2, ID_STATICTEXT7, _("WINNER!"), wxPoint(592,512), wxDefaultSize, 0, _T("ID_STATICTEXT7"));
    StatusBar1 = new wxStatusBar(this, ID_STATUSBAR1, 0, _T("ID_STATUSBAR1"));
    int __wxStatusBarWidths_1[1] = { -10 };
    int __wxStatusBarStyles_1[1] = { wxSB_NORMAL };
    StatusBar1->SetFieldsCount(1,__wxStatusBarWidths_1);
    StatusBar1->SetStatusStyles(1,__wxStatusBarStyles_1);
    SetStatusBar(StatusBar1);
    Center();

    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&arenagameplay::OnButton1Click);
    Connect(ID_CHOICE1,wxEVT_COMMAND_CHOICE_SELECTED,(wxObjectEventFunction)&arenagameplay::OnChoice1Select1);
    Connect(ID_CHOICE2,wxEVT_COMMAND_CHOICE_SELECTED,(wxObjectEventFunction)&arenagameplay::OnChoice2Select);
    Connect(ID_BUTTON5,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&arenagameplay::OnButton5Click1);
    Connect(ID_TEXTCTRL1,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&arenagameplay::OnTextCtrl1Text1);
    Panel2->Connect(wxEVT_PAINT,(wxObjectEventFunction)&arenagameplay::OnPanel2Paint,0,this);
    Connect(wxID_ANY,wxEVT_CLOSE_WINDOW,(wxObjectEventFunction)&arenagameplay::OnClose1);
    //*)


    navigate::Point dimensions = arenaSettings::getDimensions();
    this->Choice1->SetSelection(dimensions.x);
    this->Choice2->SetSelection(dimensions.y);
}


arenagameplay::~arenagameplay()
{
    //(*Destroy(arenagameplay)
    //*)
}



void arenagameplay::OnButton1Click(wxCommandEvent& event)
{


    string teachers="Teachers";

    navigate::Point dimensions = arenaSettings::getDimensions();
    //this->Choice1->SetSelection(dimensions.x);
    //this->Choice2->SetSelection(dimensions.y);
    Arena arena3(this,dimensions);
    arena3.occupy();

    wxClientDC dc(Panel2);
    watch.Start(0);
    while(!arena3.foundWinner())
    {
        arena3.toShow(dc);
        arena3.toShuffle();
    }
    watch.Pause();
    wxString wm = wxString::Format(wxT("%i"),watch.Time());
        TextCtrl3->Clear();
        TextCtrl3->SetValue(wm);

    if(arena3.getWinner()==teachers)
    {
        TextCtrl4->SetValue("Teachers");
    }

    else if(arena3.getWinner() != teachers)
    {
        TextCtrl4->SetValue("Students");
    }
    arena3.empty();


}


void arenagameplay::OnPanel2Paint(wxPaintEvent& event)
{
   // event.Skip();
}


void arenagameplay::OnChoice1Select1(wxCommandEvent& event)
{
    lengthselected=Choice1->GetSelection();
}

void arenagameplay::OnChoice2Select(wxCommandEvent& event)
{
    widthselected=Choice2->GetSelection();
}

void arenagameplay::OnButton5Click1(wxCommandEvent& event)
{
    if (widthselected==0)
    {
        width=5;
    }
    else if (widthselected==1)
    {
        width=6;
    }
    else if (widthselected==2)
    {
        width=7;
    }
    else if (widthselected==3)
    {
        width=8;
    }
    else if (widthselected==4)
    {
        width=9;
    }
    else if (widthselected==5)
    {
        width=10;
    }


    if (lengthselected==0)
    {
        length=5;
    }
    else if (lengthselected==1)
    {
        length=6;
    }
    else if (lengthselected==2)
    {
        length=7;
    }
    else if (lengthselected==3)
    {
        length=8;
    }
    else if (lengthselected==4)
    {
        length=9;
    }
    else if (lengthselected==5)
    {
        length=10;
    }


    Game game(width,length);

    game.settings();

    //Destroy();

}

void arenagameplay::OnTextCtrl1Text1(wxCommandEvent& event)
{
    //Arena.GetStudents()
}


void arenagameplay::OnIdle(wxIdleEvent& event)
{

}

void arenagameplay::OnClose(wxCloseEvent& event)
{
    //Game game(width, length);

    //game.settings();
}

void arenagameplay::OnClose1(wxCloseEvent& event)
{
}
