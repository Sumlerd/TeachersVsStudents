#ifndef ARENAGAMEPLAY_H
#define ARENAGAMEPLAY_H

#include "arena.h"

//(*Headers(arenagameplay)
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/statline.h>
#include <wx/panel.h>
#include <wx/choice.h>
#include <wx/statbmp.h>
#include <wx/button.h>
#include <wx/frame.h>
#include <wx/statusbr.h>
//*)

class arenagameplay: public wxFrame
{
	public:

		arenagameplay(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~arenagameplay();

		int speed;
		int lengthselected;
		int widthselected;
		int modeselected = 0;
		int teamselected = 0;
		int length;
		int width;
		wxStopWatch watch;

		void OnIdle(wxIdleEvent& event);

		//(*Declarations(arenagameplay)
		wxStaticBitmap* StaticBitmap2;
		wxTextCtrl* TextCtrl4;
		wxStaticText* StaticText2;
		wxButton* Button1;
		wxStaticText* StaticText6;
		wxStaticBitmap* StaticBitmap1;
		wxStaticText* StaticText1;
		wxStaticText* StaticText3;
		wxStaticLine* StaticLine2;
		wxButton* Button5;
		wxStaticBitmap* StaticBitmap10;
		wxStaticText* StaticText5;
		wxStaticText* StaticText7;
		wxStatusBar* StatusBar1;
		wxStaticLine* StaticLine1;
		wxTextCtrl* TextCtrl2;
		wxTextCtrl* TextCtrl1;
		wxPanel* Panel2;
		wxStaticBitmap* StaticBitmap6;
		wxStaticText* StaticText4;
		wxTextCtrl* TextCtrl3;
		wxChoice* Choice1;
		wxChoice* Choice2;
		//*)

	protected:

		//(*Identifiers(arenagameplay)
		static const long ID_STATICBITMAP1;
		static const long ID_STATICBITMAP2;
		static const long ID_STATICBITMAP6;
		static const long ID_STATICBITMAP10;
		static const long ID_BUTTON1;
		static const long ID_STATICLINE1;
		static const long ID_CHOICE1;
		static const long ID_CHOICE2;
		static const long ID_BUTTON5;
		static const long ID_STATICTEXT1;
		static const long ID_STATICTEXT2;
		static const long ID_STATICTEXT3;
		static const long ID_STATICLINE2;
		static const long ID_TEXTCTRL1;
		static const long ID_TEXTCTRL2;
		static const long ID_STATICTEXT4;
		static const long ID_STATICTEXT5;
		static const long ID_TEXTCTRL3;
		static const long ID_STATICTEXT6;
		static const long ID_TEXTCTRL4;
		static const long ID_STATICTEXT7;
		static const long ID_PANEL2;
		static const long ID_STATUSBAR1;
		//*)

	private:

		//(*Handlers(arenagameplay)
		void OnPanel1Paint(wxPaintEvent& event);
		void OnButton1Click(wxCommandEvent& event);
		void OnPanel1Paint1(wxPaintEvent& event);
		void OnTextCtrl1Text(wxCommandEvent& event);
		void OnTextCtrl2Text(wxCommandEvent& event);
		void OnTextCtrl3Text(wxCommandEvent& event);
		void OnTextCtrl4Text(wxCommandEvent& event);
		void OnTextCtrl5Text(wxCommandEvent& event);
		void OnTextCtrl6Text(wxCommandEvent& event);
		void OnTextCtrl7Text(wxCommandEvent& event);
		void OnTextCtrl8Text(wxCommandEvent& event);
		void OnPanel3Paint(wxPaintEvent& event);
		void OnPanel3Paint1(wxPaintEvent& event);
		void OnPanel3Paint2(wxPaintEvent& event);
		void OnPanel2Paint(wxPaintEvent& event);
		void OnButton2Click(wxCommandEvent& event);
		void OnButton3Click(wxCommandEvent& event);
		void OnButton2Click1(wxCommandEvent& event);
		void OnChoice1Select(wxCommandEvent& event);
		void OnButton5Click(wxCommandEvent& event);
		void OnButton3Click1(wxCommandEvent& event);
		void OnButton4Click(wxCommandEvent& event);
		void OnButton6Click(wxCommandEvent& event);
		void OnButton7Click(wxCommandEvent& event);
		void OnButton8Click(wxCommandEvent& event);
		void OnButton9Click(wxCommandEvent& event);
		void OnButton10Click(wxCommandEvent& event);
		void OnButton3Click2(wxCommandEvent& event);
		void Settings(wxCommandEvent& event);
		void OnChoice1Select1(wxCommandEvent& event);
		void OnChoice2Select(wxCommandEvent& event);
		void OnButton5Click1(wxCommandEvent& event);
		void OnTextCtrl1Text1(wxCommandEvent& event);
		void OnClose(wxCloseEvent& event);
		void OnClose1(wxCloseEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
