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
*
* EnterContactDetails.cpp : implementation file
*/

#include "stdafx.h"
#include "telar.h"
#include "EnterContactDetails.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CEnterContactDetails dialog


CEnterContactDetails::CEnterContactDetails(CWnd* pParent /*=NULL*/)
	: CDialog(CEnterContactDetails::IDD, pParent)
{
	//{{AFX_DATA_INIT(CEnterContactDetails)
	m_from = _T("");
	m_name = _T("");
	m_phone = _T("");
	//}}AFX_DATA_INIT
}


void CEnterContactDetails::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CEnterContactDetails)
	DDX_Text(pDX, IDC_FROM, m_from);
	DDV_MaxChars(pDX, m_from, 80);
	DDX_Text(pDX, IDC_NAME, m_name);
	DDV_MaxChars(pDX, m_name, 80);
	DDX_Text(pDX, IDC_PHONE, m_phone);
	DDV_MaxChars(pDX, m_phone, 50);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CEnterContactDetails, CDialog)
	//{{AFX_MSG_MAP(CEnterContactDetails)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEnterContactDetails message handlers
