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


#if !defined(AFX_SEPARATOR_H__8E0BFFB7_CFAB_11D6_AF2B_00C0FD02126B__INCLUDED_)
#define AFX_SEPARATOR_H__8E0BFFB7_CFAB_11D6_AF2B_00C0FD02126B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Separator.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSeparator window

class CSeparator : public CWnd
{
// Construction
public:
	CSeparator();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSeparator)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CSeparator();

	// Generated message map functions
protected:
	//{{AFX_MSG(CSeparator)
	afx_msg void OnPaint();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SEPARATOR_H__8E0BFFB7_CFAB_11D6_AF2B_00C0FD02126B__INCLUDED_)
