#include "TeachersVsStudentsApp.h"

//(*AppHeaders
#include "arenagameplay.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(TeachersVsStudentsApp);

bool TeachersVsStudentsApp::OnInit()
{

    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	arenagameplay* Frame = new arenagameplay(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
