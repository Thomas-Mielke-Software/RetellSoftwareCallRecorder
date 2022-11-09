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
*	Beschreibung:
*   Header file which contains declarations for the 
*   COleListBoxDropTarget class, and the CDDList class
*	+ derived CListeDDListbox and COrdnerDDListbox classes.
*	
*	$Log:   D:/pvcsarch/telar/ddlist.h_v  $
* 
*    Rev 1.43   Dec 19 2007 17:27:30   tmielke
* Adaptions to Windows Vista
* 
*    Rev 1.42   Oct 11 2007 10:15:02   tmielke
* Made the soundcard recognition more flexible in case plug and play
* soundcards have switched places.
* 
*    Rev 1.41   Sep 21 2007 15:47:18   tmielke
* Added Dutch translations and some additional debug code.
* 
*    Rev 1.40   Aug 14 2007 14:09:08   tmielke
* v1.83 resolved issues with voice modems and other exotic audio devices.
* 
*    Rev 1.39   May 09 2007 10:23:44   tmielke
* Word wrap now also enabled for edit box in edit record entry dialog.
* Changed the 'Maximise on line signal' checkbox to a numeric value holding 
* the number of seconds before the window maximizes to prevent the software 
* from popping up if a noise sets the recording off. 
* Added an option 'Minimize after automatic recording'.
* Improved usability of options screen by using sliders and spin buttons.
* 
*    Rev 1.38   Nov 16 2006 14:59:46   tmielke
* v1.80 -- Resolves compatibility issues with Windows NT and 9X version. 
* (SHGetSpecialFolder now from redisributable shfolder.dll included in the 
* setup rather than shell32.dll)
* 
*    Rev 1.37   Nov 13 2006 13:26:22   tmielke
* v1.79 build 2100 -- final network licensable version
* 
*    Rev 1.36   Jun 12 2006 15:13:22   tmielke
* v1.78:
*  - If a recording has been done using a password, this password is required to delete the recording (#211)
* - Now using a word-wrap edit box for the notes field (#336)
* - Playback volume control added (#314)
* 
*    Rev 1.35   Nov 25 2005 01:32:18   tmielke
* v1.76: several bugfixes
* 
*    Rev 1.34   Nov 23 2005 16:11:20   tmielke
* v1.75 solves the following issues:
* - Master master password wasn't queried when opening the scr window by clicking on the icon in the start menu
* - the application window will now really get the focus when automatically opened with 'maximize on signal'
* - same with master password when window maximized after clicking on the system tray icon (but not when maximized with start menu icon)
* - crash after FTP update is now prohibited
* - the software will now start after setup if the check on the last setup screen is set.
* 
*    Rev 1.33   Nov 11 2005 09:50:58   tmielke
* v1.74 release
* New layout of the playback tab with tabular list, including in-field
* editing of name and reference (F2 key).
* Abandoned Microsoft database engine. The new index file is now more robust
* in multiuser environments.
* 
*    Rev 1.32   Jul 11 2005 08:52:34   tmielke
* v1.74 build 1632 (alphatest version)
* - SQLite index file
* - CListCtrls on playback tab
* - Workstations table support
* 
*    Rev 1.31   Jul 05 2005 01:50:18   tmielke
* improved performance & stability when copying or deleting recordings
* 
*    Rev 1.30   Jun 28 2005 01:46:26   tmielke
* v1.72 build 1250
* 
*    Rev 1.29   Jun 02 2005 01:30:26   tmielke
* v1.72 build 1207
* 
*    Rev 1.28   May 18 2005 13:47:10   tmielke
* v1.72 build 1200
* 
*    Rev 1.27   Mar 18 2005 16:12:00   tmielke
*  
* 
*    Rev 1.26   Mar 12 2005 07:08:32   tmielke
* v1.69
* 
*    Rev 1.25   Feb 22 2005 16:53:22   tmielke
* v1.67 build 960
* Added support for 957 Data Integration Linc to allow access in automatic recording mode.
* 
*    Rev 1.24   Nov 21 2004 01:29:16   tmielke
* v1.66 build 883
* 
*    Rev 1.23   Dec 04 2003 03:36:42   tmielke
* v1.66 buid 730 -- Database Index File Pre-Release
* 
*    Rev 1.22   Nov 18 2003 09:39:42   tmielke
* komisch, Workfile älter als Archive...
* Checkin anyway...
* 
*    Rev 1.21   Oct 03 2003 01:22:08   tmielke
* v1.65 build 572:
* - Added support for master password.
* - Fixed spelling of export message.
* - Fixed export with encryption level 0.
* 
* 
*    Rev 1.20   Sep 23 2003 01:48:04   tmielke
* v1.64 build 557 (improved control tone detection)
* 
*    Rev 1.19   Sep 12 2003 01:12:10   tmielke
*  
* 
*    Rev 1.18   Sep 11 2003 04:04:04   tmielke
*  
* 
*    Rev 1.17   Sep 04 2003 00:55:26   tmielke
* v1.64 build 514
* C: drive licensing problem solved
* added build count to better determine versions
* fixed problem with disk key licensing
* 
*    Rev 1.16   Aug 04 2003 00:34:58   tmielke
* v1.64
* 
*    Rev 1.15   Jun 09 2003 15:25:16   tmielke
* v1.63 final
* 
*    Rev 1.14   Jul 07 2002 05:14:46   tmielke
* Multi-select listbox
* 
*    Rev 1.13   Jun 05 2002 19:31:54   tmielke
* v1.62
* 
*    Rev 1.12   May 05 2002 11:56:16   tmielke
* added machine name to subject line when requesting code via MAPI
* auto-inserted separators in search screen
* 
*    Rev 1.11   Mar 15 2002 20:21:52   tmielke
* v1.60
* 
*    Rev 1.10   Nov 07 2001 02:08:16   tmielke
* v1.59 bugfix release
* 
*    Rev 1.9   Nov 06 2001 05:26:52   tmielke
* v1.58a
* 
*    Rev 1.8   Oct 12 2001 16:22:42   tmielke
* v1.58 bugfix wav export
* 
*    Rev 1.7   Sep 14 2001 04:12:30   
* v1.57
* 
*    Rev 1.6   06 Jun 2001 02:00:10   tmielke
* offizielle release 1.55
* 
*    Rev 1.5   17 May 2001 02:01:06   tmielke
* v1.54
* 
*    Rev 1.4   12 Feb 2001 19:36:48   tmielke
* v1.53
* 
*    Rev 1.3   20 Dec 2000 18:18:20   tmielke
* letzter check-in der VC++ 4.2 Version vor Wechsel auf Defeloper Studio 6.0
* 
*    Rev 1.2   04 Dec 2000 02:22:52   tmielke
* v1.52
* TPT-Anpassungen: Fernsteuerung, Folder scannen, Passwortsperre
* 
*    Rev 1.1   19 Oct 2000 02:28:40   tmielke
* v1.51:
* - ALC
* Wenn Hauptfenster minimized, progress bar nicht anzeigen
* wav-Dateien löschen beim Abbruch der Aufzeichnung
* Nullabgleich beim Signal
* (v1.50 war alles von dem 1.8.00)
* 
* 
*    Rev 1.0   21 Jun 2000 05:35:54   tmielke
* Drag-and-drop basics eingebaut
*
*
*/

/////////////////////////////////////////////////////////////////////////////
// COleListBoxDropTarget window

class COleListBoxDropTarget : public COleDropTarget
{
// Construction 
public:
    COleListBoxDropTarget();

// Implementation
public:
    virtual ~COleListBoxDropTarget();   
    
   //
   // These members MUST be overridden for an OLE drop target
   // See DRAG and DROP section of OLE classes reference
   //
   DROPEFFECT OnDragEnter(CWnd* pWnd, COleDataObject* pDataObject, DWORD 
                                                dwKeyState, CPoint point );
   DROPEFFECT OnDragOver(CWnd* pWnd, COleDataObject* pDataObject, DWORD 
                                               dwKeyState, CPoint point );
   void OnDragLeave(CWnd* pWnd);               
   
   BOOL OnDrop(CWnd* pWnd, COleDataObject* pDataObject, DROPEFFECT 
                                          dropEffect, CPoint point );
};

/////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////
// CDDListBox window

class CDDListBox : public CListBox
{
// Attributes      
private:    
    // Needed to make this control an OLE data SOURCE (see OnLButtonDown)
    COleDataSource m_COleDataSource;
     
public:     

// Operations
public:   
    //*****   
    // Initialization method REQUIRED for controls created by a dialog
    // template Dynamically created controls are initialized in the 
    // OnCreate. OnCreate is not called for controls created by a 
    // template since the Windows controls are created before the 
    // CWnd objects
    //*****
    void Initialize();
    
    // Get and set the source rectangle for drag/drop operation
    void  SetDragSourceRect();
    CRect GetDragSourceRect();

// Implementation
public:
    //*****
    // COleListBoxDropTarget, derived from COleDropTarget gives us
    // the functionality to be an OLE drop target.
    // COleListBoxDropTarget.Register() must be called to register 
    // the CWnd as an OLE drop target. 
    //*****
    COleListBoxDropTarget m_DropTarget;

protected:
    // Generated message map functions
    //{{AFX_MSG(CDDListBox)
    afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
    afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	//}}AFX_MSG
    DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////
// CListeDDListbox window

class CListeDDListbox : public CDDListBox
{
// Construction
public:
	CListeDDListbox();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CListeDDListbox)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CListeDDListbox();

	// Generated message map functions
protected:
	//{{AFX_MSG(CListeDDListbox)
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
// COrdnerDDListbox window

class COrdnerDDListbox : public CDDListBox
{
// Construction
public:
	COrdnerDDListbox();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(COrdnerDDListbox)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~COrdnerDDListbox();

	// Generated message map functions
protected:
	//{{AFX_MSG(COrdnerDDListbox)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

#define CF_MYCLIPBOARDFORMAT (CF_PRIVATEFIRST + 0xce)

class MyDragItem 
{
public:
	CDDListBox *cddlbListBox;	// Source listbox
}; 
