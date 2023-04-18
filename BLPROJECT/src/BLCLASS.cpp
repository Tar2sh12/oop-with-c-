#include "BLCLASS.h"
#include <string>
using namespace std;


book_user_core::book_user_core(){
}
//-----DEFAULT USER-----
book_user_core::book_user_core(string email,string password){
   this-> account[0].email=email;
    this-> account[0].password=password;

}

//-----SYSTEM-----
void booksystem::introduction(){
        system("CLS");
        system("color 0C");
        cout<<endl<<endl<<"    ";
        for(int i=0;i<12;i++){
            cout<<"-";
            Sleep(100);
            cout<<"_";
        }
        cout<<"-";
        cout<<endl<<"    ";
        string x="< B O O K L I B R A R Y >";
        for(int i=0;i<25;i++){
            cout<<x[i];
            Sleep(150);
        }
        cout<<endl<<"    ";
        for(int i=0;i<12;i++){
            cout<<"-";
            Sleep(100);
            cout<<"_";
        }
        cout<<"-";
        cout<<endl;
        cout<<"      HELLO TO OUR PROJECT!"<<endl;
       // cout<<"";
        cout<<endl;
        //sound();
        //cout<<endl;
        cout<<"     PRESS ENTER TO CONTINUE";
        getchar();
        }
void booksystem::dlmode(){
        int choice;
        cout<<endl;
        cout<<"  [1] DARK-MODE";
        cout<<endl;
        cout<<"  [2] LIGHT-MODE";
        cout<<endl;
        cout<<"  -------------------------";
        cout<<endl;
        do{
            cout<<"  PLEASE ENTER YOUR CHOICE: ";
            cin>>choice;
            if(choice==1){
                system("color 0C");
                cout<<"  DONE!";


            }
            else if(choice==2){
                system("color F0");
                cout<<"  DONE!";
                Sleep(500);

            }else{
            cout<<"  WRONG!";
            cout<<endl;

            }
        }while(choice>2||choice<1);
}


//-----LOG/SIGN METHODS-----
void book_user_core::loginMenu(){
        system("CLS");
        cout<<endl<<endl;
        cout<<"    B O O K L I B R A R Y";
        cout<<endl<<endl;
        int choice;
        cout<<endl;
        cout<<"  [1] LOGIN";
        cout<<endl;
        cout<<"  [2] SIGNUP";
        cout<<endl;
        cout<<"  -------------------------";
        cout<<endl;
        do{
            cout<<"  PLEASE ENTER YOUR CHOICE: ";
            cin>>choice;
            if(choice==1){
                login();



            }
            else if(choice==2){
                signup();
            }else{
            cout<<"  WRONG!";
            cout<<endl;

            }
        }while(choice>2||choice<1);
}
void book_user_core::login(){

    string emailcheck;
    string passcheck;
            cout<<endl<<endl;
            cout<<"  EMAIL: ";
            cin>>emailcheck;
            cout<<"  PASSWORD: ";
            cin>>passcheck;
            cout<<"  -------------------------";
            cout<<endl;
            if(loginCheck(emailcheck,passcheck)){
                loginMenu();
            }
            cout<<"  LOGGED IN SUCCESSFULLY!";
            Sleep(1500);

            bookmenu();


}
void book_user_core::logout(){
        loginStatus=0;
        loginMenu();
}
bool book_user_core::loginCheck(string &emailcheck,string &passcheck){
        for(int i=0;i<10;i++){
            if(emailcheck==account[i].email&&passcheck==account[i].password){
                loginStatus=1;
                cout<<endl;
                loggeduser=i;
                cout<<"  LOGGED IN SUCCESSFULLY!";
                return 0;
            }


            }
            loginStatus=0;
            cout<<"  WRONG!";
            Sleep(1000);
            return 1;
    }
bool book_user_core::signCheck(string &emailcheck){
        for(int i=0;i<10;i++){
            if(emailcheck==account[i].email){
                cout<<"  EMAIL IS DUBLICATED!";
                Sleep(1000);
                loginMenu();
                return 1;
            }
        }
        return 0;
    }
void book_user_core::signup(){
    string emailcheck;
    cout<<"  NAME: ";
    cin>>account[usercount].name;
        do{

            cout<<"  EMAIL: ";
            cin>>emailcheck;
        }while(book_user_core::signCheck(emailcheck));
            account[usercount].email=emailcheck;
            cout<<"  PASSWORD: ";
            cin>>account[usercount].password;
            cout<<"  YEAROFBIRTH: ";
            cin>>account[usercount].yearofbirth;
            cout<<"  ADDRESS: ";
            cin>>account[usercount].address;
            cout<<endl;
            cout<<"  SIGNED UP SUCCESSFULLY";
            usercount++;
            Sleep(1000);
            loginMenu();
}
void book_user_core::showprofile(){
            cout<<"  NAME: "<<account[loggeduser].name;
            cout<<endl;

            cout<<"  EMAIL: "<<account[loggeduser].email;
            cout<<endl;



            cout<<"  YEAROFBIRTH: "<<account[loggeduser].yearofbirth;
            cout<<endl;
            cout<<"  ADDRESS: "<<account[loggeduser].address;
            cout<<endl;
            cout<<endl<<"  ";
            for(int i=1;i<11;i++){
                cout<<i<<" ";
                Sleep(1000);
            }
            bookmenu();


}


