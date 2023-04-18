#ifndef BLCLASS_H
#define BLCLASS_H
#include <iostream>
#include <string>
//#include <conio.h>
#include <windows.h>

using namespace std;


class booksystem
{
    public:
        void introduction();
        void dlmode();
       // void sound();
};




class book_user_core
{
    public:
        book_user_core();
        book_user_core(string,string);
        void showprofile();
        void bookmenu();
        void loginMenu();
        void login();
        void signup();
        void logout();
        bool loginCheck(string&,string&);
        bool signCheck(string&);

    protected:


    public:

       int loggeduser;
       int usercount=0;
       bool loginStatus=0;
       struct {
       string name;
       string yearofbirth;
       string email;
       string password;
       string address;

       }account[10];


       public:
        int bookcount=0;
        struct{
        string bookname;
        string year_pub;
        string auther_name;
        string catbook;
        }bookacc[10];

    public:

        void editbook();
        void addbook();
        void showbook();
        bool bookcheck(string&);
        void showbooks();
        void searchbook();

};






#endif // BLCLASS_H



