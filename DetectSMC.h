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

#if !defined(AFX_DETECTSMC_H__CA32F28C_49C0_4DDE_83E5_082DF0F987D8__INCLUDED_)
#define AFX_DETECTSMC_H__CA32F28C_49C0_4DDE_83E5_082DF0F987D8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DetectSMC.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDetectSMC dialog

class CDetectSMC : public CDialog
{
// Construction
public:
	CDetectSMC(CWnd* pParent = NULL);   // standard constructor

	int m_couter;
	int m_result;

// Dialog Data
	//{{AFX_DATA(CDetectSMC)
	enum { IDD = IDD_DETECT_SUPER_MODULAR };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDetectSMC)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDetectSMC)
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	virtual void OnCancel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DETECTSMC_H__CA32F28C_49C0_4DDE_83E5_082DF0F987D8__INCLUDED_)
