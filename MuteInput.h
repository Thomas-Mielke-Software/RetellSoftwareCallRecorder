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

#if !defined(AFX_MUTEINPUT_H__9BD9DEA4_1BFF_49A1_A6B8_EDD3381AF00E__INCLUDED_)
#define AFX_MUTEINPUT_H__9BD9DEA4_1BFF_49A1_A6B8_EDD3381AF00E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// MuteInput.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CMuteInput dialog

class CMuteInput : public CDialog
{
// Construction
public:
	CMuteInput(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CMuteInput)
	enum { IDD = IDD_MUTEINPUT };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMuteInput)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	char m_strControlPanelPath[1000];

	// Generated message map functions
	//{{AFX_MSG(CMuteInput)
	afx_msg void OnOpenControlPanel();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MUTEINPUT_H__9BD9DEA4_1BFF_49A1_A6B8_EDD3381AF00E__INCLUDED_)
