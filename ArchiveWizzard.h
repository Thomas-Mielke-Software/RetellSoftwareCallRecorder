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
*	Beschreibung: class CArchiveWizzard
*	
*	ArchiveWizzard.h : header file
*	Klasse zur Verwaltung des Archive Wizard Property Sheet
*	
*	$Log:   D:/pvcsarch/telar/IndexDB.cpv  $
*/

// This class defines custom modal property sheet 
// CArchiveWizzard.
 // CArchiveWizzard has been customized to include
// a preview window.
 
#ifndef __ARCHIVEWIZZARD_H__
#define __ARCHIVEWIZZARD_H__

#include "ArchiveWizzardPage.h"
#include "ArchiveWizzardPreviewWnd.h"

/////////////////////////////////////////////////////////////////////////////
// CArchiveWizzard

class CArchiveWizzard : public CPropertySheet
{
	DECLARE_DYNAMIC(CArchiveWizzard)

// Construction
public:
	CArchiveWizzard(CWnd* pWndParent = NULL);

// Attributes
public:
	CArchiveWizzardPage1 m_Page1;
	CArchiveWizzardPage2 m_Page2;
	CArchiveWizzardPage3 m_Page3;
	CArchiveWizzardPage4 m_Page4;
	CArchiveWizzardPage5 m_Page5;
	CArchiveWizzardPage6 m_Page6;
	CArchiveWizzardPage7 m_Page7;
	CWnd *m_pWndParent;

// PropSheet Data
	int m_nVolumeSize;
	int m_nMethod;
	CString m_csTempFolder;
	int *m_pSelector;
	int m_nSelected;
	CStringArray m_csaFiles;


// Operations
public:
	//int DoModal();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CArchiveWizzard)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CArchiveWizzard();
		 virtual BOOL OnInitDialog();

// Generated message map functions
protected:
	//{{AFX_MSG(CArchiveWizzard)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

#endif	// __ARCHIVEWIZZARD_H__
