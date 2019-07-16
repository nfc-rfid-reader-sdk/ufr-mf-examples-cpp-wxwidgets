/***************************************************************
 * Name:      uFR_SimpleMain.h
 * Purpose:   Defines Application Frame
 * Author:    Digital Logic (support@d-logic.rs)
 * Created:   2019-07-16
 * Copyright: Digital Logic (www.d-logic.net)
 * License:
 **************************************************************/

#ifndef UFR_SIMPLEMAIN_H
#define UFR_SIMPLEMAIN_H

#include "lib/include/uFCoder.h"

//(*Headers(uFR_SimpleFrame)
#include <wx/notebook.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/checkbox.h>
#include <wx/spinctrl.h>
#include <wx/statline.h>
#include <wx/radiobut.h>
#include <wx/statbox.h>
#include <wx/panel.h>
#include <wx/hyperlink.h>
#include <wx/button.h>
#include <wx/frame.h>
#include <wx/timer.h>
#include <wx/combobox.h>
#include <wx/statusbr.h>
//*)

class uFR_SimpleFrame: public wxFrame
{
    public:

        uFR_SimpleFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~uFR_SimpleFrame();

    private:

        //(*Handlers(uFR_SimpleFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnUseAdvancedCHClick(wxCommandEvent& event);
        void CheckCardStatus(UFR_STATUS status);
        void CheckFunctionStatus(UFR_STATUS status);
        void OnbtnReaderOpenClick(wxCommandEvent& event);
        void OnTimer1Trigger(wxTimerEvent& event);
        void OnbtnReaderUISignalClick(wxCommandEvent& event);
        void OnbtnFormatCardClick(wxCommandEvent& event);
        void OnbtnWriteKeyIntoReaderClick(wxCommandEvent& event);
        void OnbtnLinearReadClick(wxCommandEvent& event);
        void OnbtnLinearWriteClick(wxCommandEvent& event);
        void OnWriteDataTBTextEnter(wxCommandEvent& event);
        void OnWriteDataTBText(wxCommandEvent& event);
        //*)

        //(*Identifiers(uFR_SimpleFrame)
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
        static const long ID_STATICBOX3;
        static const long ID_STATICTEXT5;
        static const long ID_TEXTCTRL5;
        static const long ID_STATICTEXT6;
        static const long ID_TEXTCTRL6;
        static const long ID_STATICTEXT7;
        static const long ID_TEXTCTRL7;
        static const long ID_STATICTEXT8;
        static const long ID_TEXTCTRL8;
        static const long ID_STATICTEXT9;
        static const long ID_TEXTCTRL9;
        static const long ID_STATICLINE1;
        static const long ID_STATICTEXT10;
        static const long ID_COMBOBOX1;
        static const long ID_STATICTEXT11;
        static const long ID_COMBOBOX2;
        static const long ID_BUTTON2;
        static const long ID_STATICLINE2;
        static const long ID_STATICBOX4;
        static const long ID_RADIOBUTTON1;
        static const long ID_RADIOBUTTON2;
        static const long ID_STATICTEXT12;
        static const long ID_TEXTCTRL10;
        static const long ID_STATICTEXT13;
        static const long ID_TEXTCTRL11;
        static const long ID_BUTTON3;
        static const long ID_STATICTEXT14;
        static const long ID_TEXTCTRL12;
        static const long ID_PANEL1;
        static const long ID_STATICTEXT15;
        static const long ID_TEXTCTRL13;
        static const long ID_STATICTEXT16;
        static const long ID_SPINCTRL1;
        static const long ID_BUTTON4;
        static const long ID_PANEL2;
        static const long ID_NOTEBOOK1;
        static const long ID_STATICTEXT21;
        static const long ID_TEXTCTRL18;
        static const long ID_STATICTEXT22;
        static const long ID_TEXTCTRL19;
        static const long ID_STATICTEXT23;
        static const long ID_TEXTCTRL20;
        static const long ID_STATICTEXT24;
        static const long ID_TEXTCTRL21;
        static const long ID_BUTTON6;
        static const long ID_PANEL3;
        static const long ID_STATICTEXT17;
        static const long ID_TEXTCTRL14;
        static const long ID_STATICTEXT18;
        static const long ID_TEXTCTRL15;
        static const long ID_STATICTEXT19;
        static const long ID_TEXTCTRL16;
        static const long ID_STATICTEXT20;
        static const long ID_TEXTCTRL17;
        static const long ID_BUTTON5;
        static const long ID_PANEL4;
        static const long ID_NOTEBOOK2;
        static const long ID_STATICLINE3;
        static const long ID_STATICTEXT25;
        static const long ID_STATICLINE4;
        static const long ID_STATICTEXT26;
        static const long ID_STATICLINE5;
        static const long ID_STATICTEXT27;
        static const long ID_STATICTEXT28;
        static const long ID_STATUSBAR1;
        static const long ID_TIMER1;
        //*)

