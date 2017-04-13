//
//#include "TeachersVsStudentsMain.h"
//#include <wx/msgdlg.h>
//#include "SettingsDialog.h"
//#include "arenagameplay.h"
//#include "arena.h"
//
//
////(*InternalHeaders(TeachersVsStudentsFrame)
//#include <wx/string.h>
//#include <wx/intl.h>
//#include <wx/bitmap.h>
//#include <wx/image.h>
////*)
//
////helper functions
//enum wxbuildinfoformat {
//    short_f, long_f };
//
//wxString wxbuildinfo(wxbuildinfoformat format)
//{
//    wxString wxbuild(wxVERSION_STRING);
//
//    if (format == long_f )
//    {
//#if defined(__WXMSW__)
//        wxbuild << _T("-Windows");
//#elif defined(__UNIX__)
//        wxbuild << _T("-Linux");
//#endif
//
//#if wxUSE_UNICODE
//        wxbuild << _T("-Unicode build");
//#else
//        wxbuild << _T("-ANSI build");
//#endif // wxUSE_UNICODE
//    }
//
//    return wxbuild;
//}
//
////(*IdInit(TeachersVsStudentsFrame)
//const long TeachersVsStudentsFrame::ID_STATICBITMAP1 = wxNewId();
//const long TeachersVsStudentsFrame::ID_BITMAPBUTTON2 = wxNewId();
//const long TeachersVsStudentsFrame::ID_PANEL2 = wxNewId();
//const long TeachersVsStudentsFrame::ID_STATICTEXT1 = wxNewId();
//const long TeachersVsStudentsFrame::ID_BITMAPBUTTON1 = wxNewId();
//const long TeachersVsStudentsFrame::ID_PANEL1 = wxNewId();
//const long TeachersVsStudentsFrame::idMenuQuit = wxNewId();
//const long TeachersVsStudentsFrame::idMenuAbout = wxNewId();
//const long TeachersVsStudentsFrame::ID_STATUSBAR1 = wxNewId();
////*)
//
//BEGIN_EVENT_TABLE(TeachersVsStudentsFrame,wxFrame)
//    //(*EventTable(TeachersVsStudentsFrame)
//    //*)
//END_EVENT_TABLE()
//
//TeachersVsStudentsFrame::TeachersVsStudentsFrame(wxWindow* parent,wxWindowID id)
//{
//    //(*Initialize(TeachersVsStudentsFrame)
//    wxMenuItem* MenuItem2;
//    wxMenuItem* MenuItem1;
//    wxMenu* Menu1;
//    wxMenuBar* MenuBar1;
//    wxMenu* Menu2;
//
//    Create(parent, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("wxID_ANY"));
//    SetClientSize(wxSize(609,799));
//    Panel1 = new wxPanel(this, ID_PANEL1, wxPoint(608,799), wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL1"));
//    StaticBitmap1 = new wxStaticBitmap(Panel1, ID_STATICBITMAP1, wxBitmap(wxImage(_T("Arcade.png")).Rescale(wxSize(608,799).GetWidth(),wxSize(608,799).GetHeight())), wxPoint(0,0), wxSize(608,799), wxSIMPLE_BORDER|wxSTATIC_BORDER, _T("ID_STATICBITMAP1"));
//    Panel2 = new wxPanel(Panel1, ID_PANEL2, wxPoint(0,424), wxSize(188,72), wxTAB_TRAVERSAL, _T("ID_PANEL2"));
//    Panel2->SetBackgroundColour(wxColour(102,102,102));
//    BitmapButton2 = new wxBitmapButton(Panel2, ID_BITMAPBUTTON2, wxBitmap(wxImage(_T("Settings.png"))), wxPoint(16,32), wxSize(160,32), wxBU_AUTODRAW|wxNO_BORDER, wxDefaultValidator, _T("ID_BITMAPBUTTON2"));
//    BitmapButton2->SetBackgroundColour(wxColour(102,102,102));
//    StaticText1 = new wxStaticText(Panel1, ID_STATICTEXT1, _("Henceforth tells the forgotten tale of the Battle of Midevil\n\nDo you dare to travel alone\?\n\nIn a time long, long ago, the Students of Rygon were locked in deep battle against the Teachers of Zoruvia. One day two mysterious figures appeared, battle hardened and wise, they claimed to have come from the future to end this battle once and for all. \n\nThe world awaited their decision which sides were they on\?"), wxPoint(160,296), wxSize(288,256), wxALIGN_CENTRE, _T("ID_STATICTEXT1"));
//    BitmapButton1 = new wxBitmapButton(Panel1, ID_BITMAPBUTTON1, wxBitmap(wxImage(_T("Start.png"))), wxPoint(456,432), wxSize(160,32), wxBU_AUTODRAW|wxNO_BORDER, wxDefaultValidator, _T("ID_BITMAPBUTTON1"));
//    BitmapButton1->SetBackgroundColour(wxColour(102,102,102));
//    MenuBar1 = new wxMenuBar();
//    Menu1 = new wxMenu();
//    MenuItem1 = new wxMenuItem(Menu1, idMenuQuit, _("Quit\tAlt-F4"), _("Quit the application"), wxITEM_NORMAL);
//    Menu1->Append(MenuItem1);
//    MenuBar1->Append(Menu1, _("&File"));
//    Menu2 = new wxMenu();
//    MenuItem2 = new wxMenuItem(Menu2, idMenuAbout, _("About\tF1"), _("Show info about this application"), wxITEM_NORMAL);
//    Menu2->Append(MenuItem2);
//    MenuBar1->Append(Menu2, _("Help"));
//    SetMenuBar(MenuBar1);
//    StatusBar1 = new wxStatusBar(this, ID_STATUSBAR1, 0, _T("ID_STATUSBAR1"));
//    int __wxStatusBarWidths_1[1] = { -1 };
//    int __wxStatusBarStyles_1[1] = { wxSB_NORMAL };
//    StatusBar1->SetFieldsCount(1,__wxStatusBarWidths_1);
//    StatusBar1->SetStatusStyles(1,__wxStatusBarStyles_1);
//    SetStatusBar(StatusBar1);
//
//    Connect(ID_BITMAPBUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&TeachersVsStudentsFrame::OnBitmapButton2Click);
//    Panel2->Connect(wxEVT_PAINT,(wxObjectEventFunction)&TeachersVsStudentsFrame::OnPanel2Paint,0,this);
//    Connect(ID_BITMAPBUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&TeachersVsStudentsFrame::OnBitmapButton1Click);
//    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&TeachersVsStudentsFrame::OnQuit);
//    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&TeachersVsStudentsFrame::OnAbout);
//    //*)
//}
//
//TeachersVsStudentsFrame::~TeachersVsStudentsFrame()
//{
//    //(*Destroy(TeachersVsStudentsFrame)
//    //*)
//}
//
//void TeachersVsStudentsFrame::OnQuit(wxCommandEvent& event)
//{
//    Close();
//}
//
//void TeachersVsStudentsFrame::OnAbout(wxCommandEvent& event)
//{
//    wxString msg = wxbuildinfo(long_f);
//    wxMessageBox(msg, _("Welcome to..."));
//}
//
//void TeachersVsStudentsFrame::OnBitmapButton1Click(wxCommandEvent& event) //Start
//{
//    arenagameplay* Frame2 = new arenagameplay(0);
//    Frame2->Show(); // has to be removed
//    Destroy();
//}
//
//void TeachersVsStudentsFrame::OnBitmapButton2Click(wxCommandEvent& event) //Settings
//{
//    SettingsDialog dialog(this);
//    dialog.ShowModal(); //move to main game frame
//}
//
//void TeachersVsStudentsFrame::OnPanel2Paint(wxPaintEvent& event)
//{
//}
//
//
