;lt614.asm
	.386
	.model flat,stdcall
	option casemap:none
	include include\windows.inc
	include include\kernel32.inc
	include include\user32.inc
	includelib lib\kernel32.lib 
	includelib lib\user32.lib
WinMain	proto :DWORD,:DWORD,:DWORD,:DWORD
	.data	;���г�ֵ�����ݶζ��壨���ʱ��������ռ䣩
ClassName	db "SimpleWinClass",0	;����������
AppName	db "Win32ʾ��",0	;������

szText	db '��ӭ����32λWindows���磡',0

	.data?	;û�г�ֵ�����ݶζ��壨����ʱ��������ռ䣩
hInstance	dd ?	;Ӧ�ó���ʵ�����
CommandLine dd ?	;�����в�����ַָ��
	.code
start:	;����������
	invoke GetModuleHandle, NULL
	mov    hInstance,eax	;���ʵ�����������
	invoke GetCommandLine
	mov    CommandLine,eax	;��������в�����ַָ�룬����
	invoke WinMain, hInstance,NULL,CommandLine, SW_SHOWDEFAULT
	invoke ExitProcess,eax
	;WinMain������
WinMain proc hInst:DWORD ,hPrevInst:DWORD,CmdLine:DWORD,CmdShow:DWORD
	LOCAL wc:WNDCLASSEX	;���崰�����ԵĽṹ����
	LOCAL msg:MSG	;������Ϣ����
	LOCAL hwnd:DWORD	;���崰�ھ������
	;��ʼ�����������
	mov   wc.cbSize,SIZEOF WNDCLASSEX
	mov   wc.style,CS_HREDRAW or CS_VREDRAW
	mov   wc.lpfnWndProc, OFFSET WndProc	;WndProc�Ǵ��ڹ���
	mov   wc.cbClsExtra,NULL
	mov   wc.cbWndExtra,NULL
	push  hInstance
	pop   wc.hInstance
	mov   wc.hbrBackground,COLOR_WINDOW+1
	mov   wc.lpszMenuName,NULL	;û��ʹ�ò˵���
	mov   wc.lpszClassName,OFFSET ClassName
	invoke LoadIcon,NULL,IDI_APPLICATION	;���ϵͳ��׼ͼ��
	mov   wc.hIcon,eax
	mov   wc.hIconSm,eax
	invoke LoadCursor,NULL,IDC_ARROW	;���ϵͳ��׼���
	mov   wc.hCursor,eax
	invoke RegisterClassEx, addr wc	;ע�ᴰ����
	INVOKE CreateWindowEx,NULL,ADDR ClassName,ADDR AppName,\
	WS_OVERLAPPEDWINDOW,CW_USEDEFAULT, CW_USEDEFAULT,\
	CW_USEDEFAULT,CW_USEDEFAULT,NULL,NULL, hInst,NULL
	mov   hwnd,eax	;�������ڣ���������
	invoke ShowWindow, hwnd,SW_SHOWNORMAL	;��ʾ����
	invoke UpdateWindow, hwnd	;���´���
	.WHILE TRUE	;��Ϣѭ��
	invoke GetMessage, ADDR msg,NULL,0,0	;�����Ϣ
	.BREAK .IF (!eax)
	;.WHILE TRUE�γ�������ѭ�����˴���EAX����0������ѭ��
	invoke TranslateMessage, ADDR msg	;������Ϣ
	invoke DispatchMessage, ADDR msg	;������Ϣ
	.ENDW
	mov     eax,msg.wParam
	ret
WinMain endp
;���ڹ���
WndProc proc hWnd:DWORD, uMsg:DWORD, wParam:DWORD, lParam:DWORD
	.IF uMsg==WM_DESTROY
	invoke PostQuitMessage,NULL	;����رճ������Ϣ

	.ELSEIF uMsg==WM_LBUTTONDOWN	;����������������Ϣ
	invoke MessageBox,NULL,addr szText, addr AppName,MB_OK

	.ELSE	;���������Ϣ��ϵͳĬ�ϲ���
	invoke DefWindowProc,hWnd,uMsg,wParam,lParam		
            ret
	.ENDIF
	xor eax,eax
	ret
WndProc	endp
end start