        //(*Declarations(uFR_SimpleFrame)
        wxStaticText* StaticText10;
        wxStaticText* StaticText22;
        wxStaticText* StaticText9;
        wxStaticText* StaticText20;
        wxTextCtrl* ReaderSerialTB;
        wxTextCtrl* ReadBytesTB;
        wxCheckBox* UseAdvancedCH;
        wxComboBox* LightCB;
        wxTextCtrl* CardTypeTB;
        wxNotebook* Notebook1;
        wxStaticText* ArgST;
        wxStaticText* StaticText13;
        wxPanel* Panel4;
        wxStaticText* StaticText14;
        wxTextCtrl* ArgTB;
        wxStaticText* StaticText26;
        wxStaticText* StaticText6;
        wxTextCtrl* ReadDataTB;
        wxTextCtrl* ReaderTypeViewTB;
        wxStaticText* StaticText19;
        wxStaticText* StaticText8;
        wxStaticText* StaticText11;
        wxTextCtrl* UidTB;
        wxStaticText* StaticText18;
        wxButton* btnReaderUISignal;
        wxPanel* Panel1;
        wxRadioButton* RB_KeyA;
        wxTextCtrl* DA_WriteTB;
        wxButton* btnLinearWrite;
        wxHyperlinkCtrl* HyperlinkCtrl1;
        wxStaticBox* StaticBox1;
        wxTextCtrl* UidSizeTB;
        wxTextCtrl* PinterfaceTB;
        wxStaticText* PnameST;
        wxStaticLine* StaticLine4;
        wxPanel* Panel3;
        wxStaticText* StaticText21;
        wxStaticLine* StaticLine2;
        wxStaticText* FunctionStatus;
        wxTextCtrl* PnameTB;
        wxStaticBox* StaticBox2;
        wxStaticText* StaticText23;
        wxStaticText* StaticText24;
        wxStaticText* RtypeST;
        wxTextCtrl* RtypeTB;
        wxComboBox* BeepCB;
        wxButton* btnWriteKeyIntoReader;
        wxStaticText* StaticText5;
        wxStaticText* StaticText7;
        wxButton* btnLinearRead;
        wxTextCtrl* NewKeyBTB;
        wxRadioButton* RB_KeyB;
        wxStatusBar* StatusBar1;
        wxStaticText* PinterfaceST;
        wxStaticLine* StaticLine3;
        wxButton* btnReaderOpen;
        wxStaticLine* StaticLine1;
        wxButton* btnFormatCard;
        wxTextCtrl* DL_ReadTB;
        wxTextCtrl* LA_ReadTB;
        wxTextCtrl* Written_TB;
        wxStaticBox* StaticBox3;
        wxTextCtrl* NewKeyATB;
        wxTextCtrl* ReaderKeyTB;
        wxStaticText* StaticText15;
        wxStaticText* StaticText12;
        wxStaticText* CardStatus;
        wxTextCtrl* SectorsFormattedTB;
        wxTextCtrl* LA_WriteTB;
        wxPanel* Panel2;
        wxTextCtrl* WriteDataTB;
        wxStaticText* StaticText25;
        wxNotebook* Notebook2;
        wxStaticText* StaticText17;
        wxStaticText* StaticText16;
        wxTimer Timer1;
        wxSpinCtrl* KeyIndexSpin;
        wxStaticBox* StaticBox4;
        wxStaticLine* StaticLine5;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // UFR_SIMPLEMAIN_H
