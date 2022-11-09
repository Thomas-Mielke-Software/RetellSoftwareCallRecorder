/*
* This file is part of Retell Software Call Recorder.
*
* Retell Software Call Recorder is free software: you can redistribute it
* and/or modify it under the terms of the GNU General Public License as
* published by the Free Software Foundation, either version 3 of the License,
* or (at your option) any later version.
*
* Retell Software Call Recorder is distributed in the hope that it will be
* useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General
* Public License for more details.
*
* You should have received a copy of the GNU General Public License along with
* Retell Software Call Recorder. If not, see <https://www.gnu.org/licenses/>.
*
*	Beschreibung: class CArchiveWizzardPage
*	
*	ArchiveWizzardPage.cpp : implementation file
*	Klasse zur Verwaltung der Archive Wizard Property Pages
*	
*	$Log:   D:/pvcsarch/telar/IndexDB.cpv  $
*/

#include "stdafx.h"
#include <io.h>

#include "resource.h"
#include "ArchiveWizzardPage.h"
#include "ArchiveWizzard.h"
#include "TelAr.h"
#include "TelArPropertyPage.h"
//#include "neroDlg.h"

#ifdef _DEBUG
#undef THIS_FILE
static char BASED_CODE THIS_FILE[] = __FILE__;
#endif

IMPLEMENT_DYNCREATE(CArchiveWizzardPage1, CPropertyPage)
IMPLEMENT_DYNCREATE(CArchiveWizzardPage2, CPropertyPage)
IMPLEMENT_DYNCREATE(CArchiveWizzardPage3, CPropertyPage)
IMPLEMENT_DYNCREATE(CArchiveWizzardPage4, CPropertyPage)
IMPLEMENT_DYNCREATE(CArchiveWizzardPage5, CPropertyPage)
IMPLEMENT_DYNCREATE(CArchiveWizzardPage6, CPropertyPage)
IMPLEMENT_DYNCREATE(CArchiveWizzardPage7, CPropertyPage)


/////////////////////////////////////////////////////////////////////////////
// CArchiveWizzardPage1 property page

CArchiveWizzardPage1::CArchiveWizzardPage1() : CPropertyPage(CArchiveWizzardPage1::IDD)
{
	//{{AFX_DATA_INIT(CArchiveWizzardPage1)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT

	m_psp.dwFlags &= ~PSP_HASHELP;
}

CArchiveWizzardPage1::~CArchiveWizzardPage1()
{
}

void CArchiveWizzardPage1::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CArchiveWizzardPage1)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CArchiveWizzardPage1, CPropertyPage)
	//{{AFX_MSG_MAP(CArchiveWizzardPage1)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


BOOL CArchiveWizzardPage1::OnSetActive() 
{
	int n = ((CComboBox *)GetDlgItem(IDC_SELECT_MEDIUM))->GetCount();

	CString csItemText;

	// select medium in combo box according to MB number
	int i;
	for (i = 0; i < n; i++)
	{
		((CComboBox *)GetDlgItem(IDC_SELECT_MEDIUM))->GetLBText(i, csItemText);

		if (((CArchiveWizzard *)GetParent())->m_nVolumeSize == atoi(csItemText.GetBuffer(0)))
		{
			((CComboBox *)GetDlgItem(IDC_SELECT_MEDIUM))->SelectString(0, csItemText);
			break;
		}
	}

	// not found? just add MBs
	if (i >= n)
	{
		csItemText.Format("%d MB", ((CArchiveWizzard *)GetParent())->m_nVolumeSize);
		SetDlgItemText(IDC_SELECT_MEDIUM, csItemText);
	}

	return CPropertyPage::OnSetActive();
}

BOOL CArchiveWizzardPage1::OnKillActive() 
{
	CString csItemText;
	GetDlgItemText(IDC_SELECT_MEDIUM, csItemText);
	((CArchiveWizzard *)GetParent())->m_nVolumeSize = atoi(csItemText.GetBuffer(0));
	
	return CPropertyPage::OnKillActive();
}

void CArchiveWizzardPage1::OnCancel() 
{
	//((CArchiveWizzard *)GetParent())->SetActivePage(0);
	//GetParent()->ShowWindow(SW_HIDE);
	CPropertyPage::OnCancel();
}


/////////////////////////////////////////////////////////////////////////////
// CArchiveWizzardPage2 property page

CArchiveWizzardPage2::CArchiveWizzardPage2() : CPropertyPage(CArchiveWizzardPage2::IDD)
{
	//{{AFX_DATA_INIT(CArchiveWizzardPage2)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT

	m_psp.dwFlags &= ~PSP_HASHELP;
}

CArchiveWizzardPage2::~CArchiveWizzardPage2()
{
}

void CArchiveWizzardPage2::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CArchiveWizzardPage2)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CArchiveWizzardPage2, CPropertyPage)
	//{{AFX_MSG_MAP(CArchiveWizzardPage2)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


