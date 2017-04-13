#include "Specs.h"

//(*InternalHeaders(Specs)
#include <wx/string.h>
#include <wx/intl.h>
#include <wx/bitmap.h>
#include <wx/image.h>
//*)

//(*IdInit(Specs)
const long Specs::ID_STATICBITMAP1 = wxNewId();
const long Specs::ID_STATICBITMAP2 = wxNewId();
const long Specs::ID_STATICBITMAP3 = wxNewId();
const long Specs::ID_STATICBITMAP4 = wxNewId();
const long Specs::ID_STATICBITMAP5 = wxNewId();
const long Specs::ID_STATICBITMAP6 = wxNewId();
const long Specs::ID_STATICBITMAP7 = wxNewId();
const long Specs::ID_STATICBITMAP8 = wxNewId();
const long Specs::ID_STATICTEXT1 = wxNewId();
const long Specs::ID_STATICTEXT2 = wxNewId();
const long Specs::ID_STATICTEXT3 = wxNewId();
const long Specs::ID_STATICTEXT4 = wxNewId();
const long Specs::ID_STATICTEXT5 = wxNewId();
const long Specs::ID_STATICTEXT6 = wxNewId();
const long Specs::ID_STATICTEXT7 = wxNewId();
const long Specs::ID_STATICTEXT8 = wxNewId();
const long Specs::ID_BUTTON1 = wxNewId();
const long Specs::ID_PANEL1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(Specs,wxDialog)
	//(*EventTable(Specs)
	//*)
END_EVENT_TABLE()

Specs::Specs(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(Specs)
	Create(parent, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("wxID_ANY"));
	SetClientSize(wxSize(417,444));
	Panel1 = new wxPanel(this, ID_PANEL1, wxDefaultPosition, wxSize(417,441), wxTAB_TRAVERSAL, _T("ID_PANEL1"));
	StaticBitmap1 = new wxStaticBitmap(Panel1, ID_STATICBITMAP1, wxBitmap(wxImage(_T("./wrarrioswin.png"))), wxPoint(16,16), wxDefaultSize, wxSIMPLE_BORDER, _T("ID_STATICBITMAP1"));
	StaticBitmap2 = new wxStaticBitmap(Panel1, ID_STATICBITMAP2, wxBitmap(wxImage(_T("./midwarrior.png"))), wxPoint(16,120), wxDefaultSize, wxSIMPLE_BORDER, _T("ID_STATICBITMAP2"));
	StaticBitmap3 = new wxStaticBitmap(Panel1, ID_STATICBITMAP3, wxBitmap(wxImage(_T("./darkwarrior.png"))), wxPoint(16,224), wxDefaultSize, wxSIMPLE_BORDER, _T("ID_STATICBITMAP3"));
	StaticBitmap4 = new wxStaticBitmap(Panel1, ID_STATICBITMAP4, wxBitmap(wxImage(_T("./lightwarrior.png"))), wxPoint(16,328), wxDefaultSize, wxSIMPLE_BORDER, _T("ID_STATICBITMAP4"));
	StaticBitmap5 = new wxStaticBitmap(Panel1, ID_STATICBITMAP5, wxBitmap(wxImage(_T("./mageswin.png"))), wxPoint(232,16), wxDefaultSize, wxSIMPLE_BORDER, _T("ID_STATICBITMAP5"));
	StaticBitmap6 = new wxStaticBitmap(Panel1, ID_STATICBITMAP6, wxBitmap(wxImage(_T("./midmage.png"))), wxPoint(232,120), wxDefaultSize, wxSIMPLE_BORDER, _T("ID_STATICBITMAP6"));
	StaticBitmap7 = new wxStaticBitmap(Panel1, ID_STATICBITMAP7, wxBitmap(wxImage(_T("./darkmage.png"))), wxPoint(232,224), wxDefaultSize, wxSIMPLE_BORDER, _T("ID_STATICBITMAP7"));
	StaticBitmap8 = new wxStaticBitmap(Panel1, ID_STATICBITMAP8, wxBitmap(wxImage(_T("./lightmage.png"))), wxPoint(232,328), wxDefaultSize, wxSIMPLE_BORDER, _T("ID_STATICBITMAP8"));
	StaticText1 = new wxStaticText(Panel1, ID_STATICTEXT1, _("Damage   **\nHealth       **\nRange        *\nSpeed        **"), wxPoint(72,216), wxDefaultSize, 0, _T("ID_STATICTEXT1"));
	StaticText2 = new wxStaticText(Panel1, ID_STATICTEXT2, _("Damage   *****\nHealth      *****\nRange       **\nSpeed      ***"), wxPoint(72,8), wxDefaultSize, 0, _T("ID_STATICTEXT2"));
	StaticText3 = new wxStaticText(Panel1, ID_STATICTEXT3, _("Damage   ***\nHealth      ***\nRange       **\nSpeed       **"), wxPoint(72,112), wxDefaultSize, 0, _T("ID_STATICTEXT3"));
	StaticText4 = new wxStaticText(Panel1, ID_STATICTEXT4, _("Damage   *\nHealth       **\nRange        **\nSpeed        **"), wxPoint(72,320), wxDefaultSize, 0, _T("ID_STATICTEXT4"));
	StaticText5 = new wxStaticText(Panel1, ID_STATICTEXT5, _("Damage   *\nHealth       *\nRange        **\nSpeed        *"), wxPoint(288,216), wxDefaultSize, 0, _T("ID_STATICTEXT5"));
	StaticText6 = new wxStaticText(Panel1, ID_STATICTEXT6, _("Damage   **\nHealth       ***\nRange        ****\nSpeed       *****"), wxPoint(288,8), wxDefaultSize, 0, _T("ID_STATICTEXT6"));
	StaticText7 = new wxStaticText(Panel1, ID_STATICTEXT7, _("Damage   **\nHealth      **\nRange       ***\nSpeed       ***"), wxPoint(288,112), wxDefaultSize, 0, _T("ID_STATICTEXT7"));
	StaticText8 = new wxStaticText(Panel1, ID_STATICTEXT8, _("Damage   *\nHealth      *\nRange      **\nSpeed      **"), wxPoint(288,320), wxDefaultSize, 0, _T("ID_STATICTEXT8"));
	Button1 = new wxButton(Panel1, ID_BUTTON1, _("Close"), wxPoint(152,400), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));

	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&Specs::OnButton1Click);
	//*)
}

Specs::~Specs()
{
	//(*Destroy(Specs)
	//*)
}


void Specs::OnButton1Click(wxCommandEvent& event)
{
    Destroy();
}
