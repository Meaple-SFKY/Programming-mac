;lt612f.asm for MASM32
    .386
    .model flat,stdcall
    option casemap:none
    include include\windows.inc
    include include\kernel32.inc
    include include\user32.inc
    includelib lib\kernel32.lib
    includelib lib\user32.lib
    .data
szCaption   db 'Win32ʾ��',0
szText  db '��ӭ����32λWindows����!',0
    .code
start:
    invoke MessageBox,NULL,addr szText, addr szCaption,MB_OK
    invoke ExitProcess,NULL
end start