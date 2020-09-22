// libraryDlg.h : header file
//

#if !defined(AFX_LIBRARYDLG_H__DF490809_1F54_44A5_BE3C_41F195A63F3D__INCLUDED_)
#define AFX_LIBRARYDLG_H__DF490809_1F54_44A5_BE3C_41F195A63F3D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CLibraryDlg dialog
#include "Book.h"

class CLibraryDlg : public CDialog
{
// Construction
public:
	int m_nSel;
	CLibraryDlg(CWnd* pParent = NULL);	// standard constructor
	int ShowBookInfo(BOOK_INFO *pInfo, unsigned int nNum);
	int InitList();

// Dialog Data
	//{{AFX_DATA(CLibraryDlg)
	enum { IDD = IDD_LIBRARY_DIALOG };
	CListCtrl	m_listBook;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLibraryDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CLibraryDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	virtual void OnCancel();
	afx_msg void OnAdd();
	afx_msg void OnDel();
	afx_msg void OnChange();
	afx_msg void OnQuery();
	afx_msg void OnStaff();
	afx_msg void OnLoan();
	afx_msg void OnGiveback();
	afx_msg void OnClickBookList(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LIBRARYDLG_H__DF490809_1F54_44A5_BE3C_41F195A63F3D__INCLUDED_)
