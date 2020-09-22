#if !defined(AFX_ADDBOOK_H__88655EB8_DA59_4C4F_8298_C32BFA0F1D4A__INCLUDED_)
#define AFX_ADDBOOK_H__88655EB8_DA59_4C4F_8298_C32BFA0F1D4A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// AddBook.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CAddBook dialog

class CAddBook : public CDialog
{
// Construction
public:
	CAddBook(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CAddBook)
	enum { IDD = IDD_ADDBOOK };
	CString	m_sName;
	CString	m_sAuthor;
	CString	m_sPub;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAddBook)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CAddBook)
	virtual void OnOK();
	virtual void OnCancel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ADDBOOK_H__88655EB8_DA59_4C4F_8298_C32BFA0F1D4A__INCLUDED_)
