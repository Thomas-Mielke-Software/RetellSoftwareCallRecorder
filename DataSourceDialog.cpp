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
*    DataSourceDialog.cpp : implementation file
*/

#include "stdafx.h"
#include "Telar.h"
#include "DataSourceDialog.h"


// CDataSourceDialog dialog

IMPLEMENT_DYNAMIC(CDataSourceDialog, CDialog)

CDataSourceDialog::CDataSourceDialog(CWnd* pParent /*=NULL*/)
	: CDialog(CDataSourceDialog::IDD, pParent)
	, m_csDSN(_T(""))
{

}

CDataSourceDialog::~CDataSourceDialog()
{
}

void CDataSourceDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_ctrlList);
}


BEGIN_MESSAGE_MAP(CDataSourceDialog, CDialog)
	ON_LBN_SELCHANGE(IDC_LIST1, &CDataSourceDialog::OnLbnSelchangeList1)
	ON_BN_CLICKED(IDOK, &CDataSourceDialog::OnBnClickedOk)
	ON_LBN_DBLCLK(IDC_LIST1, &CDataSourceDialog::OnLbnDblclkList1)
END_MESSAGE_MAP()


// CDataSourceDialog message handlers

void CDataSourceDialog::OnLbnSelchangeList1()
{
	m_csDSN = "";
}

void CDataSourceDialog::OnBnClickedOk()
{
	int n = m_ctrlList.GetCurSel();
	if (n >= 0)
	{
		m_ctrlList.GetText(n, m_csDSN);

		OnOK();
	}
}

BOOL CDataSourceDialog::OnInitDialog(void)
{
	UpdateData(FALSE);

    HKEY hklm;
    HKEY hkcu;
	char valuename[1000];
	long lCb = sizeof(valuename);
	*valuename = '\0';


	// try HKEY_LOCAL_MACHINE
	if (RegOpenKeyEx(HKEY_LOCAL_MACHINE, "SOFTWARE\\ODBC\\ODBC.INI\\ODBC DATA SOURCES", 0L, KEY_READ, &hklm) != ERROR_SUCCESS)
	{
		DF("CDataSourceDialog::OnInitDialog Opening system data sources failed.")
		hklm = NULL;
	}

	// HKEY_CURRENT_USER
	if (RegOpenKeyEx(HKEY_CURRENT_USER, "SOFTWARE\\ODBC\\ODBC.INI\\ODBC DATA SOURCES", 0L, KEY_READ, &hkcu) != ERROR_SUCCESS)
	{
		// give up
		DF("CDataSourceDialog::OnInitDialog Opening user data sources failed.")
		hkcu = NULL;
	}

	int i;
	for (i = 0; ERROR_SUCCESS == RegEnumValue(hklm, i, valuename, (ULONG *)&lCb, NULL, NULL, NULL, NULL); i++)
	{
		m_ctrlList.AddString(valuename);
		*valuename = '\0';		
		lCb = sizeof(valuename);
	}

	for (i = 0; ERROR_SUCCESS == RegEnumValue(hkcu, i, valuename, (ULONG *)&lCb, NULL, NULL, NULL, NULL); i++)
	{
		m_ctrlList.AddString(valuename);
		*valuename = '\0';		
		lCb = sizeof(valuename);
	}

	if (hklm) RegCloseKey(hklm);
	if (hkcu) RegCloseKey(hkcu);

	return 0;
}

void CDataSourceDialog::OnLbnDblclkList1()
{
	OnBnClickedOk();
}
