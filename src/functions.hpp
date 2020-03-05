#include <iostream>
#include <string>
#include "Windows.h"
#include "objects.hpp"

using namespace std;
void display_init();
void display_login();
void set_color(int color);

void set_color(int color)
{
    HANDLE hConsole;

    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}

void display_init(int time)
{
    int counter = 0;

    cout << "Initializing system";
    cout << ".";
    Sleep(500);
    cout << ".";
    Sleep(500);
    cout << ".";

    while(counter < time)
    {
        cout << flush;
        Sleep(500);
        cout << "\b\b\b   \b\b\b";
        Sleep(500);
        cout << ".";
        Sleep(500);
        cout << ".";
        Sleep(500);
        cout << ".";
        
        counter++;
    }
    cout << endl;
    cout << "Disks: ";
    set_color(2);
    cout << "ONLINE" << endl;
    set_color(15);
    cout << "Checking file system..." << endl;
    Sleep(1000);
    cout << "Memory: ";
    set_color(2);
    Sleep(3000);
    cout << "NOERROR" << endl;
    set_color(15);
    Sleep(300);
    cout << "Network: ";
    set_color(4);
    Sleep(300);
    cout << "NOT CONNECTED!" << endl;
    Sleep(300);
    set_color(15);
    cout << "System up!" << endl;

    display_login();

}

void display_login()
{
    cout << "Entering user mode";
    Sleep(500);
    cout << ".";
    Sleep(500);
    cout << ".";
    Sleep(500);
    cout << ".";
    cout << endl;
    cout << "User: ";
}

void proc_login(sys sys_home)
{
    string username;
    string password;

    getline(cin, username);
    cout << "Password: ";
    getline(cin, password);
    cout << endl;

    if(sys_home.check_user(username))
    {
        string current_key = sys_home.security.encode(username, password);
        if(current_key == sys_home.get_local_key())
        {
            sys_home.grant_access(username);
            
        }else 
        {
            cout << "Incorrect credentials" << endl;
        }
    }else
    {
        cout << "Incorrect credentials" << endl;
    }
}

void proc_command()
{
    string command;
    getline(cin, command);
}

void proc_main(sys local_sys)
{
    while(local_sys.isAuthorized())
    {
        cout << local_sys.get_user() << "@" << local_sys.hostname << "> ";
        proc_command();
    }
}