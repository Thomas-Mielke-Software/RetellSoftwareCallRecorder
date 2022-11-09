
// TelarView.cpp : implementation of the CTelarView class
//

#include "stdafx.h"
#include <mmsystem.h>

#include "Telar.h"
#include "TelarDoc.h"
#include "TelarView.h"

#include "PasswortCheckDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CTelarView

IMPLEMENT_DYNCREATE(CTelarView, CListView)

BEGIN_MESSAGE_MAP(CTelarView, CListView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CTelarView::OnFilePrintPreview)
	ON_WM_CREATE()
	ON_WM_DESTROY()
	ON_WM_TIMER()
	ON_WM_DRAWITEM()
	ON_WM_MEASUREITEM()
	ON_WM_COMPAREITEM()
	ON_WM_DELETEITEM()
	ON_NOTIFY_REFLECT(LVN_DELETEITEM, &CTelarView::OnLvnDeleteitem)
	ON_NOTIFY_REFLECT(LVN_BEGINRDRAG, &CTelarView::OnLvnBeginrdrag)
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
	ON_NOTIFY_REFLECT(LVN_ITEMCHANGED, &CTelarView::OnLvnItemchanged)
	ON_NOTIFY_REFLECT(LVN_BEGINLABELEDIT, &CTelarView::OnLvnBeginlabeledit)
	ON_NOTIFY_REFLECT(LVN_ENDLABELEDIT, &CTelarView::OnLvnEndlabeledit)
END_MESSAGE_MAP()

// CTelarView construction/destruction

CTelarView::CTelarView()
{
	suchfilter = NULL;
	archivewizzard = NULL;
	nLastSelection = -1;
	csKillTheFile = "";
	csOrdner = C_standard_ordner;
	myItemData = NULL;
	myItemDataSize = 0;
	
	// drag&frop init
	m_bDragging = false;
	m_nDragIndex = -1;
	m_nDropIndex = -1;
	m_pDragImage = NULL;
	m_bCopyDropeffect = FALSE;

	pFolders = new TMTabelle(FOLDERS_FILEMAGIC, FOLDERS_FILECOLUMNS, FOLDERS_FILEVERSION);
}

CTelarView::~CTelarView()
{
}

BOOL CTelarView::PreCreateWindow(CREATESTRUCT& cs)
{
	cs.style |= LVS_OWNERDATA | LVS_OWNERDRAWFIXED | LVS_EDITLABELS | LVS_NOSORTHEADER | LVS_SHOWSELALWAYS | LVS_REPORT;

	return CListView::PreCreateWindow(cs);
}

// CTelarView drawing

void CTelarView::OnDraw(CDC* /*pDC*/)
{
	CTelarDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CTelarView printing


void CTelarView::OnFilePrintPreview()
{
	AFXPrintPreview(this);
}

BOOL CTelarView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CTelarView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CTelarView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CTelarView::OnRButtonUp(UINT nFlags, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CTelarView::OnContextMenu(CWnd* pWnd, CPoint point)
{
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
}


// CTelarView diagnostics

#ifdef _DEBUG
void CTelarView::AssertValid() const
{
	CListView::AssertValid();
}

void CTelarView::Dump(CDumpContext& dc) const
{
	CListView::Dump(dc);
}

CTelarDoc* CTelarView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTelarDoc)));
	return (CTelarDoc*)m_pDocument;
}
#endif //_DEBUG


// CTelarView message handlers


// --- INIT / DESTROY / TIMER ---


int CTelarView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	return 0;
}

void CTelarView::OnInitialUpdate()
{
	CListView::OnInitialUpdate();

	ListView_SetExtendedListViewStyleEx(GetListCtrl().m_hWnd, LVS_EX_FULLROWSELECT, LVS_EX_FULLROWSELECT);
	ListView_SetExtendedListViewStyleEx(GetListCtrl().m_hWnd, LVS_EX_SUBITEMIMAGES , LVS_EX_SUBITEMIMAGES );
	//ListView_SetExtendedListViewStyleEx(GetListCtrl().m_hWnd, LVS_EX_TRACKSELECT, LVS_EX_TRACKSELECT );
	ListView_SetExtendedListViewStyleEx(GetListCtrl().m_hWnd, LVS_EX_CHECKBOXES, LVS_EX_CHECKBOXES );
	
	m_imgList.Create(IDB_IMAGE_LIST, 16, ILC_COLOR4, RGB(255, 255, 255));
	//m_imgLargeList.Create(IDB_IMAGE_LIST_LARGE, 32, ILC_COLOR4, RGB(255, 255, 255));

	//GetListCtrl().SetBackgroundColor(RGB(255,255,255));

	GetListCtrl().SetImageList(&m_imgList, LVSIL_SMALL);

	char buffer[1000];
	LANG2BUFFER(IDS_STRING187, buffer);
	GetListCtrl().InsertColumn(0, buffer, LVCFMT_LEFT, 23);		// ID
	LANG2BUFFER(IDS_STRING188, buffer);
	GetListCtrl().InsertColumn(1, buffer, LVCFMT_LEFT, 110);	// Date/Time
	LANG2BUFFER(IDS_STRING189, buffer);
	GetListCtrl().InsertColumn(2, buffer, LVCFMT_LEFT, 50);		// Dur.
	LANG2BUFFER(IDS_STRING125, buffer);
	GetListCtrl().InsertColumn(3, buffer, LVCFMT_LEFT, 70);		// Reference
	LANG2BUFFER(IDS_STRING126, buffer);
	GetListCtrl().InsertColumn(4, buffer, LVCFMT_LEFT, 121);		// Note

/*
#ifndef QUICKLIST_NOEMPTYMESSAGE	
	char empmessbuf[1000];
	LANG2BUFFER(IDS_STRING186, empmessbuf);
	CString csEmpMessBuf = empmessbuf;
	GetListCtrl().SetEmptyMessage(csEmpMessBuf);
#endif
*/
	GetListCtrl().EnableToolTips(TRUE);

	liste_index.Close();
	if (dest_index.IsOpen()) dest_index.Close();

//XXX	if (bPlaying) OnStop();

	ResetItemData(0);	// clear ListCtrl cache	
	RefreshListe();

	//SetDlgItemText(IDC_FILE, "File: ");
	KillTimer(1);

	if (suchfilter)
	{
		suchfilter->DestroyWindow();
		if (suchfilter) delete suchfilter; 
		suchfilter = NULL;
	}

	if (archivewizzard)
	{
		archivewizzard->DestroyWindow();
		if (archivewizzard) delete archivewizzard; 
		archivewizzard = NULL;
	}
}


void CTelarView::OnUpdate(CView* /*pSender*/, LPARAM /*lHint*/, CObject* /*pHint*/)
{
	RefreshListe();
}


void CTelarView::OnDestroy()
{
	CListView::OnDestroy();

	DF("CTelarView::OnDestroy()");

	liste_index.Close();
	if (dest_index.IsOpen()) dest_index.Close();

//XXX	if (bPlaying) OnStop();

	ResetItemData(0);	// clear ListCtrl cache

	//SetDlgItemText(IDC_FILE, "File: ");
	KillTimer(1);

	if (suchfilter)
	{
		suchfilter->DestroyWindow();
		if (suchfilter) delete suchfilter; 
		suchfilter = NULL;
	}

	if (archivewizzard)
	{
		archivewizzard->DestroyWindow();
		if (archivewizzard) delete archivewizzard; 
		archivewizzard = NULL;
	}
}