BOOL CArchiveWizzardPage2::OnSetActive() 
{
	if (((CArchiveWizzard *)GetParent())->m_nMethod == 0)
	{
		((CButton *)GetDlgItem(IDC_METHOD2))->SetCheck(0);
		((CButton *)GetDlgItem(IDC_METHOD1))->SetCheck(1);
	}
	else
	{
		((CButton *)GetDlgItem(IDC_METHOD1))->SetCheck(0);
		((CButton *)GetDlgItem(IDC_METHOD2))->SetCheck(1);
	}

	((CArchiveWizzard *)GetParent())->SetWizardButtons(PSWIZB_BACK|PSWIZB_NEXT);

	return CPropertyPage::OnSetActive();
}

BOOL CArchiveWizzardPage2::OnKillActive() 
{
	if (((CButton *)GetDlgItem(IDC_METHOD1))->GetCheck())
		((CArchiveWizzard *)GetParent())->m_nMethod = 0;
	else
		((CArchiveWizzard *)GetParent())->m_nMethod = 1;
	
	return CPropertyPage::OnKillActive();
}


/////////////////////////////////////////////////////////////////////////////
// CArchiveWizzardPage3 property page

CArchiveWizzardPage3::CArchiveWizzardPage3() : CPropertyPage(CArchiveWizzardPage3::IDD)
{
	//{{AFX_DATA_INIT(CArchiveWizzardPage3)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT

	m_psp.dwFlags &= ~PSP_HASHELP;
}

CArchiveWizzardPage3::~CArchiveWizzardPage3()
{
}

void CArchiveWizzardPage3::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CArchiveWizzardPage3)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CArchiveWizzardPage3, CPropertyPage)
	//{{AFX_MSG_MAP(CArchiveWizzardPage3)
	ON_BN_CLICKED(IDC_BROWSE_TEMP_FOLDER, OnBrowseTempFolder)
	ON_WM_TIMER()
	ON_EN_CHANGE(IDC_TEMP_FOLDER, OnChangeTempFolder)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


BOOL CArchiveWizzardPage3::OnSetActive() 
{
	SetDlgItemText(IDC_TEMP_FOLDER, ((CArchiveWizzard *)GetParent())->m_csTempFolder);
	SetTimer(1, 1, NULL);
	((CArchiveWizzard *)GetParent())->SetWizardButtons(PSWIZB_BACK);
	return CPropertyPage::OnSetActive();
}

BOOL CArchiveWizzardPage3::OnKillActive() 
{
	CString csTemp;
	GetDlgItemText(IDC_TEMP_FOLDER, csTemp);
	
	if (((CArchiveWizzard *)GetParent())->m_csTempFolder == csTemp)
	{
		CString destIndexFileName = csTemp + "\\" + INDEX_FILENAME;
		DeleteFile(destIndexFileName);
	}
	else
	{
		CString destIndexFileName = csTemp + "\\" + INDEX_FILENAME;
		if (!_access(destIndexFileName.GetBuffer(0), 00))
		{
			if (AfxMessageBox("The temporary folder already contains an index file. Do you wish to overwrite it?", MB_YESNO) == IDYES)
			{
				DeleteFile(destIndexFileName);
			}
			else
			{
				return FALSE;
			}
		}
		((CArchiveWizzard *)GetParent())->m_csTempFolder = csTemp;
	}

	return CPropertyPage::OnKillActive();
}

void CArchiveWizzardPage3::OnBrowseTempFolder() 
{
	CString csPathBuffer;	 
	char TitleBuffer[200];

	GetDlgItemText(IDC_TEMP_FOLDER, csPathBuffer);
	if (!*csPathBuffer)
	{
		char pathbuf[2000];
		GetTempPath(sizeof(pathbuf), pathbuf);
		csPathBuffer = pathbuf;
	}
	LANG2BUFFER(IDS_STRING179, TitleBuffer);
	CXFolderDialog dlg(csPathBuffer);
	dlg.SetOsVersion(CXFolderDialog::XFILEDIALOG_AUTO_DETECT_OS_VERSION);
	dlg.SetTitle(TitleBuffer);
	if (dlg.DoModal() == IDOK)
	{
    	csPathBuffer = dlg.GetPath();

		if (csPathBuffer.GetLength() && csPathBuffer[csPathBuffer.GetLength()-1] == '\\')
			csPathBuffer = csPathBuffer.Left(csPathBuffer.GetLength()-1);
		SetDlgItemText(IDC_TEMP_FOLDER, csPathBuffer);
		ShowFreeSpace();
	}
}

