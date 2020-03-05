#include <iostream>
#include <string>
#include "windows.h"
#include "functions.hpp"

using namespace std;

sys state_init();
void state_update();
void state_exit();

int main()
{
    sys home = state_init();
    display_init(3);
    proc_login(home);
    proc_main(home);
}

sys state_init() 
{
    sys local_system("LOAN-DEPT-03", "jerry", "mypassword");
    return local_system;
}