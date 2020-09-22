// AddStaff.cpp : implementation file
//

#include "stdafx.h"
#include "library.h"
#include "AddStaff.h"
#include "Staff.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAddStaff dialog


CAddStaff::CAddStaff(CWnd* pParent /*=NULL*/)
	: CDialog(CAddStaff::IDD, pParent)
{
	//{{AFX_DATA_INIT(CAddStaff)
	m_sName = _T("");
	m_sPwd = _T("");
	m_sPwd2 = _T("");
	//}}AFX_DATA_INIT
}


void CAddStaff::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAddStaff)
	DDX_Text(pDX, IDC_NAME, m_sName);
	DDV_MaxChars(pDX, m_sName, 8);
	DDX_Text(pDX, IDC_PWD, m_sPwd);
	DDV_MaxChars(pDX, m_sPwd, 8);
	DDX_Text(pDX, IDC_PWD2, m_sPwd2);
	DDV_MaxChars(pDX, m_sPwd2, 8);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CAddStaff, CDialog)
	//{{AFX_MSG_MAP(CAddStaff)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAddStaff message handlers

void CAddStaff::OnOK() 
{
	// TODO: Add extra validation here
	UpdateData(TRUE);

	if (m_sName.IsEmpty() || m_sPwd.IsEmpty() || m_sPwd2.IsEmpty())
	{
		MessageBox(_T("请填充完整"), _T("错误"));
	}
	else if (m_sPwd != m_sPwd2)
	{
		MessageBox(_T("密码不一致"), _T("错误"));
	}
	else if (AddStaffInfo(m_sName.GetBuffer(m_sName.GetLength()), m_sPwd.GetBuffer(m_sPwd.GetLength())) == 0)
	{
		CDialog::OnOK();
	}
	else
	{	
		MessageBox(_T("添加失败"), _T("添加职员"));
		CDialog::OnCancel();
	}
}

void CAddStaff::OnCancel() 
{
	// TODO: Add extra cleanup here
	
	CDialog::OnCancel();
}
