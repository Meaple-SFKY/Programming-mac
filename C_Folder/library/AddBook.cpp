// AddBook.cpp : implementation file
//

#include "stdafx.h"
#include "library.h"
#include "AddBook.h"
#include "Book.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAddBook dialog


CAddBook::CAddBook(CWnd* pParent /*=NULL*/)
	: CDialog(CAddBook::IDD, pParent)
{
	//{{AFX_DATA_INIT(CAddBook)
	m_sName = _T("");
	m_sAuthor = _T("");
	m_sPub = _T("");
	//}}AFX_DATA_INIT
}


void CAddBook::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAddBook)
	DDX_Text(pDX, IDC_EDIT_NAME, m_sName);
	DDV_MaxChars(pDX, m_sName, 64);
	DDX_Text(pDX, IDC_EDIT_AUTHOR, m_sAuthor);
	DDV_MaxChars(pDX, m_sAuthor, 32);
	DDX_Text(pDX, IDC_EDIT_PUB, m_sPub);
	DDV_MaxChars(pDX, m_sPub, 128);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CAddBook, CDialog)
	//{{AFX_MSG_MAP(CAddBook)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAddBook message handlers

void CAddBook::OnOK() 
{
	// TODO: Add extra validation here
	UpdateData(TRUE);
	if (m_sName.IsEmpty() || m_sAuthor.IsEmpty() || m_sPub.IsEmpty())
	{
		MessageBox(_T("请填充完整"), _T("错误"));
	}
	else if (AddBookInfo(m_sName.GetBuffer(m_sName.GetLength()), m_sAuthor.GetBuffer(m_sAuthor.GetLength()), m_sPub.GetBuffer(m_sPub.GetLength())) == 0)
	{
		CDialog::OnOK();
	}
	else
	{
		MessageBox(_T("添加失败"), _T("添加书籍信息"));
		CDialog::OnCancel();
	}
}

void CAddBook::OnCancel() 
{
	// TODO: Add extra cleanup here
	
	CDialog::OnCancel();
}
