// QueryBook.cpp : implementation file
//

#include "stdafx.h"
#include "library.h"
#include "QueryBook.h"
#include "Book.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CQueryBook dialog


CQueryBook::CQueryBook(CWnd* pParent /*=NULL*/)
	: CDialog(CQueryBook::IDD, pParent)
{
	//{{AFX_DATA_INIT(CQueryBook)
	m_sStr = _T("");
	//}}AFX_DATA_INIT
}


void CQueryBook::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CQueryBook)
	DDX_Text(pDX, IDC_EDIT_STR, m_sStr);
	DDV_MaxChars(pDX, m_sStr, 128);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CQueryBook, CDialog)
	//{{AFX_MSG_MAP(CQueryBook)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CQueryBook message handlers

void CQueryBook::OnOK() 
{
	// TODO: Add extra validation here
	UpdateData(TRUE);
	memset(m_info, 0, sizeof(BOOK_INFO)*BOOK_NUM_MAX);
	m_nNum = 0;

	if (((CButton *)GetDlgItem(IDC_RADIO_ALL))->GetCheck())				//全选
	{
		if (QueryBookInfo(m_info, &m_nNum) == 0)
		{
			CDialog::OnOK();
		}
		else
		{
			MessageBox(_T("查询失败"), _T("查询书籍信息"));
			CDialog::OnCancel();
		}
	}
	else if (((CButton *)GetDlgItem(IDC_RADIO_ID))->GetCheck())			//按ID
	{
		unsigned int nID = atoi(m_sStr.GetBuffer(m_sStr.GetLength()));
		if (m_sStr.IsEmpty())
		{
			MessageBox(_T("请输入查询条件"), _T("错误"));
		}
		else if (QueryBookInfoByID(nID, m_info, &m_nNum) == 0)
		{
			CDialog::OnOK();
		}
		else
		{
			MessageBox(_T("查询失败"), _T("查询书籍信息"));
			CDialog::OnCancel();
		}
	}
	else if (((CButton *)GetDlgItem(IDC_RADIO_NAME))->GetCheck())		//按书名
	{
		if (m_sStr.IsEmpty())
		{
			MessageBox(_T("请输入查询条件"), _T("错误"));
		}
		else if (QueryBookInfoByName(m_sStr.GetBuffer(m_sStr.GetLength()), m_info, &m_nNum) == 0)
		{
			CDialog::OnOK();
		}
		else
		{
			MessageBox(_T("查询失败"), _T("查询书籍信息"));
			CDialog::OnCancel();
		}
	}
	else if (((CButton *)GetDlgItem(IDC_RADIO_AUTHOR))->GetCheck())		//按作者
	{
		if (m_sStr.IsEmpty())
		{
			MessageBox(_T("请输入查询条件"), _T("错误"));
		}
		else if (QueryBookInfoByAuthor(m_sStr.GetBuffer(m_sStr.GetLength()), m_info, &m_nNum) == 0)
		{
			CDialog::OnOK();
		}
		else
		{
			MessageBox(_T("查询失败"), _T("查询书籍信息"));
			CDialog::OnCancel();
		}
	}
	else if (((CButton *)GetDlgItem(IDC_RADIO_PUB))->GetCheck())		//按出版社
	{
		if (m_sStr.IsEmpty())
		{
			MessageBox(_T("请输入查询条件"), _T("错误"));
		}
		else if (QueryBookInfoByPub(m_sStr.GetBuffer(m_sStr.GetLength()), m_info, &m_nNum) == 0)
		{
			CDialog::OnOK();
		}
		else
		{
			MessageBox(_T("查询失败"), _T("查询书籍信息"));
			CDialog::OnCancel();
		}
	}
}

void CQueryBook::OnCancel() 
{
	// TODO: Add extra cleanup here
	
	CDialog::OnCancel();
}

BOOL CQueryBook::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	((CButton *)GetDlgItem(IDC_RADIO_ALL))->SetCheck(TRUE);
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
