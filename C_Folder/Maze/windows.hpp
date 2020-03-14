#ifndef _WINDOWS_HPP_
#define _WINDOWS_HPP_

#include<iostream>
#include<windows.h>
#include<cstdlib>

using namespace std;

class Window
{
    private:
        short XCOORD;
        short YCOORD;

    public:
        Window(short x, short y);
        ~Window();
        void SetWindowSize(short x, short y);
        void SetWindowTitle(const TCHAR* title);
        void CleanWindow(void);
};

Window::Window(short x, short y)
{
    XCOORD = x;
    YCOORD = y;
}

Window::~Window()
{
    cout << "Bye~" << endl;
};

void Window::SetWindowSize(short x, short y)
{
    system("mode con cols=%hd lines=%hd");
}

void Window::SetWindowTitle(const TCHAR* title)
{
    SetConsoleTitle(title);
}

void Window::CleanWindow(void)
{
    system("cls");
}

#endif