#include <iostream>
#include <string>

using namespace std;

char* reverse(char* s) {
    char t1, t2, * a1 = s, *a2, * b1, * b2 = s;
    while(*b2) {
        b2++;
    }
    cout << "b2 = " << b2 << endl;
    b2--;
    cout << "b2 = " << b2 << endl;
    a2 = a1 + 1;
    cout << "a2 = " << a2 << endl; 
    b1 = b2 - 1;
    cout << "b1 = " << b1 << endl;
    t1 = * a1;
    cout << "t1 = " << t1 << endl;
    * a1 = * b1;
    cout << "a1 = " << a1 << endl;
    * b1 = t1;
    cout << "b1 = " << b1 << endl;
    t2 = * a2;
    cout << "t2 = " << t2 << endl;
    * a2 = * b2;
    cout << "a2 = " << a2 << endl;
    * b2 = t2;
    cout << "b2 = " << b2 << endl;
    a1 += 2;
    cout << "a1 = " << a1 << endl;
    b2 -= 2;
    cout << "b2 = " << b2 << endl;
    return s;
}

int main(void) {
    char c[10] = "seshxi";
    char b[40] = "jisuseofnajgsh和suzhsh";
    char* sp = NULL;
    cout << reverse(c) << endl;
    sp = b + 4;
    cout << reverse(sp) << endl;
    return 0;
}