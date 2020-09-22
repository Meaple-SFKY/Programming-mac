// Logon.cpp : implementation file
//

#include "stdafx.h"
#include "library.h"
#include "Logon.h"
#include "Staff.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// Logon dialog


Logon::Logon(CWnd* pParent /*=NULL*/)
	: CDialog(Logon::IDD, pParent)
{
	//{{AFX_DATA_INIT(Logon)
	m_sID = _T("");
	m_sPwd = _T("");
	//}}AFX_DATA_INIT
}


void Logon::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(Logon)
	DDX_Text(pDX, IDC_EDIT_ID, m_sID);
	DDV_MaxChars(pDX, m_sID, 8);
	DDX_Text(pDX, IDC_EDIT_PWD, m_sPwd);
	DDV_MaxChars(pDX, m_sPwd, 8);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(Logon, CDialog)
	//{{AFX_MSG_MAP(Logon)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// Logon message handlers

void Logon::OnOK() 
{
	// TODO: Add extra validation here
	UpdateData(TRUE);
	if (QueryStaffInfo(m_sID.GetBuffer(m_sID.GetLength()), m_sPwd.GetBuffer(m_sPwd.GetLength())) == 0)
	{
		CDialog::OnOK();
	}
	else
	{
		MessageBox("用户名或密码错误", "输入错误");
	}
	
}

void Logon::OnCancel() 
{
	// TODO: Add extra cleanup here
	
	CDialog::OnCancel();
}
