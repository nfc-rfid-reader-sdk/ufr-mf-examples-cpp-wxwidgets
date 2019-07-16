/***************************************************************
 * Name:      uFR_SimplestMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    Digital Logic (support@d-logic.net)
 * Created:   2019-07-15
 * Copyright: Digital Logic (www.d-logic.net)
 * License:
 **************************************************************/

#include "uFR_SimplestMain.h"
#include <wx/msgdlg.h>
#include <string>
#include <string.h>
#include <cstring>
#include <sstream>

using namespace std;

//(*InternalHeaders(uFR_SimplestFrame)
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

//(*IdInit(uFR_SimplestFrame)
const long uFR_SimplestFrame::ID_STATICBOX1 = wxNewId();
const long uFR_SimplestFrame::ID_BUTTON1 = wxNewId();
const long uFR_SimplestFrame::ID_CHECKBOX1 = wxNewId();
const long uFR_SimplestFrame::ID_HYPERLINKCTRL1 = wxNewId();
const long uFR_SimplestFrame::ID_STATICBOX2 = wxNewId();
const long uFR_SimplestFrame::ID_STATICTEXT1 = wxNewId();
const long uFR_SimplestFrame::ID_TEXTCTRL1 = wxNewId();
const long uFR_SimplestFrame::ID_STATICTEXT2 = wxNewId();
const long uFR_SimplestFrame::ID_TEXTCTRL2 = wxNewId();
const long uFR_SimplestFrame::ID_STATICTEXT3 = wxNewId();
const long uFR_SimplestFrame::ID_TEXTCTRL3 = wxNewId();
const long uFR_SimplestFrame::ID_STATICTEXT4 = wxNewId();
const long uFR_SimplestFrame::ID_TEXTCTRL4 = wxNewId();
const long uFR_SimplestFrame::ID_STATICTEXT5 = wxNewId();
const long uFR_SimplestFrame::ID_TEXTCTRL5 = wxNewId();
const long uFR_SimplestFrame::ID_STATICTEXT6 = wxNewId();
const long uFR_SimplestFrame::ID_TEXTCTRL6 = wxNewId();
const long uFR_SimplestFrame::ID_STATICTEXT7 = wxNewId();
const long uFR_SimplestFrame::ID_TEXTCTRL7 = wxNewId();
const long uFR_SimplestFrame::ID_BUTTON2 = wxNewId();
const long uFR_SimplestFrame::ID_STATICTEXT8 = wxNewId();
const long uFR_SimplestFrame::ID_TEXTCTRL8 = wxNewId();
const long uFR_SimplestFrame::ID_STATICTEXT9 = wxNewId();
const long uFR_SimplestFrame::ID_TEXTCTRL9 = wxNewId();
const long uFR_SimplestFrame::ID_BUTTON3 = wxNewId();
const long uFR_SimplestFrame::ID_BUTTON4 = wxNewId();
const long uFR_SimplestFrame::ID_STATICLINE1 = wxNewId();
const long uFR_SimplestFrame::ID_STATICTEXT10 = wxNewId();
const long uFR_SimplestFrame::ID_STATICLINE2 = wxNewId();
const long uFR_SimplestFrame::ID_STATICTEXT11 = wxNewId();
const long uFR_SimplestFrame::ID_STATICLINE3 = wxNewId();
const long uFR_SimplestFrame::ID_STATICLINE4 = wxNewId();
const long uFR_SimplestFrame::ID_STATICTEXT12 = wxNewId();
const long uFR_SimplestFrame::ID_STATICTEXT13 = wxNewId();
const long uFR_SimplestFrame::ID_STATICTEXT14 = wxNewId();
const long uFR_SimplestFrame::ID_STATICTEXT15 = wxNewId();
const long uFR_SimplestFrame::ID_STATUSBAR1 = wxNewId();
const long uFR_SimplestFrame::ID_TIMER1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(uFR_SimplestFrame,wxFrame)
    //(*EventTable(uFR_SimplestFrame)
    //*)
END_EVENT_TABLE()

