
// TelarDoc.cpp : implementation of the CTelarDoc class
//

#include "stdafx.h"
#include "Telar.h"

#include "TelarDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CTelarDoc

IMPLEMENT_DYNCREATE(CTelarDoc, CDocument)

BEGIN_MESSAGE_MAP(CTelarDoc, CDocument)
END_MESSAGE_MAP()


// CTelarDoc construction/destruction

CTelarDoc::CTelarDoc()
{
	// TODO: add one-time construction code here

}

CTelarDoc::~CTelarDoc()
{
}

BOOL CTelarDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}




// CTelarDoc serialization

void CTelarDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}


// CTelarDoc diagnostics

#ifdef _DEBUG
void CTelarDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CTelarDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CTelarDoc commands
