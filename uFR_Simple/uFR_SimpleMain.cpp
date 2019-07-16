/***************************************************************
 * Name:      uFR_SimpleMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    Digital Logic (support@d-logic.rs)
 * Created:   2019-07-16
 * Copyright: Digital Logic (www.d-logic.net)
 * License:
 **************************************************************/

#include "uFR_SimpleMain.h"
#include <wx/msgdlg.h>
#include <string>
#include <string.h>
#include <cstring>
#include <sstream>
#include <algorithm>

using namespace std;

//(*InternalHeaders(uFR_SimpleFrame)
#include <wx/settings.h>
#include <wx/font.h>
#include <wx/intl.h>
#include <wx/string.h>
//*)

const char hexChars[22] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
                         'a', 'b', 'c', 'd', 'e', 'f',
                         'A', 'B', 'C', 'D', 'E', 'F'};

bool isHexChar(char c)
{
    for(uint8_t i = 0; i < 22; i++)
    {
        if(c == hexChars[i])
        {
            return true;
        }
    }

    return false;
}

bool isHexString(string str)
{

   for(uint32_t i = 0; i < str.length(); i++)
   {
       if(!isHexChar(str.at(i)))
       {
           return false;
       }
   }

   return true;
}

string eraseDelimiters(string hexStr)
{
    for(uint32_t i = 0; i < hexStr.length(); i++)
    {
        if(!isHexChar(hexStr.at(i)))
        {
            hexStr.erase(i, 1);
        }
    }

    return hexStr;
}

void ConvertHexStringToByteArray(string str, uint8_t *array) {

    str = eraseDelimiters(str);

    for (unsigned int i = 0; i < str.length() / 2; i++) {

        string part = str.substr(i * 2, 2);

        char str1[32];
        char *ptr;
        strcpy(str1, part.c_str());

        array[i] = strtol(str1, &ptr, 16);
    }
}

string ConvertByteArrayToHexString(const uint8_t *data, int len, string delimiter) {

    stringstream ss;
    ss << uppercase << hex;

    for (int i = 0; i < len; i++) {
    	if(data[i] <= 0x0F)
    	{
    		 ss << "0";
    	}
    	 ss << (uint32_t) data[i] << delimiter;
    }
    string result = ss.str();

    if(delimiter != "")
    {
         result = result.substr(0, result.length()-1);
    }

    return result;
}

//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}

