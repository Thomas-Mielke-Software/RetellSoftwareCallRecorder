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
*   Source file for the Drag/Drop enabled CListeDDListbox
*	and COrdnerDDListbox ListBox control classes.
*
*  Functions:  
*  
*        ----- CListBox derived class member functions -----
*  
*        CDDListBox:: Initialize() - Registers this window with OLE Dll's to 
*                                enable drag/drop
*        CDDListBox:: OnCreate() - Handles WM_CREATE message                                  
*        CDDListBox:: OnLButtonDown() - Handles WM_LBUTTONDOWN message
*        CDDListBox:: GetDragSourceRect() - Gets the drag source rectangle 
*                                       stored in the application view class
*        CDDListBox:: SetDragSourceRect() - Sets the drag source rectangle 
*                                       stored in the application view class
*                                       
*        ----- COleDropTarget derived class member functions -----
*                                                                                              
*        COleListBoxDropTarget:: COleListBoxDropTarget() - constructor 
*        COleListBoxDropTarget:: ~COleListBoxDropTarget() - destructor
*        COleListBoxDropTarget:: OnDragEnter() - Called by the OLE Dll's when 
*                                    drag/drop cursor enters edit control
*        COleListBoxDropTarget:: OnDragLeave() - Called by the OLE Dll's when
*                                    drag/drop cursor leaves edit control
*        COleListBoxDropTarget:: OnDragOver() - Called by the OLE Dll's when 
*                             drag/drop cursor is moved over edit control
*        COleListBoxDropTarget:: OnDrop() -  Called by the OLE Dll's when Drop
*                                        action occurs in edit control
*
*	$Log:   D:/pvcsarch/telar/ddlist.cpv  $
* 
*    Rev 1.46   Dec 19 2007 17:27:30   tmielke
* Adaptions to Windows Vista
* 
*    Rev 1.45   Oct 11 2007 10:15:02   tmielke
* Made the soundcard recognition more flexible in case plug and play
* soundcards have switched places.
* 
*    Rev 1.44   Sep 21 2007 15:47:18   tmielke
* Added Dutch translations and some additional debug code.
* 
*    Rev 1.43   Aug 14 2007 14:09:08   tmielke
* v1.83 resolved issues with voice modems and other exotic audio devices.
* 
*    Rev 1.42   May 09 2007 10:23:44   tmielke
* Word wrap now also enabled for edit box in edit record entry dialog.
* Changed the 'Maximise on line signal' checkbox to a numeric value holding 
* the number of seconds before the window maximizes to prevent the software 
* from popping up if a noise sets the recording off. 
* Added an option 'Minimize after automatic recording'.
* Improved usability of options screen by using sliders and spin buttons.
* 
*    Rev 1.41   Nov 16 2006 14:59:46   tmielke
* v1.80 -- Resolves compatibility issues with Windows NT and 9X version. 
* (SHGetSpecialFolder now from redisributable shfolder.dll included in the 
* setup rather than shell32.dll)
* 
*    Rev 1.40   Nov 13 2006 13:26:22   tmielke
* v1.79 build 2100 -- final network licensable version
* 
*    Rev 1.39   Jun 12 2006 15:13:22   tmielke
* v1.78:
*  - If a recording has been done using a password, this password is required to delete the recording (#211)
* - Now using a word-wrap edit box for the notes field (#336)
* - Playback volume control added (#314)
* 
*    Rev 1.38   Nov 25 2005 01:32:18   tmielke
* v1.76: several bugfixes
* 
*    Rev 1.37   Nov 23 2005 16:11:20   tmielke
* v1.75 solves the following issues:
* - Master master password wasn't queried when opening the scr window by clicking on the icon in the start menu
* - the application window will now really get the focus when automatically opened with 'maximize on signal'
* - same with master password when window maximized after clicking on the system tray icon (but not when maximized with start menu icon)
* - crash after FTP update is now prohibited
* - the software will now start after setup if the check on the last setup screen is set.
* 
*    Rev 1.36   Nov 11 2005 09:50:58   tmielke
* v1.74 release
* New layout of the playback tab with tabular list, including in-field
* editing of name and reference (F2 key).
* Abandoned Microsoft database engine. The new index file is now more robust
* in multiuser environments.
* 
*    Rev 1.35   Jul 11 2005 08:52:34   tmielke
* v1.74 build 1632 (alphatest version)
* - SQLite index file
* - CListCtrls on playback tab
* - Workstations table support
* 
*    Rev 1.34   Jul 05 2005 01:50:18   tmielke
* improved performance & stability when copying or deleting recordings
* 
*    Rev 1.33   Jun 28 2005 01:46:26   tmielke
* v1.72 build 1250
* 
*    Rev 1.32   Jun 02 2005 01:30:26   tmielke
* v1.72 build 1207
* 
*    Rev 1.31   May 18 2005 13:47:10   tmielke
* v1.72 build 1200
* 
*    Rev 1.30   Mar 18 2005 16:12:00   tmielke
*  
* 
*    Rev 1.29   Mar 12 2005 07:08:32   tmielke
* v1.69
* 
*    Rev 1.28   Feb 22 2005 16:53:22   tmielke
* v1.67 build 960
* Added support for 957 Data Integration Linc to allow access in automatic recording mode.
* 
*    Rev 1.27   Nov 21 2004 01:29:16   tmielke
* v1.66 build 883
* 
*    Rev 1.26   Sep 22 2004 05:20:34   tmielke
* v1.66 build 869 
* improved db-index file creation & cleaned up moving files
* 
*    Rev 1.25   Dec 04 2003 03:36:42   tmielke
* v1.66 buid 730 -- Database Index File Pre-Release
* 
*    Rev 1.24   Nov 18 2003 09:39:42   tmielke
* komisch, Workfile älter als Archive...
* Checkin anyway...
* 
*    Rev 1.23   Oct 03 2003 01:22:08   tmielke
* v1.65 build 572:
* - Added support for master password.
* - Fixed spelling of export message.
* - Fixed export with encryption level 0.
* 
* 
*    Rev 1.22   Sep 23 2003 01:48:04   tmielke
* v1.64 build 557 (improved control tone detection)
* 
*    Rev 1.21   Sep 12 2003 01:12:10   tmielke
*  
* 
*    Rev 1.20   Sep 11 2003 04:04:04   tmielke
*  
* 
*    Rev 1.19   Sep 04 2003 00:55:26   tmielke
* v1.64 build 514
* C: drive licensing problem solved
* added build count to better determine versions
* fixed problem with disk key licensing
* 
*    Rev 1.18   Aug 04 2003 00:34:58   tmielke
* v1.64
* 
*    Rev 1.17   Jun 09 2003 15:25:16   tmielke
* v1.63 final
* 
*    Rev 1.16   Apr 07 2003 09:53:18   tmielke
* pre release 28 - speeded up delete and move recordings
* 
*    Rev 1.15   Dec 15 2002 21:50:56   tmielke
* auto resore window, speeded up bulk deletion
* 
*    Rev 1.14   Jul 07 2002 05:14:44   tmielke
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
*    Rev 1.10   Nov 07 2001 02:08:14   tmielke
* v1.59 bugfix release
* 
*    Rev 1.9   Nov 06 2001 05:26:50   tmielke
* v1.58a
* 
*    Rev 1.8   Oct 12 2001 16:22:42   tmielke
* v1.58 bugfix wav export
* 
*    Rev 1.7   Sep 14 2001 04:12:30   
* v1.57
* 
*    Rev 1.6   06 Jun 2001 02:00:08   tmielke
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
*    Rev 1.1   19 Oct 2000 02:28:38   tmielke
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

#include "stdafx.h"                                     
#include "afxole.h"  
                     
#include "resource.h"
//#include "listddoc.h"
//#include "ddedit.h"
//#include "ddwnd.h"
//#include "ddlist.h"
#include "TelArPropertyPage.h"

//#include "listvw.h"                        
//#include "listdrag.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif 


/////////////////////////////////////////////////////////////////////////////
// CDDListBox

BEGIN_MESSAGE_MAP(CDDListBox, CListBox)
    //{{AFX_MSG_MAP(CDDListBox)
    ON_WM_CREATE()
    ON_WM_LBUTTONDOWN()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()                       

/////////////////////////////////////////////////////////////////////////////
// ****
// This member calls the Register method of m_DropTarget to register
// this control as a drop target with the OLE dll's. We need to call 
// this method in the CFormView::OnInitialUpdate for controls created 
// by a dialog template since the OnCreate does not get called for 
// template created controls (this is because the windows controls 
// get created before the CWnd wrappers).
// *****
void CDDListBox::Initialize()
{   
    // Register the COleDropTarget object with the OLE dll's
    BOOL success = m_DropTarget.Register(this);
    if(!success )
      MessageBox("Ole Register Drop Target Failed");     
}                                                                             

/////////////////////////////////////////////////////////////////////////////
// CDDListBox message handlers

//*****
// This only gets called for dynamically created controls. For controls
// created by a dialog template, Initialize() must be called in the 
// OnInitialUpdate method of the CFormView.
//*****

int CDDListBox::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
    if (CWnd::OnCreate(lpCreateStruct) == -1)           
        return -1;                                      
        
    // Register the COleDropTarget object with the OLE dll's
    BOOL success = m_DropTarget.Register(this);
    
    if(!success ) 
      {
      MessageBox("Ole Register Drop Target Failed");     
      return -1;
      }
 
    return 0;
}

//*****
// This implementation of a drag/drop list box breaks one listbox 
// standard effect. In a normal list box, you can hold down the left
// mouse button and scroll through the various listbox items. The 
// button down message starts drag/drop in this implementation, 
// selection scrolling with the lbuttondown is not implemented here.
//*****
void CDDListBox::OnLButtonDown(UINT nFlags, CPoint point)
{     
    // Let Base class do default message processing    
    CListBox::OnLButtonDown(nFlags, point); 
    
	// Any items selected?
	if (GetSelCount() < 1) return;
 
    // Create global memory for sharing dragdrop text
    HGLOBAL hgData=GlobalAlloc(GPTR,sizeof(MyDragItem));   
    ASSERT(hgData!=NULL);
    
    MyDragItem *lpData=(MyDragItem *)GlobalLock(hgData);
    ASSERT(lpData!=NULL);
                                                 
    lpData->cddlbListBox = this;	// just copy all selected items of this listbox
    
    // Cache the data, and initiate DragDrop
    m_COleDataSource.CacheGlobalData(CF_MYCLIPBOARDFORMAT, hgData);           
    
    // Set drag/drop source rectangle (screen coord)
    SetDragSourceRect();
    
    DROPEFFECT dropEffect
    =m_COleDataSource.DoDragDrop(DROPEFFECT_COPY|DROPEFFECT_MOVE,NULL);  
          
    if((dropEffect&DROPEFFECT_MOVE)==DROPEFFECT_MOVE)     
    {
		int n;

		n = GetSelCount();
		int *items;
		items = new int[n];
		if (GetSelItems(n, items) == LB_ERR) { delete items; return; }

//		((CTelArPropertyPage2*)GetParent())->LoescheListeneintraege(this, items, n);
		
		((CTelArPropertyPage2*)GetParent())->OnSelchange(this);

		delete items;
    }
          
    // We need to send WM_LBUTTONUP to control or else the selection rectangle 
    // will "follow" the mouse (like when you hold the left mouse down and 
    // scroll through a regular listbox). WM_LBUTTONUP was sent to window that 
    // recieved the drag/drop, not the one that initiated it, so we simulate
    // an WM_LBUTTONUP to the initiating window.
    LPARAM lparam;
    
    // "Pack" lparam with x and y coordinates where lbuttondown originated
    lparam=point.y; 
    lparam=lparam<<16;
    lparam &= point.x;                         
    
    SendMessage(WM_LBUTTONUP,0,lparam);
   
    // Clear the Data Source's cache
    m_COleDataSource.Empty();
	
	((CTelArPropertyPage2*)GetParent())->OnSelchange(this);
}                          

CRect CDDListBox::GetDragSourceRect()
{   
    // return the drag/drop source rect (maintained in view class)
    return ((CTelArPropertyPage2*)GetParent())->m_DragSourceRect;
}

void CDDListBox::SetDragSourceRect()
{                                                            
    CRect ListWindowRect;
    
    GetWindowRect(&ListWindowRect);
    
    // Set drag/drop source rectangle (screen coord)
    //  (maintained in the view class)
    ((CTelArPropertyPage2*)GetParent())->m_DragSourceRect=ListWindowRect;    
}

/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
// COleListBoxDropTarget - Enable OLE dragdrop for the ListBox control

COleListBoxDropTarget::COleListBoxDropTarget() {}

COleListBoxDropTarget::~COleListBoxDropTarget() {}

//
// OnDragEnter is called by OLE dll's when drag cursor enters
// a window that is REGISTERed with the OLE dll's
//
DROPEFFECT COleListBoxDropTarget::OnDragEnter(CWnd* pWnd, COleDataObject* 
           pDataObject, DWORD dwKeyState, CPoint point )
{   
	CPoint clientpoint = point;

    // If point is inside of the source list box, don't 
    // allow a drop                             
    pWnd->ClientToScreen(&point);   // convert client point to screen point
    
    if(((CDDListBox*)pWnd)->GetDragSourceRect().PtInRect(point))
        return DROPEFFECT_NONE;
                 
	BOOL bOutside;
	int nDestLBItem = (int)((CDDListBox*)pWnd)->ItemFromPoint(clientpoint, bOutside);
	if (bOutside) 
		return DROPEFFECT_NONE;

    // Check if the Control key was pressed
    if((dwKeyState&MK_CONTROL) == MK_CONTROL)
        return DROPEFFECT_COPY; // copy source text
    else
        return DROPEFFECT_MOVE; // move source text   
}

//
// OnDragLeave is called by OLE dll's when drag cursor leaves
// a window that is REGISTERed with the OLE dll's
//
void COleListBoxDropTarget::OnDragLeave(CWnd* pWnd)
{
    // Call base class implementation
    COleDropTarget:: OnDragLeave(pWnd);
}

// 
// OnDragOver is called by OLE dll's when cursor is dragged over 
// a window that is REGISTERed with the OLE dll's
//
DROPEFFECT COleListBoxDropTarget::OnDragOver(CWnd* pWnd, COleDataObject* 
           pDataObject, DWORD dwKeyState, CPoint point )
{                              
	CPoint clientpoint = point;

    // If point is inside of the source list box, don't 
    // allow a drop                                                        
    pWnd->ClientToScreen(&point);   // convert client to screen 
    if(((CDDListBox*)pWnd)->GetDragSourceRect().PtInRect(point))
        return DROPEFFECT_NONE;
        
	BOOL bOutside;
	int nDestLBItem = (int)((CDDListBox*)pWnd)->ItemFromPoint(clientpoint, bOutside);
	if (bOutside) 
		return DROPEFFECT_NONE;

    if((dwKeyState&MK_CONTROL) == MK_CONTROL)
        return DROPEFFECT_COPY;
    else
        return DROPEFFECT_MOVE;    
}

// 
// OnDrop is called by OLE dll's when item is dropped in a window
// that is REGISTERed with the OLE dll's
//
BOOL COleListBoxDropTarget::OnDrop(CWnd* pWnd, COleDataObject* pDataObject, 
                 DROPEFFECT dropEffect, CPoint point )
{           
    HGLOBAL		hGlobal;
    MyDragItem *pData;
    int			ErrCode;
	CPoint clientpoint = point;

    // Get text data from COleDataObject
    hGlobal=pDataObject->GetGlobalData(CF_MYCLIPBOARDFORMAT);

    // Get pointer to data
    pData=(MyDragItem *)GlobalLock(hGlobal);    
    ASSERT(pData!=NULL); 

	BOOL bOutside;
	int nDestLBItem = (int)((CDDListBox*)pWnd)->ItemFromPoint(clientpoint, bOutside);
	if (bOutside) 
		ErrCode = FALSE;
	else
	// Transfer data between listboxes
	{
		int i, n;

		n = pData->cddlbListBox->GetSelCount();
		int *items;
		items = new int[n];
		if (pData->cddlbListBox->GetSelItems(n, items) == LB_ERR) { n = -1; ErrCode = FALSE; }

		HCURSOR oldCursor = SetCursor(LoadCursor(NULL, IDC_WAIT));

		for (i = 0; i < n; i++)
		{
//%%			ErrCode = ((CTelArPropertyPage2*)(((CDDListBox*)pWnd)->GetParent()))
//%%				->KopiereListeneintrag(pData->cddlbListBox, items[i], (CDDListBox*)pWnd, nDestLBItem);
			if (ErrCode == FALSE) break;
		}

		SetCursor(oldCursor);

		{
			CString cs;
			cs.Format("%d entries successfully copied", n);
			((CTelArPropertyPage2*)(((CDDListBox*)pWnd)->GetParent()))->liste_index.AppendAccesslog("Copy", TRUE, cs.GetBuffer(0));
		}

		delete items;
	}

    // Unlock memory
    GlobalUnlock(hGlobal);

    return ErrCode;
}

/////////////////////////////////////////////////////////////////////////////
// 

/////////////////////////////////////////////////////////////////////////////
// CListeDDListbox

CListeDDListbox::CListeDDListbox()
{
}

CListeDDListbox::~CListeDDListbox()
{
}


BEGIN_MESSAGE_MAP(CListeDDListbox, CDDListBox)
	//{{AFX_MSG_MAP(CListeDDListbox)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CListeDDListbox message handlers

//void CListeDDListbox::OnSelchange() 
//{
//	((CTelArPropertyPage2*)GetParent())->OnSelchangeListe();
//}
/////////////////////////////////////////////////////////////////////////////
// COrdnerDDListbox

COrdnerDDListbox::COrdnerDDListbox()
{
}

COrdnerDDListbox::~COrdnerDDListbox()
{
}


BEGIN_MESSAGE_MAP(COrdnerDDListbox, CDDListBox)
	//{{AFX_MSG_MAP(COrdnerDDListbox)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// COrdnerDDListbox message handlers