//-----BOOK MANAGEMENT-----

void book_user_core::bookmenu(){
    int choice;
        system("CLS");
        cout<<endl;
        cout<<"  [1] ADD BOOK";
        cout<<endl;
        cout<<"  [2] SHOW BOOKS";
        cout<<endl;
        cout<<"  [3] SEARCH BOOK";
        cout<<endl;

        cout<<"  [4] EDIT BOOK";
        cout<<endl;
        cout<<"  [5] SHOW PROFILE";
        cout<<endl;
        cout<<"  [6] LOGOUT";
        cout<<endl;
        cout<<"  -------------------------";
        cout<<endl;
        do{
            cout<<"  PLEASE ENTER YOUR CHOICE: ";
            cin>>choice;
            if(choice==1){
                //system("color 0C");
                addbook();


            }
            else if(choice==2){
                showbook();

            }
            else if(choice==3){
                searchbook();


            }
            else if(choice==5){
                showprofile();



            }else if(choice==6){
            logout();

            }
            else if(choice==4){
                editbook();
            }

            else{
            cout<<"  WRONG!";
            cout<<endl;

            }
        }while(choice>5||choice<1);

}
void book_user_core::searchbook(){
    int x=0;
    string checkbok;
    cout<<"  ENTER BOOK NAME: ";
    cin>>checkbok;
    for(int j=0;j<bookcount;j++){
        if(checkbok==bookacc[j].bookname){
            cout<<" AUTHER NAME: "<<bookacc[j].auther_name;
            cout<<endl;
            cout<<" BOOK NAME: "<<bookacc[j].bookname;
            cout<<endl;
            cout<<" YEAR PUBLISHED: "<<bookacc[j].year_pub;
            cout<<endl;
            cout<<"  CATEGORY: "<<bookacc[j].catbook;
            cout<<endl;
            cout<<"  ---------------------"<<endl;
            x++;
        }
    }
    if(x==0){
        cout<<"  BOOK IS NOT AVAILABLE!"<<endl;
    }
    cout<<"  ";
    for(int i=1;i<6;i++){
                cout<<i<<" ";
                Sleep(1000);
            }
            bookmenu();

}
bool book_user_core::bookcheck(string &bookname){
        for(int i=0;i<10;i++){
            if(bookname==bookacc[i].bookname){
                cout<<" BOOK IS ALREADY EXIST!";
                Sleep(1000);
                book_user_core::bookmenu();
                return 1;
            }
        }
        return 0;
    }
void book_user_core::addbook(){
    string booname;
    cout<<"  AUTHER NAME: ";
    cin>>bookacc[bookcount].auther_name;
    do{

            cout<<"  BOOK NAME: ";
            cin>>booname;
        }while(book_user_core::bookcheck(booname));
            bookacc[bookcount].bookname=booname;
            cout<<"  YEAR OF PUBLISHED: ";
            cin>>bookacc[bookcount].year_pub;
            cout<<"  CATEGORY: ";
            cin>>bookacc[bookcount].catbook;
            cout<<endl;
            cout<<endl;
            cout<<"  ---------------------"<<endl;
            cout<<"  BOOK ADDED SUCCESSFULLY";
            bookcount++;
            Sleep(1000);
            book_user_core::bookmenu();

}
void book_user_core::showbook(){
    for(int i=0;i<bookcount;i++){
    cout<<"  AUTHER NAME: "<<bookacc[i].auther_name;
    cout<<endl;
    cout<<"  BOOK NAME: "<<bookacc[i].bookname;
    cout<<endl;
    cout<<"  YEAR PUBLISHED: "<<bookacc[i].year_pub;
    cout<<endl;
    cout<<"  CATEGORY: "<<bookacc[i].catbook;
    cout<<endl;

    cout<<"  --------------------"<<endl;


}
cout<<"  ";
for(int i=1;i<11;i++){
                cout<<i<<" ";
                Sleep(1000);
            }
            bookmenu();
    }
void book_user_core::editbook(){
    int x=0;
    string checkbok;
    cout<<"  ENTER BOOK NAME: ";
    cin>>checkbok;
    cout<<endl;
    cout<<"  ---------------------"<<endl;
    for(int j=0;j<bookcount;j++){
        if(checkbok==bookacc[j].bookname){
            cout<<"  AUTHER NAME: ";
            cin>>bookacc[j].auther_name;
            cout<<"  BOOK NAME: ";
            cin>>bookacc[j].bookname;
            cout<<endl;
            cout<<"  YEAR PUBLISHED: ";
            cin>>bookacc[j].year_pub;

            cout<<"  CATEGORY: ";
            cin>>bookacc[j].catbook;
            cout<<"DONE!";
            Sleep(1500);

            cout<<endl<<"  ---------------------"<<endl;
            x++;
        }
    }
    if(x==0){
        cout<<endl<<"  BOOK IS NOT AVAILABLE!"<<endl;
    }
    cout<<"  ";
    for(int i=1;i<6;i++){
                cout<<i<<" ";
                Sleep(1000);
            }
            bookmenu();

}






