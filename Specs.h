#ifndef SPECS_H
#define SPECS_H

//(*Headers(Specs)
#include <wx/dialog.h>
#include <wx/button.h>
#include <wx/panel.h>
#include <wx/stattext.h>
#include <wx/statbmp.h>
//*)

class Specs: public wxDialog
{
	public:

		Specs(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~Specs();

		//(*Declarations(Specs)
		wxPanel* Panel1;
		wxStaticBitmap* StaticBitmap7;
		wxButton* Button1;
		wxStaticBitmap* StaticBitmap5;
		wxStaticBitmap* StaticBitmap6;
		wxStaticText* StaticText1;
		wxStaticText* StaticText3;
		wxStaticBitmap* StaticBitmap8;
		wxStaticText* StaticText8;
		wxStaticText* StaticText7;
		wxStaticText* StaticText4;
		wxStaticText* StaticText5;
		wxStaticText* StaticText2;
		wxStaticBitmap* StaticBitmap3;
		wxStaticBitmap* StaticBitmap1;
		wxStaticText* StaticText6;
		wxStaticBitmap* StaticBitmap4;
		wxStaticBitmap* StaticBitmap2;
		//*)

	protected:

		//(*Identifiers(Specs)
		static const long ID_STATICBITMAP1;
		static const long ID_STATICBITMAP2;
		static const long ID_STATICBITMAP3;
		static const long ID_STATICBITMAP4;
		static const long ID_STATICBITMAP5;
		static const long ID_STATICBITMAP6;
		static const long ID_STATICBITMAP7;
		static const long ID_STATICBITMAP8;
		static const long ID_STATICTEXT1;
		static const long ID_STATICTEXT2;
		static const long ID_STATICTEXT3;
		static const long ID_STATICTEXT4;
		static const long ID_STATICTEXT5;
		static const long ID_STATICTEXT6;
		static const long ID_STATICTEXT7;
		static const long ID_STATICTEXT8;
		static const long ID_BUTTON1;
		static const long ID_PANEL1;
		//*)

	private:

		//(*Handlers(Specs)
		void OnButton1Click(wxCommandEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