void CTelarView::OnTimer(UINT_PTR nIDEvent) 
{
	DFTICK("T");

	switch (nIDEvent)
	{
	case 1:
		{
			DFTICK("1");
			if (bPlaying)
			{
				char buf[30], buf2[60];
				long l,h,m,s;
				MyMciSendString("status s1 position",buf,sizeof(buf),m_hWnd);
				l = atol(buf) / 1000;
				s = l % 60;
				m = (l / 60) % 60;
				h = (l / 3600);
			
				sprintf(buf2,"%02ld:%02ld:%02ld", h, m, s);
				SetDlgItemText(IDC_POSITION, buf2);
				((CSliderCtrl *)GetDlgItem(IDC_SLIDER))->SetPos(l);

				MyMciSendString("status s1 mode",buf,sizeof(buf),m_hWnd);
				if (!strcmp(buf, "stopped") && bPlaying && !bSeeking)
				{
					MyMciSendString("close s1",buf,sizeof(buf),m_hWnd);
					bPlaying = FALSE;
					if (csKillTheFile != "") 
					{
						DeleteFile(csKillTheFile);
						csKillTheFile = "";

						DF("OnTimer KillTheFile (nIDEvent == 1)");
					}
				}
			}
			else
			{
				SetDlgItemText(IDC_POSITION, "00:00:00");
				((CSliderCtrl *)GetDlgItem(IDC_SLIDER))->SetPos(0);			
			}
		}	
		break;
	
	case 2:
		{
			DFTICK("2");
			char buf[30];
			MyMciSendString("play s1",buf,sizeof(buf),m_hWnd);
			bSeeking = FALSE;
			KillTimer(2);
			KillTimer(1);
			SetTimer(1, 100, NULL);
		}
		break;

	case 3:
		if (X_AutomatischLoeschen && csOrdner == C_standard_ordner)
		{
			DFTICK("3");
			if (GetListCtrl().GetItemCount())
			{
				TMZeile *p;
				CTime now = now.GetCurrentTime(), ctBirth;
				CTimeSpan ctsAge;
				CString csDate, csTime;

				p = SafeGetItemData(0);	// Get first element of recordings list

				// item older than allowed? (number of days in X_AutomatischLoeschen)
				if (p)
				{
					csDate = p->Spalte(SPID_DATUM);
					csTime = p->Spalte(SPID_ZEIT);
					if (String2CTime(csDate, csTime, ctBirth))
					{
						ctsAge = now - ctBirth;
						if (ctsAge.GetDays() > X_AutomatischLoeschen)
						{
							POSITION pos = GetListCtrl().GetFirstSelectedItemPosition();
							if (pos)
								nLastSelection = GetListCtrl().GetNextSelectedItem(pos);
							else
								nLastSelection = -1;

							int i;
							for (i = 1; i < GetListCtrl().GetItemCount(); i++)
							{
								GetListCtrl().SetItemState(i-1, GetListCtrl().GetItemState(i, 0xffffffff), 0xffffffff);
								GetListCtrl().SetRedraw(TRUE);
							}

							if (nLastSelection > 0) 
								nLastSelection--;

							DoDeleteEintrag(p);
		
							RefreshListe();

							break;
						}
					}
				}
			}
		}
		break;
	}

	CListView::OnTimer(nIDEvent);
}


// --- ListCtrl MANAGEMENT ---

