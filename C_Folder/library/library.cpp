// library.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "library.h"
#include "libraryDlg.h"
#include "Logon.h"
#include "Staff.h"
#include "Book.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CLibraryApp

BEGIN_MESSAGE_MAP(CLibraryApp, CWinApp)
	//{{AFX_MSG_MAP(CLibraryApp)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLibraryApp construction

CLibraryApp::CLibraryApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CLibraryApp object

CLibraryApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CLibraryApp initialization

BOOL CLibraryApp::InitInstance()
{
	AfxEnableControlContainer();

	// Standard initialization
	// If you are not using these features and wish to reduce the size
	//  of your final executable, you should remove from the following
	//  the specific initialization routines you do not need.

#ifdef _AFXDLL
	Enable3dControls();			// Call this when using MFC in a shared DLL
#else
	Enable3dControlsStatic();	// Call this when linking to MFC statically
#endif

	Logon logondlg;
	CLibraryDlg dlg;
	int nResponse;

	GetStaffInfo();						//获取职员信息
	nResponse = logondlg.DoModal();		//先进入登入界面
	if (nResponse == IDCANCEL)			//直接退出
		return FALSE;

	m_pMainWnd = &dlg;
	nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with OK
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with Cancel
	}

	// Since the dialog has been closed, return FALSE so that we exit the
	//  application, rather than start the application's message pump.
	return FALSE;
}
