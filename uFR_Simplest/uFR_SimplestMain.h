/***************************************************************
 * Name:      uFR_SimplestMain.h
 * Purpose:   Defines Application Frame
 * Author:    Aleksandar Krstic (aleksandar.krstic@d-logic.rs)
 * Created:   2019-07-15
 * Copyright: Aleksandar Krstic (www.d-logic.net)
 * License:
 **************************************************************/

#ifndef UFR_SIMPLESTMAIN_H
#define UFR_SIMPLESTMAIN_H

#include "lib/include/uFCoder.h"

//(*Headers(uFR_SimplestFrame)
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/checkbox.h>
#include <wx/statline.h>
#include <wx/statbox.h>
#include <wx/hyperlink.h>
#include <wx/button.h>
#include <wx/frame.h>
#include <wx/timer.h>
#include <wx/statusbr.h>
//*)

class uFR_SimplestFrame: public wxFrame
{
    public:

        uFR_SimplestFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~uFR_SimplestFrame();

    private:

        //(*Handlers(uFR_SimplestFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnbtnReaderOpenClick(wxCommandEvent& event);
        void OnUseAdvancedCHClick(wxCommandEvent& event);
        void CheckConnectionStatus(UFR_STATUS status);
        void CheckCardStatus(UFR_STATUS status);
        void CheckFunctionStatus(UFR_STATUS status);
        void OnTimer1Trigger(wxTimerEvent& event);
        void OnbtnFormatCardClick(wxCommandEvent& event);
        void OnbtnLinearWriteClick(wxCommandEvent& event);
        void OnbtnLinearReadClick(wxCommandEvent& event);
        //*)

        //(*Identifiers(uFR_SimplestFrame)
        static const long ID_STATICBOX1;
        static const long ID_BUTTON1;
        static const long ID_CHECKBOX1;
        static const long ID_HYPERLINKCTRL1;
        static const long ID_STATICBOX2;
        static const long ID_STATICTEXT1;
        static const long ID_TEXTCTRL1;
        static const long ID_STATICTEXT2;
        static const long ID_TEXTCTRL2;
        static const long ID_STATICTEXT3;
        static const long ID_TEXTCTRL3;
        static const long ID_STATICTEXT4;
        static const long ID_TEXTCTRL4;
        static const long ID_STATICTEXT5;
        static const long ID_TEXTCTRL5;
        static const long ID_STATICTEXT6;
        static const long ID_TEXTCTRL6;
        static const long ID_STATICTEXT7;
        static const long ID_TEXTCTRL7;
        static const long ID_BUTTON2;
        static const long ID_STATICTEXT8;
        static const long ID_TEXTCTRL8;
        static const long ID_STATICTEXT9;
        static const long ID_TEXTCTRL9;
        static const long ID_BUTTON3;
        static const long ID_BUTTON4;
        static const long ID_STATICLINE1;
        static const long ID_STATICTEXT10;
        static const long ID_STATICLINE2;
        static const long ID_STATICTEXT11;
        static const long ID_STATICLINE3;
        static const long ID_STATICLINE4;
        static const long ID_STATICTEXT12;
        static const long ID_STATICTEXT13;
        static const long ID_STATICTEXT14;
        static const long ID_STATICTEXT15;
        static const long ID_STATUSBAR1;
        static const long ID_TIMER1;
        //*)

        //(*Declarations(uFR_SimplestFrame)
        wxStaticText* StaticText10;
        wxStaticText* StaticText9;
        wxCheckBox* UseAdvancedCH;
        wxTextCtrl* CardTypeTB;
        wxStaticText* ArgST;
        wxTextCtrl* ArgTB;
        wxTextCtrl* RTypeTB;
        wxStaticText* StaticText6;
        wxTextCtrl* ReadDataTB;
        wxStaticText* StaticText8;
        wxStaticText* StaticText11;
        wxTextCtrl* UidTB;
        wxButton* btnLinearWrite;
        wxHyperlinkCtrl* HyperlinkCtrl1;
        wxStaticBox* StaticBox1;
        wxTextCtrl* UidSizeTB;
        wxTextCtrl* PinterfaceTB;
        wxStaticText* PnameST;
        wxStaticLine* StaticLine4;
        wxStaticLine* StaticLine2;
        wxStaticText* FunctionStatus;
        wxTextCtrl* PnameTB;
        wxStaticBox* StaticBox2;
        wxStaticText* ConnectionStatus;
        wxStaticText* RtypeST;
        wxStaticText* StaticText5;
        wxStaticText* StaticText7;
        wxButton* btnLinearRead;
        wxStatusBar* StatusBar1;
        wxStaticText* PinterfaceST;
        wxStaticLine* StaticLine3;
        wxButton* btnReaderOpen;
        wxStaticLine* StaticLine1;
        wxButton* btnFormatCard;
        wxStaticText* StaticText12;
        wxStaticText* CardStatus;
        wxTextCtrl* WriteDataTB;
        wxTimer Timer1;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // UFR_SIMPLESTMAIN_H