/*XXX
void CTelarView::OnSelchangeListe() 
{
	DF("CTelarView::OnSelchangeListe()");

	//TMZeile *zeile = theTabelle.Find(SPID_DATEINAME, CString &suchstring)

	int n = GetListCtrl( ).GetItemCount();
	if (n == LB_ERR || !n)
	{
		SetDlgItemText(IDC_NOTIZEN_OUTPUT, (CString)"");
		return;
	}

	CString cs;

	POSITION p = GetListCtrl().GetFirstSelectedItemPosition();
	if (p)
	{
		int nSelected = GetListCtrl().GetNextSelectedItem(p);
		nLastSelection = nSelected;
		TMZeile *zeile = SafeGetItemData(nSelected);

		if (zeile)
			cs = zeile->Spalte(SPID_NOTIZEN);			
	}

	// allways maintain itemdata for selected list entries in case they are being deleted or moved
	while (p)
	{
		int nSelected = GetListCtrl().GetNextSelectedItem(p);
		TMZeile *zeile = SafeGetItemData(nSelected);
	}

	SetDlgItemText(IDC_NOTIZEN_OUTPUT, cs);
}
*/
void CTelarView::RefreshListe()
{
	DF("CTelarView::RefreshListe()");

	char pathfile[1000];
	
//XXX	TMZeile *p = pFolders->Find(0, csOrdner);
//XXX	if (!p)
	strncpy(pathfile, G_CurrentPath, sizeof(pathfile));
//XXX	else
//XXX		strcpy(pathfile, (LPCSTR)p->Spalte(1));

	int file_version = INDEX_FILEVERSION;
	
	if (*pathfile && pathfile[strlen(pathfile)-1] != '\\')
		strcat(pathfile, "\\");
	strcat(pathfile, INDEX_FILENAME);

	//GetListCtrl( ).DeleteAllItems();	not needed in virtual listbox
	GetListCtrl().EnableToolTips(TRUE);

	if (IsOldStyleIndexFile(pathfile))
	{
		if (theTabelle.Read(pathfile, &file_version, FALSE))
		{
			DF("Old-style index file opened");

//			int TabStopArray[] = { 15, 170, 180, 190, 200 };
//			((CListBox *)GetDlgItem(IDC_LISTE))->SetTabStops(sizeof(TabStopArray)/sizeof(TabStopArray[0]), TabStopArray);

			// reserve some space before we know the number of items
			GetListCtrl().LockWindowUpdate();
			GetListCtrl().SetItemCount(100000);
			ResetItemData(100000);
			m_CurrentIndexType = IDXTYPE_FILE;

			int nItemCount = 0;

			TMZeile *p = theTabelle.tabelle;
			char str[100000];

			// Suchfilter
			CString sid;
			CString sge;	
			CString sno;	
			CString sdv;	
			CString sdb;	
			CString szv;	
			CString szb;	
			CString smindau;		
			CString smaxdau;
			
			if (suchfilter && suchfilter->IsWindowVisible())
			{
				sid = suchfilter->m_Identifikation;
				sge = suchfilter->m_Gespraechspartner;
				sno = suchfilter->m_Notizen;
				sdv = suchfilter->m_DatumVon;
				sdb = suchfilter->m_DatumBis;
				szv = suchfilter->m_ZeitVon;
				szb = suchfilter->m_ZeitBis;
				smindau = suchfilter->m_MinDauer;
				smaxdau = suchfilter->m_MaxDauer;
			}
			CTime ctDatumVon, ctDatumBis, ctDatum;
			
			while (p)
			{
				BOOL bDisplay = TRUE;

				CString tid = p->Spalte(SPID_INITIALEN);
				CString tge = p->Spalte(SPID_GESPRAECHSPARTNER);
				CString tno = p->Spalte(SPID_NOTIZEN);
				CString td = p->Spalte(SPID_DATUM);
				CString tz = p->Spalte(SPID_ZEIT);
				BOOL bValidDate = String2CTime(td, tz, ctDatum);

				if (suchfilter && suchfilter->IsWindowVisible())
				{
					bDisplay = FALSE;

					if (!szv.GetLength()) szv = "00:00";
					if (!szb.GetLength()) szb = "23:59";

					BOOL bCheckVon = FALSE, bCheckBis = FALSE;
					if (bValidDate)
					{
						bCheckVon = String2CTime(sdv, szv, ctDatumVon);
						bCheckBis = String2CTime(sdb, szb, ctDatumBis);
					}

					CString tdauer = p->Spalte(SPID_DAUER);

					// Dauer
					int nMindau, nMaxdau;
					BOOL bCheckMindau, bCheckMaxdau;
					if (!isdigit(*smindau) || !isdigit(smindau[1]) || smindau[2]!=':' || !isdigit(smindau[3]) || !isdigit(smindau[4])) 
						bCheckMindau = FALSE;
					else
					{
						nMindau = atoi(smindau)*60+atoi(smindau.GetBuffer(0)+3);
						bCheckMindau = TRUE;
					}
					if (!isdigit(*smaxdau) || !isdigit(smaxdau[1]) || smaxdau[2]!=':' || !isdigit(smaxdau[3]) || !isdigit(smaxdau[4])) 
						bCheckMaxdau = FALSE;
					else
					{
						nMaxdau = atoi(smaxdau)*60+atoi(smaxdau.GetBuffer(0)+3);
						bCheckMaxdau = TRUE;
					}
					int nTDauer = atoi(tdauer)*60+atoi(tdauer.GetBuffer(0)+3);

					// Suchstrings
					sid.MakeUpper(); sge.MakeUpper(); sno.MakeUpper(); tid.MakeUpper(); tge.MakeUpper(); tno.MakeUpper(); 
					
					if ((sid == "" || sid == tid)
						&& (sge == "" || tge.Find(sge) != -1)
						&& (sno == "" || tno.Find(sno) != -1)
						&& (!bCheckVon || ctDatum >= ctDatumVon)
						&& (!bCheckBis || ctDatum <= ctDatumBis)
						&& (!bCheckMindau || nMindau <= nTDauer)
						&& (!bCheckMaxdau || nMaxdau > nTDauer))
							bDisplay = TRUE;
				}

				if (bDisplay)
				{
					sprintf(str, "%-2.2s\t%-10.10s  %-8.8s  %-8.8s  %s  \t%s",
						p->Spalte(SPID_INITIALEN).GetBuffer(0),
						p->Spalte(SPID_DATUM).GetBuffer(0),
						p->Spalte(SPID_ZEIT).GetBuffer(0),
						p->Spalte(SPID_DAUER).GetBuffer(0),
						p->Spalte(SPID_GESPRAECHSPARTNER).GetBuffer(0),
						p->Spalte(SPID_NOTIZEN).GetBuffer(0));

					/*
					if (!bValidDate)	// einfach anhängen
					{
						GetListCtrl( ).AddString(str);
						GetListCtrl( ).SetItemData(
							GetListCtrl( ).GetItemCount()-1,
							(DWORD)p
						);
					}
					else	// einsortieren
					*/
					{
						//int n = EinsortierenNachDatum(&ctDatum, 0, GetListCtrl( ).GetItemCount());
						//GetListCtrl( ).InsertString(n, str);
						SetItemData(nItemCount, p);
					}
				}
				p = p->next;
				nItemCount++;
			}

			GetListCtrl().SetItemCount(nItemCount);
			GetListCtrl().UnlockWindowUpdate();
		}
	}
	else	// open new-style database based index file
	{
		int n;

		liste_index.Close();
		if (liste_index.OpenCreate(pathfile, ""))
		{
			// move to last recording
			// GetRecordCount IS NOT VERY ACCURATE: n = liste_index.recordingsRS->GetRecordCount();
			CString csRecordingsCount;
			//liste_index.GetConfig("RecordingsCount", csRecordingsCount);
			//n = atoi((LPCSTR)csRecordingsCount);
			n = liste_index.DetermineRecordingsCount();

			GetListCtrl().LockWindowUpdate();
			GetListCtrl().SetItemCount(n);		// max number of items displayed
			ResetItemData(n);
			m_CurrentIndexType = IDXTYPE_ACCESS;

			int nItemCount = 0;

			m_CurrentIndexPosition = n - 1;

			// if search filter
			if (suchfilter && suchfilter->IsWindowVisible())
			{
				TMZeile *p;				

				CString sid;
				CString sge;	
				CString sno;	
				CString sdv;	
				CString sdb;	
				CString szv;	
				CString szb;	
				CString smindau;		
				CString smaxdau;

				sid = suchfilter->m_Identifikation;
				sge = suchfilter->m_Gespraechspartner;
				sno = suchfilter->m_Notizen;
				sdv = suchfilter->m_DatumVon;
				sdb = suchfilter->m_DatumBis;
				szv = suchfilter->m_ZeitVon;
				szb = suchfilter->m_ZeitBis;
				smindau = suchfilter->m_MinDauer;
				smaxdau = suchfilter->m_MaxDauer;
				CTime ctDatumVon, ctDatumBis, ctDatum;

				//GetDlgItem(IDC_LISTE)->SetRedraw(FALSE);

				liste_index.SeekRecordingByPosition(0, n);	// move to first record
				while (TRUE)
				{
					p = new TMZeile;					
					if (!liste_index.GetNextRecording(p))
					{
						delete p;
						break;
					}						

					BOOL bDisplay = TRUE;

					CString tid = p->Spalte(SPID_INITIALEN);
					CString tge = p->Spalte(SPID_GESPRAECHSPARTNER);
					CString tno = p->Spalte(SPID_NOTIZEN);
					CString td = p->Spalte(SPID_DATUM);
					CString tz = p->Spalte(SPID_ZEIT);
					BOOL bValidDate = String2CTime(td, tz, ctDatum);

					if (suchfilter && suchfilter->IsWindowVisible())
					{
						bDisplay = FALSE;

						if (!szv.GetLength()) szv = "00:00:00";
						if (!szb.GetLength()) szb = "23:59:59";

						BOOL bCheckVon = FALSE, bCheckBis = FALSE;
						if (bValidDate)
						{
							bCheckVon = String2CTime(sdv, szv, ctDatumVon);
							bCheckBis = String2CTime(sdb, szb, ctDatumBis);
						}

						CString tdauer = p->Spalte(SPID_DAUER);

						// Dauer
						int nMindau, nMaxdau;
						BOOL bCheckMindau, bCheckMaxdau;
						if (!isdigit(*smindau) || !isdigit(smindau[1]) || smindau[2]!=':' || !isdigit(smindau[3]) || !isdigit(smindau[4])) 
							bCheckMindau = FALSE;
						else
						{
							nMindau = atoi(smindau)*60+atoi(smindau.GetBuffer(0)+3);
							bCheckMindau = TRUE;
						}
						if (!isdigit(*smaxdau) || !isdigit(smaxdau[1]) || smaxdau[2]!=':' || !isdigit(smaxdau[3]) || !isdigit(smaxdau[4])) 
							bCheckMaxdau = FALSE;
						else
						{
							nMaxdau = atoi(smaxdau)*60+atoi(smaxdau.GetBuffer(0)+3);
							bCheckMaxdau = TRUE;
						}
						int nTDauer = atoi(tdauer)*60+atoi(tdauer.GetBuffer(0)+3);

						// Suchstrings
						sid.MakeUpper(); sge.MakeUpper(); sno.MakeUpper(); tid.MakeUpper(); tge.MakeUpper(); tno.MakeUpper(); 
						
						if ((sid == "" || sid == tid)
							&& (sge == "" || tge.Find(sge) != -1)
							&& (sno == "" || tno.Find(sno) != -1)
							&& (!bCheckVon || ctDatum >= ctDatumVon)
							&& (!bCheckBis || ctDatum <= ctDatumBis)
							&& (!bCheckMindau || nMindau <= nTDauer)
							&& (!bCheckMaxdau || nMaxdau > nTDauer))
								bDisplay = TRUE;
					}

					if (bDisplay)
					{
						// einfach anhängen
						SetItemData(nItemCount, p);
						nItemCount++;
					}
					else
						delete p;
				}
				liste_index.EndSeekRecording();

				GetListCtrl().SetItemCount(nItemCount);
				GetListCtrl().UnlockWindowUpdate();
				GetListCtrl().RedrawItems(
						GetListCtrl().GetTopIndex(),
						GetListCtrl().GetTopIndex()+GetListCtrl().GetCountPerPage());
			}
			else // if no search filter
			{
				GetListCtrl().UnlockWindowUpdate();
				GetListCtrl().RedrawItems(
						GetListCtrl().GetTopIndex(),
						GetListCtrl().GetTopIndex()+GetListCtrl().GetCountPerPage());

/* outdated listbox code:
				// create dummy list
				GetDlgItem(IDC_LISTE)->SetRedraw(FALSE);
				for (int i = 0; i < n; i++)
				{
					((CListBox *)GetDlgItem(IDC_LISTE))->AddString("");
					((CListBox *)GetDlgItem(IDC_LISTE))->SetItemData(i, 0L);
				}

				for (i = 0; i < n; i++)
				{
					DWORD dw;
					dw = ((CListBox *)GetDlgItem(IDC_LISTE))->GetItemData(i);
				}			// was soll das bloß?
*/
			}
			//GetDlgItem(IDC_LISTE)->SetRedraw(TRUE);

			DF("List refresh with database index file");
		}
	}

	int n = GetListCtrl( ).GetItemCount();
	if (nLastSelection != -1 && nLastSelection < n)
	{
		if (nLastSelection >= n - 5)
			GetListCtrl( ).EnsureVisible(n-1, FALSE);
		else
			GetListCtrl( ).EnsureVisible(nLastSelection, FALSE);

		((CQuickList *)(((CTelArPropertySheet *)GetParent())->m_Page2.GetDlgItem(IDC_LISTE)))->SetItemState(nLastSelection, LVIS_SELECTED, LVIS_SELECTED | LVIS_FOCUSED);
		((CQuickList *)(((CTelArPropertySheet *)GetParent())->m_Page2.GetDlgItem(IDC_LISTE)))->SetRedraw(TRUE);
	}
	else	// at least one item, which is not selected
		if (n >= 1) GetListCtrl( ).EnsureVisible(n-1, FALSE);

	DF1("   RefreshListe() finished -- %d items", GetListCtrl( ).GetItemCount());
}