void CArchiveWizzardPage3::ShowFreeSpace()
{
	CString csPathBuffer;	 
	GetDlgItemText(IDC_TEMP_FOLDER, csPathBuffer);
	if (*csPathBuffer)
	{
		ULARGE_INTEGER uliSpace, uliDummy;
		GetDiskFreeSpaceEx(csPathBuffer.GetBuffer(0), &uliSpace, &uliDummy, &uliDummy);
		DWORD dwSpace = (DWORD)(uliSpace.QuadPart / (1024*1024));
		CString csSpace;
		if (dwSpace >= 10240)
			csSpace.Format("%lu GB", dwSpace / 1024);
		else
			csSpace.Format("%lu MB", dwSpace);
		SetDlgItemText(IDC_SPACE, csSpace);

		((CArchiveWizzard *)GetParent())->SetWizardButtons(PSWIZB_BACK|PSWIZB_NEXT);
	}
	else
	{
		SetDlgItemText(IDC_SPACE, "");

		((CArchiveWizzard *)GetParent())->SetWizardButtons(PSWIZB_BACK);
	}
}

void CArchiveWizzardPage3::OnTimer(UINT_PTR nIDEvent) 
{
	ShowFreeSpace();
	KillTimer(1);
	
	CPropertyPage::OnTimer(nIDEvent);
}

void CArchiveWizzardPage3::OnChangeTempFolder() 
{
	SetTimer(1, 1000, NULL);
}


/////////////////////////////////////////////////////////////////////////////
// CArchiveWizzardPage4 property page

CArchiveWizzardPage4::CArchiveWizzardPage4() : CPropertyPage(CArchiveWizzardPage4::IDD)
{
	//{{AFX_DATA_INIT(CArchiveWizzardPage4)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT

	m_psp.dwFlags &= ~PSP_HASHELP;
}

CArchiveWizzardPage4::~CArchiveWizzardPage4()
{
}

void CArchiveWizzardPage4::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CArchiveWizzardPage4)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CArchiveWizzardPage4, CPropertyPage)
	//{{AFX_MSG_MAP(CArchiveWizzardPage4)
	ON_BN_CLICKED(IDC_RECALCULATE, OnRecalculate)
	ON_WM_TIMER()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()



BOOL CArchiveWizzardPage4::OnSetActive() 
{
	SetTimer(1, 1, NULL);
	((CArchiveWizzard *)GetParent())->SetWizardButtons(PSWIZB_BACK);
	
	return CPropertyPage::OnSetActive();
}

BOOL CArchiveWizzardPage4::OnKillActive() 
{
	// TODO: Add your specialized code here and/or call the base class
	
	return CPropertyPage::OnKillActive();
}

void CArchiveWizzardPage4::OnTimer(UINT_PTR nIDEvent) 
{
	KillTimer(1);
	OnRecalculate();
	
	CPropertyPage::OnTimer(nIDEvent);
}

