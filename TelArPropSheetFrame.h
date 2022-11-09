/*	$Header:   D:/pvcsarch/telar/TelArPropSheetFrame.h_v   1.30   Dec 19 2007 17:27:28   tmielke  $
*
*	Beschreibung:
*     This file contains the mini-frame that controls modeless 
*     property sheet
*
*	TelArPropertyPage.cpp : implementation file
*	
*	$Log:   D:/pvcsarch/telar/TelArPropSheetFrame.h_v  $
* 
*    Rev 1.30   Dec 19 2007 17:27:28   tmielke
* Adaptions to Windows Vista
* 
*    Rev 1.29   Oct 11 2007 10:15:02   tmielke
* Made the soundcard recognition more flexible in case plug and play
* soundcards have switched places.
* 
*    Rev 1.28   Sep 21 2007 15:47:18   tmielke
* Added Dutch translations and some additional debug code.
* 
*    Rev 1.27   Aug 14 2007 14:09:06   tmielke
* v1.83 resolved issues with voice modems and other exotic audio devices.
* 
*    Rev 1.26   May 09 2007 10:23:42   tmielke
* Word wrap now also enabled for edit box in edit record entry dialog.
* Changed the 'Maximise on line signal' checkbox to a numeric value holding 
* the number of seconds before the window maximizes to prevent the software 
* from popping up if a noise sets the recording off. 
* Added an option 'Minimize after automatic recording'.
* Improved usability of options screen by using sliders and spin buttons.
* 
*    Rev 1.25   Nov 16 2006 14:59:44   tmielke
* v1.80 -- Resolves compatibility issues with Windows NT and 9X version. 
* (SHGetSpecialFolder now from redisributable shfolder.dll included in the 
* setup rather than shell32.dll)
* 
*    Rev 1.24   Nov 13 2006 13:26:20   tmielke
* v1.79 build 2100 -- final network licensable version
* 
*    Rev 1.23   Jun 12 2006 15:13:20   tmielke
* v1.78:
*  - If a recording has been done using a password, this password is required to delete the recording (#211)
* - Now using a word-wrap edit box for the notes field (#336)
* - Playback volume control added (#314)
* 
*    Rev 1.22   Nov 25 2005 01:32:16   tmielke
* v1.76: several bugfixes
* 
*    Rev 1.21   Nov 23 2005 16:11:18   tmielke
* v1.75 solves the following issues:
* - Master master password wasn't queried when opening the scr window by clicking on the icon in the start menu
* - the application window will now really get the focus when automatically opened with 'maximize on signal'
* - same with master password when window maximized after clicking on the system tray icon (but not when maximized with start menu icon)
* - crash after FTP update is now prohibited
* - the software will now start after setup if the check on the last setup screen is set.
* 
*    Rev 1.20   Nov 11 2005 09:50:58   tmielke
* v1.74 release
* New layout of the playback tab with tabular list, including in-field
* editing of name and reference (F2 key).
* Abandoned Microsoft database engine. The new index file is now more robust
* in multiuser environments.
* 
*    Rev 1.19   Jul 11 2005 08:52:32   tmielke
* v1.74 build 1632 (alphatest version)
* - SQLite index file
* - CListCtrls on playback tab
* - Workstations table support
* 
*    Rev 1.18   Jul 05 2005 01:50:18   tmielke
* improved performance & stability when copying or deleting recordings
* 
*    Rev 1.17   Jun 28 2005 01:46:24   tmielke
* v1.72 build 1250
* 
*    Rev 1.16   Jun 02 2005 01:30:26   tmielke
* v1.72 build 1207
* 
*    Rev 1.15   May 18 2005 13:47:10   tmielke
* v1.72 build 1200
* 
*    Rev 1.14   Mar 18 2005 16:11:58   tmielke
*  
* 
*    Rev 1.13   Mar 12 2005 07:08:30   tmielke
* v1.69
* 
*    Rev 1.12   Feb 22 2005 16:53:20   tmielke
* v1.67 build 960
* Added support for 957 Data Integration Linc to allow access in automatic recording mode.
* 
*    Rev 1.11   Nov 21 2004 01:29:14   tmielke
* v1.66 build 883
* 
*    Rev 1.10   Dec 04 2003 03:36:42   tmielke
* v1.66 buid 730 -- Database Index File Pre-Release
* 
*    Rev 1.9   Nov 18 2003 09:39:42   tmielke
* komisch, Workfile älter als Archive...
* Checkin anyway...
* 
*    Rev 1.8   Oct 03 2003 01:22:08   tmielke
* v1.65 build 572:
* - Added support for master password.
* - Fixed spelling of export message.
* - Fixed export with encryption level 0.
* 
* 
*    Rev 1.7   Sep 23 2003 01:48:02   tmielke
* v1.64 build 557 (improved control tone detection)
* 
*    Rev 1.6   Sep 12 2003 01:12:10   tmielke
*  
* 
*    Rev 1.5   Sep 11 2003 04:04:04   tmielke
*  
* 
*    Rev 1.4   Sep 04 2003 00:55:26   tmielke
* v1.64 build 514
* C: drive licensing problem solved
* added build count to better determine versions
* fixed problem with disk key licensing
* 
*    Rev 1.3   Aug 04 2003 00:34:58   tmielke
* v1.64
* 
*    Rev 1.2   Jun 09 2003 15:25:16   tmielke
* v1.63 final
* 
*    Rev 1.1   Oct 12 2002 00:43:32   tmielke
* - suppressed multiple popup of message box 'Couldn't start recording' and other
* - redesigned the applications frame window which should avoid problems with newer 
*   windows versions
* - fixed IRI recording
* 
*    Rev 1.0   Oct 08 2002 02:26:10   tmielke
* initial check-in
* 
*/



#ifndef __TELARPROPSHEETFRAME_H__
#define __TELARPROPSHEETFRAME_H__

#include "TelArPropertySheet.h"

/////////////////////////////////////////////////////////////////////////////
// CTelArPropSheetFrame frame

class CTelArPropSheetFrame : public CMiniFrameWnd
{
	DECLARE_DYNCREATE(CTelArPropSheetFrame)
//Construction
public:
	CTelArPropSheetFrame();

// Attributes
public:
	CTelArPropertySheet* m_pModelessPropSheet;

// Operations
public:
	void On_MYWM_NOTIFYICON(WPARAM wParam, LPARAM lParam);

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTelArPropSheetFrame)
	protected:
	virtual BOOL OnCommand(WPARAM wParam, LPARAM lParam);
	virtual LRESULT WindowProc(UINT message, WPARAM wParam, LPARAM lParam);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CTelArPropSheetFrame();

	// Generated message map functions
	//{{AFX_MSG(CTelArPropSheetFrame)
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSetFocus(CWnd* pOldWnd);
	afx_msg void OnActivate(UINT nState, CWnd* pWndOther, BOOL bMinimized);
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnDestroy();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
	HICON m_hIcon;
};

/////////////////////////////////////////////////////////////////////////////
#endif	// __TELARPROPSHEETFRAME_H__
