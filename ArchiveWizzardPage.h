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
*	ArchiveWizzardPage.h : header file
*	Klasse zur Verwaltung der Archive Wizard Property Pages
*	
*	$Log:   D:/pvcsarch/telar/IndexDB.cpv  $
*/

#ifndef __ARCHIVEWIZZARDPAGE_H__
#define __ARCHIVEWIZZARDPAGE_H__

/////////////////////////////////////////////////////////////////////////////
// CArchiveWizzardPage1 dialog

class CArchiveWizzardPage1 : public CPropertyPage
{
	DECLARE_DYNCREATE(CArchiveWizzardPage1)

// Construction
public:
	CArchiveWizzardPage1();
	~CArchiveWizzardPage1();

// Dialog Data
	//{{AFX_DATA(CArchiveWizzardPage1)
	enum { IDD = IDD_ARCHIVEWIZZARDPAGE1 };
		// NOTE - ClassWizard will add data members here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_DATA


// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CArchiveWizzardPage1)
	public:
	virtual BOOL OnSetActive();
	virtual BOOL OnKillActive();
	virtual void OnCancel();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(CArchiveWizzardPage1)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

/////////////////////////////////////////////////////////////////////////////
// CArchiveWizzardPage2 dialog

class CArchiveWizzardPage2 : public CPropertyPage
{
	DECLARE_DYNCREATE(CArchiveWizzardPage2)

// Construction
public:
	CArchiveWizzardPage2();
	~CArchiveWizzardPage2();

// Dialog Data
	//{{AFX_DATA(CArchiveWizzardPage2)
	enum { IDD = IDD_ARCHIVEWIZZARDPAGE2 };
		// NOTE - ClassWizard will add data members here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_DATA


// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CArchiveWizzardPage2)
	public:
	virtual BOOL OnSetActive();
	virtual BOOL OnKillActive();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(CArchiveWizzardPage2)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};


/////////////////////////////////////////////////////////////////////////////
// CArchiveWizzardPage3 dialog

class CArchiveWizzardPage3 : public CPropertyPage
{
	DECLARE_DYNCREATE(CArchiveWizzardPage3)

// Construction
public:
	CArchiveWizzardPage3();
	~CArchiveWizzardPage3();

// Dialog Data
	//{{AFX_DATA(CArchiveWizzardPage3)
	enum { IDD = IDD_ARCHIVEWIZZARDPAGE3 };
		// NOTE - ClassWizard will add data members here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_DATA

	void ShowFreeSpace();

// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CArchiveWizzardPage3)
	public:
	virtual BOOL OnSetActive();
	virtual BOOL OnKillActive();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(CArchiveWizzardPage3)
	afx_msg void OnBrowseTempFolder();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnChangeTempFolder();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};


/////////////////////////////////////////////////////////////////////////////
// CArchiveWizzardPage4 dialog

class CArchiveWizzardPage4 : public CPropertyPage
{
	DECLARE_DYNCREATE(CArchiveWizzardPage4)

// Construction
public:
	CArchiveWizzardPage4();
	~CArchiveWizzardPage4();

// Dialog Data
	//{{AFX_DATA(CArchiveWizzardPage4)
	enum { IDD = IDD_ARCHIVEWIZZARDPAGE4 };
		// NOTE - ClassWizard will add data members here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_DATA


// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CArchiveWizzardPage4)
	public:
	virtual BOOL OnSetActive();
	virtual BOOL OnKillActive();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(CArchiveWizzardPage4)
	afx_msg void OnRecalculate();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};


/////////////////////////////////////////////////////////////////////////////
// CArchiveWizzardPage5 dialog

class CArchiveWizzardPage5 : public CPropertyPage
{
	DECLARE_DYNCREATE(CArchiveWizzardPage5)

// Construction
public:
	CArchiveWizzardPage5();
	~CArchiveWizzardPage5();

// Dialog Data
	//{{AFX_DATA(CArchiveWizzardPage5)
	enum { IDD = IDD_ARCHIVEWIZZARDPAGE5 };
	CProgressCtrl	m_Progress;
	//}}AFX_DATA

	void CopyFiles();
	void Status(CString &s);
	void Breathe();

// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CArchiveWizzardPage5)
	public:
	virtual BOOL OnSetActive();
	virtual BOOL OnKillActive();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(CArchiveWizzardPage5)
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};


/////////////////////////////////////////////////////////////////////////////
// CArchiveWizzardPage6 dialog

class CArchiveWizzardPage6 : public CPropertyPage
{
	DECLARE_DYNCREATE(CArchiveWizzardPage6)

// Construction
public:
	CArchiveWizzardPage6();
	~CArchiveWizzardPage6();

// Dialog Data
	//{{AFX_DATA(CArchiveWizzardPage6)
	enum { IDD = IDD_ARCHIVEWIZZARDPAGE6 };
	//}}AFX_DATA


// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CArchiveWizzardPage6)
	public:
	virtual BOOL OnSetActive();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(CArchiveWizzardPage6)
	afx_msg void OnOpenTemporaryFolder();
	afx_msg void OnNero();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};


/////////////////////////////////////////////////////////////////////////////
// CArchiveWizzardPage7 dialog

class CArchiveWizzardPage7 : public CPropertyPage
{
	DECLARE_DYNCREATE(CArchiveWizzardPage7)

// Construction
public:
	CArchiveWizzardPage7();
	~CArchiveWizzardPage7();

// Dialog Data
	//{{AFX_DATA(CArchiveWizzardPage7)
	enum { IDD = IDD_ARCHIVEWIZZARDPAGE7 };
	int		m_delete;
	//}}AFX_DATA


// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CArchiveWizzardPage7)
	public:
	virtual BOOL OnSetActive();
	virtual BOOL OnKillActive();
	virtual BOOL OnWizardFinish();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(CArchiveWizzardPage7)
	afx_msg void OnDelete();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};



#endif // __ARCHIVEWIZZARDPAGE_H__
