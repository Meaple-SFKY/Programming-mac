#if !defined(AFX_QUERYBOOK_H__6EB2727A_7DB4_4466_8031_B46C406790FD__INCLUDED_)
#define AFX_QUERYBOOK_H__6EB2727A_7DB4_4466_8031_B46C406790FD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// QueryBook.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CQueryBook dialog
#include "Book.h"

class CQueryBook : public CDialog
{
// Construction
public:
	BOOK_INFO m_info[BOOK_NUM_MAX];
	unsigned int m_nNum;
	CQueryBook(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CQueryBook)
	enum { IDD = IDD_QUERY };
	CString	m_sStr;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CQueryBook)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CQueryBook)
	virtual void OnOK();
	virtual void OnCancel();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_QUERYBOOK_H__6EB2727A_7DB4_4466_8031_B46C406790FD__INCLUDED_)
