#ifndef SINGLEPLAYER_H
#define SINGLEPLAYER_H

//(*Headers(Singleplayer)
#include <wx/dialog.h>
//*)

class Singleplayer: public wxDialog
{
	public:

		Singleplayer(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~Singleplayer();

		//(*Declarations(Singleplayer)
		//*)

	protected:

		//(*Identifiers(Singleplayer)
		//*)

	private:

		//(*Handlers(Singleplayer)
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
