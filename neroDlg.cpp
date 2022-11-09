// neroDlg.cpp : implementation file
//

#include "stdafx.h"
#include "resource.h"	
#include "neroDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


/////////////////////////////////////////////////////////////////////////////
// CneroDlg dialog

CneroDlg::CneroDlg(CWnd* pParent /*=NULL*/)
  : CDialog(CneroDlg::IDD, pParent)
{
  //{{AFX_DATA_INIT(CneroDlg)
	m_csVolumeName = _T("");
	//}}AFX_DATA_INIT
  
  // Note that LoadIcon does not require a subsequent DestroyIcon in Win32
  //m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);

  // Init volume name with current date
  CTime now = CTime::GetCurrentTime();
  m_csVolumeName.Format("%d/%d/%d", now.GetYear(), now.GetMonth(), now.GetDay());
  
  pmniiFile = NULL;
}

void CneroDlg::DoDataExchange(CDataExchange* pDX)
{
  CDialog::DoDataExchange(pDX);
  //{{AFX_DATA_MAP(CneroDlg)
	DDX_Control(pDX, IDC_BURN, mbtnBurn);
	DDX_Control(pDX, IDC_MESSAGES, medtMessages);
	DDX_Control(pDX, IDC_PROGRESS1, mpgsProgress);
	DDX_Control(pDX, IDC_DEVICES, mcbxDevices);
	DDX_Control(pDX, IDC_ABORT, mbtnAbort);
	DDX_Control(pDX, IDCANCEL, mCancel);
	DDX_Text(pDX, IDC_VOLUME_NAME, m_csVolumeName);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CneroDlg, CDialog)
  //{{AFX_MSG_MAP(CneroDlg)
  ON_WM_SYSCOMMAND()
  ON_WM_PAINT()
  ON_WM_QUERYDRAGICON()
  ON_BN_CLICKED(IDC_ABORT, OnAbort)
	ON_BN_CLICKED(IDC_BURN, OnBurn)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CneroDlg message handlers

BOOL CneroDlg::OnInitDialog()
{
  CDialog::OnInitDialog();

  // Add "About..." menu item to system menu.
/*
  // IDM_ABOUTBOX must be in the system command range.
  ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
  ASSERT(IDM_ABOUTBOX < 0xF000);

  CMenu* pSysMenu = GetSystemMenu(FALSE);
  if (pSysMenu != NULL)
  {
    CString strAboutMenu;
    strAboutMenu.LoadString(IDS_ABOUTBOX);
    if (!strAboutMenu.IsEmpty())
    {
      pSysMenu->AppendMenu(MF_SEPARATOR);
      pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
    }
  }

  // Set the icon for this dialog.  The framework does this automatically
  //  when the application's main window is not a dialog
  SetIcon(m_hIcon, TRUE);     // Set big icon
  SetIcon(m_hIcon, FALSE);    // Set small icon
*/  
  // TODO: Add extra initialization here

  // Initialize the NeroAPI

  NeroAPIInit();

  return TRUE;  // return TRUE  unless you set the focus to a control
}

void CneroDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
    CDialog::OnSysCommand(nID, lParam);
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CneroDlg::OnPaint() 
{
  if (IsIconic())
  {
    CPaintDC dc(this); // device context for painting

    SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

    // Center icon in client rectangle
    int cxIcon = GetSystemMetrics(SM_CXICON);
    int cyIcon = GetSystemMetrics(SM_CYICON);
    CRect rect;
    GetClientRect(&rect);
    int x = (rect.Width() - cxIcon + 1) / 2;
    int y = (rect.Height() - cyIcon + 1) / 2;

    // Draw the icon
    dc.DrawIcon(x, y, m_hIcon);
  }
  else
  {
    CDialog::OnPaint();
  }
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CneroDlg::OnQueryDragIcon()
{
  return (HCURSOR) m_hIcon;
}

void CneroDlg::OnBurn() 
{
  // TODO: Add your control notification handler code here

  // perform the burn process

  // check whether a file has been selected
  if (m_pcsaFiles->GetSize() < 2)
  {
    // Tell the user what went wrong

    AppendString("There has to be at least one recording before you can start burning!");
  }
  else
  {
    // fill the NERO_ISO_ITEM struct for all files to be burned

	NERO_ISO_ITEM *pPrevItem = NULL;
	int i;
	for (i = 0; i < m_pcsaFiles->GetSize(); i++)
	{
		// extract filename from path
		char *cp = strrchr((*m_pcsaFiles)[i].GetBuffer(0), '\\');
		if (!cp) cp = strrchr((*m_pcsaFiles)[i].GetBuffer(0), ':');
		if (!cp) continue;

		pmniiFile = new NERO_ISO_ITEM;
		//pmniiFile->longFileName = (CString)cp+1; 
		//pmniiFile->longSourceFilePath = (*m_pcsaFiles)[i].GetBuffer(0); 
		strcpy(pmniiFile->fileName, cp+1);	// fileName & sourceFilePath deprecated but working...
		strcpy(pmniiFile->sourceFilePath, (*m_pcsaFiles)[i].GetBuffer(0)); 
		pmniiFile->isDirectory=FALSE;
		pmniiFile->isReference=FALSE;
		pmniiFile->nextItem=pPrevItem;
		pPrevItem = pmniiFile;
	}

    // no CD stamp, artist or title required

    writeCD.nwcdpCDStamp=NULL;
    writeCD.nwcdArtist=NULL;
    writeCD.nwcdTitle=NULL;

    // no CD Extra information available

    writeCD.nwcdCDExtra=FALSE;

    // we have no Audio tracks

    writeCD.nwcdNumTracks=0;

	// selected media size
	if (m_nVolumeSize <= 700)
		writeCD.nwcdMediaType = MEDIA_CD;
	else
		writeCD.nwcdMediaType = MEDIA_DVD_ANY;

    // get the currently selected device from the ComboBox

    i = mcbxDevices.GetCurSel();

    // retrieve the NERO_SCSI_DEVICE_INFO pointer for the selected device
    // and assign it to a local variable

    NERO_SCSI_DEVICE_INFO* nsdiDevice = (NERO_SCSI_DEVICE_INFO*)mcbxDevices.GetItemDataPtr(i);

    // try to open the selected device

    ndhDeviceHandle = NeroOpenDevice(nsdiDevice);

    // check whether a valid handle was returned

    if (!ndhDeviceHandle)
    {
      // no handle available; tell the user what happened

      AppendString("Device could not be opened: "+(CString)nsdiDevice->nsdiDeviceName);
    }
    else
    {
      // we have a valid device handle

      // while burning the "Abort" button needs to be enabled
      // all the other buttons and controls have to be disabled

      mbtnAbort.EnableWindow(true);
      mCancel.EnableWindow(false);
      mcbxDevices.EnableWindow(false);
      mbtnBurn.EnableWindow(false);
	  GetDlgItem(IDC_VOLUME_NAME)->EnableWindow(false);

      // set the range for the progress control, we will display percent

      mpgsProgress.SetRange(0,100);

      // create an ISO track
      // usage : NeroCreateIsoTrack(struct NERO_ISO_ITEM *root, const char *name,
      //                            BOOL useJoliet, BOOL useMode2);
      //
      // root = mniiFile, the NERO_ISO_ITEM we filled before
      // name = neroFiddles


      writeCD.nwcdIsoTrack = NeroCreateIsoTrackEx(pmniiFile, m_csVolumeName.GetBuffer(0), NCITEF_CREATE_ISO_FS|NCITEF_USE_JOLIET);

      // start the burn process by calling NeroBurn
      // usage:NEROAPI_BURN_ERROR NADLL_ATTR NeroBurn( NERO_DEVICEHANDLE  aDeviceHandle,
      // NERO_CD_FORMAT  CDFormat, const void*  pWriteCD, DWORD  dwFlags, DWORD  dwSpeedInX,
      // NERO_PROGRESS*  pNeroProgress);
      //
      // aDeviceHandle = ndhDeviceHandle, the handle we got from NeroOpenDevice()
      // CDFormat = NERO_ISO_AUDIO_CD
      // pWriteCD = writeCD
      // dwFlags = NBF_WRITE, do not simulate - burn!
      // dwSpeedInX = 0, use maximum speed
      // pNeroProgress = npProgress, filled during NeroAPIInit()

      int iRes = NeroBurn(ndhDeviceHandle, NERO_ISO_AUDIO_CD, &writeCD, NBF_WRITE|NBF_BUF_UNDERRUN_PROT, 0, &npProgress);

      // free memory that was allocated for the track

      NeroFreeIsoTrack(writeCD.nwcdIsoTrack);

      // close the device

      NeroCloseDevice(ndhDeviceHandle);

      // burning is finished, disable "Abort" activate all other controls 

      mbtnAbort.EnableWindow(false);
      mCancel.EnableWindow(true);
      mcbxDevices.EnableWindow(true);
      mbtnBurn.EnableWindow(true);
	  GetDlgItem(IDC_VOLUME_NAME)->EnableWindow(true);

      // clear the progress bar

      mpgsProgress.SetPos(0);

      // make sure that aborted flag is not set if "Burn" button is pressed again

      mbAborted = false;

      // retrieve the error log

      char* Log = NeroGetErrorLog();

      // display the error log contents

      AppendString(Log);

	  // free the log
	  NeroFreeMem(Log);


      // tell the user how the burn process was finished

      switch(iRes)
      {
        case NEROAPI_BURN_OK:
          AppendString ("BurnCD() : burn successful");
          break;
        case NEROAPI_BURN_UNKNOWN_CD_FORMAT:
          AppendString ("BurnCD() : unknown CD format");
          break;
        case NEROAPI_BURN_INVALID_DRIVE:
          AppendString ("BurnCD() : invalid drive");
          break;
        case NEROAPI_BURN_FAILED:
          AppendString ("BurnCD() : burn failed");
          break;
        case NEROAPI_BURN_FUNCTION_NOT_ALLOWED:
          AppendString ("BurnCD() : function not allowed");
          break;
        case NEROAPI_BURN_DRIVE_NOT_ALLOWED:
          AppendString ("BurnCD() : drive not allowed");
          break;
		case NEROAPI_BURN_USER_ABORT:
          AppendString ("BurnCD() : user aborted");
          break;
		case NEROAPI_BURN_BAD_MESSAGE_FILE:
          AppendString ("BurnCD() : bad message file");
          break;
        default:
          AppendString ("BurnCD() : unknown error");
		  break;
      }
    }
  }
}

BOOL NERO_CALLBACK_ATTR CneroDlg::IdleCallback(void *pUserData)
{
  // idle callback is called frequently by NeroAPI

  // make sure that messages from other controls can be handled

  static MSG msg;
  while (!(((CneroDlg*)pUserData)->mbAborted) && ::PeekMessage(&msg,NULL,NULL,NULL,PM_NOREMOVE))
  {
    if (!AfxGetThread()->PumpMessage())
	  {
      break;
	  }
	}

  // aborted-flag serves as function result

  return ((CneroDlg*)pUserData)->mbAborted;
}

void CneroDlg::NeroAPIInit()
{
  // initialization part, provide necessary information and check status

  mbAborted = false;

  // try to open the NeroAPI DLL

  if (!NeroAPIGlueConnect (NULL))
  {
    AppendString("Cannot open NeroAPI.DLL");

    // it makes no sense to continue after loading the DLL failed

    return;
  }

  // the NeroAPI DLL could be openend, get version information

  AppendString("Retrieving version information.");

  WORD majhi, majlo, minhi, minlo;

  NeroGetAPIVersionEx(&majhi, &majlo, &minhi, &minlo, NULL);


  // format and display the version information

  CString strVersion;
  strVersion.Format("NeroAPI version %d.%d.%d.%d",
                    majhi, majlo, minhi, minlo);

  AppendString(strVersion);

  // setup of structures that the NeroAPI needs

  AppendString("Filling NERO_SETTINGS structure");

  // Information for registry access

  strcpy(pcNeroFilesPath, "NeroFiles");
  strcpy(pcVendor, "ahead");
  strcpy(pcSoftware, "Nero - Burning Rom");

  // use the US-English error message file

  strcpy(pcLanguageFile, "Nero.txt");

  nsSettings.nstNeroFilesPath = pcNeroFilesPath;
  nsSettings.nstVendor = pcVendor;

  // set pointers to various callback functions

  nsSettings.nstIdle.ncCallbackFunction = IdleCallback;      

  // this pointer is required to access non-static variables from callback functions

  nsSettings.nstIdle.ncUserData = this;
  nsSettings.nstSoftware = pcSoftware;
  nsSettings.nstUserDialog.ncCallbackFunction = UserDialog; 
  nsSettings.nstUserDialog.ncUserData = this;
  nsSettings.nstLanguageFile =pcLanguageFile;

  // npProgress will be used during the burn process

  npProgress.npAbortedCallback = AbortedCallback;
  npProgress.npAddLogLineCallback = AddLogLine;
  npProgress.npDisableAbortCallback = NULL;
  npProgress.npProgressCallback = ProgressCallback;
  npProgress.npSetPhaseCallback = SetPhaseCallback;
  npProgress.npUserData = this;
  npProgress.npSetMajorPhaseCallback=NULL;	
  npProgress.npSubTaskProgressCallback=NULL;


  // no devices available yet

  pndiDeviceInfos = NULL;

  // initialize the NeroAPI with nsSettings and the 
  // Serial Number that we got from the Registry

  NEROAPI_INIT_ERROR initErr;
  initErr = NeroInit (&nsSettings, NULL);

  // display the result of NeroInit()

  switch (initErr)
  {
    case NEROAPI_INIT_OK:
      AppendString("Initialization of the NeroAPI successful.");
      break;
    case NEROAPI_INIT_INVALID_ARGS:
      AppendString("The arguments are not valid.");
      break;
    case NEROAPI_INIT_INVALID_SERIAL_NUM:
      AppendString("The Serial Number is not valid.");
      break;
    default:
      AppendString("An error occured. The type of error cannot be determined.");
      break;
  }

  // get a list of available drives

  pndiDeviceInfos = NeroGetAvailableDrivesEx (MEDIA_CD, NULL);

  // check whether any devices have been found 

  if (!pndiDeviceInfos)
  {
    // no device found, let the user know

    AppendString("NeroGetAvailableDrivesEx() returned no available devices.");
  }
  else
  {
    // devices found

    // check the number of available devices to be sure

    if (pndiDeviceInfos->nsdisNumDevInfos > 0)
    {
      // we have some devices, now fill the ComboBox

      AppendString("Found the following devices:");
      for (DWORD dDeviceCounter = 0; dDeviceCounter < pndiDeviceInfos->nsdisNumDevInfos; dDeviceCounter++)
      {
        AppendString(pndiDeviceInfos->nsdisDevInfos[dDeviceCounter].nsdiDeviceName);

        // add the device name to the ComboBox and get the index number

        int i = mcbxDevices.AddString(pndiDeviceInfos->nsdisDevInfos[dDeviceCounter].nsdiDeviceName);

        // use the index number to access the corresponding entry
        // connect the entry's ItemData pointer to a NERO_DEVICE_INFO structure

        mcbxDevices.SetItemDataPtr(i, &pndiDeviceInfos->nsdisDevInfos[dDeviceCounter]);
      }

      // select the first ComboBox entry

      mcbxDevices.SelectString(-1, pndiDeviceInfos->nsdisDevInfos[0].nsdiDeviceName);
    }
    else
    {
      AppendString("The number of available devices is 0.");
    }
  }
}

void CneroDlg::AppendString(CString str)
{
  // a CString for temporary use

  CString   strBuffer;

  // retrieve the content of the EditControl we use for messages

  medtMessages.GetWindowText (strBuffer);

  // add a new line if the EditControl is not empty

  if (!strBuffer.IsEmpty())
  {
     strBuffer += "\r\n";
  }

  // append the string the function got as a parameter

  strBuffer += str;

  // update the EditiControl with the new content

  medtMessages.SetWindowText (strBuffer);

  // Scroll the edit control to the end

  medtMessages.LineScroll (medtMessages.GetLineCount(), 0);
}

NeroUserDlgInOut NERO_CALLBACK_ATTR CneroDlg::UserDialog(void *pUserData, NeroUserDlgInOut type, void *data)
{
  // handling of messages that require the user to perform an action
  // for reasons of brevity we only deal with the messages that 
  // are absolutely mandatory for this application

  switch (type)
  {
    case DLG_AUTO_INSERT:
      return DLG_RETURN_CONTINUE;
      break;
    case DLG_DISCONNECT_RESTART:
      return DLG_RETURN_ON_RESTART;
      break;
    case DLG_DISCONNECT:
      return DLG_RETURN_CONTINUE;
      break;
    case DLG_AUTO_INSERT_RESTART:
      return DLG_RETURN_EXIT;
      break;
    case DLG_RESTART:
      return DLG_RETURN_EXIT;
      break;
    case DLG_SETTINGS_RESTART:
      return DLG_RETURN_CONTINUE;
      break;
    case DLG_OVERBURN:
      return DLG_RETURN_TRUE;
      break;
    case DLG_AUDIO_PROBLEMS:
      return DLG_RETURN_EXIT;
      break;
    case DLG_FILESEL_IMAGE:
      {
        // create filter for image files

        static char BASED_CODE szFilter[] = "Image Files (*.nrg)|*.nrg|All Files (*.*)|*.*||";

        // create a CFileDialog object. 
        // usage : CFileDialog( BOOL bOpenFileDialog, LPCTSTR lpszDefExt = NULL, LPCTSTR lpszFileName = NULL,
        //                      DWORD dwFlags = OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, LPCTSTR lpszFilter = NULL,
        //                      CWnd* pParentWnd = NULL );
        //
        // bOpenFileDialog = TRUE, create a File Open dialog 
        // lpszDefExt = NULL, do not automatically append a file extension
        // dwFlags = OFN_OVERWRITEPROMPT, makes no sense during file open,
        //           just in case we decide to use File Save later
        // szFilter = "Image Files (*.nrg)|*.nrg|All Files (*.*)|*.*||"
        // pParentWnd = ((CneroDlg*)pUserData), our current Dialog window is the parent

        CFileDialog dlgOpen(TRUE, NULL, "test.nrg", OFN_OVERWRITEPROMPT, szFilter, ((CneroDlg*)pUserData));

        // check how the dialog was ended

        if (dlgOpen.DoModal() == IDOK)
        {
          // user pressed "OK", copy the file name to the data parameter

          strcpy((char*)data,dlgOpen.GetPathName());

          // proceed with the burn process

          return DLG_RETURN_TRUE; 
        }
        else
        {
          // user canceled, do not proceed with the burn process

          return DLG_BURNIMAGE_CANCEL;
        }
      }
      break;
    case DLG_WAITCD:
    {
      NERO_WAITCD_TYPE waitcdType = (NERO_WAITCD_TYPE) (int)data;
	  char *waitcdString = NeroGetLocalizedWaitCDTexts (waitcdType);
      ((CneroDlg*)pUserData)->AppendString(waitcdString);
	  NeroFreeMem(waitcdString);
      return DLG_RETURN_EXIT;
      break;
    }
    default:
      break;
  }

  // default return value, in case we forgot to handle a request
  
  return DLG_RETURN_EXIT;
}

BOOL NERO_CALLBACK_ATTR CneroDlg::ProgressCallback(void *pUserData, DWORD dwProgressInPercent)
{
  // the NeroAPI updates the current progress counter

  // set the progress bar to the percentage value that was passed to this function

  ((CneroDlg*)pUserData)->mpgsProgress.SetPos(dwProgressInPercent);

  return true;
}

BOOL NERO_CALLBACK_ATTR CneroDlg::AbortedCallback(void *pUserData)
{
  // do not ask the user if he really wants to abort
  // just return the aborted flag

  return ((CneroDlg*)pUserData)->mbAborted;
}

void NERO_CALLBACK_ATTR CneroDlg::AddLogLine(void *pUserData, NERO_TEXT_TYPE type, const char *text)
{
  // Add the text that was passed to this function to the message log
  CString csTemp(text);
  ((CneroDlg*)pUserData)->AppendString("Log line:" + csTemp);
  return;
}

void NERO_CALLBACK_ATTR CneroDlg::SetPhaseCallback(void *pUserData, const char *text)
{
  // display the current phase the burn process is currently going through
  CString csTemp(text);
  ((CneroDlg*)pUserData)->AppendString("Phase: " + csTemp);
  return;
}

void CneroDlg::NeroAPIFree()
{
  // free the resources that have been used

  // make sure there is something to free so we do not run into an exception
  if (pndiDeviceInfos)
  {
    NeroFreeMem(pndiDeviceInfos);
  }

  // nothing to check before calling these functions

  NeroClearErrors();
  if(NeroDone())
  {
	  AfxMessageBox("Detected memory leaks in call to NeroAPI.");
  }

  NeroAPIGlueDone();

  return;
}

void CneroDlg::OnOK() 
{
  // TODO: Add extra validation here

  // user decides to quit by pressing "OK"

  NeroAPIFree();
  
  CDialog::OnOK();
}

void CneroDlg::OnCancel() 
{
  // TODO: Add extra cleanup here

  // user decides to quit by pressing "Cancel"
  // we handle this like the "OK" button

  NeroAPIFree();
  
  CDialog::OnCancel();
}

void CneroDlg::OnAbort() 
{
  // TODO: Add your control notification handler code here

  // nothing more required but setting the aborted flag

  mbAborted = true;
}
