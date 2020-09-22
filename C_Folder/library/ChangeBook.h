#if !defined(AFX_CHANGEBOOK_H__C30BEF68_29B0_41F3_88CD_EED06B82A6E1__INCLUDED_)
#define AFX_CHANGEBOOK_H__C30BEF68_29B0_41F3_88CD_EED06B82A6E1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ChangeBook.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CChangeBook dialog

class CChangeBook : public CDialog
{
// Construction
public:
	unsigned int m_nID;
	CChangeBook(CWnd* pParent = NULL);   // standard constructor
	int SetID(unsigned int nID);
// Dialog Data
	//{{AFX_DATA(CChangeBook)
	enum { IDD = IDD_CHANGBOOK };
	CString	m_sAuthor;
	CString	m_sName;
	CString	m_sPub;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CChangeBook)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CChangeBook)
	virtual void OnOK();
	virtual void OnCancel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CHANGEBOOK_H__C30BEF68_29B0_41F3_88CD_EED06B82A6E1__INCLUDED_)
