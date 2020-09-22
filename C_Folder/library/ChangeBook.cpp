// ChangeBook.cpp : implementation file
//

#include "stdafx.h"
#include "library.h"
#include "ChangeBook.h"
#include "Book.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CChangeBook dialog


CChangeBook::CChangeBook(CWnd* pParent /*=NULL*/)
	: CDialog(CChangeBook::IDD, pParent)
{
	//{{AFX_DATA_INIT(CChangeBook)
	m_sAuthor = _T("");
	m_sName = _T("");
	m_sPub = _T("");
	//}}AFX_DATA_INIT
}


void CChangeBook::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CChangeBook)
	DDX_Text(pDX, IDC_AUTHOR, m_sAuthor);
	DDV_MaxChars(pDX, m_sAuthor, 32);
	DDX_Text(pDX, IDC_NAME, m_sName);
	DDV_MaxChars(pDX, m_sName, 64);
	DDX_Text(pDX, IDC_PUB, m_sPub);
	DDV_MaxChars(pDX, m_sPub, 128);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CChangeBook, CDialog)
	//{{AFX_MSG_MAP(CChangeBook)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CChangeBook message handlers

int CChangeBook::SetID(unsigned int nID)
{
	m_nID = nID;
	return 0;
}

void CChangeBook::OnOK() 
{
	// TODO: Add extra validation here
	UpdateData(TRUE);

	if (m_sName.IsEmpty() || m_sAuthor.IsEmpty() || m_sPub.IsEmpty())
	{
		MessageBox(_T("请填充完整"), _T("错误"));
	}
	else if (ChangeBookInfo(m_nID, m_sName.GetBuffer(m_sName.GetLength()), m_sAuthor.GetBuffer(m_sAuthor.GetLength()), m_sPub.GetBuffer(m_sPub.GetLength())) == 0)
	{
		CDialog::OnOK();
	}
	else
	{	
		MessageBox(_T("修改失败"), _T("修改书籍信息"));
		CDialog::OnCancel();
	}
}

void CChangeBook::OnCancel() 
{
	// TODO: Add extra cleanup here
	
	CDialog::OnCancel();
}
