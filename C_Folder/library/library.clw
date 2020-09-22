; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CQueryBook
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "library.h"

ClassCount=8
Class1=CLibraryApp
Class2=CLibraryDlg
Class3=CAboutDlg

ResourceCount=8
Resource1=IDD_CHANGBOOK
Resource2=IDR_MAINFRAME
Resource3=IDD_ADDSTAFF
Class4=Logon
Resource4=IDD_LIBRARY_DIALOG
Class5=CAddBook
Resource5=IDD_ADDBOOK
Class6=CAddStaff
Resource6=IDD_DIALOG_LOGON
Class7=CChangeBook
Resource7=IDD_ABOUTBOX
Class8=CQueryBook
Resource8=IDD_QUERY

[CLS:CLibraryApp]
Type=0
HeaderFile=library.h
ImplementationFile=library.cpp
Filter=N

[CLS:CLibraryDlg]
Type=0
HeaderFile=libraryDlg.h
ImplementationFile=libraryDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=IDC_BOOK_LIST

[CLS:CAboutDlg]
Type=0
HeaderFile=libraryDlg.h
ImplementationFile=libraryDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_LIBRARY_DIALOG]
Type=1
Class=CLibraryDlg
ControlCount=9
Control1=IDC_ADD,button,1342242817
Control2=IDC_CHANGE,button,1342242816
Control3=IDC_DEL,button,1342242816
Control4=IDC_QUERY,button,1342242816
Control5=IDC_LOAN,button,1342242816
Control6=IDC_GIVEBACK,button,1342242816
Control7=IDC_STAFF,button,1342242816
Control8=IDCANCEL,button,1342242816
Control9=IDC_BOOK_LIST,SysListView32,1350631433

[CLS:Logon]
Type=0
HeaderFile=Logon.h
ImplementationFile=Logon.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_EDIT_ID
VirtualFilter=dWC

[DLG:IDD_DIALOG_LOGON]
Type=1
Class=Logon
ControlCount=6
Control1=IDC_EDIT_ID,edit,1350631552
Control2=IDC_EDIT_PWD,edit,1350631584
Control3=IDOK,button,1342242817
Control4=IDCANCEL,button,1342242816
Control5=IDC_STATIC,static,1342308352
Control6=IDC_STATIC,static,1342308352

[DLG:IDD_ADDBOOK]
Type=1
Class=CAddBook
ControlCount=8
Control1=IDC_EDIT_NAME,edit,1350631552
Control2=IDC_EDIT_AUTHOR,edit,1350631552
Control3=IDC_EDIT_PUB,edit,1350631552
Control4=IDOK,button,1342242817
Control5=IDCANCEL,button,1342242816
Control6=IDC_STATIC,static,1342308352
Control7=IDC_STATIC,static,1342308352
Control8=IDC_STATIC,static,1342308352

[CLS:CAddBook]
Type=0
HeaderFile=AddBook.h
ImplementationFile=AddBook.cpp
BaseClass=CDialog
Filter=D
LastObject=CAddBook
VirtualFilter=dWC

[DLG:IDD_ADDSTAFF]
Type=1
Class=CAddStaff
ControlCount=8
Control1=IDC_NAME,edit,1350631552
Control2=IDC_PWD,edit,1350631584
Control3=IDC_PWD2,edit,1350631584
Control4=IDOK,button,1342242817
Control5=IDCANCEL,button,1342242816
Control6=IDC_STATIC,static,1342308352
Control7=IDC_STATIC,static,1342308352
Control8=IDC_STATIC,static,1342308352

[CLS:CAddStaff]
Type=0
HeaderFile=AddStaff.h
ImplementationFile=AddStaff.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC

[DLG:IDD_CHANGBOOK]
Type=1
Class=CChangeBook
ControlCount=8
Control1=IDC_NAME,edit,1350631552
Control2=IDC_AUTHOR,edit,1350631552
Control3=IDC_PUB,edit,1350631552
Control4=IDOK,button,1342242817
Control5=IDCANCEL,button,1342242816
Control6=IDC_STATIC,static,1342308352
Control7=IDC_STATIC,static,1342308352
Control8=IDC_STATIC,static,1342308352

[CLS:CChangeBook]
Type=0
HeaderFile=ChangeBook.h
ImplementationFile=ChangeBook.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC

[DLG:IDD_QUERY]
Type=1
Class=CQueryBook
ControlCount=8
Control1=IDC_RADIO_ALL,button,1342373897
Control2=IDC_RADIO_ID,button,1342242825
Control3=IDC_RADIO_NAME,button,1342242825
Control4=IDC_RADIO_AUTHOR,button,1342242825
Control5=IDC_RADIO_PUB,button,1342242825
Control6=IDC_EDIT_STR,edit,1350631552
Control7=IDOK,button,1342242817
Control8=IDCANCEL,button,1342242816

[CLS:CQueryBook]
Type=0
HeaderFile=QueryBook.h
ImplementationFile=QueryBook.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CQueryBook

