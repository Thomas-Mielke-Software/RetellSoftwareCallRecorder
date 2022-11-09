// ArchiveWizzardPreviewWnd.h : header file
//
// This file contains the preview window used by the 
// CArchiveWizzard property sheet.

/////////////////////////////////////////////////////////////////////////////
// CArchiveWizzardPreviewWnd window

#ifndef __ARCHIVEWIZZARDPREVIEWWND_H__
#define __ARCHIVEWIZZARDPREVIEWWND_H__

class CArchiveWizzardPreviewWnd : public CWnd
{
// Construction
public:
	CArchiveWizzardPreviewWnd();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CArchiveWizzardPreviewWnd)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CArchiveWizzardPreviewWnd();

	// Generated message map functions
protected:
	//{{AFX_MSG(CArchiveWizzardPreviewWnd)
	afx_msg void OnPaint();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

#endif		// __ARCHIVEWIZZARDPREVIEWWND_H__