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

#if !defined(AFX_SELECTDEVICEDLG_H__365F1B10_A0F8_4446_81F3_4DBA565305B9__INCLUDED_)
#define AFX_SELECTDEVICEDLG_H__365F1B10_A0F8_4446_81F3_4DBA565305B9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SelectDeviceDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSelectDeviceDlg dialog

class CSelectDeviceDlg : public CDialog
{
// Construction
public:
	CSelectDeviceDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CSelectDeviceDlg)
	enum { IDD = IDD_SELECT_DEVICE };
	int		m_liste;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSelectDeviceDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CSelectDeviceDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnDblclkListe();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SELECTDEVICEDLG_H__365F1B10_A0F8_4446_81F3_4DBA565305B9__INCLUDED_)
