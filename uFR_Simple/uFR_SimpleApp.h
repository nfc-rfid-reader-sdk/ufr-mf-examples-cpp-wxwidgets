/***************************************************************
 * Name:      uFR_SimpleApp.h
 * Purpose:   Defines Application Class
 * Author:    Digital Logic (support@d-logic.rs)
 * Created:   2019-07-16
 * Copyright: Digital Logic (www.d-logic.net)
 * License:
 **************************************************************/

#ifndef UFR_SIMPLEAPP_H
#define UFR_SIMPLEAPP_H

#include <wx/app.h>

class uFR_SimpleApp : public wxApp
{
    public:
        virtual bool OnInit();
};

#endif // UFR_SIMPLEAPP_H
