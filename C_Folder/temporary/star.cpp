#include<iostream>
#include<stdlib.h>

using namespace std;

void mode1(int);
void mode2(int);

int main(void) {
    int key;
    cout << "Please select a mode(1, 2): ";
    cin >> key;
    if (key == 1) {
        cout << "----Mode 1----" << endl;
    }
    else if (key == 2) {
        cout << "----Mode 2----" << endl;
    }
    else {
        cout << "Mode Error..." << endl;
        return 0;
    }
    int temp;
    cout << "Please enter the number of lines: ";
    cin >> temp;
    if (key == 1) {
        mode1(temp);
    }
    else {
        mode2(temp);
    }
    cout << "Finished!";
    getchar();
    return 0;
}

void mode1(int row) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < row - i - 1; j++) {
            cout << " ";
        }
        for (int j = 0; j < 2 * i + 1; j++) {
            cout << "*";
        }
        cout << endl;
    }
}

void mode2(int row) {
    for (int i = 0; i < row - 1; i++) {
        for (int j = 0; j < row - i - 1; j++) {
            cout << " ";
        }
        for (int j = 0; j < 2 * i + 1; j++) {
            if (j == 0 || j == 2 * i) {
                cout << "*";
            }
            else {
                cout << " ";
            }
        }
        cout << endl;
    }
    for (int i = 0; i < 2 * row - 1; i++) {
        cout << "*";
    }
    cout << endl;
}
