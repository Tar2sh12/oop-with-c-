#include <iostream>
#include "BLCLASS.h"
#include <conio.h>
#include <windows.h>

using namespace std;


int main()
{
    booksystem x;
    book_user_core users("admin","admin");
    x.introduction();
    x.dlmode();
    users.loginMenu();
    return 0;
}
