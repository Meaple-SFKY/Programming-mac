#if !defined(AFX_LOGON_H__BE0EEAA0_1869_445B_90B3_2D102995931F__INCLUDED_)
#define AFX_LOGON_H__BE0EEAA0_1869_445B_90B3_2D102995931F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Logon.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// Logon dialog

class Logon : public CDialog
{
// Construction
public:
	Logon(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(Logon)
	enum { IDD = IDD_DIALOG_LOGON };
	CString	m_sID;
	CString	m_sPwd;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(Logon)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(Logon)
	virtual void OnOK();
	virtual void OnCancel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LOGON_H__BE0EEAA0_1869_445B_90B3_2D102995931F__INCLUDED_)
