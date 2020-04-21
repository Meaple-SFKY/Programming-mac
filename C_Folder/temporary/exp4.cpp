#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int main(void) {
    int i;
    cin >> i;
    fflush(stdin);
    string *s = new string[i];
    for (int j = 0; j < i; j++) {
        getline(cin, s[j]);
    }
    for (int j = 0; j < i; j++) {
        reverse(s[j].begin(), s[j].end());
    }
    for (int j = 0; j < i; j++) {
        cout << s[j] << endl;
    }

    return 0;
}