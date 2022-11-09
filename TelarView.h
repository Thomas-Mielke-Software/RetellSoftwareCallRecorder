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

// TelarView.h : interface of the CTelarView class
//

#include "SuchfilterDlg.h"
#include "ArchiveWizzard.h"

#pragma once


class CTelarView : public CListView
{
protected: // create from serialization only
	CTelarView();
	DECLARE_DYNCREATE(CTelarView)

// Attributes
public:
	CTelarDoc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Implementation
public:
	virtual ~CTelarView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

    CRect           m_DragSourceRect;   // drag/drop source rectangle
                                        // maintained so that we don't
                                        // allow a drag/drop source to 
                                        // drop on itself 
	// Dialogs
	CSuchfilterDlg *suchfilter;
	CArchiveWizzard *archivewizzard;

	// Functions
//	void RefreshOrdner();
	void RefreshListe();
//	void OnSelchange(CWnd *child);
	void SetDragCursor(POINT dragpos);
	int  KopiereListeneintrag(CListCtrl *Source, int nSourceLBItem, CListCtrl *Dest, int nDestLBItem);
	void LoescheListeneintraege(CListCtrl *lb, int *pLBItem, int n);
	void DoDeleteEintrag(TMZeile *zeile);
	int  EinsortierenNachDatum(CTime *date, int begin, int end);
	BOOL MyMciSendString(LPCSTR cmd, char *ret, int retsize, HWND hWnd);
	TMZeile *SafeGetItemData(int n);
	void ResetItemData(int size);
	void SetItemData(int item, TMZeile *p);
	TMZeile *GetItemData(int item);
	void DeleteItemData(int item);

	int nLastSelection;
	BOOL bPlaying;
	BOOL bSeeking;
	long position;
	CString csKillTheFile;		// temporäres file - löschen z.B. wenn das programm verlassen wird
	CString csOrdner;			// Name der gerade geöffneten Ordners

	// ListCtrl management
	TMTabelle *pFolders;
	CIndexDB liste_index;
	int m_CurrentIndexType;		// IDXTYPE_FILE v IDXTYPE_ACCESS
	long m_CurrentIndexPosition;
	CIndexDB dest_index;		// for copy operations, see KopiereListeneintrag
	TMZeile **myItemData;		// for caching list elements
	int myItemDataSize;			// size of the cache 

	// CQuickList Listbox
	CImageList m_imgList;
	//CImageList m_imgLargeList;
	CImageList* m_DragImage;	

	// for drag&drop
	CListCtrl*  m_pDragList;		//Which ListCtrl we are dragging FROM
	CListCtrl*  m_pDropList;		//Which List we are dropping ON
	CImageList* m_pDragImage;	//For creating and managing the drag-image
	BOOL		m_bDragging;	//T during a drag operation
	int			m_nDragIndex;	//Index of selected item in the List we are dragging FROM
	int			m_nDropIndex;	//Index at which to drop item in the List we are dropping ON
	CWnd*		m_pDropWnd;		//Pointer to window we are dropping on (will be cast to CListCtrl* type)
	BOOL		m_bCopyDropeffect;	// TRUE=copy, FALSE=move

	// Button-Bitmaps
	CBitmap AddOrdnerBmp;
	CBitmap DelOrdnerBmp;
	CBitmap EditOrdnerBmp;
	CBitmap ArchiveOrdnerBmp;
	CBitmap Rew2Bmp;
	CBitmap RewBmp;
	CBitmap PlayBmp;
	CBitmap PauseBmp;
	CBitmap StopBmp;
	CBitmap FfBmp;
	CBitmap Ff2Bmp;
	CBitmap SuchenBmp;
	CBitmap ExportBmp;
	CBitmap EditBmp;
	CBitmap DeleteBmp;

	char m_szMyTitle[100];

// Generated message map functions
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	virtual void OnInitialUpdate();
	afx_msg void OnDestroy();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnDrawItem(int nIDCtl, LPDRAWITEMSTRUCT lpDrawItemStruct);
	afx_msg void OnMeasureItem(int nIDCtl, LPMEASUREITEMSTRUCT lpMeasureItemStruct);
	afx_msg int OnCompareItem(int nIDCtl, LPCOMPAREITEMSTRUCT lpCompareItemStruct);
	afx_msg void OnDeleteItem(int nIDCtl, LPDELETEITEMSTRUCT lpDeleteItemStruct);
	afx_msg void OnLvnDeleteitem(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnLvnBeginrdrag(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnLvnItemchanged(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnLvnBeginlabeledit(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnLvnEndlabeledit(NMHDR *pNMHDR, LRESULT *pResult);
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	virtual void DrawItem(LPDRAWITEMSTRUCT /*lpDrawItemStruct*/);
protected:
	virtual void OnUpdate(CView* /*pSender*/, LPARAM /*lHint*/, CObject* /*pHint*/);
};

#ifndef _DEBUG  // debug version in TelarView.cpp
inline CTelarDoc* CTelarView::GetDocument() const
   { return reinterpret_cast<CTelarDoc*>(m_pDocument); }
#endif

