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

// EnterKeyDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CEnterKeyDlg dialog

class CEnterKeyDlg : public CDialog
{
// Construction
public:
	CEnterKeyDlg(CWnd* pParent = NULL);   // standard constructor

	BOOL m_no_more_trial;

// Dialog Data
	//{{AFX_DATA(CEnterKeyDlg)
	enum { IDD = IDD_ENTER_KEY };
	CString	m_license_key;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEnterKeyDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CEnterKeyDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnTrial();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
