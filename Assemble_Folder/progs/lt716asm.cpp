// lt716asm.cpp
# include <iostream.h>
bool findArray(int searchVal, int array[], int count);
void main (void)
{
	const int SIZE=10000;
	int array[SIZE];
	int temp1,temp2;
	for( int i=0; i<=SIZE; i++) array[i]=0;
	__asm 	{
			rdtsc
			mov temp1,eax
			mov temp2,edx 	}
	findArray(100,array,SIZE);
	__asm 	{
			rdtsc
			sub eax,temp1
			sbb edx,temp2
			mov temp1,eax
			mov temp2,edx 	}
	cout<<"����ִ�е�ʱ����������  "<<temp1+temp2*(2^32)<<endl;
}
bool findArray(int searchVal, int array[], int count)
{
__asm 	{
		mov ecx,count
		jecxz notfound	;�������Ԫ�ظ���Ϊ0�����˳�
		mov edi,array
		mov eax,searchVal
again:		cmp eax,[edi]
		je found
		add edi,4
		loop again
notfound:		xor al,al
		jmp done
found:		mov al,1
done:
		}
}