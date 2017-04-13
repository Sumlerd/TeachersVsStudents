#ifndef SETTINGSDIALOG_H
#define SETTINGSDIALOG_H

//(*Headers(SettingsDialog)
#include <wx/dialog.h>
#include <wx/button.h>
#include <wx/stattext.h>
#include <wx/choice.h>
#include <wx/statbmp.h>
//*)

class SettingsDialog: public wxDialog
{
	public:

		SettingsDialog(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~SettingsDialog();

		//(*Declarations(SettingsDialog)
		wxChoice* Choice3;
		wxButton* Button1;
		wxButton* Button2;
		wxChoice* Choice2;
		wxStaticText* StaticText1;
		wxChoice* Choice4;
		wxStaticText* StaticText3;
		wxChoice* Choice1;
		wxStaticText* StaticText4;
		wxStaticText* StaticText5;
		wxStaticText* StaticText2;
		wxStaticBitmap* StaticBitmap1;
		wxStaticText* StaticText6;
		//*)
		int lengthselected;
		int widthselected;
		int modeselected;
		int teamselected;
		int length;
		int width;

	protected:

		//(*Identifiers(SettingsDialog)
		static const long ID_STATICBITMAP1;
		static const long ID_CHOICE1;
		static const long ID_STATICTEXT1;
		static const long ID_STATICTEXT2;
		static const long ID_CHOICE2;
		static const long ID_CHOICE3;
		static const long ID_STATICTEXT3;
		static const long ID_STATICTEXT4;
		static const long ID_STATICTEXT5;
		static const long ID_CHOICE4;
		static const long ID_STATICTEXT6;
		static const long ID_BUTTON1;
		static const long ID_BUTTON2;
		//*)

	private:

		//(*Handlers(SettingsDialog)
		void OnChoice3Select(wxCommandEvent& event);
		void OnChoice2Select(wxCommandEvent& event);
		void OnChoice1Select(wxCommandEvent& event);
		void OnChoice4Select(wxCommandEvent& event);
		void OnButton1Click(wxCommandEvent& event);
		void OnButton2Click(wxCommandEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};


#endif
