// C++����lt715.cpp 
#include <iostream.h>
extern "C" {long isum(int,int *);}
int imin(int,int *);
void main(void)
{
    const int SIZE=10;
    int array[SIZE];
    int temp;
	cout<<"������10��������-2147483648 ~ 2147483647֮�䣩��"<<endl;
    for(temp=0;temp<SIZE;temp++)
    cin>>array[temp];
   	cout<<endl;
    cout<<"��������֮��Ϊ��\t"<<isum(SIZE,array)<<endl;
    cout<<"������СֵΪ��\t"<<imin(SIZE,array)<<endl;
}
int imin(int itmp,int iarray[])
{
__asm {
	mov ecx,itmp
	jecxz minexit
	dec ecx
	mov esi,iarray
	mov eax,[esi]
	jecxz minexit
minlp:	add esi,4
	cmp eax,[esi]	;�Ƚ��������ݵĴ�С
	jle nochange
	mov eax,[esi]	;ȡ�ý�Сֵ
nochange:	loop minlp
minexit: 
	}
}