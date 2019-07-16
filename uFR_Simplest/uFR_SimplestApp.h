/***************************************************************
 * Name:      uFR_SimplestApp.h
 * Purpose:   Defines Application Class
 * Author:    Aleksandar Krstic (aleksandar.krstic@d-logic.rs)
 * Created:   2019-07-15
 * Copyright: Aleksandar Krstic (www.d-logic.net)
 * License:
 **************************************************************/

#ifndef UFR_SIMPLESTAPP_H
#define UFR_SIMPLESTAPP_H

#include <wx/app.h>

class uFR_SimplestApp : public wxApp
{
    public:
        virtual bool OnInit();
};

#endif // UFR_SIMPLESTAPP_H