//--- administration of own itemdata for owner-draw list control

/*
LRESULT CTelarView::OnGetListItem(WPARAM wParam, LPARAM lParam)
{
    //wParam is a handler to the list
    //Make sure message comes from list box
    ASSERT( (HWND)wParam == GetListCtrl().GetSafeHwnd() );

    //lParam is a pointer to the data that 
    //is needed for the element
    CQuickList::CListItemData* data = 
        (CQuickList::CListItemData*) lParam;

    //Get which item and subitem that is asked for.
    int item = data->GetItem();
    int subItem = data->GetSubItem();

	
	TMZeile *p = SafeGetItemData(item);

	if (!p)
	{
		if (subItem == 1) 
			data->m_text = "- locked -";
		else
			data->m_text = "";
		data->m_tooltip = "Recording has been moved, deleted, or is locked by another user";
	}
	else
	{
		switch (subItem)
		{
			char buffer[1000];
		case 0: 
			data->m_text = p->Spalte(SPID_INITIALEN);
			LANG2BUFFER(IDS_STRING187, buffer);
			data->m_tooltip = (CString)buffer + ": " + data->m_text;
			break;
		case 1:
			data->m_text = p->Spalte(SPID_DATUM) + " " + p->Spalte(SPID_ZEIT);
			LANG2BUFFER(IDS_STRING188, buffer);
			data->m_tooltip = (CString)buffer + ": " + data->m_text;
			break;
		case 2:
			data->m_text = p->Spalte(SPID_DAUER);
			LANG2BUFFER(IDS_STRING189, buffer);
			data->m_tooltip = (CString)buffer + ": " + data->m_text;
			break;
		case 3:
			data->m_text = p->Spalte(SPID_GESPRAECHSPARTNER);
			LANG2BUFFER(IDS_STRING125, buffer);
			data->m_tooltip = (CString)buffer + ": " + data->m_text;
			data->m_allowEdit = TRUE;
			break;
		case 4:
			data->m_text = p->Spalte(SPID_NOTIZEN);
			LANG2BUFFER(IDS_STRING126, buffer);
			data->m_tooltip = (CString)buffer + ": " + data->m_text;
			data->m_allowEdit = TRUE;
			break;
		}
	}

    return 0;
}
*/

#define CACHE_FORWARD 14

TMZeile *CTelarView::SafeGetItemData(int n)
{
	TMZeile *p = GetItemData(n);
	if (!p)
	{
		try	// ignore missing records
		{

			if (m_CurrentIndexType == IDXTYPE_FILE) 
				return NULL;

			// Seek in database
			liste_index.SeekRecordingByPosition(n, CACHE_FORWARD);
			m_CurrentIndexPosition = n;
			
			while (n < m_CurrentIndexPosition + CACHE_FORWARD && !p)
			{
				p = new TMZeile;
				if (!liste_index.GetNextRecording(p)) 
					break;
				SetItemData(n, p);

				n++;
				p = GetItemData(n);
			}

			liste_index.EndSeekRecording();

			p = GetItemData(m_CurrentIndexPosition);
		}
		catch( CADOException& e )
		{
			e;
			return NULL;			
		}
	}
	return p;
}

void CTelarView::ResetItemData(int size)
{
	if (myItemData) 
	{
		if (m_CurrentIndexType != IDXTYPE_FILE)
			for (int i = 0; i < myItemDataSize; i++)
				if (myItemData[i])
				{
					delete myItemData[i];
					myItemData[i] = NULL;
				}

		delete myItemData; 
		myItemData = NULL; 
	}

	if (size)
	{
		myItemData = (TMZeile **)new DWORD[size];
		memset(myItemData, 0x00, size * sizeof(myItemData[0]));
		myItemDataSize = size;
	}
}

void CTelarView::SetItemData(int item, TMZeile *p)
{
	if (item >= 0 && item < myItemDataSize)
		myItemData[item] = p;
}

TMZeile *CTelarView::GetItemData(int item)
{
	if (item >= 0 && item < myItemDataSize)
		return myItemData[item];
	else
		return NULL;

}

void CTelarView::DeleteItemData(int item)
{
	if (item >= 0 && item < myItemDataSize)
	{
		if (myItemData[item])
		{
			delete myItemData[item];
			myItemData[item] = NULL;
		}

		for (int i = item; i < myItemDataSize-1; i++)
			myItemData[i] = myItemData[i+1];

		myItemDataSize--;
	}
}



void CTelarView::OnLvnDeleteitem(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_LISTVIEW* pNMListView = (NM_LISTVIEW*)pNMHDR;

	CString cs;
	cs.Format("%d", (int)pNMHDR->idFrom);
	AfxMessageBox(cs);
	/*
		if (m_CurrentIndexType != IDXTYPE_FILE)
			if (lpDeleteItemStruct->itemData) 
			{
				delete (TMZeile *)lpDeleteItemStruct->itemData;
				lpDeleteItemStruct->itemData = 0L;
			}
	*/

	*pResult = 0;
}


void CTelarView::OnDeleteItem(int nIDCtl, LPDELETEITEMSTRUCT lpDeleteItemStruct) 
{
	if (nIDCtl == IDC_LISTE && lpDeleteItemStruct->itemID >= 0)
	{
		ASSERT(lpDeleteItemStruct->CtlType == ODT_LISTBOX);

		if (m_CurrentIndexType != IDXTYPE_FILE)
			DeleteItemData(lpDeleteItemStruct->itemID);
	}

	CListView::OnDeleteItem(nIDCtl, lpDeleteItemStruct);
}

void CTelarView::OnMeasureItem(int nIDCtl, LPMEASUREITEMSTRUCT lpMeasureItemStruct) 
{
	lpMeasureItemStruct->itemHeight = 13;
	
	CListView::OnMeasureItem(nIDCtl, lpMeasureItemStruct);
}

int CTelarView::OnCompareItem(int nIDCtl, LPCOMPAREITEMSTRUCT lpCompareItemStruct) 
{
	
	
	return CListView::OnCompareItem(nIDCtl, lpCompareItemStruct);
}


// rekursiv-binäres suchen
int CTelarView::EinsortierenNachDatum(CTime *date, int begin, int end)
{
	int nCheckPos = (end - begin) / 2 + begin;
	CTime ctCheckPos;

	if (end == begin) return begin;

	TMZeile *zeile = SafeGetItemData(nCheckPos);
	if (!String2CTime(zeile->Spalte(SPID_DATUM), zeile->Spalte(SPID_ZEIT), ctCheckPos) || *date < ctCheckPos)
	{
		if (end - begin <=1) 
			return begin;
		else
			return EinsortierenNachDatum(date, begin, nCheckPos);
	}
	else
	{
		if (end - begin <=1) 
			return end;
		else
			return EinsortierenNachDatum(date, nCheckPos, end);
	}
}


//--- Drag & Drop ---

BOOL CTelarView::PreTranslateMessage(MSG* pMsg) 
{
    if(pMsg->message==WM_KEYDOWN)
    {
        if(pMsg->wParam==VK_CONTROL)
			m_bCopyDropeffect = TRUE;            

	    if (m_bDragging)
			SetDragCursor(CPoint(0,0));
    }	
	
    if(pMsg->message==WM_KEYUP)
    {
        if(pMsg->wParam==VK_CONTROL)
			m_bCopyDropeffect = FALSE;            

	    if (m_bDragging)
			SetDragCursor(CPoint(0,0));
    }	
		
	return CListView::PreTranslateMessage(pMsg);
}

void CTelarView::OnLvnBeginrdrag(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_LISTVIEW* pNMListView = (NM_LISTVIEW*)pNMHDR;
    
	POSITION p = GetListCtrl().GetFirstSelectedItemPosition();

	m_nDragIndex = pNMListView->iItem;

	SetDragCursor(pNMListView->ptAction);
	
    //// Set dragging flag and others
    m_bDragging = TRUE;    //we are in a drag and drop operation
    m_nDropIndex = -1;    //we don't have a drop index yet
    m_pDragList = &GetListCtrl(); //make note of which list we are dragging from
    m_pDropWnd = &GetListCtrl();    //at present the drag list is the drop list

	*pResult = 0;
}

