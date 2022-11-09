#if !defined(AFX_neroDlg_H__78BE85B9_87B6_11D4_8056_00105ABB05E6__INCLUDED_)
#define AFX_neroDlg_H__78BE85B9_87B6_11D4_8056_00105ABB05E6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "neroapiglue.h"

/////////////////////////////////////////////////////////////////////////////
// CneroDlg dialog

class CneroDlg : public CDialog
{
// Construction
public:
	static void NERO_CALLBACK_ATTR SetPhaseCallback (void* pUserData, const char* text);
	static void NERO_CALLBACK_ATTR AddLogLine(void* pUserData, NERO_TEXT_TYPE type, const char* text);
	static BOOL NERO_CALLBACK_ATTR AbortedCallback (void* pUserData);
	static BOOL NERO_CALLBACK_ATTR ProgressCallback (void* pUserData, DWORD dwProgressInPercent);
	static NeroUserDlgInOut NERO_CALLBACK_ATTR UserDialog(void* pUserData, NeroUserDlgInOut type, void* data);
	static BOOL NERO_CALLBACK_ATTR IdleCallback (void* pUserData);
	CneroDlg(CWnd* pParent = NULL);	// standard constructor
	
	// Data Supply Members
	CStringArray *m_pcsaFiles;
	int m_nVolumeSize;

// Dialog Data
	//{{AFX_DATA(CneroDlg)
	enum { IDD = IDD_NERO_DIALOG };
	CButton	mbtnBurn;
	CEdit	medtMessages;
	CProgressCtrl	mpgsProgress;
	CComboBox	mcbxDevices;
	CButton	mbtnAbort;
	CButton	mCancel;
	CString	m_csVolumeName;
	CEdit	medtFileName;
	CButton	mbtnBrowse;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CneroDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CneroDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnBrowse();
	virtual void OnOK();
	virtual void OnCancel();
	afx_msg void OnAbort();
	afx_msg void OnBurn();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	char mpcImage [256];
	bool mbAborted;
	void NeroAPIFree();
	NERO_SETTINGS nsSettings;
	void AppendString(CString str);
	void NeroAPIInit();
    char pcLanguageFile [128];
    char pcSoftware [128];
    char pcVendor [128];
	char pcNeroFilesPath [128];
	char pcDriveName [128];
	FILE* pFile;
	NERO_ISO_ITEM *pmniiFile;
	NERO_WRITE_CD writeCD;
	NERO_PROGRESS npProgress;
	NERO_SCSI_DEVICE_INFOS* pndiDeviceInfos;
	NERO_DEVICEHANDLE ndhDeviceHandle;
	CString mstrPathName;
	CString mstrFileName;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_neroDlg_H__78BE85B9_87B6_11D4_8056_00105ABB05E6__INCLUDED_)