//(*IdInit(uFR_SimpleFrame)
const long uFR_SimpleFrame::ID_STATICBOX1 = wxNewId();
const long uFR_SimpleFrame::ID_BUTTON1 = wxNewId();
const long uFR_SimpleFrame::ID_CHECKBOX1 = wxNewId();
const long uFR_SimpleFrame::ID_HYPERLINKCTRL1 = wxNewId();
const long uFR_SimpleFrame::ID_STATICBOX2 = wxNewId();
const long uFR_SimpleFrame::ID_STATICTEXT1 = wxNewId();
const long uFR_SimpleFrame::ID_TEXTCTRL1 = wxNewId();
const long uFR_SimpleFrame::ID_STATICTEXT2 = wxNewId();
const long uFR_SimpleFrame::ID_TEXTCTRL2 = wxNewId();
const long uFR_SimpleFrame::ID_STATICTEXT3 = wxNewId();
const long uFR_SimpleFrame::ID_TEXTCTRL3 = wxNewId();
const long uFR_SimpleFrame::ID_STATICTEXT4 = wxNewId();
const long uFR_SimpleFrame::ID_TEXTCTRL4 = wxNewId();
const long uFR_SimpleFrame::ID_STATICBOX3 = wxNewId();
const long uFR_SimpleFrame::ID_STATICTEXT5 = wxNewId();
const long uFR_SimpleFrame::ID_TEXTCTRL5 = wxNewId();
const long uFR_SimpleFrame::ID_STATICTEXT6 = wxNewId();
const long uFR_SimpleFrame::ID_TEXTCTRL6 = wxNewId();
const long uFR_SimpleFrame::ID_STATICTEXT7 = wxNewId();
const long uFR_SimpleFrame::ID_TEXTCTRL7 = wxNewId();
const long uFR_SimpleFrame::ID_STATICTEXT8 = wxNewId();
const long uFR_SimpleFrame::ID_TEXTCTRL8 = wxNewId();
const long uFR_SimpleFrame::ID_STATICTEXT9 = wxNewId();
const long uFR_SimpleFrame::ID_TEXTCTRL9 = wxNewId();
const long uFR_SimpleFrame::ID_STATICLINE1 = wxNewId();
const long uFR_SimpleFrame::ID_STATICTEXT10 = wxNewId();
const long uFR_SimpleFrame::ID_COMBOBOX1 = wxNewId();
const long uFR_SimpleFrame::ID_STATICTEXT11 = wxNewId();
const long uFR_SimpleFrame::ID_COMBOBOX2 = wxNewId();
const long uFR_SimpleFrame::ID_BUTTON2 = wxNewId();
const long uFR_SimpleFrame::ID_STATICLINE2 = wxNewId();
const long uFR_SimpleFrame::ID_STATICBOX4 = wxNewId();
const long uFR_SimpleFrame::ID_RADIOBUTTON1 = wxNewId();
const long uFR_SimpleFrame::ID_RADIOBUTTON2 = wxNewId();
const long uFR_SimpleFrame::ID_STATICTEXT12 = wxNewId();
const long uFR_SimpleFrame::ID_TEXTCTRL10 = wxNewId();
const long uFR_SimpleFrame::ID_STATICTEXT13 = wxNewId();
const long uFR_SimpleFrame::ID_TEXTCTRL11 = wxNewId();
const long uFR_SimpleFrame::ID_BUTTON3 = wxNewId();
const long uFR_SimpleFrame::ID_STATICTEXT14 = wxNewId();
const long uFR_SimpleFrame::ID_TEXTCTRL12 = wxNewId();
const long uFR_SimpleFrame::ID_PANEL1 = wxNewId();
const long uFR_SimpleFrame::ID_STATICTEXT15 = wxNewId();
const long uFR_SimpleFrame::ID_TEXTCTRL13 = wxNewId();
const long uFR_SimpleFrame::ID_STATICTEXT16 = wxNewId();
const long uFR_SimpleFrame::ID_SPINCTRL1 = wxNewId();
const long uFR_SimpleFrame::ID_BUTTON4 = wxNewId();
const long uFR_SimpleFrame::ID_PANEL2 = wxNewId();
const long uFR_SimpleFrame::ID_NOTEBOOK1 = wxNewId();
const long uFR_SimpleFrame::ID_STATICTEXT21 = wxNewId();
const long uFR_SimpleFrame::ID_TEXTCTRL18 = wxNewId();
const long uFR_SimpleFrame::ID_STATICTEXT22 = wxNewId();
const long uFR_SimpleFrame::ID_TEXTCTRL19 = wxNewId();
const long uFR_SimpleFrame::ID_STATICTEXT23 = wxNewId();
const long uFR_SimpleFrame::ID_TEXTCTRL20 = wxNewId();
const long uFR_SimpleFrame::ID_STATICTEXT24 = wxNewId();
const long uFR_SimpleFrame::ID_TEXTCTRL21 = wxNewId();
const long uFR_SimpleFrame::ID_BUTTON6 = wxNewId();
const long uFR_SimpleFrame::ID_PANEL3 = wxNewId();
const long uFR_SimpleFrame::ID_STATICTEXT17 = wxNewId();
const long uFR_SimpleFrame::ID_TEXTCTRL14 = wxNewId();
const long uFR_SimpleFrame::ID_STATICTEXT18 = wxNewId();
const long uFR_SimpleFrame::ID_TEXTCTRL15 = wxNewId();
const long uFR_SimpleFrame::ID_STATICTEXT19 = wxNewId();
const long uFR_SimpleFrame::ID_TEXTCTRL16 = wxNewId();
const long uFR_SimpleFrame::ID_STATICTEXT20 = wxNewId();
const long uFR_SimpleFrame::ID_TEXTCTRL17 = wxNewId();
const long uFR_SimpleFrame::ID_BUTTON5 = wxNewId();
const long uFR_SimpleFrame::ID_PANEL4 = wxNewId();
const long uFR_SimpleFrame::ID_NOTEBOOK2 = wxNewId();
const long uFR_SimpleFrame::ID_STATICLINE3 = wxNewId();
const long uFR_SimpleFrame::ID_STATICTEXT25 = wxNewId();
const long uFR_SimpleFrame::ID_STATICLINE4 = wxNewId();
const long uFR_SimpleFrame::ID_STATICTEXT26 = wxNewId();
const long uFR_SimpleFrame::ID_STATICLINE5 = wxNewId();
const long uFR_SimpleFrame::ID_STATICTEXT27 = wxNewId();
const long uFR_SimpleFrame::ID_STATICTEXT28 = wxNewId();
const long uFR_SimpleFrame::ID_STATUSBAR1 = wxNewId();
const long uFR_SimpleFrame::ID_TIMER1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(uFR_SimpleFrame,wxFrame)
    //(*EventTable(uFR_SimpleFrame)
    //*)
END_EVENT_TABLE()