void CTelarView::SetDragCursor(POINT mousepos) 
{
    if (m_bDragging)
    {
        ReleaseCapture();

        // temporyrily End dragging image
        m_pDragImage->DragLeave(GetDesktopWindow ());
        m_pDragImage->EndDrag();
	}

    //// Create a drag image
    POINT pt;
    int nOffset = -10; //offset in pixels for drag image 
                           //(positive is up and to the left; 
                           //neg is down and to the right)
//    if(GetListCtrl().GetSelectedCount() > 1) //more than one item is selected
    pt.x = nOffset;
    pt.y = nOffset;

	if (m_pDragImage) delete m_pDragImage;
    m_pDragImage = GetListCtrl().CreateDragImage(m_nDragIndex, &pt);
    ASSERT(m_pDragImage); //make sure it was created
    //We will call delete later (in LButtonUp) to clean this up

	CBitmap bitmap;
	if(GetListCtrl().GetSelectedCount() > 1) //more than 1 item in list is selected
		if (m_bCopyDropeffect)
			bitmap.LoadBitmap(IDB_DRAGDROP_MULTI_COPY);
		else
			bitmap.LoadBitmap(IDB_DRAGDROP_MULTI);
	else
		if (m_bCopyDropeffect)
		  bitmap.LoadBitmap(IDB_DRAGDROP_COPY);
		else
		  bitmap.LoadBitmap(IDB_DRAGDROP);
	m_pDragImage->Replace(0, &bitmap, &bitmap);

    //// Change the cursor to the drag image
    ////    (still must perform DragMove() in OnMouseMove() to show it moving)
    m_pDragImage->BeginDrag(0, CPoint(nOffset, nOffset - 4));
    m_pDragImage->DragEnter(GetDesktopWindow(), mousepos);

    //// Capture all mouse messages
    SetCapture ();
}

void CTelarView::OnMouseMove(UINT nFlags, CPoint point) 
{
    if (m_bDragging)
    {
		//// Move the drag image
        CPoint pt(point);    //get our current mouse coordinates
        ClientToScreen(&pt); //convert to screen coordinates
        m_pDragImage->DragMove(pt); //move the drag image to those coordinates
        // Unlock window updates (this allows the dragging image to be shown 
                // smoothly)
        m_pDragImage->DragShowNolock(false);

        // Get the CWnd pointer of the window that is under the 
        // mouse cursor
        CWnd* pDropWnd = WindowFromPoint (pt);
        ASSERT(pDropWnd); //make sure we have a window
		
        //// If we drag outside current window we need 
                //   to adjust the highlights displayed
		if (pDropWnd == GetDlgItem(IDC_ORDNER))
		{
			TRACE1("drop index: %d\n", m_nDropIndex);
			if (m_nDropIndex != -1) //If we drag over the CListCtrl header, turn off the hover highlight
			{
				CListCtrl* pList = (CListCtrl*)pDropWnd;
				VERIFY (pList->SetItemState (m_nDropIndex, 0, LVIS_DROPHILITED));
				// redraw item
				VERIFY (pList->RedrawItems (m_nDropIndex, m_nDropIndex));
				pList->UpdateWindow ();
				m_nDropIndex = -1;
			}
			else //If we drag out of the CListCtrl altogether
			{
				CListCtrl* pList = (CListCtrl*)pDropWnd;
				int i = 0;
				int nCount = pList->GetItemCount();
				for(i = 0; i < nCount; i++)
				{
					pList->SetItemState(i, 0, LVIS_DROPHILITED);
				}
				pList->RedrawItems(0, nCount);
				pList->UpdateWindow();
			}
		}
		
        // Save current window pointer as the CListCtrl we are dropping onto
        m_pDropWnd = pDropWnd;

        // Convert from screen coordinates to drop target client coordinates
        pDropWnd->ScreenToClient(&pt);

        //If we are hovering over a CListCtrl we need to adjust the highlights
        if(pDropWnd == GetDlgItem(IDC_ORDNER))	// ->IsKindOf(RUNTIME_CLASS (CListCtrl)))
        {            
 			//Note that we can drop here
			SetCursor(LoadCursor(NULL, IDC_ARROW));
            UINT uFlags;
            CListCtrl* pList = (CListCtrl*)pDropWnd;

			if (m_nDropIndex != -1)
			{
				// Turn off hilight for previous drop target
				pList->SetItemState (m_nDropIndex, 0, LVIS_DROPHILITED);
				// Redraw previous item
				pList->RedrawItems (m_nDropIndex, m_nDropIndex);
			}
            
            // Get the item that is below cursor
            m_nDropIndex = ((CListCtrl*)pDropWnd)->HitTest(pt, &uFlags);
			if (m_nDropIndex != -1)
			{
				// Highlight it
				pList->SetItemState(m_nDropIndex, LVIS_DROPHILITED, LVIS_DROPHILITED);
			}

            // Redraw item
            pList->RedrawItems(m_nDropIndex, m_nDropIndex);
            pList->UpdateWindow();
        }
		else
		{
			//If we are not hovering over a CListCtrl, change the cursor
			// to note that we cannot drop here
			SetCursor(LoadCursor(NULL, IDC_NO));
		}
        // Lock window updates
        m_pDragImage->DragShowNolock(true);
    }

	CListView::OnMouseMove(nFlags, point);
}


