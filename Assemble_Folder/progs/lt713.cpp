// C++����lt713.cpp 
#include <iostream.h>
int power2(int,int);
void main(void)
{
    cout<<"2��6�η���5���ڣ�\t";
    cout<<power2(5,6)<<endl;
}
int power2(int num,int power);
{
__asm
{
     mov eax,num
     mov ecx,power
     shl eax,cl
}
}
