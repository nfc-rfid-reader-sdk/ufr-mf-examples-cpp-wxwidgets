/***************************************************************
 * Name:      uFR_SimplestApp.cpp
 * Purpose:   Code for Application Class
 * Author:    Aleksandar Krstic (aleksandar.krstic@d-logic.rs)
 * Created:   2019-07-15
 * Copyright: Aleksandar Krstic (www.d-logic.net)
 * License:
 **************************************************************/

#include "uFR_SimplestApp.h"

//(*AppHeaders
#include "uFR_SimplestMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(uFR_SimplestApp);

bool uFR_SimplestApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	uFR_SimplestFrame* Frame = new uFR_SimplestFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
