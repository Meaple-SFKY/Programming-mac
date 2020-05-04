#include <cstdlib>
#include <iostream>
#include <map>
#include <string>

using namespace std;

typedef map<string, int> Phone_Book;

void call(Phone_Book pb, string name)
{
    cout << "calling ... " << pb[name] << endl;
}

int main(int argc, char *argv[])
{
    map<string, int> phone_book;
    phone_book["zhangsan"] = 2901101;
    phone_book["LiSi"] = 2903105;
    call(phone_book, "LiSi");
    system("read -p 'Press Enter to continue...' var");
    return EXIT_SUCCESS;
}