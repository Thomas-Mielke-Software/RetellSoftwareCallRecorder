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

#if !defined(AFX_ENTERRESPONSEKEY_H__42BCD089_0710_45FE_8712_5DBE3B4112FF__INCLUDED_)
#define AFX_ENTERRESPONSEKEY_H__42BCD089_0710_45FE_8712_5DBE3B4112FF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// EnterResponseKey.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CEnterResponseKey dialog

class CEnterResponseKey : public CDialog
{
// Construction
public:
	CEnterResponseKey(int idd, CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CEnterResponseKey)
	enum { IDD = IDD_ENTERRESPONSEKEY_DIALOG };
	CString	m_request_code;
	CString	m_response_code;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEnterResponseKey)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

public:
	CString m_phone;
	CString m_product;

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CEnterResponseKey)
	virtual BOOL OnInitDialog();
	afx_msg void OnChangeResponseCode();
	afx_msg void OnMapimail();
	afx_msg void OnInternetmail();
	afx_msg void OnCopytoclipboard();
	afx_msg void OnWww();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ENTERRESPONSEKEY_H__42BCD089_0710_45FE_8712_5DBE3B4112FF__INCLUDED_)