void CArchiveWizzardPage4::OnRecalculate() 
{
	static BOOL bStopCalcSemaphore = 0;

	CString csTemp;
	GetDlgItemText(IDC_RECALCULATE, csTemp);
	MSG msg;
	if (csTemp == "Recalculate")
	{
		bStopCalcSemaphore = 0;
		SetDlgItemText(IDC_RECALCULATE, "Stop calc.");
	}
	else
	{
		bStopCalcSemaphore = 1;
		return;
	}

	((CArchiveWizzard *)GetParent())->SetWizardButtons(PSWIZB_BACK);

	int *pSelector = ((CArchiveWizzard *)GetParent())->m_pSelector;
	if (!pSelector) return;

	int nMethod = ((CArchiveWizzard *)GetParent())->m_nMethod;
	int nVolumeSize = ((CArchiveWizzard *)GetParent())->m_nVolumeSize;

	CTelArPropertyPage2 *pProp2 = (CTelArPropertyPage2 *)((CArchiveWizzard *)GetParent())->m_pWndParent;
	CListCtrl *lb = (CListCtrl *)pProp2->GetDlgItem(IDC_LISTE);

	// get path of current folder
	char pathbuffer[1000];
	TMZeile *p = pProp2->pFolders->Find(0, pProp2->csOrdner);
	if (!p)
		strcpy(pathbuffer, X_path);
	else
		strcpy(pathbuffer, (LPCSTR)p->Spalte(1));
	if (*pathbuffer && pathbuffer[strlen(pathbuffer)-1] != '\\')
		strcat(pathbuffer, "\\");

	CString csStatus;
	csStatus = "Starting calculation...";
	SetDlgItemText(IDC_STATUS, csStatus);

	int n = lb->GetItemCount();
	WIN32_FILE_ATTRIBUTE_DATA fad;
	DWORD dwSizeOfSelectedFiles1024 = 0L;
	DWORD dwTotalSizeOfFiles1024 = 0L;
	char buffer[1000];
	BOOL bStillFreeSpace = TRUE;
	int nSelected = 0;
	DWORD *pSelectorSizeOfSelectedFiles1024 = new DWORD[n];

	// calculate size of all the recordings
	int i;
	for (i = 0; i < n; i++)
	{
		if (bStopCalcSemaphore)
		{
			csStatus += "\r\nCalculation aborted by user.";
			SetDlgItemText(IDC_RECALCULATE, "Recalculate");
			SetDlgItemText(IDC_STATUS, csStatus);
			((CEdit*)GetDlgItem(IDC_STATUS))->SetSel(csStatus.GetLength(), csStatus.GetLength());
			return;
		}

		BOOL bAddRecording = FALSE;
		strcpy(buffer, pathbuffer);
		p = pProp2->SafeGetItemData(i);
		if (p) strcat(buffer, p->Spalte(SPID_DATEINAME).GetBuffer(0));

		if (bStillFreeSpace && (nMethod == 0 || (nMethod == 1 && ((CListBox *)pProp2->m_ListeLB.GetItemState(i, LVIS_SELECTED)))))
			bAddRecording = TRUE;

		// get file size
		if (p && GetFileAttributesEx(buffer, GetFileExInfoStandard, &fad))
		{
			if (fad.nFileSizeHigh > 2047) 
			{
				csStatus += "\r\nWarning: Single file size is exceeding internal arithmetics. Calculation will be faulty.";
				SetDlgItemText(IDC_STATUS, csStatus);
				((CEdit*)GetDlgItem(IDC_STATUS))->SetSel(csStatus.GetLength(), csStatus.GetLength());
			}

			DWORD dwHigh = fad.nFileSizeHigh %= 1023;
			DWORD dwLow  = fad.nFileSizeLow + 2047;	// round up to next 2048kB block
			if (fad.nFileSizeLow > fad.nFileSizeLow) dwHigh++;
			DWORD dwSizeOfSingleFile1024 = (dwHigh << 21) | dwLow >> 11;
			dwSizeOfSingleFile1024 = dwSizeOfSingleFile1024 << 1;
			
			DWORD dwTotalSizeOfFiles1024Safe = dwTotalSizeOfFiles1024;
			if (bAddRecording)
			{
				dwSizeOfSelectedFiles1024 += dwSizeOfSingleFile1024;
				if (dwSizeOfSelectedFiles1024/1024 >= (unsigned)nVolumeSize)	// volume full?
				{
					bStillFreeSpace = FALSE;	// stop adding files
					dwSizeOfSelectedFiles1024 -= dwSizeOfSingleFile1024;	// rollback last file
				}
				else
				{
					pSelector[nSelected] = i;
					pSelectorSizeOfSelectedFiles1024[i] = dwSizeOfSelectedFiles1024;
					nSelected++;	// this recording to be archived
				}
			}
			dwTotalSizeOfFiles1024 += dwSizeOfSingleFile1024;
			if (dwTotalSizeOfFiles1024 < dwTotalSizeOfFiles1024Safe) 
			{
				csStatus += "\r\nWarning: Total file size is exceeding internal arithmetics. Calculation will be faulty.";
				SetDlgItemText(IDC_STATUS, csStatus);
				((CEdit*)GetDlgItem(IDC_STATUS))->SetSel(csStatus.GetLength(), csStatus.GetLength());
			}

			// display progress
			CString csMeter;
			csMeter.Format("%d of %d listed", nSelected, n);
			SetDlgItemText(IDC_NUMBER_OF_RECORDINGS, csMeter);
			csMeter.Format("%lu of %lu MB\r\n(%lu of %lu KB)", dwSizeOfSelectedFiles1024/1024, dwTotalSizeOfFiles1024/1024, dwSizeOfSelectedFiles1024, dwTotalSizeOfFiles1024);
			SetDlgItemText(IDC_STORAGE_CONSUMTION, csMeter);

			MSG msg;
			// Handle dialog messages to update dialog
			while(PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
			{
				if(!IsDialogMessage(&msg))
				{
				TranslateMessage(&msg);
				DispatchMessage(&msg);  
				}
			}
		}
		else
		{
			CString csErr;
			csErr.Format("\r\nWarning: Couldn't obtain size of file '%s'.", buffer);
			csStatus += csErr;
			SetDlgItemText(IDC_STATUS, csStatus);
			((CEdit*)GetDlgItem(IDC_STATUS))->SetSel(csStatus.GetLength(), csStatus.GetLength());
		}
	}

	// status message about files
	csTemp.Format("\r\n%d files consuming %lu KB to archive.", nSelected, dwSizeOfSelectedFiles1024);
	csStatus += csTemp;
	SetDlgItemText(IDC_STATUS, csStatus);
	((CEdit*)GetDlgItem(IDC_STATUS))->SetSel(csStatus.GetLength(), csStatus.GetLength());

	// creating index file
	csStatus += "\r\nCreating index file...";
	SetDlgItemText(IDC_STATUS, csStatus);
	CIndexDB destIndex;
	CString destIndexFileName = ((CArchiveWizzard *)GetParent())->m_csTempFolder + "\\" + INDEX_FILENAME;
	if (GetFileAttributes(destIndexFileName) != 0xFFFFFFFF && !DeleteFile(destIndexFileName))
	{
		AfxMessageBox("Wasn't able to delete the temporary index file. Try restarting the application or choose another temporary folder to make sure this file is not currently used by the application.");
		return;
	}
	if (!destIndex.Create(destIndexFileName.GetBuffer(0), ""))
	{
		csStatus += "\r\nFAILED: Couldn't create index file '" + destIndexFileName + "'.";
		SetDlgItemText(IDC_STATUS, csStatus);
		((CEdit*)GetDlgItem(IDC_STATUS))->SetSel(csStatus.GetLength(), csStatus.GetLength());
		return;
	}
	
	// adding records to index file...
	csStatus += "\r\nAdding records to index file...";
	SetDlgItemText(IDC_STATUS, csStatus);
	for (i = 0; i < nSelected; i++)
	{
		p = pProp2->SafeGetItemData(pSelector[i]);
		destIndex.AppendRecording(p);
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			if (!IsDialogMessage(&msg))
			{
				TranslateMessage(&msg);
				DispatchMessage(&msg);  
			}
		}
		if (bStopCalcSemaphore)
			break;
	}
	destIndex.Close();

	if (bStopCalcSemaphore)
	{
		csStatus += "\r\nCalculation aborted by user.";
		SetDlgItemText(IDC_STATUS, csStatus);
		SetDlgItemText(IDC_RECALCULATE, "Recalculate");
		((CEdit*)GetDlgItem(IDC_STATUS))->SetSel(csStatus.GetLength(), csStatus.GetLength());
		return;
	}

	DWORD dwSizeOfIndexFile1024 = 0;
	if (GetFileAttributesEx(destIndexFileName, GetFileExInfoStandard, &fad))
	{
		DWORD dwHigh = fad.nFileSizeHigh %= 1023;
		DWORD dwLow  = fad.nFileSizeLow + 2047;	// round up to next 2048kB block
		dwSizeOfIndexFile1024 = (dwHigh << 21) | dwLow >> 11;
		dwSizeOfIndexFile1024 = dwSizeOfIndexFile1024 << 1;

		csTemp.Format("\r\nIndex file consumes %lu KB.", dwSizeOfIndexFile1024);
		csStatus += csTemp;
		SetDlgItemText(IDC_STATUS, csStatus);
		((CEdit*)GetDlgItem(IDC_STATUS))->SetSel(csStatus.GetLength(), csStatus.GetLength());
	}
	else
	{
		CString csErr;
		csErr.Format("\r\nWarning: Couldn't obtain size of index file '%s'.", destIndexFileName.GetBuffer(0));
		csStatus += csErr;
		SetDlgItemText(IDC_STATUS, csStatus);
		((CEdit*)GetDlgItem(IDC_STATUS))->SetSel(csStatus.GetLength(), csStatus.GetLength());
	}

	int nSelectedOld = nSelected;
	if ((dwSizeOfSelectedFiles1024 + dwSizeOfIndexFile1024) / 1024 >= (unsigned)nVolumeSize)
	{
		do
		{
			nSelected--;
			if (nSelected <= 0)
				break;
		}
		while ((pSelectorSizeOfSelectedFiles1024[nSelected-1] + dwSizeOfIndexFile1024) / 1024 >= (unsigned)nVolumeSize);

		csTemp.Format("\r\nExcluded %d files to get space for index file.", nSelectedOld-nSelected);
		csStatus += csTemp;
		SetDlgItemText(IDC_STATUS, csStatus);

		// creating smaller index file to fit available space
		if (GetFileAttributes(destIndexFileName) != 0xFFFFFFFF && !DeleteFile(destIndexFileName))
		{
			AfxMessageBox("Wasn't able to delete the temporary index file. Try restarting the application or choose another temporary folder to make sure this file is not currently used by the application.");
			return;
		}
		csStatus += "\r\nCreating index file...";
		SetDlgItemText(IDC_STATUS, csStatus);
		CIndexDB destIndex;
		CString destIndexFileName = ((CArchiveWizzard *)GetParent())->m_csTempFolder + "\\" + INDEX_FILENAME;
		if (!destIndex.Create(destIndexFileName.GetBuffer(0), ""))
		{
			csStatus += "\r\nFAILED: Couldn't create index file '" + destIndexFileName + "'.";
			SetDlgItemText(IDC_STATUS, csStatus);
			return;
		}
		
		// adding records to index file...
		csStatus += "\r\nAdding records to index file...";
		SetDlgItemText(IDC_STATUS, csStatus);
		for (i = 0; i < nSelected; i++)
		{
			p = pProp2->SafeGetItemData(pSelector[i]);
			destIndex.AppendRecording(p);
		}
		destIndex.Close();

		// status message
		if (nSelected > 0)
			csTemp.Format("\r\nFinally having %d files consuming %lu KB (index file excluded).", nSelected, pSelectorSizeOfSelectedFiles1024[nSelected-1]);
		else
			csTemp = "\r\nNo files left to archive. Try using a bigger storage medium.";
		csStatus += csTemp;
		SetDlgItemText(IDC_STATUS, csStatus);
		((CEdit*)GetDlgItem(IDC_STATUS))->SetSel(csStatus.GetLength(), csStatus.GetLength());
	}

	CString csMeter;
	csMeter.Format("%d of %d listed", nSelected, n);
	SetDlgItemText(IDC_NUMBER_OF_RECORDINGS, csMeter);
	csMeter.Format("%lu of %lu MB\r\n(%lu of %lu KB)", (pSelectorSizeOfSelectedFiles1024[nSelected-1]+dwSizeOfIndexFile1024)/1024, dwTotalSizeOfFiles1024/1024, pSelectorSizeOfSelectedFiles1024[nSelected-1]+dwSizeOfIndexFile1024, dwTotalSizeOfFiles1024);
	SetDlgItemText(IDC_STORAGE_CONSUMTION, csMeter);

	csStatus += "\r\nFinished.";
	SetDlgItemText(IDC_STATUS, csStatus);
	((CEdit*)GetDlgItem(IDC_STATUS))->SetSel(csStatus.GetLength(), csStatus.GetLength());

	((CArchiveWizzard *)GetParent())->m_nSelected = nSelected;
	((CArchiveWizzard *)GetParent())->SetWizardButtons(PSWIZB_BACK|PSWIZB_NEXT);
		
	SetDlgItemText(IDC_RECALCULATE, "Recalculate");
}