uFR_SimpleFrame::uFR_SimpleFrame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(uFR_SimpleFrame)
    Create(parent, wxID_ANY, _("µFR MIFARE® Simple"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("wxID_ANY"));
    SetClientSize(wxSize(567,729));
    SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_WINDOW));
    StaticBox1 = new wxStaticBox(this, ID_STATICBOX1, _("Reader Open"), wxPoint(8,8), wxSize(552,80), 0, _T("ID_STATICBOX1"));
    btnReaderOpen = new wxButton(this, ID_BUTTON1, _("Reader Open"), wxPoint(16,32), wxSize(104,40), 0, wxDefaultValidator, _T("ID_BUTTON1"));
    UseAdvancedCH = new wxCheckBox(this, ID_CHECKBOX1, _("Use Advanced options"), wxPoint(144,48), wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX1"));
    UseAdvancedCH->SetValue(false);
    HyperlinkCtrl1 = new wxHyperlinkCtrl(this, ID_HYPERLINKCTRL1, _("https://www.d-logic.net/nfc-rfid-reader-sdk/"), wxEmptyString, wxPoint(312,48), wxDefaultSize, wxHL_CONTEXTMENU|wxHL_ALIGN_CENTRE|wxNO_BORDER, _T("ID_HYPERLINKCTRL1"));
    StaticBox2 = new wxStaticBox(this, ID_STATICBOX2, _("Advaned options"), wxPoint(8,96), wxSize(552,48), 0, _T("ID_STATICBOX2"));
    RtypeST = new wxStaticText(this, ID_STATICTEXT1, _("Reader type :"), wxPoint(16,120), wxDefaultSize, 0, _T("ID_STATICTEXT1"));
    RtypeST->Disable();
    RtypeTB = new wxTextCtrl(this, ID_TEXTCTRL1, wxEmptyString, wxPoint(88,119), wxSize(25,18), wxTE_CENTRE, wxDefaultValidator, _T("ID_TEXTCTRL1"));
    RtypeTB->SetMaxLength(1);
    RtypeTB->Disable();
    PnameST = new wxStaticText(this, ID_STATICTEXT2, _("Port name :"), wxPoint(128,120), wxDefaultSize, 0, _T("ID_STATICTEXT2"));
    PnameST->Disable();
    PnameTB = new wxTextCtrl(this, ID_TEXTCTRL2, wxEmptyString, wxPoint(192,119), wxSize(85,18), wxTE_CENTRE, wxDefaultValidator, _T("ID_TEXTCTRL2"));
    PnameTB->Disable();
    PinterfaceST = new wxStaticText(this, ID_STATICTEXT3, _("Port interface :"), wxPoint(288,120), wxDefaultSize, 0, _T("ID_STATICTEXT3"));
    PinterfaceST->Disable();
    PinterfaceTB = new wxTextCtrl(this, ID_TEXTCTRL3, wxEmptyString, wxPoint(368,119), wxSize(25,18), wxTE_CENTRE, wxDefaultValidator, _T("ID_TEXTCTRL3"));
    PinterfaceTB->SetMaxLength(1);
    PinterfaceTB->Disable();
    ArgST = new wxStaticText(this, ID_STATICTEXT4, _("Arg :"), wxPoint(400,120), wxDefaultSize, 0, _T("ID_STATICTEXT4"));
    ArgST->Disable();
    ArgTB = new wxTextCtrl(this, ID_TEXTCTRL4, wxEmptyString, wxPoint(432,119), wxSize(120,18), wxTE_CENTRE, wxDefaultValidator, _T("ID_TEXTCTRL4"));
    ArgTB->Disable();
    StaticBox3 = new wxStaticBox(this, ID_STATICBOX3, wxEmptyString, wxPoint(8,156), wxSize(552,136), 0, _T("ID_STATICBOX3"));
    StaticText5 = new wxStaticText(this, ID_STATICTEXT5, _("Reader type :"), wxPoint(16,168), wxDefaultSize, 0, _T("ID_STATICTEXT5"));
    ReaderTypeViewTB = new wxTextCtrl(this, ID_TEXTCTRL5, wxEmptyString, wxPoint(96,167), wxSize(181,18), wxTE_READONLY|wxTE_CENTRE, wxDefaultValidator, _T("ID_TEXTCTRL5"));
    StaticText6 = new wxStaticText(this, ID_STATICTEXT6, _("Reader serial :"), wxPoint(16,192), wxDefaultSize, 0, _T("ID_STATICTEXT6"));
    ReaderSerialTB = new wxTextCtrl(this, ID_TEXTCTRL6, wxEmptyString, wxPoint(96,191), wxSize(181,18), wxTE_READONLY|wxTE_CENTRE, wxDefaultValidator, _T("ID_TEXTCTRL6"));
    StaticText7 = new wxStaticText(this, ID_STATICTEXT7, _("Card type :"), wxPoint(288,168), wxDefaultSize, 0, _T("ID_STATICTEXT7"));
    CardTypeTB = new wxTextCtrl(this, ID_TEXTCTRL7, wxEmptyString, wxPoint(352,167), wxSize(56,18), wxTE_READONLY|wxTE_CENTRE, wxDefaultValidator, _T("ID_TEXTCTRL7"));
    StaticText8 = new wxStaticText(this, ID_STATICTEXT8, _("UID Size :"), wxPoint(416,168), wxDefaultSize, 0, _T("ID_STATICTEXT8"));
    UidSizeTB = new wxTextCtrl(this, ID_TEXTCTRL8, wxEmptyString, wxPoint(472,167), wxSize(80,18), wxTE_READONLY|wxTE_CENTRE, wxDefaultValidator, _T("ID_TEXTCTRL8"));
    StaticText9 = new wxStaticText(this, ID_STATICTEXT9, _("Card serial :"), wxPoint(288,192), wxDefaultSize, 0, _T("ID_STATICTEXT9"));
    UidTB = new wxTextCtrl(this, ID_TEXTCTRL9, wxEmptyString, wxPoint(352,191), wxSize(200,18), wxTE_READONLY|wxTE_CENTRE, wxDefaultValidator, _T("ID_TEXTCTRL9"));
    StaticLine1 = new wxStaticLine(this, ID_STATICLINE1, wxPoint(8,216), wxSize(552,5), wxLI_HORIZONTAL, _T("ID_STATICLINE1"));
    StaticText10 = new wxStaticText(this, ID_STATICTEXT10, _("Light mode :"), wxPoint(16,232), wxDefaultSize, 0, _T("ID_STATICTEXT10"));
    LightCB = new wxComboBox(this, ID_COMBOBOX1, wxEmptyString, wxPoint(96,228), wxSize(181,18), 0, 0, wxCB_READONLY, wxDefaultValidator, _T("ID_COMBOBOX1"));
    LightCB->SetSelection( LightCB->Append(_("None")) );
    LightCB->Append(_("Long green"));
    LightCB->Append(_("Long red"));
    LightCB->Append(_("Alternation"));
    LightCB->Append(_("Flash"));
    StaticText11 = new wxStaticText(this, ID_STATICTEXT11, _("Sound mode :"), wxPoint(16,264), wxDefaultSize, 0, _T("ID_STATICTEXT11"));
    BeepCB = new wxComboBox(this, ID_COMBOBOX2, wxEmptyString, wxPoint(96,260), wxSize(181,18), 0, 0, wxCB_READONLY, wxDefaultValidator, _T("ID_COMBOBOX2"));
    BeepCB->SetSelection( BeepCB->Append(_("None")) );
    BeepCB->Append(_("Short"));
    BeepCB->Append(_("Long"));
    BeepCB->Append(_("Double short"));
    BeepCB->Append(_("Triple short"));
    BeepCB->Append(_("Triple melody"));
    btnReaderUISignal = new wxButton(this, ID_BUTTON2, _("READER UI SIGNAL"), wxPoint(288,230), wxSize(264,50), 0, wxDefaultValidator, _T("ID_BUTTON2"));
    StaticLine2 = new wxStaticLine(this, ID_STATICLINE2, wxPoint(8,296), wxSize(552,16), wxLI_HORIZONTAL, _T("ID_STATICLINE2"));
    StaticBox4 = new wxStaticBox(this, ID_STATICBOX4, wxEmptyString, wxPoint(8,312), wxSize(552,40), 0, _T("ID_STATICBOX4"));
    StaticBox4->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_INACTIVEBORDER));
    RB_KeyA = new wxRadioButton(this, ID_RADIOBUTTON1, _("AUTH 1A"), wxPoint(184,328), wxSize(72,13), 0, wxDefaultValidator, _T("ID_RADIOBUTTON1"));
    RB_KeyA->SetValue(true);
    RB_KeyA->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_INACTIVEBORDER));
    wxFont RB_KeyAFont(wxDEFAULT,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,wxEmptyString,wxFONTENCODING_DEFAULT);
    RB_KeyA->SetFont(RB_KeyAFont);
    RB_KeyB = new wxRadioButton(this, ID_RADIOBUTTON2, _("AUTH 1B"), wxPoint(324,328), wxSize(72,13), 0, wxDefaultValidator, _T("ID_RADIOBUTTON2"));
    RB_KeyB->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_INACTIVEBORDER));
    wxFont RB_KeyBFont(wxDEFAULT,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,wxEmptyString,wxFONTENCODING_DEFAULT);
    RB_KeyB->SetFont(RB_KeyBFont);
    Notebook1 = new wxNotebook(this, ID_NOTEBOOK1, wxPoint(8,360), wxSize(552,112), 0, _T("ID_NOTEBOOK1"));
    Panel1 = new wxPanel(Notebook1, ID_PANEL1, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL1"));
    StaticText12 = new wxStaticText(Panel1, ID_STATICTEXT12, _("Key A :"), wxPoint(16,16), wxDefaultSize, 0, _T("ID_STATICTEXT12"));
    NewKeyATB = new wxTextCtrl(Panel1, ID_TEXTCTRL10, _("FFFFFFFFFFFF"), wxPoint(56,15), wxSize(200,18), 0, wxDefaultValidator, _T("ID_TEXTCTRL10"));
    NewKeyATB->SetMaxLength(12);
    StaticText13 = new wxStaticText(Panel1, ID_STATICTEXT13, _("Key B :"), wxPoint(16,40), wxDefaultSize, 0, _T("ID_STATICTEXT13"));
    NewKeyBTB = new wxTextCtrl(Panel1, ID_TEXTCTRL11, _("FFFFFFFFFFFF"), wxPoint(56,39), wxSize(200,18), 0, wxDefaultValidator, _T("ID_TEXTCTRL11"));
    NewKeyBTB->SetMaxLength(12);
    btnFormatCard = new wxButton(Panel1, ID_BUTTON3, _("FORMAT CARD"), wxPoint(264,16), wxSize(275,40), 0, wxDefaultValidator, _T("ID_BUTTON3"));
    StaticText14 = new wxStaticText(Panel1, ID_STATICTEXT14, _("Sectors formatted :"), wxPoint(392,64), wxDefaultSize, 0, _T("ID_STATICTEXT14"));
    SectorsFormattedTB = new wxTextCtrl(Panel1, ID_TEXTCTRL12, wxEmptyString, wxPoint(496,63), wxSize(40,18), wxTE_READONLY|wxTE_CENTRE, wxDefaultValidator, _T("ID_TEXTCTRL12"));
    Panel2 = new wxPanel(Notebook1, ID_PANEL2, wxDefaultPosition, wxSize(544,107), wxTAB_TRAVERSAL, _T("ID_PANEL2"));
    StaticText15 = new wxStaticText(Panel2, ID_STATICTEXT15, _("KEY :"), wxPoint(8,32), wxDefaultSize, 0, _T("ID_STATICTEXT15"));
    ReaderKeyTB = new wxTextCtrl(Panel2, ID_TEXTCTRL13, wxEmptyString, wxPoint(48,31), wxSize(200,18), 0, wxDefaultValidator, _T("ID_TEXTCTRL13"));
    ReaderKeyTB->SetMaxLength(12);
    StaticText16 = new wxStaticText(Panel2, ID_STATICTEXT16, _("Key index :"), wxPoint(264,32), wxDefaultSize, 0, _T("ID_STATICTEXT16"));
    KeyIndexSpin = new wxSpinCtrl(Panel2, ID_SPINCTRL1, _T("0"), wxPoint(328,31), wxSize(50,18), 0, 0, 31, 0, _T("ID_SPINCTRL1"));
    KeyIndexSpin->SetValue(_T("0"));
    btnWriteKeyIntoReader = new wxButton(Panel2, ID_BUTTON4, _("WRITE KEY INTO READER"), wxPoint(392,29), wxSize(144,23), 0, wxDefaultValidator, _T("ID_BUTTON4"));
    Notebook1->AddPage(Panel1, _("New card keys"), false);
    Notebook1->AddPage(Panel2, _("New reader key"), false);
    Notebook2 = new wxNotebook(this, ID_NOTEBOOK2, wxPoint(8,480), wxSize(552,168), 0, _T("ID_NOTEBOOK2"));
    Panel3 = new wxPanel(Notebook2, ID_PANEL3, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL3"));
    StaticText21 = new wxStaticText(Panel3, ID_STATICTEXT21, _("Read Data"), wxPoint(8,8), wxDefaultSize, 0, _T("ID_STATICTEXT21"));
    ReadDataTB = new wxTextCtrl(Panel3, ID_TEXTCTRL18, wxEmptyString, wxPoint(8,24), wxSize(528,80), wxTE_MULTILINE|wxTE_READONLY, wxDefaultValidator, _T("ID_TEXTCTRL18"));
    StaticText22 = new wxStaticText(Panel3, ID_STATICTEXT22, _("Linear address :"), wxPoint(8,115), wxDefaultSize, 0, _T("ID_STATICTEXT22"));
    LA_ReadTB = new wxTextCtrl(Panel3, ID_TEXTCTRL19, wxEmptyString, wxPoint(96,113), wxSize(35,21), 0, wxDefaultValidator, _T("ID_TEXTCTRL19"));
    StaticText23 = new wxStaticText(Panel3, ID_STATICTEXT23, _("Data length :"), wxPoint(136,115), wxDefaultSize, 0, _T("ID_STATICTEXT23"));
    DL_ReadTB = new wxTextCtrl(Panel3, ID_TEXTCTRL20, wxEmptyString, wxPoint(208,113), wxSize(35,21), 0, wxDefaultValidator, _T("ID_TEXTCTRL20"));
    StaticText24 = new wxStaticText(Panel3, ID_STATICTEXT24, _("Read bytes :"), wxPoint(248,115), wxDefaultSize, 0, _T("ID_STATICTEXT24"));
    ReadBytesTB = new wxTextCtrl(Panel3, ID_TEXTCTRL21, wxEmptyString, wxPoint(320,113), wxSize(35,21), wxTE_READONLY, wxDefaultValidator, _T("ID_TEXTCTRL21"));
    ReadBytesTB->Disable();
    btnLinearRead = new wxButton(Panel3, ID_BUTTON6, _("LINEAR READ"), wxPoint(368,112), wxSize(168,23), 0, wxDefaultValidator, _T("ID_BUTTON6"));
    Panel4 = new wxPanel(Notebook2, ID_PANEL4, wxDefaultPosition, wxSize(544,127), wxTAB_TRAVERSAL, _T("ID_PANEL4"));
    StaticText17 = new wxStaticText(Panel4, ID_STATICTEXT17, _("Write Data"), wxPoint(8,8), wxDefaultSize, 0, _T("ID_STATICTEXT17"));
    WriteDataTB = new wxTextCtrl(Panel4, ID_TEXTCTRL14, wxEmptyString, wxPoint(8,24), wxSize(528,80), wxTE_MULTILINE, wxDefaultValidator, _T("ID_TEXTCTRL14"));
    StaticText18 = new wxStaticText(Panel4, ID_STATICTEXT18, _("Linear address :"), wxPoint(8,115), wxDefaultSize, 0, _T("ID_STATICTEXT18"));
    LA_WriteTB = new wxTextCtrl(Panel4, ID_TEXTCTRL15, wxEmptyString, wxPoint(96,112), wxSize(35,21), 0, wxDefaultValidator, _T("ID_TEXTCTRL15"));
    StaticText19 = new wxStaticText(Panel4, ID_STATICTEXT19, _("Data length :"), wxPoint(136,115), wxDefaultSize, 0, _T("ID_STATICTEXT19"));
    DA_WriteTB = new wxTextCtrl(Panel4, ID_TEXTCTRL16, wxEmptyString, wxPoint(208,112), wxSize(35,21), wxTE_READONLY|wxTE_CENTRE, wxDefaultValidator, _T("ID_TEXTCTRL16"));
    StaticText20 = new wxStaticText(Panel4, ID_STATICTEXT20, _("Bytes written :"), wxPoint(253,115), wxDefaultSize, 0, _T("ID_STATICTEXT20"));
    Written_TB = new wxTextCtrl(Panel4, ID_TEXTCTRL17, wxEmptyString, wxPoint(330,112), wxSize(35,21), 0, wxDefaultValidator, _T("ID_TEXTCTRL17"));
    btnLinearWrite = new wxButton(Panel4, ID_BUTTON5, _("LINEAR WRITE"), wxPoint(376,111), wxSize(160,23), 0, wxDefaultValidator, _T("ID_BUTTON5"));
    Notebook2->AddPage(Panel3, _("Linear Read"), false);
    Notebook2->AddPage(Panel4, _("Linear Write"), false);
    StaticLine3 = new wxStaticLine(this, ID_STATICLINE3, wxPoint(0,656), wxSize(568,2), wxLI_HORIZONTAL, _T("ID_STATICLINE3"));
    StaticText25 = new wxStaticText(this, ID_STATICTEXT25, _("FUNCTION ERROR"), wxPoint(8,662), wxDefaultSize, 0, _T("ID_STATICTEXT25"));
    StaticLine4 = new wxStaticLine(this, ID_STATICLINE4, wxPoint(0,680), wxSize(568,2), wxLI_HORIZONTAL, _T("ID_STATICLINE4"));
    StaticText26 = new wxStaticText(this, ID_STATICTEXT26, _("CARD STATUS"), wxPoint(8,686), wxDefaultSize, 0, _T("ID_STATICTEXT26"));
    StaticLine5 = new wxStaticLine(this, ID_STATICLINE5, wxPoint(0,704), wxSize(568,2), wxLI_HORIZONTAL, _T("ID_STATICLINE5"));
    FunctionStatus = new wxStaticText(this, ID_STATICTEXT27, wxEmptyString, wxPoint(288,662), wxDefaultSize, 0, _T("ID_STATICTEXT27"));
    CardStatus = new wxStaticText(this, ID_STATICTEXT28, wxEmptyString, wxPoint(288,686), wxDefaultSize, 0, _T("ID_STATICTEXT28"));
    StatusBar1 = new wxStatusBar(this, ID_STATUSBAR1, 0, _T("ID_STATUSBAR1"));
    int __wxStatusBarWidths_1[1] = { -1 };
    int __wxStatusBarStyles_1[1] = { wxSB_NORMAL };
    StatusBar1->SetFieldsCount(1,__wxStatusBarWidths_1);
    StatusBar1->SetStatusStyles(1,__wxStatusBarStyles_1);
    SetStatusBar(StatusBar1);
    Timer1.SetOwner(this, ID_TIMER1);
    Timer1.Start(200, false);

    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&uFR_SimpleFrame::OnbtnReaderOpenClick);
    Connect(ID_CHECKBOX1,wxEVT_COMMAND_CHECKBOX_CLICKED,(wxObjectEventFunction)&uFR_SimpleFrame::OnUseAdvancedCHClick);
    Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&uFR_SimpleFrame::OnbtnReaderUISignalClick);
    Connect(ID_BUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&uFR_SimpleFrame::OnbtnFormatCardClick);
    Connect(ID_BUTTON4,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&uFR_SimpleFrame::OnbtnWriteKeyIntoReaderClick);
    Connect(ID_BUTTON6,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&uFR_SimpleFrame::OnbtnLinearReadClick);
    Connect(ID_TEXTCTRL14,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&uFR_SimpleFrame::OnWriteDataTBText);
    Connect(ID_TEXTCTRL14,wxEVT_COMMAND_TEXT_ENTER,(wxObjectEventFunction)&uFR_SimpleFrame::OnWriteDataTBTextEnter);
    Connect(ID_BUTTON5,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&uFR_SimpleFrame::OnbtnLinearWriteClick);
    Connect(ID_TIMER1,wxEVT_TIMER,(wxObjectEventFunction)&uFR_SimpleFrame::OnTimer1Trigger);
    //*)

    Timer1.Stop();
}

