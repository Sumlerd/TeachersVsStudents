

#ifndef TEACHERSVSSTUDENTS_H
#define TEACHERSVSSTUDENTS_H

//(*Headers(TeachersVsStudentsFrame)
#include <wx/bmpbuttn.h>
#include <wx/menu.h>
#include <wx/panel.h>
#include <wx/statusbr.h>
#include <wx/frame.h>
#include <wx/stattext.h>
#include <wx/statbmp.h>
//*)

class TeachersVsStudentsFrame: public wxFrame
{
    public:

        TeachersVsStudentsFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~TeachersVsStudentsFrame();

    private:

        //(*Handlers(TeachersVsStudentsFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnPanel2Paint(wxPaintEvent& event);
        void OnBitmapButton1Click(wxCommandEvent& event);
        void OnBitmapButton2Click(wxCommandEvent& event);
        void OnClose(wxCloseEvent& event);
        //*)

        //(*Identifiers(TeachersVsStudentsFrame)
        static const long ID_STATICBITMAP1;
        static const long ID_BITMAPBUTTON2;
        static const long ID_PANEL2;
        static const long ID_STATICTEXT1;
        static const long ID_BITMAPBUTTON1;
        static const long ID_PANEL1;
        static const long idMenuQuit;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        //*)

        //(*Declarations(TeachersVsStudentsFrame)
        wxBitmapButton* BitmapButton2;
        wxPanel* Panel1;
        wxStatusBar* StatusBar1;
        wxStaticText* StaticText1;
        wxPanel* Panel2;
        wxStaticBitmap* StaticBitmap1;
        wxBitmapButton* BitmapButton1;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // TEACHERSVSSTUDENTS_H