/////////////////////////////////////////////////////////////////////////////
// CArchiveWizzardPage5 property page

CArchiveWizzardPage5::CArchiveWizzardPage5() : CPropertyPage(CArchiveWizzardPage5::IDD)
{
	//{{AFX_DATA_INIT(CArchiveWizzardPage5)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT

	m_psp.dwFlags &= ~PSP_HASHELP;
}

CArchiveWizzardPage5::~CArchiveWizzardPage5()
{
}

void CArchiveWizzardPage5::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CArchiveWizzardPage5)
	DDX_Control(pDX, IDC_PROGRESS, m_Progress);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CArchiveWizzardPage5, CPropertyPage)
	//{{AFX_MSG_MAP(CArchiveWizzardPage5)
	ON_WM_TIMER()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


BOOL CArchiveWizzardPage5::OnSetActive() 
{
	SetTimer(1, 1, NULL);
	((CArchiveWizzard *)GetParent())->SetWizardButtons(PSWIZB_BACK);
	
	return CPropertyPage::OnSetActive();
}

BOOL CArchiveWizzardPage5::OnKillActive() 
{
	// TODO: Add your specialized code here and/or call the base class
	
	return CPropertyPage::OnKillActive();
}

void CArchiveWizzardPage5::OnTimer(UINT_PTR nIDEvent) 
{
	KillTimer(1);
	CopyFiles();	

	CPropertyPage::OnTimer(nIDEvent);
}