uFR_SimpleFrame::~uFR_SimpleFrame()
{
    //(*Destroy(uFR_SimpleFrame)
    //*)
}

void uFR_SimpleFrame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void uFR_SimpleFrame::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}

void uFR_SimpleFrame::OnUseAdvancedCHClick(wxCommandEvent& event)
{
    if(UseAdvancedCH->IsChecked())
    {
        RtypeST->Enable();
        RtypeTB->Enable();
        PnameST->Enable();
        PnameTB->Enable();
        PinterfaceST->Enable();
        PinterfaceTB->Enable();
        ArgST->Enable();
        ArgTB->Enable();
    }
    else
    {
        RtypeST->Disable();
        RtypeTB->Disable();
        PnameST->Disable();
        PnameTB->Disable();
        PinterfaceST->Disable();
        PinterfaceTB->Disable();
        ArgST->Disable();
        ArgTB->Disable();
    }
}

void uFR_SimpleFrame::CheckCardStatus(UFR_STATUS status)
{
    if(status)
    {
        CardStatus->SetLabel((string)UFR_Status2String(status));
        wxColor color(255,0,0);
        CardStatus->SetForegroundColour(color);
    }
    else
    {
        CardStatus->SetLabel((string)UFR_Status2String(status));
        wxColor color(19, 207, 19);
        CardStatus->SetForegroundColour(color);
    }
}

