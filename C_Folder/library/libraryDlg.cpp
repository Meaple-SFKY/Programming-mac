// libraryDlg.cpp : implementation file
//

#include "stdafx.h"
#include "library.h"
#include "libraryDlg.h"
#include "AddBook.h"
#include "Book.h"
#include "AddStaff.h"
#include "ChangeBook.h"
#include "QueryBook.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLibraryDlg dialog

CLibraryDlg::CLibraryDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CLibraryDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CLibraryDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CLibraryDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CLibraryDlg)
	DDX_Control(pDX, IDC_BOOK_LIST, m_listBook);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CLibraryDlg, CDialog)
	//{{AFX_MSG_MAP(CLibraryDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_ADD, OnAdd)
	ON_BN_CLICKED(IDC_DEL, OnDel)
	ON_BN_CLICKED(IDC_CHANGE, OnChange)
	ON_BN_CLICKED(IDC_QUERY, OnQuery)
	ON_BN_CLICKED(IDC_STAFF, OnStaff)
	ON_BN_CLICKED(IDC_LOAN, OnLoan)
	ON_BN_CLICKED(IDC_GIVEBACK, OnGiveback)
	ON_NOTIFY(NM_CLICK, IDC_BOOK_LIST, OnClickBookList)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLibraryDlg message handlers

BOOL CLibraryDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	m_nSel = -1;
	InitList();
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CLibraryDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CLibraryDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CLibraryDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CLibraryDlg::OnCancel() 
{
	// TODO: Add extra cleanup here
	
	CDialog::OnCancel();
}

void CLibraryDlg::OnAdd() 
{
	// TODO: Add your control notification handler code here
	CAddBook dlg;
	if (dlg.DoModal() == IDOK)
	{
		MessageBox("添加成功", "添加书籍信息");
		BOOK_INFO binfo[BOOK_NUM_MAX];
		unsigned int nNum = 0;
		memset(binfo, 0, sizeof(BOOK_INFO)*BOOK_NUM_MAX);
		GetBookInfo();						//获取书本信息
		QueryBookInfo(binfo, &nNum);
		ShowBookInfo(binfo, nNum);
	}
}

void CLibraryDlg::OnDel() 
{
	// TODO: Add your control notification handler code here
	if (-1 == m_nSel)
	{
		MessageBox(_T("未选中条目"), _T("错误"));
		return;
	}
	
	char szID[5] = {0};
	unsigned int nID;
	
	m_listBook.GetItemText(m_nSel, 0, szID, 5);
	nID = atoi(szID);
	
	if (DelBookInfo(nID) == 0)
	{
		MessageBox(_T("删除信息成功"), _T("删除书籍"));
		m_listBook.DeleteItem(m_nSel);
		m_nSel = -1;
	}
	else
		MessageBox(_T("删除信息失败"), _T("错误"));
}

void CLibraryDlg::OnChange() 
{
	// TODO: Add your control notification handler code here
	if (-1 == m_nSel)
	{
		MessageBox(_T("未选中条目"), _T("错误"));
		return;
	}
	
	char szID[5] = {0};
	unsigned int nID;
	
	m_listBook.GetItemText(m_nSel, 0, szID, 5);
	nID = atoi(szID);

	CChangeBook dlg;
	dlg.SetID(nID);
	if (dlg.DoModal() == IDOK)
	{
		MessageBox(_T("修改信息成功"), _T("修改书籍"));
		m_listBook.SetItemText(m_nSel, 1, dlg.m_sName.GetBuffer(dlg.m_sName.GetLength()));
		m_listBook.SetItemText(m_nSel, 2, dlg.m_sAuthor.GetBuffer(dlg.m_sAuthor.GetLength()));
		m_listBook.SetItemText(m_nSel, 3, dlg.m_sPub.GetBuffer(dlg.m_sPub.GetLength()));
	}
}

void CLibraryDlg::OnQuery() 
{
	// TODO: Add your control notification handler code here
	CQueryBook dlg;
	if (dlg.DoModal() == IDOK)
	{
		MessageBox(_T("查询信息成功"), _T("查询书籍"));
		ShowBookInfo(dlg.m_info, dlg.m_nNum);
	}
}