uFR_SimplestFrame::uFR_SimplestFrame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(uFR_SimplestFrame)
    Create(parent, wxID_ANY, _("µFR MIFARE® Simplest"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("wxID_ANY"));
    SetClientSize(wxSize(550,562));
    SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_WINDOW));
    StaticBox1 = new wxStaticBox(this, ID_STATICBOX1, _("Reader Open"), wxPoint(8,8), wxSize(536,80), 0, _T("ID_STATICBOX1"));
    btnReaderOpen = new wxButton(this, ID_BUTTON1, _("Reader Open"), wxPoint(16,32), wxSize(96,40), 0, wxDefaultValidator, _T("ID_BUTTON1"));
    UseAdvancedCH = new wxCheckBox(this, ID_CHECKBOX1, _("Use Advanced options"), wxPoint(128,48), wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX1"));
    UseAdvancedCH->SetValue(false);
    HyperlinkCtrl1 = new wxHyperlinkCtrl(this, ID_HYPERLINKCTRL1, _("https://www.d-logic.net/nfc-rfid-reader-sdk/"), wxEmptyString, wxPoint(288,48), wxDefaultSize, wxHL_CONTEXTMENU|wxHL_ALIGN_CENTRE|wxNO_BORDER, _T("ID_HYPERLINKCTRL1"));
    StaticBox2 = new wxStaticBox(this, ID_STATICBOX2, _("Advanced options"), wxPoint(8,96), wxSize(536,48), 0, _T("ID_STATICBOX2"));
    RtypeST = new wxStaticText(this, ID_STATICTEXT1, _("Reader type :"), wxPoint(16,120), wxDefaultSize, 0, _T("ID_STATICTEXT1"));
    RtypeST->Disable();
    RTypeTB = new wxTextCtrl(this, ID_TEXTCTRL1, wxEmptyString, wxPoint(88,119), wxSize(25,18), wxTE_CENTRE, wxDefaultValidator, _T("ID_TEXTCTRL1"));
    RTypeTB->SetMaxLength(1);
    RTypeTB->Disable();
    PnameST = new wxStaticText(this, ID_STATICTEXT2, _("Port name :"), wxPoint(120,120), wxDefaultSize, 0, _T("ID_STATICTEXT2"));
    PnameST->Disable();
    PnameTB = new wxTextCtrl(this, ID_TEXTCTRL2, wxEmptyString, wxPoint(184,119), wxSize(85,18), wxTE_CENTRE, wxDefaultValidator, _T("ID_TEXTCTRL2"));
    PnameTB->Disable();
    PinterfaceST = new wxStaticText(this, ID_STATICTEXT3, _("Port interface :"), wxPoint(280,120), wxDefaultSize, 0, _T("ID_STATICTEXT3"));
    PinterfaceST->Disable();
    PinterfaceTB = new wxTextCtrl(this, ID_TEXTCTRL3, wxEmptyString, wxPoint(360,119), wxSize(25,18), wxTE_CENTRE, wxDefaultValidator, _T("ID_TEXTCTRL3"));
    PinterfaceTB->SetMaxLength(1);
    PinterfaceTB->Disable();
    ArgST = new wxStaticText(this, ID_STATICTEXT4, _("Arg :"), wxPoint(392,120), wxDefaultSize, 0, _T("ID_STATICTEXT4"));
    ArgST->Disable();
    ArgTB = new wxTextCtrl(this, ID_TEXTCTRL4, wxEmptyString, wxPoint(424,119), wxSize(112,18), wxTE_CENTRE, wxDefaultValidator, _T("ID_TEXTCTRL4"));
    ArgTB->Disable();
    StaticText5 = new wxStaticText(this, ID_STATICTEXT5, _("Card type :"), wxPoint(8,152), wxDefaultSize, 0, _T("ID_STATICTEXT5"));
    CardTypeTB = new wxTextCtrl(this, ID_TEXTCTRL5, wxEmptyString, wxPoint(72,151), wxSize(40,18), wxTE_CENTRE, wxDefaultValidator, _T("ID_TEXTCTRL5"));
    CardTypeTB->Disable();
    wxFont CardTypeTBFont(wxDEFAULT,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,wxEmptyString,wxFONTENCODING_DEFAULT);
    CardTypeTB->SetFont(CardTypeTBFont);
    StaticText6 = new wxStaticText(this, ID_STATICTEXT6, _("UID Size :"), wxPoint(120,152), wxDefaultSize, 0, _T("ID_STATICTEXT6"));
    UidSizeTB = new wxTextCtrl(this, ID_TEXTCTRL6, wxEmptyString, wxPoint(176,151), wxSize(96,18), wxTE_CENTRE, wxDefaultValidator, _T("ID_TEXTCTRL6"));
    UidSizeTB->Disable();
    wxFont UidSizeTBFont(wxDEFAULT,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,wxEmptyString,wxFONTENCODING_DEFAULT);
    UidSizeTB->SetFont(UidSizeTBFont);
    StaticText7 = new wxStaticText(this, ID_STATICTEXT7, _("Card UID :"), wxPoint(8,179), wxDefaultSize, 0, _T("ID_STATICTEXT7"));
    UidTB = new wxTextCtrl(this, ID_TEXTCTRL7, wxEmptyString, wxPoint(72,175), wxSize(200,18), wxTE_CENTRE, wxDefaultValidator, _T("ID_TEXTCTRL7"));
    UidTB->Disable();
    wxFont UidTBFont(wxDEFAULT,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,wxEmptyString,wxFONTENCODING_DEFAULT);
    UidTB->SetFont(UidTBFont);
    btnFormatCard = new wxButton(this, ID_BUTTON2, _("FORMAT CARD"), wxPoint(280,152), wxSize(264,39), 0, wxDefaultValidator, _T("ID_BUTTON2"));
    StaticText8 = new wxStaticText(this, ID_STATICTEXT8, _("Write data"), wxPoint(8,208), wxDefaultSize, 0, _T("ID_STATICTEXT8"));
    WriteDataTB = new wxTextCtrl(this, ID_TEXTCTRL8, wxEmptyString, wxPoint(8,224), wxSize(264,152), wxTE_MULTILINE, wxDefaultValidator, _T("ID_TEXTCTRL8"));
    StaticText9 = new wxStaticText(this, ID_STATICTEXT9, _("Read data"), wxPoint(280,208), wxDefaultSize, 0, _T("ID_STATICTEXT9"));
    ReadDataTB = new wxTextCtrl(this, ID_TEXTCTRL9, wxEmptyString, wxPoint(280,224), wxSize(264,152), wxTE_MULTILINE|wxTE_READONLY, wxDefaultValidator, _T("ID_TEXTCTRL9"));
    btnLinearWrite = new wxButton(this, ID_BUTTON3, _("LINEAR WRITE"), wxPoint(8,384), wxSize(264,40), 0, wxDefaultValidator, _T("ID_BUTTON3"));
    btnLinearRead = new wxButton(this, ID_BUTTON4, _("LINEAR READ"), wxPoint(280,384), wxSize(264,40), 0, wxDefaultValidator, _T("ID_BUTTON4"));
    StaticLine1 = new wxStaticLine(this, ID_STATICLINE1, wxPoint(0,440), wxSize(552,2), wxLI_HORIZONTAL, _T("ID_STATICLINE1"));
    StaticText10 = new wxStaticText(this, ID_STATICTEXT10, _("FUNCTION STATUS"), wxPoint(8,445), wxDefaultSize, 0, _T("ID_STATICTEXT10"));
    StaticLine2 = new wxStaticLine(this, ID_STATICLINE2, wxPoint(0,464), wxSize(552,2), wxLI_HORIZONTAL, _T("ID_STATICLINE2"));
    StaticText11 = new wxStaticText(this, ID_STATICTEXT11, _("CARD STATUS"), wxPoint(8,470), wxDefaultSize, 0, _T("ID_STATICTEXT11"));
    StaticLine3 = new wxStaticLine(this, ID_STATICLINE3, wxPoint(0,488), wxSize(552,2), wxLI_HORIZONTAL, _T("ID_STATICLINE3"));
    StaticLine4 = new wxStaticLine(this, ID_STATICLINE4, wxPoint(0,512), wxSize(552,2), wxLI_HORIZONTAL, _T("ID_STATICLINE4"));
    StaticText12 = new wxStaticText(this, ID_STATICTEXT12, _("CONNECTION"), wxPoint(8,494), wxDefaultSize, 0, _T("ID_STATICTEXT12"));
    FunctionStatus = new wxStaticText(this, ID_STATICTEXT13, wxEmptyString, wxPoint(280,445), wxDefaultSize, 0, _T("ID_STATICTEXT13"));
    CardStatus = new wxStaticText(this, ID_STATICTEXT14, wxEmptyString, wxPoint(280,470), wxDefaultSize, 0, _T("ID_STATICTEXT14"));
    ConnectionStatus = new wxStaticText(this, ID_STATICTEXT15, wxEmptyString, wxPoint(280,494), wxDefaultSize, 0, _T("ID_STATICTEXT15"));
    StatusBar1 = new wxStatusBar(this, ID_STATUSBAR1, 0, _T("ID_STATUSBAR1"));
    int __wxStatusBarWidths_1[1] = { -1 };
    int __wxStatusBarStyles_1[1] = { wxSB_NORMAL };
    StatusBar1->SetFieldsCount(1,__wxStatusBarWidths_1);
    StatusBar1->SetStatusStyles(1,__wxStatusBarStyles_1);
    SetStatusBar(StatusBar1);
    Timer1.SetOwner(this, ID_TIMER1);
    Timer1.Start(200, false);

    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&uFR_SimplestFrame::OnbtnReaderOpenClick);
    Connect(ID_CHECKBOX1,wxEVT_COMMAND_CHECKBOX_CLICKED,(wxObjectEventFunction)&uFR_SimplestFrame::OnUseAdvancedCHClick);
    Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&uFR_SimplestFrame::OnbtnFormatCardClick);
    Connect(ID_BUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&uFR_SimplestFrame::OnbtnLinearWriteClick);
    Connect(ID_BUTTON4,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&uFR_SimplestFrame::OnbtnLinearReadClick);
    Connect(ID_TIMER1,wxEVT_TIMER,(wxObjectEventFunction)&uFR_SimplestFrame::OnTimer1Trigger);
    //*)

    Timer1.Stop();
}

