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

#if !defined(AFX_ENTERCONTACTDETAILS_H__B8672395_9089_4F07_ABCF_0A167F273C5F__INCLUDED_)
#define AFX_ENTERCONTACTDETAILS_H__B8672395_9089_4F07_ABCF_0A167F273C5F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// EnterContactDetails.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CEnterContactDetails dialog

class CEnterContactDetails : public CDialog
{
// Construction
public:
	CEnterContactDetails(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CEnterContactDetails)
	enum { IDD = IDD_ENTER_CONTACT_DETAILS };
	CString	m_from;
	CString	m_name;
	CString	m_phone;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEnterContactDetails)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CEnterContactDetails)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ENTERCONTACTDETAILS_H__B8672395_9089_4F07_ABCF_0A167F273C5F__INCLUDED_)