void CTelarView::OnLButtonUp(UINT nFlags, CPoint point) 
{
/*XXX
	if (m_bDragging)
    {
        // Release mouse capture, so that other controls 
        // can get control/messages
        ReleaseCapture ();

        // Note that we are NOT in a drag operation
        m_bDragging = FALSE;

        // End dragging image
        m_pDragImage->DragLeave (GetDesktopWindow ());
        m_pDragImage->EndDrag ();
        delete m_pDragImage; 
		m_pDragImage = NULL;
                //must delete it because it was created at the beginning of the drag
        CPoint pt (point); //Get current mouse coordinates
        ClientToScreen (&pt); //Convert to screen coordinates
        // Get the CWnd pointer of the window that is under the mouse cursor
        CWnd* pDropWnd = WindowFromPoint (pt);
        ASSERT (pDropWnd); //make sure we have a window pointer
        // If window is CListCtrl, we perform the drop

		// release hover highlighting
        if (pDropWnd == GetDlgItem(IDC_ORDNER))
        {
 			int i = 0;
			int nCount = m_OrdnerLB.GetItemCount();
			for(i = 0; i < nCount; i++)
			{
				m_OrdnerLB.SetItemState(i, 0, LVIS_DROPHILITED);
			}
			m_OrdnerLB.RedrawItems(0, nCount);
			m_OrdnerLB.UpdateWindow();

            m_pDropList = (CListCtrl*)pDropWnd; 
            //Set pointer to the list we are dropping on

			// actual drop action:
			// Transfer data between listboxes
			{
				HCURSOR oldCursor = SetCursor(LoadCursor(NULL, IDC_WAIT));

				POSITION p = GetListCtrl().GetFirstSelectedItemPosition();
				int nCopied = 0, nFailed = 0;
				int nItemCount = GetListCtrl().GetItemCount();
				int *ppnCopied = new int[nItemCount];

				// for all selected recodings list entries...
				while (p)
				{
					int nSelected = GetListCtrl().GetNextSelectedItem(p);
					TMZeile *zeile = SafeGetItemData(nSelected);

					if (zeile)
					{
						int nRet;
						if (IDOK == (nRet = KopiereListeneintrag(m_pDragList, nSelected, m_pDropList, m_nDropIndex))) 
						{	
							// list for entries that can be safely deleted
							if (!m_bCopyDropeffect)
								ppnCopied[nCopied] = nSelected;
							nCopied++;
						}
						else 
						{
							nFailed++;
							if (nRet == IDABORT) break;
						}
					}
#if defined(_DEBUG)
					else
					{
						AfxMessageBox("SafeGetItemData() returned 0");
					}
					TRACE2("nCopied == %d  nFailed == %d\n", nCopied, nFailed);
#endif
				}

				if (!m_bCopyDropeffect)
					LoescheListeneintraege(m_pDragList, ppnCopied, nCopied);

				SetCursor(oldCursor);

				{
					CString cs;
					cs.Format("%d entries successfully copied, %d failed", nCopied, nFailed);
					liste_index.AppendAccesslog(m_bCopyDropeffect ? "Copy" : "Move", TRUE, cs.GetBuffer(0));
					DF3("CTelarView::OnLButtonUp: %d entries successfully %s, %d failed", nCopied, m_bCopyDropeffect ? "copied" : "moved", nFailed);
				}

				delete ppnCopied;
			}
        }
    }
*/	
	CListView::OnLButtonUp(nFlags, point);
}
/*XXX
void CTelarView::OnSelchange(CWnd *child)
{
	if (child == GetDlgItem(IDC_LISTE))
		OnSelchangeListe();
//	else if (child == GetDlgItem(IDC_ORDNER))
//		OnSelchangeOrdner();
}
*/
int CTelarView::KopiereListeneintrag(CListCtrl *Source, int nSourceLBItem, CListCtrl *Dest, int nDestLBItem)
{
/*XXX	DF2("CTelarView::KopiereListeneintrag(nSourceLBItem=%d, nDestLBItem=%d)", nSourceLBItem, nDestLBItem)
	if (Source == (CListCtrl *)GetDlgItem(IDC_LISTE) && Dest == (CListCtrl *)GetDlgItem(IDC_ORDNER))
	{
		// Listenelement nach Ordner kopieren
		POSITION p = Dest->GetFirstSelectedItemPosition();

		// for all selected recodings list entries...
		if (p)
		{
			int nSelected = Dest->GetNextSelectedItem(p);

			if (nSelected == nDestLBItem)	// soll in den aktuell geöffneten Ordner kopiert werden?
			{
				LANG_MESSAGEBOX2(IDS_STRING64, MB_ICONEXCLAMATION); // The recording is already in this folder.
				return IDABORT;
			}
		}
		else
			return IDABORT;

		// Zielpfad aus Ordnerliste herausbekommen
		CString sDest;
		sDest = m_OrdnerLB.GetItemText(nDestLBItem, 0);
		TMZeile *pDestFolderZeile = pFolders->Find(0, sDest);
		TMZeile *pSourceFolderZeile = pFolders->Find(0, csOrdner);

		// Quell- und Zielpfad aufbereiten
		char DestPath[1000];
		char SourcePath[1000];
		char DestPathWithoutFilename[1000];
		char DestPathWithIndexFilename[1000];
		if (!pDestFolderZeile)
			strcpy(DestPath, X_path);
		else
			strcpy(DestPath, pDestFolderZeile->Spalte(1));
		if (!*DestPath) return IDABORT;
		if (DestPath[strlen(DestPath)-1] != '\\') strcat(DestPath, "\\");
		if (!pSourceFolderZeile)
			strcpy(SourcePath, X_path);
		else
			strcpy(SourcePath, pSourceFolderZeile->Spalte(1));
		if (!*SourcePath) return IDABORT;
		if (SourcePath[strlen(SourcePath)-1] != '\\') strcat(SourcePath, "\\");
		strcpy(DestPathWithoutFilename, DestPath);
		strcpy(DestPathWithIndexFilename, DestPathWithoutFilename);
		strcat(DestPathWithIndexFilename, INDEX_FILENAME);

		// Dateiname zu Pfaden hinzufügen
		TMZeile *zeile = SafeGetItemData(nSourceLBItem);
		if (!zeile) return IDABORT;
		strcat(DestPath, zeile->Spalte(SPID_DATEINAME).GetBuffer(0));
		strcat(SourcePath, zeile->Spalte(SPID_DATEINAME).GetBuffer(0));

		//--- nun den Index des Dest-Ordners ergänzen ---
		BOOL bReopenDestIndex = TRUE;
		if (dest_index.IsOpen())
			if (dest_index.GetName() == DestPathWithIndexFilename)
				bReopenDestIndex = FALSE;

		// this dest index file not already open?
		if (bReopenDestIndex)
		{
			// is there an index file in the dest. folder? 
			DWORD dw = GetFileAttributes(DestPathWithoutFilename);
			if (dw == 0xFFFFFFFF)
				dest_index.OpenCreate(DestPathWithoutFilename, "");	// if not, create one & open it
			else
			{
				// check for old-style index file
				int file_version = INDEX_FILEVERSION;	
				TMTabelle tempTabelle(INDEX_FILEMAGIC, INDEX_FILECOLUMNS, INDEX_FILEVERSION);
				if (IsOldStyleIndexFile(DestPathWithIndexFilename))
				{
					if (!DoConvert(DestPathWithoutFilename, ""))
						return IDABORT;
					else
					{
						RefreshListe();
						return IDABORT;
					}
				}
			}

			if (dest_index.IsOpen()) dest_index.Close();

			if (!dest_index.Open(DestPathWithIndexFilename))
				return FALSE;
		}

		int nMsgBoxRet;
		do
		{
			if (!CopyFile((LPCSTR)SourcePath, (LPCSTR)DestPath, FALSE)) 
			{
				char buffer[1000];
				LANG2BUFFER(IDS_STRING68, buffer);
				CString csErrorMsg;
				csErrorMsg.Format(buffer, SourcePath);
				nMsgBoxRet = AfxMessageBox(csErrorMsg.GetBuffer(0), MB_ABORTRETRYIGNORE);
				if (nMsgBoxRet == IDABORT) // Recording couldnt be kopied due to filesystem error. Please check source and destination folders.
				{
					DF2("CopyFile %s -> %s -- Recording couldn't be copied due to filesystem error.", SourcePath, DestPath)
					return IDABORT;
				}
			}
			else
			{
				DF2("CopyFile %s -> %s", SourcePath, DestPath);
				nMsgBoxRet = IDOK; // IDOK means: no msgbox shown, everything ok

				// If copied from CDROM, clear read-only attribute
				DWORD dwFileAttr = GetFileAttributes((LPCSTR)DestPath);
				if (dwFileAttr & FILE_ATTRIBUTE_READONLY)
					SetFileAttributes((LPCSTR)DestPath, dwFileAttr & ~FILE_ATTRIBUTE_READONLY);
			}
		}
		while (nMsgBoxRet == IDRETRY);
*/

/*
		// find out if recording already exists
		{
			try
			{
				liste_index.m_pWorkspace->BeginTrans();
				CDaoQueryDef editQD(&liste_index);
				CString csSQL;
				csSQL.Format("SELECT * FROM Recordings WHERE f4 = '%s' AND f5 = '%s' AND f1 = '%s';", zeile->Spalte(SPID_DATUM), zeile->Spalte(SPID_ZEIT), zeile->Spalte(SPID_INITIALEN));
				editQD.Create("", csSQL);
		//		editQD.Open(&recordingsQD, dbOpenDynaset);
			}
			catch( CADOException* e )
			{
				if (liste_index.m_show_messages)
					AfxMessageBox( 
							e->m_pErrorInfo->m_strDescription, 
							MB_ICONEXCLAMATION );
				liste_index.AppendAccesslog("Edit", FALSE, e->m_pErrorInfo->m_strDescription.GetBuffer(0));
				DF(e->m_pErrorInfo->m_strDescription.GetBuffer(0));
				e->Delete();
				liste_index.m_pWorkspace->Rollback();
				return;
			}
*/

/*XXX
	//	if (dest_index.SeekRecordingDateTimeID(zeile))	// if recording already exists

		// see if existing record matches the one to copy, if existing: overwrite, if not existing: append
		if (nMsgBoxRet == IDOK)
		{
			TMZeile dummy;
			int old_show_messages = dest_index.m_show_messages;	
			dest_index.m_show_messages = FALSE;	// suppress message if record not found
			int bSeekReturn = dest_index.SeekRecordingByDateTimeID(zeile);
			if (bSeekReturn) 
				bSeekReturn = dest_index.GetNextRecording(&dummy);
			if (bSeekReturn) dest_index.EndSeekRecording();
			dest_index.m_show_messages = old_show_messages;
			if (bSeekReturn)
			{
				if (!dest_index.UpdateRecordingByDateTimeID(zeile))	
				{
					LANG_MESSAGEBOX2(IDS_STRING56, MB_ICONSTOP);	// The changes made to the list item couldn't be saved to the archive index file.
					return IDIGNORE;
				}
				int n = dest_index.m_bIsSQLite ? dest_index.m_sqlite.GetChanges() : dest_index.GetRecordsAffected();
				if (n) 
					dest_index.AppendAccesslog("Copy overwrite", TRUE, zeile->Spalte(SPID_DATEINAME).GetBuffer(0));
			}
			else
			{
				dest_index.AppendAccesslog("Copy inserted", TRUE, zeile->Spalte(SPID_DATEINAME).GetBuffer(0));
				if (!dest_index.AppendRecording(zeile))		
				{
					LANG_MESSAGEBOX2(IDS_STRING56, MB_ICONSTOP);	// The changes made to the list item couldn't be saved to the archive index file.
					return IDIGNORE;
				}
			}
		}

		return nMsgBoxRet;
	}
*/
	return IDABORT;
}

