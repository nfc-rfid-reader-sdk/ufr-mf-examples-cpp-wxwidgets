/***************************************************************
 * Name:      uFR_SimpleApp.cpp
 * Purpose:   Code for Application Class
 * Author:    Digital Logic (support@d-logic.rs)
 * Created:   2019-07-16
 * Copyright: Digital Logic (www.d-logic.net)
 * License:
 **************************************************************/

#include "uFR_SimpleApp.h"

//(*AppHeaders
#include "uFR_SimpleMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(uFR_SimpleApp);

bool uFR_SimpleApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	uFR_SimpleFrame* Frame = new uFR_SimpleFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