uFR_SimplestFrame::~uFR_SimplestFrame()
{
    //(*Destroy(uFR_SimplestFrame)
    //*)
}

void uFR_SimplestFrame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void uFR_SimplestFrame::OnAbout(wxCommandEvent& event)
{
    wxString msg = "Digital Logic MIFARE® Simplest Example";
    wxMessageBox(msg, _("Welcome to..."));
}

void uFR_SimplestFrame::CheckConnectionStatus(UFR_STATUS status)
{
    if(status)
    {
        ConnectionStatus->SetLabel((string)UFR_Status2String(status));
        wxColor color(255,0,0);
        ConnectionStatus->SetForegroundColour(color);
    }
    else
    {
        ConnectionStatus->SetLabel((string)UFR_Status2String(status));
        wxColor color(19, 207, 19);
        ConnectionStatus->SetForegroundColour(color);
    }
}

void uFR_SimplestFrame::CheckCardStatus(UFR_STATUS status)
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

void uFR_SimplestFrame::CheckFunctionStatus(UFR_STATUS status)
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

void uFR_SimplestFrame::OnbtnReaderOpenClick(wxCommandEvent& event)
{
    UFR_STATUS status;

    if (UseAdvancedCH->IsChecked())
    {
        wxString wxReaderType    = RTypeTB->GetValue();
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
            RTypeTB->SetFocus();
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

    if(!status)
    {
        ReaderUISignal(1, 1);
        Timer1.Start();
    }

    CheckConnectionStatus(status);
}

void uFR_SimplestFrame::OnUseAdvancedCHClick(wxCommandEvent& event)
{
    if(UseAdvancedCH->IsChecked())
    {
        RtypeST->Enable();
        RTypeTB->Enable();
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
        RTypeTB->Disable();
        PnameST->Disable();
        PnameTB->Disable();
        PinterfaceST->Disable();
        PinterfaceTB->Disable();
        ArgST->Disable();
        ArgTB->Disable();
    }
}

void uFR_SimplestFrame::OnTimer1Trigger(wxTimerEvent& event)
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

void uFR_SimplestFrame::OnbtnFormatCardClick(wxCommandEvent& event)
{
    UFR_STATUS status;

    uint8_t new_key_A[6] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};
    uint8_t new_key_B[6] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};
    uint8_t sectorsFormatted = 0;

    status = LinearFormatCard(new_key_A, 0, 1, 0x69, new_key_B, &sectorsFormatted, 0x60, 0);

    CheckFunctionStatus(status);
}

void uFR_SimplestFrame::OnbtnLinearWriteClick(wxCommandEvent& event)
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
    uint32_t data_length = dataStr.length() / 2;
    uint8_t data[data_length];
    memset(data, 0, data_length);

    ConvertHexStringToByteArray(dataStr, data);

    status = LinearWrite(data, 0, data_length, &bytesWritten, 0x60, 0);

    CheckFunctionStatus(status);
}

void uFR_SimplestFrame::OnbtnLinearReadClick(wxCommandEvent& event)
{
    UFR_STATUS status;

    uint32_t linearSize;
    uint32_t rawSize;
    uint16_t bytesReturned;

    GetCardSize(&linearSize, &rawSize);

    uint8_t data[linearSize];
    memset(data, 0, linearSize);

    status = LinearRead(data, 0, linearSize, &bytesReturned, 0x60, 0);

    if(!status)
    {
        ReadDataTB->SetValue(ConvertByteArrayToHexString(data, linearSize, ""));
    }
    else
    {
        ReadDataTB->Clear();
    }

    CheckFunctionStatus(status);
}