void uFR_SimpleFrame::CheckFunctionStatus(UFR_STATUS status)
{
    if(status)
    {
        FunctionStatus->SetLabel((string)UFR_Status2String(status));
        wxColor color(255,0,0);
        FunctionStatus->SetForegroundColour(color);
    }
    else
    {
        FunctionStatus->SetLabel((string)UFR_Status2String(status));
        wxColor color(19, 207, 19);
        FunctionStatus->SetForegroundColour(color);
    }
}

void uFR_SimpleFrame::OnbtnReaderOpenClick(wxCommandEvent& event)
{
    UFR_STATUS status;

    if (UseAdvancedCH->IsChecked())
    {
        wxString wxReaderType    = RtypeTB->GetValue();
        wxString wxPortName      = PnameTB->GetValue();
        wxString wxPortInterface = PinterfaceTB->GetValue();
        wxString wxAddArg        = ArgTB->GetValue();

        wxReaderType    = wxReaderType.Trim();
        wxPortName      = wxPortName.Trim();
        wxPortInterface = wxPortInterface.Trim();
        wxAddArg        = wxAddArg.Trim();

        uint32_t port_interface = 0;
        uint32_t reader_type = 0;

        c_string port_name = 0;

        if (wxPortName != "0")
        {
            port_name = wxPortName.c_str();
        }

        try
        {
            reader_type = std::stoi((std::string)wxReaderType);
        }
        catch (const exception &e)
        {
            wxMessageBox("Invalid Advanced options parameter: Reader type");
            RtypeTB->SetFocus();
            return;
        }

        try
        {
            if (wxPortInterface == "T"){
                port_interface = 84;
            } else if (wxPortInterface == "U"){
                port_interface = 85;
            } else {
                port_interface = std::stoi((std::string)wxPortInterface);
            }
        }
        catch(const exception &e)
        {
            wxMessageBox("Invalid Advanced options parameter: Port interface");
            PinterfaceTB->SetFocus();
            return;
        }

        c_string additional;

        if (wxAddArg != "")
        {
            additional = wxAddArg.c_str();
        }
        else
        {
            additional = 0;
        }

        status = ReaderOpenEx(reader_type, port_name, port_interface, (void *) additional);

    }
    else
    {
        status = ReaderOpen();
    }

    if(status)
        return;

    ReaderUISignal(1, 1);

    uint32_t reader_type;
    uint32_t serial_number;
    GetReaderType(&reader_type);
    GetReaderSerialNumber(&serial_number);

    stringstream ss_reader_type;
    ss_reader_type << hex << reader_type;

    string reader_type_str = ss_reader_type.str();

    transform(reader_type_str.begin(), reader_type_str.end(),reader_type_str.begin(), ::toupper);

    ReaderTypeViewTB->SetValue(reader_type_str);
    ReaderSerialTB->SetValue("UN" + to_string(serial_number));

    Timer1.Start();
}