void CLibraryDlg::OnStaff() 
{
	// TODO: Add your control notification handler code here
	CAddStaff dlg;

	if (dlg.DoModal() == IDOK)
	{
		MessageBox(_T("添加职员成功"), _T("添加职员"));
	}
}

//初始化列表
int CLibraryDlg::InitList()
{
	CRect rc;
	BOOK_INFO binfo[BOOK_NUM_MAX];
	unsigned int nNum = 0;
	m_listBook.GetClientRect(&rc);
	int nColInterval = rc.Width() / 5;

	m_listBook.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES); //设置风格

	m_listBook.InsertColumn(0, _T("编号"), LVCFMT_CENTER, nColInterval/2, 0);
	m_listBook.InsertColumn(1, _T("书名"), LVCFMT_CENTER, nColInterval, 1);
	m_listBook.InsertColumn(2, _T("作者名"), LVCFMT_CENTER, nColInterval, 2);
	m_listBook.InsertColumn(3, _T("出版社"), LVCFMT_CENTER, nColInterval*2, 3);
	m_listBook.InsertColumn(4, _T("是否在馆"), LVCFMT_CENTER, nColInterval/2, 4);

	memset(binfo, 0, sizeof(BOOK_INFO)*BOOK_NUM_MAX);
	GetBookInfo();						//获取书本信息
	QueryBookInfo(binfo, &nNum);
	ShowBookInfo(binfo, nNum);

	return 0;
}

//显示书籍信息
int CLibraryDlg::ShowBookInfo(BOOK_INFO *pInfo, unsigned int nNum)
{
	unsigned int loop = 0;
	CString str;

	m_listBook.DeleteAllItems();
	m_nSel = -1;

	for (loop=0; loop<nNum; loop++)
	{
		str.Format("%04d", pInfo[loop].nID);
		m_listBook.InsertItem(loop, str.GetBuffer(str.GetLength()));
		m_listBook.SetItemText(loop, 1, pInfo[loop].szName);
		m_listBook.SetItemText(loop, 2, pInfo[loop].szAuthor);
		m_listBook.SetItemText(loop, 3, pInfo[loop].szPub);
		if (pInfo[loop].bState)
			m_listBook.SetItemText(loop, 4, _T("在馆"));
		else
			m_listBook.SetItemText(loop, 4, _T("借出"));
	}

	return 0;
}

void CLibraryDlg::OnLoan() 
{
	// TODO: Add your control notification handler code here
	if (-1 == m_nSel)
	{
		MessageBox(_T("未选中条目"), _T("错误"));
		return;
	}

	char szID[5] = {0};
	unsigned int nID;

	m_listBook.GetItemText(m_nSel, 0, szID, 5);
	nID = atoi(szID);

	if (LoanBook(nID) == 0)
	{
		MessageBox(_T("成功借出"), _T("借出书籍"));
		m_listBook.SetItemText(m_nSel, 4, _T("借出"));
	}
	else
		MessageBox(_T("已借出"), _T("错误"));
	
}

void CLibraryDlg::OnGiveback() 
{
	// TODO: Add your control notification handler code here
	if (-1 == m_nSel)
	{
		MessageBox(_T("未选中条目"), _T("错误"));
		return;
	}
	
	char szID[5] = {0};
	unsigned int nID;
	
	m_listBook.GetItemText(m_nSel, 0, szID, 5);
	nID = atoi(szID);
	
	if (GiveBackBook(nID) == 0)
	{
		MessageBox(_T("成功还入"), _T("还入书籍"));
		m_listBook.SetItemText(m_nSel, 4, _T("在馆"));
	}
	else
		MessageBox(_T("已在馆"), _T("错误"));
	
}

void CLibraryDlg::OnClickBookList(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	LPNMITEMACTIVATE lpNMItemActivate = (LPNMITEMACTIVATE)pNMHDR;
	if (NULL != lpNMItemActivate)
	{
		m_nSel = lpNMItemActivate->iItem;
	}
	
	*pResult = 0;
}