void CArchiveWizzardPage5::CopyFiles()
{
	((CArchiveWizzard *)GetParent())->SetWizardButtons(PSWIZB_BACK);

	int *pSelector = ((CArchiveWizzard *)GetParent())->m_pSelector;
	int	nSelected  = ((CArchiveWizzard *)GetParent())->m_nSelected;

	CFileFind ff_wav, ff_trs;
	BOOL found_wav, found_trs;
	CString destIndexFileName = INDEX_FILENAME;

	// Init status box
	CString csStatus;
	csStatus = "Looking for existing audio files...";
	SetDlgItemText(IDC_STATUS, csStatus);

	// Init progress bar
    m_Progress.SetRange(0, ((CArchiveWizzard *)GetParent())->m_nSelected);
    m_Progress.SetStep(1);
    m_Progress.SetPos(0);

	// Init list of files for Nero Burning dialog
	((CArchiveWizzard *)GetParent())->m_csaFiles.RemoveAll();
	((CArchiveWizzard *)GetParent())->m_csaFiles.Add(((CArchiveWizzard *)GetParent())->m_csTempFolder + "\\" + destIndexFileName);

	found_wav = ff_wav.FindFile((LPCSTR)(CString)(((CArchiveWizzard *)GetParent())->m_csTempFolder + "\\" + "*.wav"));
	found_trs = ff_trs.FindFile((LPCSTR)(CString)(((CArchiveWizzard *)GetParent())->m_csTempFolder + "\\" + "*.trs"));
	if (found_wav || found_trs)
	{
		if (AfxMessageBox("Some audio files were found in the temporary folder. Delete them?", MB_YESNO) == IDYES)
		{
			if (found_wav) Status((CString)"Deleting WAV files...");
			while (found_wav)
			{
				found_wav = ff_wav.FindNextFile();
				DeleteFile((LPCSTR)(CString)((CArchiveWizzard *)GetParent())->m_csTempFolder + (CString)"\\" + ff_wav.GetFileName());
			}

			if (found_trs) Status((CString)"Deleting TRS files...");
			while (found_trs)
			{
				found_trs = ff_trs.FindNextFile();
				DeleteFile((LPCSTR)(CString)((CArchiveWizzard *)GetParent())->m_csTempFolder + (CString)"\\" + ff_trs.GetFileName());
			}
		}
	}

	CTelArPropertyPage2 *pProp2 = (CTelArPropertyPage2 *)((CArchiveWizzard *)GetParent())->m_pWndParent;

	// get path of current folder
	char pathbuffer[1000];
	TMZeile *p = pProp2->pFolders->Find(0, pProp2->csOrdner);
	if (!p)
		strcpy(pathbuffer, X_path);
	else
		strcpy(pathbuffer, (LPCSTR)p->Spalte(1));
	if (*pathbuffer && pathbuffer[strlen(pathbuffer)-1] != '\\')
		strcat(pathbuffer, "\\");

	int nFailed = 0;
	Status((CString)"Copying audio files...");
	int i;
	for (i = 0; i < ((CArchiveWizzard *)GetParent())->m_nSelected; i++)
	{
		p = pProp2->SafeGetItemData(((CArchiveWizzard *)GetParent())->m_pSelector[i]);
		CString csSrcFile = (CString)pathbuffer + p->Spalte(SPID_DATEINAME);
		CString csDstFile = ((CArchiveWizzard *)GetParent())->m_csTempFolder + "\\" + p->Spalte(SPID_DATEINAME);
		if (!CopyFile(csSrcFile, csDstFile, FALSE))
		{
			Status("Problem copying file " + csSrcFile + " to " + ((CArchiveWizzard *)GetParent())->m_csTempFolder);
			nFailed++;
		}
		else
		{
			// Add files to burn with Nero Burning dialog
			((CArchiveWizzard *)GetParent())->m_csaFiles.Add(csDstFile);
		}
		m_Progress.SetPos(i);
		Breathe();
	}
	m_Progress.SetPos(i);

	CString csTemp;
	csTemp.Format("%d files copied.", ((CArchiveWizzard *)GetParent())->m_nSelected-nFailed);
	Status(csTemp);
	if (nFailed) 
	{
		csTemp.Format("%d files FAILED.", nFailed);
		Status(csTemp);
	}

	SetDlgItemText(IDC_MESSAGE, "The wizard is now copying the audio files to the temporary folder. Please stand by... Completed.");
	((CArchiveWizzard *)GetParent())->SetWizardButtons(PSWIZB_BACK|PSWIZB_NEXT);
}