void uFR_SimpleFrame::OnTimer1Trigger(wxTimerEvent& event)
{
    UFR_STATUS status;
    uint8_t sak = 0;
    uint8_t uidSize = 0;
    uint8_t uid[10];

    status = GetCardIdEx(&sak, uid, &uidSize);

    CheckCardStatus(status);

    switch(status)
    {
        case UFR_OK:
            CardTypeTB->SetValue(to_string(sak));
            UidSizeTB->SetValue(to_string(uidSize));
            UidTB->SetValue(ConvertByteArrayToHexString(uid, uidSize, ":"));
            break;

        case UFR_NO_CARD:
            CardTypeTB->SetValue("");
            UidSizeTB->SetValue("");
            UidTB->SetValue("NO CARD");
            break;

        default:
            CardTypeTB->SetValue("");
            UidSizeTB->SetValue("");
            UidTB->SetValue("");
            break;
    }
}

void uFR_SimpleFrame::OnbtnReaderUISignalClick(wxCommandEvent& event)
{
    UFR_STATUS status;

    status = ReaderUISignal((uint8_t)LightCB->GetSelection(), (uint8_t)BeepCB->GetSelection());

    CheckFunctionStatus(status);
}

void uFR_SimpleFrame::OnbtnFormatCardClick(wxCommandEvent& event)
{
    UFR_STATUS status = UFR_OK;

    uint8_t new_key_A[6];
    uint8_t new_key_B[6];
    uint8_t sectorsFormatted;

    string key_A_str = (string)NewKeyATB->GetValue();
    string key_B_str = (string)NewKeyBTB->GetValue();

    key_A_str = eraseDelimiters(key_A_str);
    key_B_str = eraseDelimiters(key_B_str);

    if(key_A_str.length() != 12 || key_B_str.length() != 12)
    {
        wxMessageBox("Key must be 6 bytes long!");
        SectorsFormattedTB->Clear();
        return;
    }

    ConvertHexStringToByteArray(key_A_str, new_key_A);
    ConvertHexStringToByteArray(key_B_str, new_key_B);

    if(RB_KeyA->GetValue())
    {
        status = LinearFormatCard(new_key_A, 0, 1, 0x69, new_key_B, &sectorsFormatted, 0x60, 0);
    }
    else
    {
        status = LinearFormatCard(new_key_A, 0, 1, 0x69, new_key_B, &sectorsFormatted, 0x61, 0);
    }

    SectorsFormattedTB->SetValue(to_string(sectorsFormatted));
    CheckFunctionStatus(status);
}