void CTelarView::LoescheListeneintraege(CListCtrl *lb, int *pLBItem, int n)
{
/*XXX	DF1("CTelarView::LoescheListeneintraege(n=%d)", n)
	if (lb == (CListCtrl *)GetDlgItem(IDC_LISTE))
	{
		int i, failed;
		CString password;

		HCURSOR oldCursor = SetCursor(LoadCursor(NULL, IDC_WAIT));

		// Liste der Dateinamen erstellen
		for (i = 0, failed = 0; i < n; i++)
		{
			TMZeile *zeile = SafeGetItemData(pLBItem[i]);

			if (zeile)
			{
				BOOL bDeleteFile = TRUE;

				// check for password
				while (atoi((LPCSTR)zeile->Spalte(SPID_GESCHUETZT)))
				{
					if (password == "")
					{   // mit PW und Dateinamen geschützt:
						CString passwort_buffer;

						{	// Passwortabfrage:
							int idd;
							
							if (!strcmp(C_language, "D")) 
								idd = IDD_PASSWORT_CHECK;
							else if (!strcmp(C_language, "GB")) 
								idd = IDD_GB_PASSWORT_CHECK;
							else if (!strcmp(C_language, "CZ")) 
								idd = IDD_CZ_PASSWORT_CHECK;
							else if (!strcmp(C_language, "NL")) 
								idd = IDD_NL_PASSWORT_CHECK;
							else if (!strcmp(C_language, "PL")) 
								idd = IDD_PL_PASSWORT_CHECK;
							else 
								idd = IDD_E_PASSWORT_CHECK;

							CPasswortCheckDlg dlg(idd, &passwort_buffer, this);
							if (dlg.DoModal() != IDOK) return;
						}
						passwort_buffer.TrimLeft();
						passwort_buffer.TrimRight();
						password = passwort_buffer; 
					}

					CString pw = password + zeile->Spalte(SPID_DATEINAME); // pw=="": nur mit Dateinamen geschützt

					// check if it's the right password
					char buffer[1000];
					TMZeile *p = pFolders->Find(0, csOrdner);
					if (!p)
						strcpy(buffer, X_path);
					else
						strcpy(buffer, (LPCSTR)p->Spalte(1));

					if (*buffer && buffer[strlen(buffer)-1] != '\\')
						strcat(buffer, "\\");
					strcat(buffer, zeile->Spalte(SPID_DATEINAME).GetBuffer(0));
					char tempfile[1000];
					strcpy(tempfile, buffer);
					strcat(tempfile, ".tmp");
					if (DecryptFile((CString)buffer, (CString)tempfile, pw))
					{
						DeleteFile(tempfile);
						bDeleteFile = TRUE;
						break;
					}
					else
					{	
						char buffer2[2000];
						LANG2BUFFER(IDS_STRING39, buffer2);
						int nReturn = AfxMessageBox(buffer2, MB_ABORTRETRYIGNORE);
						if (nReturn == IDIGNORE)
						{
							bDeleteFile = FALSE;
							break;
						}
						else if (nReturn == IDABORT)
						{
							bDeleteFile = FALSE;
							failed += n - i;
							goto EndDeleteLoop;
						}
						else 
							password = "";	// retry with different password
					}
				}

				if (bDeleteFile && liste_index.DeleteRecordingByDateTimeID(zeile))
				{
					char buffer[1000];
					TMZeile *p = pFolders->Find(0, csOrdner);
					if (!p)
						strcpy(buffer, X_path);
					else
						strcpy(buffer, (LPCSTR)p->Spalte(1));

					if (*buffer && buffer[strlen(buffer)-1] != '\\')
						strcat(buffer, "\\");

					// delete file physically on hard drive
					strcat(buffer, zeile->Spalte(SPID_DATEINAME).GetBuffer(0));
					if (!DeleteFile(buffer))
					{
						if (GetFileAttributes(buffer) != 0xFFFFFFFF)	// does exist?
						{
							// rollback if delete failed and file exists, re-append index file record
							liste_index.AppendRecording(zeile);
							pLBItem[i] = -1;	// don't delete from listbox
							strcat(buffer, " - file couldn't be deleted.");
							liste_index.AppendAccesslog("Delete", FALSE, buffer);
							liste_index.IncConfig("RecordingsCount", +1);
							failed++;
						}
					}
				}
				else
				{
					liste_index.AppendAccesslog("Delete", FALSE, "simply failed");
					failed++;
				}
			}
		}
EndDeleteLoop:

		SetCursor(oldCursor);

		// Message if some recordings were not deleted
		if (failed)
		{
			char buffer[1000], buffer2[1000];
			LANG2BUFFER(IDS_STRING62, buffer);
			sprintf(buffer2, buffer, n-failed, failed);
			AfxMessageBox(buffer2, MB_ICONSTOP);	// "Couldn't delete list entries."
			DF2("   %d deleted ok, %d entries failed", n-failed, failed)
			liste_index.AppendAccesslog("Delete", FALSE, buffer2);
		}
		else
		{
			CString cs;
			cs.Format("%d entries successfully deleted", n);
			liste_index.AppendAccesslog("Delete", TRUE, cs.GetBuffer(0));
		}

		// Wenn im Index gelöscht, jetzt auch in der Liste löschen
		if (n-failed)
		{
			for (i = n-1; i >= 0; i--)
			{	
				//if (pLBItem[i] != -1) GetListCtrl( ).DeleteItem(pLBItem[i]);	-- doesn't work any more in virtual list control
				DeleteItemData(pLBItem[i]);
				int n = GetListCtrl( ).GetItemCount();
				GetListCtrl( ).SetItemCount(n-1);
			}

			GetListCtrl().SetItemState(-1, 0, LVIS_SELECTED | LVIS_FOCUSED);
			GetListCtrl().SetRedraw(TRUE);
		}
	}
*/}

void CTelarView::DoDeleteEintrag(TMZeile *zeile)
{
	DF1("CTelArPropertyPage2::DoDeleteEintrag(%s)", zeile->Spalte(SPID_DATEINAME))
	char buffer[1000];

	if (m_CurrentIndexType == IDXTYPE_FILE) return;	// only for safety

	if (zeile->Spalte(SPID_DATEINAME) == "") return;
	
	TMZeile *p = pFolders->Find(0, csOrdner);
	if (!p)
		strcpy(buffer, X_path);
	else
		strcpy(buffer, (LPCSTR)p->Spalte(1));

	if (*buffer && buffer[strlen(buffer)-1] != '\\')
		strcat(buffer, "\\");

	strcat(buffer, zeile->Spalte(SPID_DATEINAME).GetBuffer(0));
	DeleteFile(buffer);

	// delete record in database index file
	if (m_CurrentIndexType != IDXTYPE_FILE)
		liste_index.DeleteRecordingByDateTimeID(zeile);

	/* old index file code:
	if (m_CurrentIndexType == IDXTYPE_FILE)
	{
		char pathfile[1000];
		int file_version = INDEX_FILEVERSION;
		
		if (!p)
			strcpy(pathfile, X_path);
		else
			strcpy(pathfile, (LPCSTR)p->Spalte(1));

		if (*pathfile && pathfile[strlen(pathfile)-1] != '\\')
			strcat(pathfile, "\\");
		strcat(pathfile, INDEX_FILENAME);

		CString cs = zeile->Spalte(SPID_DATEINAME);
		CString *pcs = &cs;
		if (!theTabelle.DeleteZeilen(pathfile, &file_version, SPID_DATEINAME, &pcs, 1))
			LANG_MESSAGEBOX2(IDS_STRING62, MB_ICONSTOP);
	} */
}