void CArchiveWizzardPage5::Status(CString &s)
{
	CString csStatus;
	GetDlgItemText(IDC_STATUS, csStatus);
	if (csStatus.GetLength())
		csStatus += "\r\n" + (CString)s;
	else
		csStatus += s;
	SetDlgItemText(IDC_STATUS, csStatus);
	((CEdit*)GetDlgItem(IDC_STATUS))->SetSel(csStatus.GetLength(), csStatus.GetLength());

	Breathe();
}


void CArchiveWizzardPage5::Breathe()
{
	MSG msg;
	// Handle dialog messages to update dialog
	while(PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
	{
		if(!IsDialogMessage(&msg))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);  
		}
	}
}


/////////////////////////////////////////////////////////////////////////////
// CArchiveWizzardPage6 property page

CArchiveWizzardPage6::CArchiveWizzardPage6() : CPropertyPage(CArchiveWizzardPage6::IDD)
{
	//{{AFX_DATA_INIT(CArchiveWizzardPage6)
	//}}AFX_DATA_INIT

	m_psp.dwFlags &= ~PSP_HASHELP;
}

CArchiveWizzardPage6::~CArchiveWizzardPage6()
{
}

void CArchiveWizzardPage6::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CArchiveWizzardPage6)
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CArchiveWizzardPage6, CPropertyPage)
	//{{AFX_MSG_MAP(CArchiveWizzardPage6)
	ON_BN_CLICKED(IDC_OPEN_TEMPORARY_FOLDER, OnOpenTemporaryFolder)
	ON_BN_CLICKED(IDC_NERO_DIALOG, OnNero)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


BOOL CArchiveWizzardPage6::OnSetActive() 
{
	((CArchiveWizzard *)GetParent())->SetWizardButtons(PSWIZB_BACK|PSWIZB_NEXT);
	
	return CPropertyPage::OnSetActive();
}

