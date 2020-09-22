#if !defined(AFX_ADDSTAFF_H__A3AD412F_AA27_492A_9365_23666CC89452__INCLUDED_)
#define AFX_ADDSTAFF_H__A3AD412F_AA27_492A_9365_23666CC89452__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// AddStaff.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CAddStaff dialog

class CAddStaff : public CDialog
{
// Construction
public:
	CAddStaff(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CAddStaff)
	enum { IDD = IDD_ADDSTAFF };
	CString	m_sName;
	CString	m_sPwd;
	CString	m_sPwd2;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAddStaff)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CAddStaff)
	virtual void OnOK();
	virtual void OnCancel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ADDSTAFF_H__A3AD412F_AA27_492A_9365_23666CC89452__INCLUDED_)
