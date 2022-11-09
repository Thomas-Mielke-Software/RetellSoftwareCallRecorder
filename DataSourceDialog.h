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

#pragma once
#include "afxwin.h"


// CDataSourceDialog dialog

class CDataSourceDialog : public CDialog
{
	DECLARE_DYNAMIC(CDataSourceDialog)

public:
	CDataSourceDialog(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDataSourceDialog();

// Dialog Data
	enum { IDD = IDD_DATASOURCE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLbnSelchangeList1();
	afx_msg void OnBnClickedOk();
	CString m_csDSN;
	CListBox m_ctrlList;
	virtual BOOL OnInitDialog(void);
	afx_msg void OnLbnDblclkList1();
};