/*

void CTelarView::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: Add your message handler code here and/or call default

	CListView::OnTimer(nIDEvent);
}

void CTelarView::OnMeasureItem(int nIDCtl, LPMEASUREITEMSTRUCT lpMeasureItemStruct)
{
	// TODO: Add your message handler code here and/or call default

	CListView::OnMeasureItem(nIDCtl, lpMeasureItemStruct);
}

int CTelarView::OnCompareItem(int nIDCtl, LPCOMPAREITEMSTRUCT lpCompareItemStruct)
{
	// TODO: Add your message handler code here and/or call default

	return CListView::OnCompareItem(nIDCtl, lpCompareItemStruct);
}

void CTelarView::OnDeleteItem(int nIDCtl, LPDELETEITEMSTRUCT lpDeleteItemStruct)
{
	// TODO: Add your message handler code here and/or call default

	CListView::OnDeleteItem(nIDCtl, lpDeleteItemStruct);
}

void CTelarView::OnLvnDeleteitem(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: Add your control notification handler code here
	*pResult = 0;
}

void CTelarView::OnLvnBeginrdrag(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: Add your control notification handler code here
	*pResult = 0;
}

void CTelarView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default

	CListView::OnMouseMove(nFlags, point);
}

void CTelarView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default

	CListView::OnLButtonUp(nFlags, point);
}

BOOL CTelarView::PreTranslateMessage(MSG* pMsg)
{
	// TODO: Add your specialized code here and/or call the base class

	return CListView::PreTranslateMessage(pMsg);
}
*/

void CTelarView::OnLvnItemchanged(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: Add your control notification handler code here
	*pResult = 0;
}

void CTelarView::OnLvnBeginlabeledit(NMHDR *pNMHDR, LRESULT *pResult)
{
	NMLVDISPINFO *pDispInfo = reinterpret_cast<NMLVDISPINFO*>(pNMHDR);
	//LV_DISPINFO* pDispInfo = (LV_DISPINFO*)pNMHDR;

	if (m_CurrentIndexType == IDXTYPE_FILE)
	{
		*pResult = TRUE;
//XXX		OnEdit();
		return;
	}

	// update item in case some other user in the network has changed it in the meantime
	TMZeile *zeile = SafeGetItemData(pDispInfo->item.iItem);
	if (!liste_index.SeekRecordingByDateTimeID(zeile)) return;
	if (!liste_index.GetNextRecording(zeile)) return;
	liste_index.EndSeekRecording();

	if (pDispInfo->item.iSubItem == 3)
	{
		delete pDispInfo->item.pszText;	
		pDispInfo->item.cchTextMax = zeile->Spalte(SPID_GESPRAECHSPARTNER).GetLength()+1;
		pDispInfo->item.pszText = new TCHAR[pDispInfo->item.cchTextMax];			
		strcpy(pDispInfo->item.pszText, zeile->Spalte(SPID_GESPRAECHSPARTNER).GetBuffer(0));
	}
	else if (pDispInfo->item.iSubItem == 4)
	{
		delete pDispInfo->item.pszText;	
		pDispInfo->item.cchTextMax = zeile->Spalte(SPID_NOTIZEN).GetLength()+1;
		pDispInfo->item.pszText = new TCHAR[pDispInfo->item.cchTextMax];			
		strcpy(pDispInfo->item.pszText, zeile->Spalte(SPID_NOTIZEN).GetBuffer(0));
	}

	*pResult = 0;
}

void CTelarView::OnLvnEndlabeledit(NMHDR *pNMHDR, LRESULT *pResult)
{
	NMLVDISPINFO *pDispInfo = reinterpret_cast<NMLVDISPINFO*>(pNMHDR);
	//LV_DISPINFO* pDispInfo = (LV_DISPINFO*)pNMHDR;

    // If pszText is NULL, editing was canceled
    if(pDispInfo->item.pszText != NULL && m_CurrentIndexType != IDXTYPE_FILE)
    {        
		TMZeile *zeile = SafeGetItemData(pDispInfo->item.iItem);

		if (pDispInfo->item.iSubItem == 3)
			zeile->Spalte(SPID_GESPRAECHSPARTNER) = pDispInfo->item.pszText;
		else if (pDispInfo->item.iSubItem == 4)
			zeile->Spalte(SPID_NOTIZEN) = pDispInfo->item.pszText;

		if (!liste_index.UpdateRecordingByDateTimeID(zeile)) return;
    }

	*pResult = 0;
}

void CTelarView::OnDrawItem(int nIDCtl, LPDRAWITEMSTRUCT lpDrawItemStruct)
{
//XXX X-en
	CListView::OnDrawItem(nIDCtl, lpDrawItemStruct);
}

BOOL CTelarView::MyMciSendString(LPCSTR cmd, char *ret, int retsize, HWND hWnd)
{
	MCIERROR mciret;
	mciret = mciSendString(cmd,ret,retsize,hWnd);
	if (mciret) 
	{ 
		char buf[3000]; 
		mciGetErrorString(mciret, buf, sizeof(buf)); 

		if (!X_MessageShownOnce)
		{
			X_MessageShownOnce = TRUE;

			// Display message
			AfxMessageBox("There was some internal problem. Maybe the MCI system became unstable. If this message should show up again after rebooting, please send the current 'logXX.txt' file from the program directory to our technical support and try to describe in detail the circumstances of the incident. (Note: this message only shows up once each time you start the SCR.)", MB_OK|MB_ICONINFORMATION);
		}
		DF("__________")
		DF2("MCI command '%s': %s", cmd, buf);
		DF("^^^^^^^^^^")
		return FALSE; 
	}
	else 
		return TRUE;
}


void CTelarView::DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct)
{
	if (lpDrawItemStruct->hwndItem == GetListCtrl().m_hWnd && lpDrawItemStruct->itemID >= 0)
	{
		//ASSERT(lpDrawItemStruct->CtlType == ODT_LISTBOX);

		if (!GetListCtrl().GetItemCount()) return;

		CDC *pDC = CDC::FromHandle(lpDrawItemStruct->hDC);
		TMZeile *p = SafeGetItemData(lpDrawItemStruct->itemID);
		if (lpDrawItemStruct->itemState & ODS_SELECTED)
		{
			CBrush b;
			b.CreateSolidBrush(GetSysColor(COLOR_HIGHLIGHT));
			pDC->FillRect(&lpDrawItemStruct->rcItem, &b);
			pDC->SetTextColor(GetSysColor(COLOR_HIGHLIGHTTEXT));
			pDC->SetBkColor(GetSysColor(COLOR_HIGHLIGHT));
		}
		else
		{
			CBrush b;
			b.CreateSolidBrush(GetSysColor(COLOR_WINDOW));
			pDC->FillRect(&lpDrawItemStruct->rcItem, &b);
			pDC->SetTextColor(GetSysColor(COLOR_WINDOWTEXT));
			pDC->SetBkColor(GetSysColor(COLOR_WINDOW));
		}

		if (!p)
		{
			pDC->TextOut(lpDrawItemStruct->rcItem.left+1, lpDrawItemStruct->rcItem.top, "- locked -", (int)strlen("- locked -"));
			return;
		}

		CString *pcs = &p->Spalte(SPID_INITIALEN);
		pDC->TextOut(lpDrawItemStruct->rcItem.left+1, lpDrawItemStruct->rcItem.top, pcs->GetBuffer(0), pcs->GetLength());
		pcs = &p->Spalte(SPID_DATUM);
		pDC->TextOut(lpDrawItemStruct->rcItem.left+24, lpDrawItemStruct->rcItem.top, pcs->GetBuffer(0), pcs->GetLength());
		pcs = &p->Spalte(SPID_ZEIT);
		pDC->TextOut(lpDrawItemStruct->rcItem.left+87, lpDrawItemStruct->rcItem.top, pcs->GetBuffer(0), pcs->GetLength());
		pcs = &p->Spalte(SPID_DAUER);
		pDC->TextOut(lpDrawItemStruct->rcItem.left+135, lpDrawItemStruct->rcItem.top, pcs->GetBuffer(0), pcs->GetLength());
		pcs = &p->Spalte(SPID_GESPRAECHSPARTNER);
		pDC->TextOut(lpDrawItemStruct->rcItem.left+183, lpDrawItemStruct->rcItem.top, pcs->GetBuffer(0), pcs->GetLength());
		pcs = &p->Spalte(SPID_NOTIZEN);
		pDC->TextOut(lpDrawItemStruct->rcItem.left+260, lpDrawItemStruct->rcItem.top, pcs->GetBuffer(0), pcs->GetLength());
;	
	}	

}