#include "SettingsDialog.h"
#include "settings.h"
#include "json/json.h"
#include <iostream>
#include <fstream>
#include <string>
#include "classify.h"
#include "game.h"
#include "player.h"
#include "arena.h"
#include "object.h"
#include "obstacle.h"
#include "character.h"

//(*InternalHeaders(SettingsDialog)
#include <wx/string.h>
#include <wx/intl.h>
#include <wx/bitmap.h>
#include <wx/image.h>
//*)

//(*IdInit(SettingsDialog)
const long SettingsDialog::ID_STATICBITMAP1 = wxNewId();
const long SettingsDialog::ID_CHOICE1 = wxNewId();
const long SettingsDialog::ID_STATICTEXT1 = wxNewId();
const long SettingsDialog::ID_STATICTEXT2 = wxNewId();
const long SettingsDialog::ID_CHOICE2 = wxNewId();
const long SettingsDialog::ID_CHOICE3 = wxNewId();
const long SettingsDialog::ID_STATICTEXT3 = wxNewId();
const long SettingsDialog::ID_STATICTEXT4 = wxNewId();
const long SettingsDialog::ID_STATICTEXT5 = wxNewId();
const long SettingsDialog::ID_CHOICE4 = wxNewId();
const long SettingsDialog::ID_STATICTEXT6 = wxNewId();
const long SettingsDialog::ID_BUTTON1 = wxNewId();
const long SettingsDialog::ID_BUTTON2 = wxNewId();
//*)

BEGIN_EVENT_TABLE(SettingsDialog,wxDialog)
	//(*EventTable(SettingsDialog)
	//*)
END_EVENT_TABLE()

SettingsDialog::SettingsDialog(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(SettingsDialog)
	Create(parent, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE|wxCLOSE_BOX|wxSTATIC_BORDER, _T("wxID_ANY"));
	SetClientSize(wxSize(576,336));
	StaticBitmap1 = new wxStaticBitmap(this, ID_STATICBITMAP1, wxBitmap(wxImage(_T("SettingsFrame.png")).Rescale(wxSize(576,336).GetWidth(),wxSize(576,336).GetHeight())), wxPoint(0,0), wxSize(576,336), wxSIMPLE_BORDER, _T("ID_STATICBITMAP1"));
	Choice1 = new wxChoice(this, ID_CHOICE1, wxPoint(216,64), wxSize(120,29), 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE1"));
	Choice1->SetSelection( Choice1->Append(_("Single Player")) );
	Choice1->Append(_("Multi Player"));
	Choice1->Append(_("Simulation"));
	StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("Gameplay Settings\n"), wxPoint(208,40), wxDefaultSize, 0, _T("ID_STATICTEXT1"));
	StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("Arena Settings"), wxPoint(224,112), wxSize(101,17), 0, _T("ID_STATICTEXT2"));
	Choice2 = new wxChoice(this, ID_CHOICE2, wxPoint(272,160), wxSize(80,29), 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE2"));
	Choice2->SetSelection( Choice2->Append(_("5")) );
	Choice2->Append(_("6"));
	Choice2->Append(_("7"));
	Choice2->Append(_("8"));
	Choice2->Append(_("9"));
	Choice2->Append(_("10"));
	Choice3 = new wxChoice(this, ID_CHOICE3, wxPoint(184,160), wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE3"));
	Choice3->SetSelection( Choice3->Append(_("5")) );
	Choice3->Append(_("6"));
	Choice3->Append(_("7"));
	Choice3->Append(_("8"));
	Choice3->Append(_("9"));
	Choice3->Append(_("10"));
	StaticText3 = new wxStaticText(this, ID_STATICTEXT3, _("Length"), wxPoint(200,136), wxDefaultSize, 0, _T("ID_STATICTEXT3"));
	StaticText4 = new wxStaticText(this, ID_STATICTEXT4, _("Width"), wxPoint(288,136), wxDefaultSize, 0, _T("ID_STATICTEXT4"));
	StaticText5 = new wxStaticText(this, ID_STATICTEXT5, _("Team Settings"), wxPoint(96,200), wxDefaultSize, 0, _T("ID_STATICTEXT5"));
	Choice4 = new wxChoice(this, ID_CHOICE4, wxPoint(88,224), wxSize(120,29), 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE4"));
	Choice4->SetSelection( Choice4->Append(_("Students")) );
	Choice4->Append(_("Teachers"));
	StaticText6 = new wxStaticText(this, ID_STATICTEXT6, _("Note: Team Settings will set Player 1. \nPlayer 2 will be set the opposite team"), wxPoint(224,216), wxDefaultSize, 0, _T("ID_STATICTEXT6"));
	Button1 = new wxButton(this, ID_BUTTON1, _("Apply"), wxPoint(176,272), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
	Button2 = new wxButton(this, ID_BUTTON2, _("Cancel"), wxPoint(280,272), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));

	Connect(ID_CHOICE1,wxEVT_COMMAND_CHOICE_SELECTED,(wxObjectEventFunction)&SettingsDialog::OnChoice1Select);
	Connect(ID_CHOICE2,wxEVT_COMMAND_CHOICE_SELECTED,(wxObjectEventFunction)&SettingsDialog::OnChoice2Select);
	Connect(ID_CHOICE3,wxEVT_COMMAND_CHOICE_SELECTED,(wxObjectEventFunction)&SettingsDialog::OnChoice3Select);
	Connect(ID_CHOICE4,wxEVT_COMMAND_CHOICE_SELECTED,(wxObjectEventFunction)&SettingsDialog::OnChoice4Select);
	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&SettingsDialog::OnButton1Click);
	Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&SettingsDialog::OnButton2Click);
	//*)
}

SettingsDialog::~SettingsDialog()
{
	//(*Destroy(SettingsDialog)
	//*)
}


void SettingsDialog::OnChoice3Select(wxCommandEvent& event) //Length
{
    lengthselected=Choice3->GetSelection();
}

void SettingsDialog::OnChoice2Select(wxCommandEvent& event) //Width
{
    widthselected=Choice2->GetSelection();
}

void SettingsDialog::OnChoice1Select(wxCommandEvent& event) //Mode
{
    modeselected=Choice1->GetSelection();
}

void SettingsDialog::OnChoice4Select(wxCommandEvent& event) //Team
{
    teamselected=Choice4->GetSelection();
}

void SettingsDialog::OnButton1Click(wxCommandEvent& event) //Apply
{
    if (widthselected==0){width=5;}
        else if (widthselected==1){width=6;}
        else if (widthselected==2){width=7;}
        else if (widthselected==3){width=8;}
        else if (widthselected==4){width=9;}
        else if (widthselected==5){width=10;}


    if (lengthselected==0){length=5;}
        else if (lengthselected==1){length=6;}
        else if (lengthselected==2){length=7;}
        else if (lengthselected==3){length=8;}
        else if (lengthselected==4){length=9;}
        else if (lengthselected==5){length=10;}


    Game game(width,length,modeselected,teamselected);

    game.settings();

    Destroy();

}

void SettingsDialog::OnButton2Click(wxCommandEvent& event) //Cancel
{
    Destroy();
}