void uFR_SimpleFrame::OnbtnWriteKeyIntoReaderClick(wxCommandEvent& event)
{
    UFR_STATUS status;

    uint8_t key[6];
    uint8_t key_index;
    string key_str = (string)ReaderKeyTB->GetValue();

    key_str = eraseDelimiters(key_str);

    if(key_str.length() != 12)
    {
        wxMessageBox("Key must be 6 bytes long!");
        return;
    }

    key_index = (uint8_t)KeyIndexSpin->GetValue();
    ConvertHexStringToByteArray(key_str, key);

    status = ReaderKeyWrite(key, key_index);
    CheckFunctionStatus(status);
}

void uFR_SimpleFrame::OnbtnLinearReadClick(wxCommandEvent& event)
{
    UFR_STATUS status;

    uint16_t bytesReturned = 0;
    uint16_t linearAddress = 0;
    uint16_t dataLength;

    linearAddress = wxAtoi(LA_ReadTB->GetValue());
    dataLength = wxAtoi(DL_ReadTB->GetValue());

    uint8_t data[dataLength];
    memset(data, 0, dataLength);

    if(RB_KeyA->GetValue())
    {
        status = LinearRead(data, linearAddress, dataLength, &bytesReturned, 0x60, 0);
    }
    else
    {
        status = LinearRead(data, linearAddress, dataLength, &bytesReturned, 0x61, 0);
    }

    if(!status)
    {
        ReadDataTB->SetValue(ConvertByteArrayToHexString(data, dataLength, ""));
        ReadBytesTB->SetValue(to_string(bytesReturned));
    }
    else
    {
        ReadDataTB->Clear();
        ReadBytesTB->Clear();
    }

    CheckFunctionStatus(status);
}