void CArchiveWizzardPage6::OnOpenTemporaryFolder() 
{
	HINSTANCE hInst = ShellExecute(m_hWnd, "explore", ((CArchiveWizzard *)GetParent())->m_csTempFolder.GetBuffer(0), NULL, NULL, SW_SHOWNORMAL);	
	if ((int)hInst < 32)
	{
		CString csErr;
		csErr.Format("Shell error %d.", (int)hInst);
		AfxMessageBox(csErr);
	}
}

void CArchiveWizzardPage6::OnNero() 
{
	AfxMessageBox("Sorry, Ahead Software discontinued the support for other software to connect to it. This function is no longer available.");
	return;
/*
	DSAMessageBox(IDS_STRING180, MB_OK);
	
	{
		CneroDlg dlg;
		dlg.m_pcsaFiles = &((CArchiveWizzard *)GetParent())->m_csaFiles;
		dlg.m_nVolumeSize = ((CArchiveWizzard *)GetParent())->m_nVolumeSize;
		dlg.DoModal();
	}
*/
}

/////////////////////////////////////////////////////////////////////////////
// CArchiveWizzardPage7 property page

CArchiveWizzardPage7::CArchiveWizzardPage7() : CPropertyPage(CArchiveWizzardPage7::IDD)
{
	//{{AFX_DATA_INIT(CArchiveWizzardPage7)
	m_delete = -1;
	//}}AFX_DATA_INIT

	m_psp.dwFlags &= ~PSP_HASHELP;
}

CArchiveWizzardPage7::~CArchiveWizzardPage7()
{
}

void CArchiveWizzardPage7::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CArchiveWizzardPage7)
	DDX_Radio(pDX, IDC_DELETE1, m_delete);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CArchiveWizzardPage7, CPropertyPage)
	//{{AFX_MSG_MAP(CArchiveWizzardPage7)
	ON_BN_CLICKED(IDC_DELETE1, OnDelete)
	ON_BN_CLICKED(IDC_DELETE2, OnDelete)
	ON_BN_CLICKED(IDC_DELETE3, OnDelete)
	ON_BN_CLICKED(IDC_DELETE4, OnDelete)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


BOOL CArchiveWizzardPage7::OnSetActive() 
{
	m_delete = -1;
	UpdateData(FALSE);

	((CArchiveWizzard *)GetParent())->SetWizardButtons(PSWIZB_BACK|PSWIZB_DISABLEDFINISH);
	
	return CPropertyPage::OnSetActive();
}

BOOL CArchiveWizzardPage7::OnKillActive() 
{
	// TODO: Add your specialized code here and/or call the base class
	
	return CPropertyPage::OnKillActive();
}




BOOL CArchiveWizzardPage7::OnWizardFinish() 
{
	UpdateData(TRUE);

	if (m_delete == 0 || m_delete == 2)
	{
		CFileFind ff_wav, ff_trs;
		BOOL found_wav, found_trs;
		CString destIndexFileName = INDEX_FILENAME;

		found_wav = ff_wav.FindFile((LPCSTR)(CString)(((CArchiveWizzard *)GetParent())->m_csTempFolder + "\\" + "*.wav"));
		found_trs = ff_trs.FindFile((LPCSTR)(CString)(((CArchiveWizzard *)GetParent())->m_csTempFolder + "\\" + "*.trs"));
		if (found_wav || found_trs)
		{
			{
				while (found_wav)
				{
					found_wav = ff_wav.FindNextFile();
					DeleteFile((LPCSTR)(CString)((CArchiveWizzard *)GetParent())->m_csTempFolder + (CString)"\\" + ff_wav.GetFileName());
				}

				while (found_trs)
				{
					found_trs = ff_trs.FindNextFile();
					DeleteFile((LPCSTR)(CString)((CArchiveWizzard *)GetParent())->m_csTempFolder + (CString)"\\" + ff_trs.GetFileName());
				}
			}
		}

		// index file
		DeleteFile((LPCSTR)(CString)((CArchiveWizzard *)GetParent())->m_csTempFolder + (CString)"\\" + destIndexFileName);
	}

	if (m_delete == 1 || m_delete == 2)
	{
		CTelArPropertyPage2 *pProp2 = (CTelArPropertyPage2 *)((CArchiveWizzard *)GetParent())->m_pWndParent;
		CListCtrl *lb = (CListCtrl *)pProp2->GetDlgItem(IDC_LISTE);
		pProp2->LoescheListeneintraege(lb, ((CArchiveWizzard *)GetParent())->m_pSelector, ((CArchiveWizzard *)GetParent())->m_nSelected);
	}
	
	return CPropertyPage::OnWizardFinish();
}

void CArchiveWizzardPage7::OnDelete() 
{
	((CArchiveWizzard *)GetParent())->SetWizardButtons(PSWIZB_BACK|PSWIZB_FINISH);	
}
