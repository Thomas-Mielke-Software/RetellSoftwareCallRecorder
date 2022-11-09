// ArchiveWizzardPreviewWnd.cpp : implementation file
//

#include "stdafx.h"
#include "resource.h"
#include "ArchiveWizzardPreviewWnd.h"

#ifdef _DEBUG
#undef THIS_FILE
static char BASED_CODE THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CArchiveWizzardPreviewWnd

CArchiveWizzardPreviewWnd::CArchiveWizzardPreviewWnd()
{
}

CArchiveWizzardPreviewWnd::~CArchiveWizzardPreviewWnd()
{
}


BEGIN_MESSAGE_MAP(CArchiveWizzardPreviewWnd, CWnd)
	//{{AFX_MSG_MAP(CArchiveWizzardPreviewWnd)
	ON_WM_PAINT()
	ON_WM_ERASEBKGND()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// CArchiveWizzardPreviewWnd message handlers

void CArchiveWizzardPreviewWnd::OnPaint() 
{
	// TODO: Add your custom preview paint code.
	// For an example, we are drawing a blue ellipse.

	CPaintDC dc(this); // device context for painting
	CRect rect;
	GetClientRect(rect);

	CBrush brushNew(RGB(0,0,255));
	CBrush* pBrushOld = dc.SelectObject(&brushNew);
	dc.Ellipse(rect);
	dc.SelectObject(pBrushOld);
}

BOOL CArchiveWizzardPreviewWnd::OnEraseBkgnd(CDC* pDC) 
{
	// Use the same background color as that of the dialog
	//  (property sheet).

	CWnd* pParentWnd = GetParent();
	HBRUSH hBrush = (HBRUSH)pParentWnd->SendMessage(WM_CTLCOLORDLG,
		(WPARAM)pDC->m_hDC, (LPARAM)pParentWnd->m_hWnd);
	CRect rect;
	GetClientRect(rect);
	pDC->FillRect(&rect, CBrush::FromHandle(hBrush));
	return TRUE;
}





	// add a preview window to the property sheet.
	CRect rectWnd;
	GetWindowRect(rectWnd);
	SetWindowPos(NULL, 0, 0,
		rectWnd.Width() + 100,
		rectWnd.Height(),
		SWP_NOMOVE | SWP_NOZORDER | SWP_NOACTIVATE);
	CRect rectPreview(rectWnd.Width() + 25, 25,
		rectWnd.Width()+75, 75);

	m_wndPreview.Create(NULL, NULL, WS_CHILD|WS_VISIBLE,
		rectPreview, this, 0x1000);

