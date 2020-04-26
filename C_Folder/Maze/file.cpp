#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main(void) {
    string temp;
    ifstream myFile("hello.txt");
    if (!myFile.is_open()) {
        cout << "File failed to open." << endl;
    }
    while (getline(myFile, temp)) {
        cout << temp << endl;
    }
    myFile.close();
    return 0;
}