void uFR_SimpleFrame::OnbtnLinearWriteClick(wxCommandEvent& event)
{
    UFR_STATUS status;

    string dataStr = (string)WriteDataTB->GetValue();
    dataStr = eraseDelimiters(dataStr);

    if(dataStr.length() %2 != 0)
    {
        wxMessageBox("Invalid data input! (Pairs of hex digits only)");
        return;
    }
    else if(dataStr.length() == 0)
    {
        wxMessageBox("You have to enter any data!");
        return;
    }

    uint16_t bytesWritten = 0;
    uint16_t linearAddress = wxAtoi(LA_WriteTB->GetValue());
    uint16_t dataLength = wxAtoi(DA_WriteTB->GetValue());

    uint8_t data[dataLength];
    memset(data, 0, dataLength);

    ConvertHexStringToByteArray(dataStr, data);

    if(RB_KeyA->GetValue())
    {
        status = LinearWrite(data, linearAddress, dataLength, &bytesWritten, 0x60, 0);
    }
    else
    {
        status = LinearWrite(data, linearAddress, dataLength, &bytesWritten, 0x61, 0);
    }

    Written_TB->SetValue(to_string(bytesWritten));
    CheckFunctionStatus(status);
}

void uFR_SimpleFrame::OnWriteDataTBTextEnter(wxCommandEvent& event)
{

}

void uFR_SimpleFrame::OnWriteDataTBText(wxCommandEvent& event)
{
    string input = (string)WriteDataTB->GetValue();

    input = eraseDelimiters(input);

    int len = input.length() / 2;

    DA_WriteTB->SetValue(to_string(len));
}
