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
*/

#if !defined(AFX_NBMESSAGEBOX_H__D9FAFBD4_744B_45DB_9CA6_77DDB6F6C49D__INCLUDED_)
#define AFX_NBMESSAGEBOX_H__D9FAFBD4_744B_45DB_9CA6_77DDB6F6C49D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Separator.h"

class CnbMessageBox : public CWnd
{
// Construction
public:
	CnbMessageBox(CWnd *pParent = NULL);

// Attributes
public:

// Operations
public:
    int MessageBox(LPCTSTR lpszText, UINT nType = MB_OK, UINT nIDHelp = 0 );
    int MessageBox( UINT nIDPrompt, UINT nType = MB_OK, UINT nIDHelp = (UINT) -1 );

    void SetChecked(BOOL bChecked);
    BOOL GetChecked();

    static void SetDoNotAgainStrings(CString &strDoNotShowAgain, CString &strDoNotAskAgain);
    static void SetDoNotAgainStrings(int nDoNotShowAgainId, int nDoNotAskAgainId);

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CnbMessageBox)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CnbMessageBox();

	// Generated message map functions
protected:
	//{{AFX_MSG(CnbMessageBox)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
    LRESULT OnSubclassedInit(WPARAM wParam, LPARAM lParam);
    afx_msg void OnDoNotAgain();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

    CWnd *m_pParent;
    CButton m_cbDoNotAgain;
    CSeparator m_ctrlSep;

    BOOL m_bChecked;

    int m_nType;

    static CString m_strDoNotShowAgain;
    static CString m_strDoNotAskAgain;
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_NBMESSAGEBOX_H__D9FAFBD4_744B_45DB_9CA6_77DDB6F6C49D__INCLUDED_)
