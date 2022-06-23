/*
  AIO V4.5

  Copyright (c) 2021 , AIO

  License : GNU General Publish License V4.3

  This program is a free software, you can use it by obtaining a license from the manufacturer (taha.hoveidapour84@gmail.com)
  or change it under legal copyright conditions.
  Once you get the license, you can use all subsequent versions of this software

  This app is an almost complete software with the name AIO means All In One .
  you can use its features such as calculator - convert sentences and numbers to binary - BMI calculation - save text and ....

  Its code is written in C++ language and has no graphical environment and is for use in CMD environment.
  If you see any bugs or need help , send a message to AIO Support.

  from : #Taha_hdp
*/
//- library
#include <iostream>
#include <windows.h>
#include <fstream>
#include <stdlib.h>
#include <cmath>
#include <string>
#include <conio.h>
#include <cstdlib>
#include <bitset>
//- using standard
using std::cout ;
using std::cin ;
using std::string ;
using std::fstream ;
using std::ios ;
using std::bitset ;
//- defines
#define version 4.5
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
//- global variables
bool acount_check = false , exit_type = false , write_check = true , logout_check = false , end_app = false , noacc = false , back_to_menu = false ;
char LOS , menu , exit_ask ;// LOS = Login Or Signup
int massch = 0 , contact = 0 , UAPC = 0 ; // User And Pass Check
string user{} , pass{} , userch[10] , passch[10] , New_Text , Open_Text , Exit_or_Text , User_Message , twitts , user_twitt ;
string filesname = "usertext" ,  messagename = "message text " ;
//- compact file name
char numstr[21];
string usertext = filesname + itoa(UAPC, numstr, 10);
char messagestr[21];
string messagetext = messagename + itoa(contact, messagestr, 10);
char incomestr[21];
string incomingtext = messagename + itoa(UAPC, incomestr, 10);
//- snake game variables
bool gameover;
int width = 20 , height = 17;
int x, y, fruitX, fruitY, score , nTail;
int tailX[100], tailY[100]; //snake coordinates
enum eDirecton {STOP = 0, LEFT, RIGHT, UP, DOWN}; // Controls
eDirecton dir;
//- functions
void welcome();
void LoginOrSignup();
void noaccount() ;
int  signup();
int  login();
void menuPage();
void note();
int  messager();
int  twitter();
int  setting();
void logout();
void calculator();
void DECtoBIN();
void AppInfo();
void BMI();
void game();
void invalidError();
void resetbool();
void end();
//- main function
int main() {
  welcome();
  while (true) {
    resetbool();
    while (true) {
      LoginOrSignup();
      switch (LOS) {
        case 'S' :  if (signup() == 1) {
            break ;
          }
        case 'L' :  if (login() == 1) {
            break ;
          }
        case 'E' :  end();
        return 0 ;
      }
      if (noacc == true) {
        noaccount() ;
      }
      if (acount_check == true) {
        break ;
      }
      if (end_app == true) {
        break ;
      }
      invalidError();
    }
    if (end_app == true) {
      break ;
    }
    while (true) {
      exit_type = false , back_to_menu = false ;
      menuPage();
      switch (menu) {
        case 'C'  :  calculator();
          break;
        case 'I'  :  AppInfo();
          break;
        case 'B'  :  BMI();
          break;
        case 'D'  :  DECtoBIN();
          break;
        case 'N'  :  note();
          break;
        case 'L'  :  logout();
          break;
        case 'M'  :  
          if (messager() == 1) {
            break ;
          }
          break;
        case 'T'  :  
          if (twitter() == 1) {
            break ;
          }
          break;
        case 'S'  :  
          if (setting() == 1) {
            break ;
          }
          break;
        case 'G'  :  game();
          break;
        case 'E'  :  end();
          return 0 ;
        default   :  invalidError();
          break;
      }
      if (exit_type == true ) {
        break ;
      }
      if (logout_check == true ) {
        break ;
      }
    }
    if (exit_type == true ) {
      break ;
    }
  }
  return 0;
}
void welcome() {
  Sleep(2000);
  system("cls");
  cout << "       :::                \n";
  Sleep(100);
  cout << "       :::                \n";
  Sleep(100);
  cout << "      ::::::::::::::      \n";
  Sleep(100);
  cout << "    :: ::  ::       ::    \n";
  Sleep(100);
  cout << "  ::   ::   ::        ::  \n";
  Sleep(100);
  cout << " ::    ::    ::        :: \n";
  Sleep(100);
  cout << "::     ::     ::        ::\n";
  Sleep(100);
  cout << "::     ::      ::       ::\n";
  Sleep(100);
  cout << "::     :::::::::::      ::\n";
  Sleep(100);
  cout << "::     ::        ::     ::\n";
  Sleep(100);
  cout << " ::    ::         ::   :: \n";
  Sleep(100);
  cout << "  :::  ::          :: ::  \n";
  Sleep(100);
  cout << "    :: ::           ::    \n";
  Sleep(100);
  cout << "      ::::::::::::::     AIO V" << version << '\n';
  Sleep(3000);
  system("cls");
  for (int i = 1 ; i <= 2 ; i++) {
    cout << "   :      \n";
    cout << "  ::::::: \n";
    cout << " : | \\   : \n";
    cout << ":  |--\\   :\n";
    cout << " : |   \\ : \n";
    cout << ": ::::::: ::::::::::::::::::::::::::::::::::::::::::\n" ;
    cout << ":: WELCOME TO THE 'AIO' (V " << version << ")\n";
    cout << ":: PLEASE WAIT TO LOAD APP DATA \n";
    cout << ":: LOADING";
    Sleep(400);
    for (int j = 1 ; j <= 3 ; j++) {
      cout << "." ;
      Sleep(400);
    }
    system("cls");
  }
}
//- errors and notic
void resetbool(){
  acount_check = false , exit_type = false , write_check = true , logout_check = false , end_app = false , noacc = false , back_to_menu = false ;
}
void invalidError() {
  system ("CLS");
  cout << "::::::::::::::::::::\n";
  cout << "::   Not valid !  ::\n";
  cout << "::   try agane    ::\n";
  cout << "::::::::::::::::::::\n";
  Sleep(500);
}
void pleasewait() {
  cout << ":: please wait";
  Sleep(400);
  for (int j = 1 ; j <= 3 ; j++) {
    cout << "." ;
    Sleep(400);
  }
}
//- first page : login & signup
void noaccount() {
  cout << "No account has been created in this program !\nYou must create an account first";
  Sleep(2000);
}
void loginbold() {
  system("cls");
  cout << "   :      \n";
  cout << "  ::::::: \n";
  cout << " : | \\   : \n";
  cout << ":  |--\\   :\n";
  cout << " : |   \\ : \n";
  cout << ": :::::::: :::::::::::::::::::::::::::::\n";
  cout << "::   PLEASE LOGIN TO YOUR ACCOUNT     ::\n";
  cout << "::   dont have account ? creat now .  ::\n";
  cout << ":: :::::::::::::::                    ::\n";
  cout << ":: ::   login   ::      signup        ::\n";
  cout << ":: :::::::::::::::                    ::\n";
  cout << "::      Exit                          ::\n";
  cout << "::                                    ::\n";
  cout << "::::::::::::::::::::::::::::::::::::::::\n";
}
void signupbold() {
  system("cls");
  cout << "   :      \n";
  cout << "  ::::::: \n";
  cout << " : | \\   : \n";
  cout << ":  |--\\   :\n";
  cout << " : |   \\ : \n";
  cout << ": :::::::: :::::::::::::::::::::::::::::\n";
  cout << "::   PLEASE LOGIN TO YOUR ACCOUNT     ::\n";
  cout << "::   dont have account ? creat now .  ::\n";
  cout << "::                 ::::::::::::::::   ::\n";
  cout << "::      login      ::   signup   ::   ::\n";
  cout << "::                 ::::::::::::::::   ::\n";
  cout << "::      Exit                          ::\n";
  cout << "::                                    ::\n";
  cout << "::::::::::::::::::::::::::::::::::::::::\n";
}
void exitbold() {
  system("cls");
  cout << "   :      \n";
  cout << "  ::::::: \n";
  cout << " : | \\   : \n";
  cout << ":  |--\\   :\n";
  cout << " : |   \\ : \n";
  cout << ": :::::::: :::::::::::::::::::::::::::::\n";
  cout << "::   PLEASE LOGIN TO YOUR ACCOUNT     ::\n";
  cout << "::   dont have account ? creat now .  ::\n";
  cout << "::                                    ::\n";
  cout << "::      login           signup        ::\n";
  cout << ":: ::::::::::::::                     ::\n";
  cout << ":: ::   Exit   ::                     ::\n";
  cout << ":: ::::::::::::::                     ::\n";
  cout << "::::::::::::::::::::::::::::::::::::::::\n";
}
void LoginOrSignup() {
  loginbold();
  acount_check = false ;
  int x = 1 , y = 1 ;
  while (true) {
    switch (LOS = getch()) {
      case KEY_DOWN:
        if (x < 2) {
          x = x + 1 ;
        }
        else {
          x = 1 ;
        }
        break;
      case KEY_UP:
        if (x > 1) {
          x = x - 1 ;
        }
        else {
          x = 2 ;
        }
        break;
      case KEY_RIGHT:
        x = 1 ;
        y = 2 ;
        break;
      case KEY_LEFT:
        x = 1 ;
        y = 1 ;
        break;
    }
    if (x == 1 && y == 1) {
      loginbold();
    }
    else if (x == 2 && y == 1) {
      exitbold();
    }
    else if (x == 1 && y == 2) {
      signupbold();
    }
    if (LOS == 13) {
      break ;
    }
  }
  if (x == 1 && y == 1) {
    LOS = 'L' ;
  }
  else if (x == 2 && y == 1) {
    LOS = 'E' ;
  }
  else if (x == 1 && y == 2) {
    LOS = 'S' ;
  }
}
//- signup
void userbold0(){
    system("cls");
    cout << "   :      \n";
    cout << "  ::::::: \n";
    cout << " : | \\   : \n";
    cout << ":  |--\\   :\n";
    cout << " : |   \\ : \n";
    cout << ": ::::::: ::::::::::::::::::::::::::::::::\n";
    cout << "::        Creat TO YOUR ACCOUNT         ::\n";
    cout << "::                                      ::\n";
    cout << ":: ------------:::::::::::::::::::::::  ::\n";
    cout << ":: |username : ::*****************  ::  ::\n";
    cout << ":: ------------:::::::::::::::::::::::  ::\n";
    cout << "::                                      ::\n";
    cout << ":: -----------------------------------  ::\n";
    cout << ":: |password :                       |  ::\n";
    cout << ":: -----------------------------------  ::\n";
    cout << "::                                      ::\n";
    cout << "::    Enter                             ::\n";
    cout << "::                                      ::\n";
    cout << "::::::::::::::::::::::::::::::::::::::::::\n";
}
void userbold1(){
    system("cls");
    cout << "   :      \n";
    cout << "  ::::::: \n";
    cout << " : | \\   : \n";
    cout << ":  |--\\   :\n";
    cout << " : |   \\ : \n";
    cout << ": ::::::: ::::::::::::::::::::::::::::::::\n";
    cout << "::        Creat TO YOUR ACCOUNT         ::\n";
    cout << "::                                      ::\n";
    cout << ":: ------------:::::::::::::::::::::::  ::\n";
    cout << ":: |username : ::                   ::  ::\n";
    cout << ":: ------------:::::::::::::::::::::::  ::\n";
    cout << "::                                      ::\n";
    cout << ":: -----------------------------------  ::\n";
    cout << ":: |password :                       |  ::\n";
    cout << ":: -----------------------------------  ::\n";
    cout << "::                                      ::\n";
    cout << "::    Enter                             ::\n";
    cout << "::                                      ::\n";
    cout << "::::::::::::::::::::::::::::::::::::::::::\n";
}
void userbold2(){
    system("cls");
    cout << "   :      \n";
    cout << "  ::::::: \n";
    cout << " : | \\   : \n";
    cout << ":  |--\\   :\n";
    cout << " : |   \\ : \n";
    cout << ": ::::::: ::::::::::::::::::::::::::::::::\n";
    cout << "::        Creat TO YOUR ACCOUNT         ::\n";
    cout << "::                                      ::\n";
    cout << ":: ------------:::::::::::::::::::::::  ::\n";
    cout << ":: |username : ::                   ::  ::\n";
    cout << ":: ------------:::::::::::::::::::::::  ::\n";
    cout << "::                                      ::\n";
    cout << ":: -----------------------------------  ::\n";
    cout << ":: |password :   *****************   |  ::\n";
    cout << ":: -----------------------------------  ::\n";
    cout << "::                                      ::\n";
    cout << "::    Enter                             ::\n";
    cout << "::                                      ::\n";
    cout << "::::::::::::::::::::::::::::::::::::::::::\n";
}
void userbold3(){
    system("cls");
    cout << "   :      \n";
    cout << "  ::::::: \n";
    cout << " : | \\   : \n";
    cout << ":  |--\\   :\n";
    cout << " : |   \\ : \n";
    cout << ": ::::::: ::::::::::::::::::::::::::::::::\n";
    cout << "::        Creat TO YOUR ACCOUNT         ::\n";
    cout << "::                                      ::\n";
    cout << ":: ------------:::::::::::::::::::::::  ::\n";
    cout << ":: |username : ::*****************  ::  ::\n";
    cout << ":: ------------:::::::::::::::::::::::  ::\n";
    cout << "::                                      ::\n";
    cout << ":: -----------------------------------  ::\n";
    cout << ":: |password :   *****************   |  ::\n";
    cout << ":: -----------------------------------  ::\n";
    cout << "::                                      ::\n";
    cout << "::    Enter                             ::\n";
    cout << "::                                      ::\n";
    cout << "::::::::::::::::::::::::::::::::::::::::::\n";
}
void passbold0(){
    system("cls");
    cout << "   :      \n";
    cout << "  ::::::: \n";
    cout << " : | \\   : \n";
    cout << ":  |--\\   :\n";
    cout << " : |   \\ : \n";
    cout << ": ::::::: ::::::::::::::::::::::::::::::::\n";
    cout << "::        Creat TO YOUR ACCOUNT         ::\n";
    cout << "::                                      ::\n";
    cout << ":: -----------------------------------  ::\n";
    cout << ":: |username :   *****************   |  ::\n";
    cout << ":: -----------------------------------  ::\n";
    cout << "::                                      ::\n";
    cout << ":: ------------:::::::::::::::::::::::  ::\n";
    cout << ":: |password : ::                   ::  ::\n";
    cout << ":: ------------:::::::::::::::::::::::  ::\n";
    cout << "::                                      ::\n";
    cout << "::    Enter                             ::\n";
    cout << "::                                      ::\n";
    cout << "::::::::::::::::::::::::::::::::::::::::::\n";
}
void passbold1(){
    system("cls");
    cout << "   :      \n";
    cout << "  ::::::: \n";
    cout << " : | \\   : \n";
    cout << ":  |--\\   :\n";
    cout << " : |   \\ : \n";
    cout << ": ::::::: ::::::::::::::::::::::::::::::::\n";
    cout << "::        Creat TO YOUR ACCOUNT         ::\n";
    cout << "::                                      ::\n";
    cout << ":: -----------------------------------  ::\n";
    cout << ":: |username :                       |  ::\n";
    cout << ":: -----------------------------------  ::\n";
    cout << "::                                      ::\n";
    cout << ":: ------------:::::::::::::::::::::::  ::\n";
    cout << ":: |password : ::*****************  ::  ::\n";
    cout << ":: ------------:::::::::::::::::::::::  ::\n";
    cout << "::                                      ::\n";
    cout << "::    Enter                             ::\n";
    cout << "::                                      ::\n";
    cout << "::::::::::::::::::::::::::::::::::::::::::\n";
}
void passbold2(){
    system("cls");
    cout << "   :      \n";
    cout << "  ::::::: \n";
    cout << " : | \\   : \n";
    cout << ":  |--\\   :\n";
    cout << " : |   \\ : \n";
    cout << ": ::::::: ::::::::::::::::::::::::::::::::\n";
    cout << "::        Creat TO YOUR ACCOUNT         ::\n";
    cout << "::                                      ::\n";
    cout << ":: -----------------------------------  ::\n";
    cout << ":: |username :   *****************   |  ::\n";
    cout << ":: -----------------------------------  ::\n";
    cout << "::                                      ::\n";
    cout << ":: ------------:::::::::::::::::::::::  ::\n";
    cout << ":: |password : ::*****************  ::  ::\n";
    cout << ":: ------------:::::::::::::::::::::::  ::\n";
    cout << "::                                      ::\n";
    cout << "::    Enter                             ::\n";
    cout << "::                                      ::\n";
    cout << "::::::::::::::::::::::::::::::::::::::::::\n";
}
void passbold3(){
    system("cls");
    cout << "   :      \n";
    cout << "  ::::::: \n";
    cout << " : | \\   : \n";
    cout << ":  |--\\   :\n";
    cout << " : |   \\ : \n";
    cout << ": ::::::: ::::::::::::::::::::::::::::::::\n";
    cout << "::        Creat TO YOUR ACCOUNT         ::\n";
    cout << "::                                      ::\n";
    cout << ":: -----------------------------------  ::\n";
    cout << ":: |username :                       |  ::\n";
    cout << ":: -----------------------------------  ::\n";
    cout << "::                                      ::\n";
    cout << ":: ------------:::::::::::::::::::::::  ::\n";
    cout << ":: |password : ::                   ::  ::\n";
    cout << ":: ------------:::::::::::::::::::::::  ::\n";
    cout << "::                                      ::\n";
    cout << "::    Enter                             ::\n";
    cout << "::                                      ::\n";
    cout << "::::::::::::::::::::::::::::::::::::::::::\n";
}
void sinupenterbold0(){
    system("cls");
    cout << "   :      \n";
    cout << "  ::::::: \n";
    cout << " : | \\   : \n";
    cout << ":  |--\\   :\n";
    cout << " : |   \\ : \n";
    cout << ": ::::::: ::::::::::::::::::::::::::::::::\n";
    cout << "::        Creat TO YOUR ACCOUNT         ::\n";
    cout << "::                                      ::\n";
    cout << ":: -----------------------------------  ::\n";
    cout << ":: |username :   *****************   |  ::\n";
    cout << ":: -----------------------------------  ::\n";
    cout << "::                                      ::\n";
    cout << ":: -----------------------------------  ::\n";
    cout << ":: |password :                       |  ::\n";
    cout << ":: -----------------------------------  ::\n";
    cout << ":: :::::::::::                          ::\n";
    cout << ":: :: Enter ::                          ::\n";
    cout << ":: :::::::::::                          ::\n";
    cout << "::::::::::::::::::::::::::::::::::::::::::\n";
}
void sinupenterbold1(){
    system("cls");
    cout << "   :      \n";
    cout << "  ::::::: \n";
    cout << " : | \\   : \n";
    cout << ":  |--\\   :\n";
    cout << " : |   \\ : \n";
    cout << ": ::::::: ::::::::::::::::::::::::::::::::\n";
    cout << "::        Creat TO YOUR ACCOUNT         ::\n";
    cout << "::                                      ::\n";
    cout << ":: -----------------------------------  ::\n";
    cout << ":: |username :                       |  ::\n";
    cout << ":: -----------------------------------  ::\n";
    cout << "::                                      ::\n";
    cout << ":: -----------------------------------  ::\n";
    cout << ":: |password :   *****************   |  ::\n";
    cout << ":: -----------------------------------  ::\n";
    cout << ":: :::::::::::                          ::\n";
    cout << ":: :: Enter ::                          ::\n";
    cout << ":: :::::::::::                          ::\n";
    cout << "::::::::::::::::::::::::::::::::::::::::::\n";
}
void sinupenterbold2(){
    system("cls");
    cout << "   :      \n";
    cout << "  ::::::: \n";
    cout << " : | \\   : \n";
    cout << ":  |--\\   :\n";
    cout << " : |   \\ : \n";
    cout << ": ::::::: ::::::::::::::::::::::::::::::::\n";
    cout << "::        Creat TO YOUR ACCOUNT         ::\n";
    cout << "::                                      ::\n";
    cout << ":: -----------------------------------  ::\n";
    cout << ":: |username :   *****************   |  ::\n";
    cout << ":: -----------------------------------  ::\n";
    cout << "::                                      ::\n";
    cout << ":: -----------------------------------  ::\n";
    cout << ":: |password :   *****************   |  ::\n";
    cout << ":: -----------------------------------  ::\n";
    cout << ":: :::::::::::                          ::\n";
    cout << ":: :: Enter ::                          ::\n";
    cout << ":: :::::::::::                          ::\n";
    cout << "::::::::::::::::::::::::::::::::::::::::::\n";
}
void sinupenterbold3(){
    system("cls");
    cout << "   :      \n";
    cout << "  ::::::: \n";
    cout << " : | \\   : \n";
    cout << ":  |--\\   :\n";
    cout << " : |   \\ : \n";
    cout << ": ::::::: ::::::::::::::::::::::::::::::::\n";
    cout << "::        Creat TO YOUR ACCOUNT         ::\n";
    cout << "::                                      ::\n";
    cout << ":: -----------------------------------  ::\n";
    cout << ":: |username :                       |  ::\n";
    cout << ":: -----------------------------------  ::\n";
    cout << "::                                      ::\n";
    cout << ":: -----------------------------------  ::\n";
    cout << ":: |password :                       |  ::\n";
    cout << ":: -----------------------------------  ::\n";
    cout << ":: :::::::::::                          ::\n";
    cout << ":: :: Enter ::                          ::\n";
    cout << ":: :::::::::::                          ::\n";
    cout << "::::::::::::::::::::::::::::::::::::::::::\n";
}
void userbold(){
    if(user!="" && pass==""){
        userbold0();
    }
    else if (user=="" && pass!=""){
        userbold2();
    }
    else if (user!="" && pass!=""){
        userbold3();
    }
    else{
        userbold1();
    }
}
void passbold(){
    if(user!="" && pass==""){
        passbold0();
    }
    else if (user=="" && pass!=""){
        passbold1();
    }
    else if (user!="" && pass!=""){
        passbold2();
    }
    else{
        passbold3();
    }
}
void sinupenterbold(){
   if(user!="" && pass==""){
        sinupenterbold0();
    }
    else if (user=="" && pass!=""){
        sinupenterbold1();
    }
    else if (user!="" && pass!=""){
        sinupenterbold2();
    }
    else{
        sinupenterbold3();
    } 
}
void getusername(){
    system("cls");
    cout << ":::::::::::::::::::::::::::::::::::::::::\n" ;
    cout << ":: Creat your username :" ;
    cin >> user ;
    system("cls");
}
void getpassword(){
    system("cls");
    cout << ":::::::::::::::::::::::::::::::::::::::::\n" ;
    cout << ":: Creat your password :" ;
    cin >> pass ;
    system("cls");
}
void signupproject(){
  bool acceptUAPC=false ;
  int x=1 ;
  char signuppage ;
  while(true){
    x=1 ;
    userbold();
    while (true) {
      switch (signuppage = getch()) {
        case KEY_DOWN:
          if (x < 3) {
            x = x + 1 ;
          }
          else {
            x = 1 ;
          }
          break;
        case KEY_UP:
          if (x > 1) {
            x = x - 1 ;
          }
          else {
            x = 3 ;
          }
          break;
      }
      if (x == 1) {
          userbold();
      }
      else if (x == 2) {
          passbold();
      }
      else if (x == 3) {
          sinupenterbold();
      }
      if (signuppage == 13) {
        break ;
      }
    }
    if (x == 1) {
        signuppage = 'U' ;
    }
    else if (x == 2) {
        signuppage = 'P' ;
    }
    else if (x == 3) {
        signuppage = 'E' ;
    }
    switch (signuppage){
    case 'U':
        getusername();
        break;
    case 'P':
        getpassword();
        break;
    case 'E' :
      if (user!="" && pass!=""){
          acceptUAPC=true ;
      }
      else{
          cout << "You must fill all sections \n" ;
          Sleep(2000);
      }
      break ;
    }
    if(acceptUAPC==true){
        break ;
    }
  }
}
int  signup() {
  user={};
  pass={};
  noacc = false ;
  fstream fileaccount;
  fileaccount.open("account.txt", ios::app) ;
  //check to open file
  if ( !fileaccount ) {
    cout << "some thing wrong during opening file!\n" ;
    Sleep(2000) ;
    return 1 ;
  }
  signupproject();
  fileaccount << user << '\n' ;
  fileaccount << pass << '\n' ;
  system("cls");
  for (int i = 0 ; i <= 2 ; i++) {
    cout << "   :      \n";
    cout << "  ::::::: \n";
    cout << " : | \\   : \n";
    cout << ":  |--\\   :\n";
    cout << " : |   \\ : \n";
    cout << ": ::::::: :::::::::::\n";
    cout << ":: account created :: \n";
    pleasewait();
    system("CLS");
  }
  fileaccount.close();
  Sleep(200);
  return 0 ;
}
//- login 
void loginuserbold0(){
    system("cls");
    cout << "   :      \n";
    cout << "  ::::::: \n";
    cout << " : | \\   : \n";
    cout << ":  |--\\   :\n";
    cout << " : |   \\ : \n";
    cout << ": ::::::: ::::::::::::::::::::::::::::::::\n";
    cout << "::        LOGIN TO YOUR ACCOUNT         ::\n";
    cout << "::                                      ::\n";
    cout << ":: ------------:::::::::::::::::::::::: ::\n";
    cout << ":: |username : :: ****************   :: ::\n";
    cout << ":: ------------:::::::::::::::::::::::: ::\n";
    cout << "::                                      ::\n";
    cout << ":: -----------------------------------  ::\n";
    cout << ":: |password :                       |  ::\n";
    cout << ":: -----------------------------------  ::\n";
    cout << "::                                      ::\n";
    cout << "::    Enter                             ::\n";
    cout << "::                                      ::\n";
    cout << "::::::::::::::::::::::::::::::::::::::::::\n";
}
void loginuserbold1(){
    system("cls");
    cout << "   :      \n";
    cout << "  ::::::: \n";
    cout << " : | \\   : \n";
    cout << ":  |--\\   :\n";
    cout << " : |   \\ : \n";
    cout << ": ::::::: ::::::::::::::::::::::::::::::::\n";
    cout << "::        LOGIN TO YOUR ACCOUNT         ::\n";
    cout << "::                                      ::\n";
    cout << ":: ------------:::::::::::::::::::::::: ::\n";
    cout << ":: |username : ::                    :: ::\n";
    cout << ":: ------------:::::::::::::::::::::::: ::\n";
    cout << "::                                      ::\n";
    cout << ":: -----------------------------------  ::\n";
    cout << ":: |password :                       |  ::\n";
    cout << ":: -----------------------------------  ::\n";
    cout << "::                                      ::\n";
    cout << "::    Enter                             ::\n";
    cout << "::                                      ::\n";
    cout << "::::::::::::::::::::::::::::::::::::::::::\n";
}
void loginuserbold2(){
    system("cls");
    cout << "   :      \n";
    cout << "  ::::::: \n";
    cout << " : | \\   : \n";
    cout << ":  |--\\   :\n";
    cout << " : |   \\ : \n";
    cout << ": ::::::: ::::::::::::::::::::::::::::::::\n";
    cout << "::        LOGIN TO YOUR ACCOUNT         ::\n";
    cout << "::                                      ::\n";
    cout << ":: ------------:::::::::::::::::::::::: ::\n";
    cout << ":: |username : ::                    :: ::\n";
    cout << ":: ------------:::::::::::::::::::::::: ::\n";
    cout << "::                                      ::\n";
    cout << ":: -----------------------------------  ::\n";
    cout << ":: |password :    ****************   |  ::\n";
    cout << ":: -----------------------------------  ::\n";
    cout << "::                                      ::\n";
    cout << "::    Enter                             ::\n";
    cout << "::                                      ::\n";
    cout << "::::::::::::::::::::::::::::::::::::::::::\n";
}
void loginuserbold3(){
    system("cls");
    cout << "   :      \n";
    cout << "  ::::::: \n";
    cout << " : | \\   : \n";
    cout << ":  |--\\   :\n";
    cout << " : |   \\ : \n";
    cout << ": ::::::: ::::::::::::::::::::::::::::::::\n";
    cout << "::        LOGIN TO YOUR ACCOUNT         ::\n";
    cout << "::                                      ::\n";
    cout << ":: ------------:::::::::::::::::::::::: ::\n";
    cout << ":: |username : :: ****************   :: ::\n";
    cout << ":: ------------:::::::::::::::::::::::: ::\n";
    cout << "::                                      ::\n";
    cout << ":: -----------------------------------  ::\n";
    cout << ":: |password :    ****************   |  ::\n";
    cout << ":: -----------------------------------  ::\n";
    cout << "::                                      ::\n";
    cout << "::    Enter                             ::\n";
    cout << "::                                      ::\n";
    cout << "::::::::::::::::::::::::::::::::::::::::::\n";
}
void loginpassbold0(){
    system("cls");
    cout << "   :      \n";
    cout << "  ::::::: \n";
    cout << " : | \\   : \n";
    cout << ":  |--\\   :\n";
    cout << " : |   \\ : \n";
    cout << ": ::::::: ::::::::::::::::::::::::::::::::\n";
    cout << "::        LOGIN TO YOUR ACCOUNT         ::\n";
    cout << "::                                      ::\n";
    cout << ":: -----------------------------------  ::\n";
    cout << ":: |username :    ****************   |  ::\n";
    cout << ":: -----------------------------------  ::\n";
    cout << "::                                      ::\n";
    cout << ":: ------------:::::::::::::::::::::::: ::\n";
    cout << ":: |password : ::                    :: ::\n";
    cout << ":: ------------:::::::::::::::::::::::: ::\n";
    cout << "::                                      ::\n";
    cout << "::    Enter                             ::\n";
    cout << "::                                      ::\n";
    cout << "::::::::::::::::::::::::::::::::::::::::::\n";
}
void loginpassbold1(){
    system("cls");
    cout << "   :      \n";
    cout << "  ::::::: \n";
    cout << " : | \\   : \n";
    cout << ":  |--\\   :\n";
    cout << " : |   \\ : \n";
    cout << ": ::::::: ::::::::::::::::::::::::::::::::\n";
    cout << "::        LOGIN TO YOUR ACCOUNT         ::\n";
    cout << "::                                      ::\n";
    cout << ":: -----------------------------------  ::\n";
    cout << ":: |username :                       |  ::\n";
    cout << ":: -----------------------------------  ::\n";
    cout << "::                                      ::\n";
    cout << ":: ------------:::::::::::::::::::::::: ::\n";
    cout << ":: |password : :: ****************   :: ::\n";
    cout << ":: ------------:::::::::::::::::::::::: ::\n";
    cout << "::                                      ::\n";
    cout << "::    Enter                             ::\n";
    cout << "::                                      ::\n";
    cout << "::::::::::::::::::::::::::::::::::::::::::\n";
}
void loginpassbold2(){
    system("cls");
    cout << "   :      \n";
    cout << "  ::::::: \n";
    cout << " : | \\   : \n";
    cout << ":  |--\\   :\n";
    cout << " : |   \\ : \n";
    cout << ": ::::::: ::::::::::::::::::::::::::::::::\n";
    cout << "::        LOGIN TO YOUR ACCOUNT         ::\n";
    cout << "::                                      ::\n";
    cout << ":: -----------------------------------  ::\n";
    cout << ":: |username :    ****************   |  ::\n";
    cout << ":: -----------------------------------  ::\n";
    cout << "::                                      ::\n";
    cout << ":: ------------:::::::::::::::::::::::: ::\n";
    cout << ":: |password : :: ****************   :: ::\n";
    cout << ":: ------------:::::::::::::::::::::::: ::\n";
    cout << "::                                      ::\n";
    cout << "::    Enter                             ::\n";
    cout << "::                                      ::\n";
    cout << "::::::::::::::::::::::::::::::::::::::::::\n";
}
void loginpassbold3(){
    system("cls");
    cout << "   :      \n";
    cout << "  ::::::: \n";
    cout << " : | \\   : \n";
    cout << ":  |--\\   :\n";
    cout << " : |   \\ : \n";
    cout << ": ::::::: ::::::::::::::::::::::::::::::::\n";
    cout << "::        LOGIN TO YOUR ACCOUNT         ::\n";
    cout << "::                                      ::\n";
    cout << ":: -----------------------------------  ::\n";
    cout << ":: |username :                       |  ::\n";
    cout << ":: -----------------------------------  ::\n";
    cout << "::                                      ::\n";
    cout << ":: ------------:::::::::::::::::::::::: ::\n";
    cout << ":: |password : ::                    :: ::\n";
    cout << ":: ------------:::::::::::::::::::::::: ::\n";
    cout << "::                                      ::\n";
    cout << "::    Enter                             ::\n";
    cout << "::                                      ::\n";
    cout << "::::::::::::::::::::::::::::::::::::::::::\n";
}
void loginenterbold0(){
    system("cls");
    cout << "   :      \n";
    cout << "  ::::::: \n";
    cout << " : | \\   : \n";
    cout << ":  |--\\   :\n";
    cout << " : |   \\ : \n";
    cout << ": ::::::: ::::::::::::::::::::::::::::::::\n";
    cout << "::        LOGIN TO YOUR ACCOUNT         ::\n";
    cout << "::                                      ::\n";
    cout << ":: -----------------------------------  ::\n";
    cout << ":: |username :    ****************   |  ::\n";
    cout << ":: -----------------------------------  ::\n";
    cout << "::                                      ::\n";
    cout << ":: -----------------------------------  ::\n";
    cout << ":: |password :                       |  ::\n";
    cout << ":: -----------------------------------  ::\n";
    cout << ":: :::::::::::                          ::\n";
    cout << ":: :: Enter ::                          ::\n";
    cout << ":: :::::::::::                          ::\n";
    cout << "::::::::::::::::::::::::::::::::::::::::::\n";
}
void loginenterbold1(){
    system("cls");
    cout << "   :      \n";
    cout << "  ::::::: \n";
    cout << " : | \\   : \n";
    cout << ":  |--\\   :\n";
    cout << " : |   \\ : \n";
    cout << ": ::::::: ::::::::::::::::::::::::::::::::\n";
    cout << "::        LOGIN TO YOUR ACCOUNT         ::\n";
    cout << "::                                      ::\n";
    cout << ":: -----------------------------------  ::\n";
    cout << ":: |username :                       |  ::\n";
    cout << ":: -----------------------------------  ::\n";
    cout << "::                                      ::\n";
    cout << ":: -----------------------------------  ::\n";
    cout << ":: |password :    ****************   |  ::\n";
    cout << ":: -----------------------------------  ::\n";
    cout << ":: :::::::::::                          ::\n";
    cout << ":: :: Enter ::                          ::\n";
    cout << ":: :::::::::::                          ::\n";
    cout << "::::::::::::::::::::::::::::::::::::::::::\n";
}
void loginenterbold2(){
    system("cls");
    cout << "   :      \n";
    cout << "  ::::::: \n";
    cout << " : | \\   : \n";
    cout << ":  |--\\   :\n";
    cout << " : |   \\ : \n";
    cout << ": ::::::: ::::::::::::::::::::::::::::::::\n";
    cout << "::        LOGIN TO YOUR ACCOUNT         ::\n";
    cout << "::                                      ::\n";
    cout << ":: -----------------------------------  ::\n";
    cout << ":: |username :    ****************   |  ::\n";
    cout << ":: -----------------------------------  ::\n";
    cout << "::                                      ::\n";
    cout << ":: -----------------------------------  ::\n";
    cout << ":: |password :    ****************   |  ::\n";
    cout << ":: -----------------------------------  ::\n";
    cout << ":: :::::::::::                          ::\n";
    cout << ":: :: Enter ::                          ::\n";
    cout << ":: :::::::::::                          ::\n";
    cout << "::::::::::::::::::::::::::::::::::::::::::\n";
}
void loginenterbold3(){
    system("cls");
    cout << "   :      \n";
    cout << "  ::::::: \n";
    cout << " : | \\   : \n";
    cout << ":  |--\\   :\n";
    cout << " : |   \\ : \n";
    cout << ": ::::::: ::::::::::::::::::::::::::::::::\n";
    cout << "::        LOGIN TO YOUR ACCOUNT         ::\n";
    cout << "::                                      ::\n";
    cout << ":: -----------------------------------  ::\n";
    cout << ":: |username :                       |  ::\n";
    cout << ":: -----------------------------------  ::\n";
    cout << "::                                      ::\n";
    cout << ":: -----------------------------------  ::\n";
    cout << ":: |password :                       |  ::\n";
    cout << ":: -----------------------------------  ::\n";
    cout << ":: :::::::::::                          ::\n";
    cout << ":: :: Enter ::                          ::\n";
    cout << ":: :::::::::::                          ::\n";
    cout << "::::::::::::::::::::::::::::::::::::::::::\n";
}
void loginuserbold(){
    if(user!="" && pass==""){
        loginuserbold0();
    }
    else if (user=="" && pass!=""){
        loginuserbold2();
    }
    else if (user!="" && pass!=""){
        loginuserbold3();
    }
    else{
        loginuserbold1();
    }
}
void loginpassbold(){
    if(user!="" && pass==""){
        loginpassbold0();
    }
    else if (user=="" && pass!=""){
        loginpassbold1();
    }
    else if (user!="" && pass!=""){
        loginpassbold2();
    }
    else{
        loginpassbold3();
    }
}
void loginenterbold(){
   if(user!="" && pass==""){
        loginenterbold0();
    }
    else if (user=="" && pass!=""){
        loginenterbold1();
    }
    else if (user!="" && pass!=""){
        loginenterbold2();
    }
    else{
        loginenterbold3();
    } 
}
void logingetusername(){
    system("cls");
    cout << ":::::::::::::::::::::::::::::::::::::::::\n" ;
    cout << ":: enter your username :" ;
    cin >> user ;
    system("cls");
}
void logingetpassword(){
    system("cls");
    cout << ":::::::::::::::::::::::::::::::::::::::::\n" ;
    cout << ":: enter your password :" ;
    cin >> pass ;
    system("cls");
}
void loginproject(){
  bool acceptUAPC=false ;
  int x=1 ;
  char loginpage ;
  while(true){
    x=1 ;
    loginuserbold();
    while (true) {
      switch (loginpage = getch()) {
        case KEY_DOWN:
          if (x < 3) {
            x = x + 1 ;
          }
          else {
            x = 1 ;
          }
          break;
        case KEY_UP:
          if (x > 1) {
            x = x - 1 ;
          }
          else {
            x = 3 ;
          }
          break;
      }
      if (x == 1) {
          loginuserbold();
      }
      else if (x == 2) {
          loginpassbold();
      }
      else if (x == 3) {
          loginenterbold();
      }
      if (loginpage == 13) {
        break ;
      }
    }
    if (x == 1) {
        loginpage = 'U' ;
    }
    else if (x == 2) {
        loginpage = 'P' ;
    }
    else if (x == 3) {
        loginpage = 'E' ;
    }
    switch (loginpage){
    case 'U':
        logingetusername();
        break;
    case 'P':
        logingetpassword();
        break;
    case 'E' :
      if (user!="" && pass!=""){
          acceptUAPC=true ;
      }
      else{
          cout << "You must fill all sections \n" ;
          Sleep(2000);
      }
      break ;
    }
    if(acceptUAPC==true){
        break ;
    }
  }
}
int  login() {
  user={};
  pass={};
  fstream fileaccount( "account.txt", ios::in ) ;
  //check to open file
  if ( !fileaccount ) {
    noacc = true ;
    return 1 ;
  }
  system("cls");
  loginproject();
  for (int i = 0 ; i <= 10 ; i++) {
    fileaccount >> userch[i] ;
    fileaccount >> passch[i] ;
  }
  for (UAPC = 0 ; UAPC <= 10 ; UAPC++) {
    if (user == userch[UAPC] && pass == passch[UAPC] ) {
      logout_check = false ;
      fstream filemessage;
      string incomingtext = messagename + itoa(UAPC, incomestr, 10);
      filemessage.open( incomingtext + ".txt", ios::app) ;
      filemessage.close();

      fstream filetwitt ;
      filetwitt.open( "twitter.txt", ios::app) ;
      filetwitt.close();

      acount_check = true ;
      system("cls");
      for (int i = 0 ; i <= 2 ; i++) {
        cout << "   :      \n";
        cout << "  ::::::: \n";
        cout << " : | \\   : \n";
        cout << ":  |--\\   :\n";
        cout << " : |   \\ : \n";
        cout << ": ::::::: :::::::::::\n";
        cout << ":: account finded  ::\n" ;
        pleasewait();
        system("CLS");
      }
      fileaccount.close();
      return 1 ;
    }
  }
  acount_check = false ;
  end_app = false ;
  return 1 ;
}
//- menu
void notebold() {
  system ("CLS");
  cout << "   :      \n";
  cout << "  ::::::: \n";
  cout << " : | \\   : \n";
  cout << ":  |--\\   :\n";
  cout << " : |   \\ : \n";
  cout << ": ::::::: :::::::::::::::::::::::::::::::::::::::::::::::::\n";
  cout << ":: ::::::::::                                            ::\n";
  cout << ":: :: Note ::                       Decimal to Binary    ::\n";
  cout << ":: ::::::::::                                            ::\n";
  cout << "::    Calculator                    BMI                  ::\n";
  cout << "::                                                       ::\n";
  cout << "::    Masager                       App info             ::\n";
  cout << "::                                                       ::\n";
  cout << "::    Twitter                       Game                 ::\n";
  cout << "::                                                       ::\n";
  cout << "::    Logout                        Setting              ::\n";
  cout << "::                                                       ::\n";
  cout << "::    Exit                                               ::\n";
  cout << "::                                                       ::\n";
  cout << ":::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n";
}
void calculatorbold() {
  system ("CLS");
  cout << "   :      \n";
  cout << "  ::::::: \n";
  cout << " : | \\   : \n";
  cout << ":  |--\\   :\n";
  cout << " : |   \\ : \n";
  cout << ": ::::::: :::::::::::::::::::::::::::::::::::::::::::::::::\n";
  cout << "::                                                       ::\n";
  cout << "::    Note                          Decimal to Binary    ::\n";
  cout << ":: ::::::::::::::::                                      ::\n";
  cout << ":: :: Calculator ::                 BMI                  ::\n";
  cout << ":: ::::::::::::::::                                      ::\n";
  cout << "::    Masager                       App info             ::\n";
  cout << "::                                                       ::\n";
  cout << "::    Twitter                       Game                 ::\n";
  cout << "::                                                       ::\n";
  cout << "::    Logout                        Setting              ::\n";
  cout << "::                                                       ::\n";
  cout << "::    Exit                                               ::\n";
  cout << "::                                                       ::\n";
  cout << ":::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n";
}
void messagerbold() {
  system ("CLS");
  cout << "   :      \n";
  cout << "  ::::::: \n";
  cout << " : | \\   : \n";
  cout << ":  |--\\   :\n";
  cout << " : |   \\ : \n";
  cout << ": ::::::: :::::::::::::::::::::::::::::::::::::::::::::::::\n";
  cout << "::                                                       ::\n";
  cout << "::    Note                          Decimal to Binary    ::\n";
  cout << "::                                                       ::\n";
  cout << "::    Calculator                    BMI                  ::\n";
  cout << ":: :::::::::::::                                         ::\n";
  cout << ":: :: Masager ::                    App info             ::\n";
  cout << ":: :::::::::::::                                         ::\n";
  cout << "::    Twitter                       Game                 ::\n";
  cout << "::                                                       ::\n";
  cout << "::    Logout                        Setting              ::\n";
  cout << "::                                                       ::\n";
  cout << "::    Exit                                               ::\n";
  cout << "::                                                       ::\n";
  cout << ":::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n";;
}
void twitterbold() {
  system ("CLS");
  cout << "   :      \n";
  cout << "  ::::::: \n";
  cout << " : | \\   : \n";
  cout << ":  |--\\   :\n";
  cout << " : |   \\ : \n";
  cout << ": ::::::: :::::::::::::::::::::::::::::::::::::::::::::::::\n";
  cout << "::                                                       ::\n";
  cout << "::    Note                          Decimal to Binary    ::\n";
  cout << "::                                                       ::\n";
  cout << "::    Calculator                    BMI                  ::\n";
  cout << "::                                                       ::\n";
  cout << "::    Masager                       App info             ::\n";
  cout << ":: :::::::::::::                                         ::\n";
  cout << ":: :: Twitter ::                    Game                 ::\n";
  cout << ":: :::::::::::::                                         ::\n";
  cout << "::    Logout                        Setting              ::\n";
  cout << "::                                                       ::\n";
  cout << "::    Exit                                               ::\n";
  cout << "::                                                       ::\n";
  cout << ":::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n";;
}
void logoutbold() {
  system ("CLS");
  cout << "   :      \n";
  cout << "  ::::::: \n";
  cout << " : | \\   : \n";
  cout << ":  |--\\   :\n";
  cout << " : |   \\ : \n";
  cout << ": ::::::: :::::::::::::::::::::::::::::::::::::::::::::::::\n";
  cout << "::                                                       ::\n";
  cout << "::    Note                          Decimal to Binary    ::\n";
  cout << "::                                                       ::\n";
  cout << "::    Calculator                    BMI                  ::\n";
  cout << "::                                                       ::\n";
  cout << "::    Masager                       App info             ::\n";
  cout << "::                                                       ::\n";
  cout << "::    Twitter                       Game                 ::\n";
  cout << ":: ::::::::::::                                          ::\n";
  cout << ":: :: Logout ::                     Setting              ::\n";
  cout << ":: ::::::::::::                                          ::\n";
  cout << "::    Exit                                               ::\n";
  cout << "::                                                       ::\n";
  cout << ":::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n";
}
void DECtoBINbold() {
  system ("CLS");
  cout << "   :      \n";
  cout << "  ::::::: \n";
  cout << " : | \\   : \n";
  cout << ":  |--\\   :\n";
  cout << " : |   \\ : \n";
  cout << ": ::::::: :::::::::::::::::::::::::::::::::::::::::::::::::\n";
  cout << "::                               ::::::::::::::::::::::: ::\n";
  cout << "::    Note                       :: Decimal to Binary :: ::\n";
  cout << "::                               ::::::::::::::::::::::: ::\n";
  cout << "::    Calculator                    BMI                  ::\n";
  cout << "::                                                       ::\n";
  cout << "::    Masager                       App info             ::\n";
  cout << "::                                                       ::\n";
  cout << "::    Twitter                       Game                 ::\n";
  cout << "::                                                       ::\n";
  cout << "::    Logout                        Setting              ::\n";
  cout << "::                                                       ::\n";
  cout << "::    Exit                                               ::\n";
  cout << "::                                                       ::\n";
  cout << ":::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n";
}
void BMIbold() {
  system ("CLS");
  cout << "   :      \n";
  cout << "  ::::::: \n";
  cout << " : | \\   : \n";
  cout << ":  |--\\   :\n";
  cout << " : |   \\ : \n";
  cout << ": ::::::: :::::::::::::::::::::::::::::::::::::::::::::::::\n";
  cout << "::                                                       ::\n";
  cout << "::    Note                          Decimal to Binary    ::\n";
  cout << "::                               :::::::::               ::\n";
  cout << "::    Calculator                 :: BMI ::               ::\n";
  cout << "::                               :::::::::               ::\n";
  cout << "::    Masager                       App info             ::\n";
  cout << "::                                                       ::\n";
  cout << "::    Twitter                       Game                 ::\n";
  cout << "::                                                       ::\n";
  cout << "::    Logout                        Setting              ::\n";
  cout << "::                                                       ::\n";
  cout << "::    Exit                                               ::\n";
  cout << "::                                                       ::\n";
  cout << ":::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n";
}
void infobold() {
  system ("CLS");
  cout << "   :      \n";
  cout << "  ::::::: \n";
  cout << " : | \\   : \n";
  cout << ":  |--\\   :\n";
  cout << " : |   \\ : \n";
  cout << ": ::::::: :::::::::::::::::::::::::::::::::::::::::::::::::\n";
  cout << "::                                                       ::\n";
  cout << "::    Note                          Decimal to Binary    ::\n";
  cout << "::                                                       ::\n";
  cout << "::    Calculator                    BMI                  ::\n";
  cout << "::                               ::::::::::::::          ::\n";
  cout << "::    Masager                    :: App info ::          ::\n";
  cout << "::                               ::::::::::::::          ::\n";
  cout << "::    Twitter                       Game                 ::\n";
  cout << "::                                                       ::\n";
  cout << "::    Logout                        Setting              ::\n";
  cout << "::                                                       ::\n";
  cout << "::    Exit                                               ::\n";
  cout << "::                                                       ::\n";
  cout << ":::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n";
}
void gamebold() {
  system ("CLS");
  cout << "   :      \n";
  cout << "  ::::::: \n";
  cout << " : | \\   : \n";
  cout << ":  |--\\   :\n";
  cout << " : |   \\ : \n";
  cout << ": ::::::: :::::::::::::::::::::::::::::::::::::::::::::::::\n";
  cout << "::                                                       ::\n";
  cout << "::    Note                          Decimal to Binary    ::\n";
  cout << "::                                                       ::\n";
  cout << "::    Calculator                    BMI                  ::\n";
  cout << "::                                                       ::\n";
  cout << "::    Masager                       App info             ::\n";
  cout << "::                               :::::::::::             ::\n";
  cout << "::    Twitter                    :: Game  ::             ::\n";
  cout << "::                               :::::::::::             ::\n";
  cout << "::    Logout                        Setting              ::\n";
  cout << "::                                                       ::\n";
  cout << "::    Exit                                               ::\n";
  cout << "::                                                       ::\n";
  cout << ":::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n";
}
void settingbold() {
  system ("CLS");
  cout << "   :      \n";
  cout << "  ::::::: \n";
  cout << " : | \\   : \n";
  cout << ":  |--\\   :\n";
  cout << " : |   \\ : \n";
  cout << ": ::::::: :::::::::::::::::::::::::::::::::::::::::::::::::\n";
  cout << "::                                                       ::\n";
  cout << "::    Note                          Decimal to Binary    ::\n";
  cout << "::                                                       ::\n";
  cout << "::    Calculator                    BMI                  ::\n";
  cout << "::                                                       ::\n";
  cout << "::    Masager                       App info             ::\n";
  cout << "::                                                       ::\n";
  cout << "::    Twitter                       Game                 ::\n";
  cout << "::                               :::::::::::::           ::\n";
  cout << "::    Logout                     :: Setting ::           ::\n";
  cout << "::                               :::::::::::::           ::\n";
  cout << "::    Exit                                               ::\n";
  cout << "::                                                       ::\n";
  cout << ":::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n";
}
void exitmenubold(){
  system ("CLS");
  cout << "   :      \n";
  cout << "  ::::::: \n";
  cout << " : | \\   : \n";
  cout << ":  |--\\   :\n";
  cout << " : |   \\ : \n";
  cout << ": ::::::: :::::::::::::::::::::::::::::::::::::::::::::::::\n";
  cout << "::                                                       ::\n";
  cout << "::    Note                          Decimal to Binary    ::\n";
  cout << "::                                                       ::\n";
  cout << "::    Calculator                    BMI                  ::\n";
  cout << "::                                                       ::\n";
  cout << "::    Masager                       App info             ::\n";
  cout << "::                                                       ::\n";
  cout << "::    Twitter                       Game                 ::\n";
  cout << "::                                                       ::\n";
  cout << "::    Logout                        Setting              ::\n";
  cout << ":: ::::::::::                                            ::\n";
  cout << ":: :: Exit ::                                            ::\n";
  cout << ":: ::::::::::                                            ::\n";
  cout << ":::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n";
}
void menuPage() {
  int x = 1 , y = 1 ;
  notebold();
  while (true) {
    switch (menu = getch()) {
      case KEY_DOWN:
        if (x < 6) {
          if(y==2 && x==5){
            break;
          }
          x = x + 1 ;
        }
        else {
          x = 1 ;
        }
        break;
      case KEY_UP:
        if (x > 1) {
          x = x - 1 ;
        }
        else if(y==2){
          x = 5 ;
        }
        else {
          x = 6 ;
        }
        break;
      case KEY_RIGHT:
      if(x<6){
        y = 2 ;
      } 
        break;
      case KEY_LEFT:
        y = 1 ;
        break;
    }
    if (x == 1 && y == 1) {
      notebold();
    }
    else if (x == 2 && y == 1) {
      calculatorbold();
    }
    else if (x == 3 && y == 1) {
      messagerbold();
    }
    else if (x == 4 && y == 1) {
      twitterbold();
    }
    else if (x == 5 && y == 1) {
      logoutbold();
    }
    else if (x == 6 && y == 1) {
      exitmenubold();
    }
    else if (x == 1 && y == 2) {
      DECtoBINbold();
    }
    else if (x == 2 && y == 2) {
      BMIbold();
    }
    else if (x == 3 && y == 2) {
      infobold();
    }
    else if (x == 4 && y == 2) {
      gamebold();
    }
    else if (x == 5 && y == 2) {
      settingbold();
    }
    if (menu == 13) {
      break ;
    }
  }
  if (x == 1 && y == 1) {
    menu = 'N' ;
  }
  else if (x == 2 && y == 1) {
    menu = 'C' ;
  }
  else if (x == 3 && y == 1) {
    menu = 'M' ;
  }
  else if (x == 4 && y == 1) {
    menu = 'T' ;
  }
  else if (x == 5 && y == 1) {
    menu = 'L' ;
  }
  else if (x == 6 && y == 1) {
    menu = 'E' ;
  }
  else if (x == 1 && y == 2) {
    menu = 'D' ;
  }
  else if (x == 2 && y == 2) {
    menu = 'B' ;
  }
  else if (x == 3 && y == 2) {
    menu = 'I' ;
  }
  else if (x == 4 && y == 2) {
    menu = 'G' ;
  }
  else if (x == 5 && y == 2) {
    menu = 'S' ;
  }
}
//- setting
void cleardata() {
  remove("account.txt") ;
  usertext = filesname + itoa(UAPC, numstr, 10) + ".txt" ;
  fstream filetext;
  filetext.open(usertext , std::ofstream::out | std::ofstream::trunc);
  filetext.close();
  fstream filemessage;
  string incomingtext = messagename + itoa(UAPC, incomestr, 10) + ".txt" ;
  filemessage.open(incomingtext , std::ofstream::out | std::ofstream::trunc);
  filemessage.close();
  remove("twitter.txt") ;
  exit_type = true ;
  system("cls");
  cout << ":::::::::::::::::::::::::::::::::::::\n";
  cout << ":: ALL DATA IS CLEARED             ::\n";
  cout << ":: App whill close in 3 secound... ::\n";
  cout << ":::::::::::::::::::::::::::::::::::::\n";
  Sleep(3000) ;
}
void blue() {
  system("cls");
  cout << "   :      \n";
  cout << "  ::::::: \n";
  cout << " : | \\   : \n";
  cout << ":  |--\\   :\n";
  cout << " : |   \\ : \n";
  cout << ": ::::::: ::::::::::::::::::::::::::::::::::::::\n";
  cout << ":: ::::::::::::::::                           ::\n";
  cout << ":: :: Light Blue ::         Light Red         ::\n";
  cout << ":: ::::::::::::::::                           ::\n";
  cout << "::    Light Green          Light Yellow       ::\n";
  cout << "::                                            ::\n";
  cout << "::    Light Aqua           Light Purple       ::\n";
  cout << "::                                            ::\n";
  cout << "::    Reset Them              Back            ::\n";
  cout << "::                                            ::\n";
  cout << "::::::::::::::::::::::::::::::::::::::::::::::::\n";
}
void green() {
  system("cls");
  cout << "   :      \n";
  cout << "  ::::::: \n";
  cout << " : | \\   : \n";
  cout << ":  |--\\   :\n";
  cout << " : |   \\ : \n";
  cout << ": ::::::: ::::::::::::::::::::::::::::::::::::::\n";
  cout << "::                                            ::\n";
  cout << "::    Light Blue            Light Red         ::\n";
  cout << ":: :::::::::::::::::                          ::\n";
  cout << ":: :: Light Green ::       Light Yellow       ::\n";
  cout << ":: :::::::::::::::::                          ::\n";
  cout << "::    Light Aqua           Light Purple       ::\n";
  cout << "::                                            ::\n";
  cout << "::    Reset Them              Back            ::\n";
  cout << "::                                            ::\n";
  cout << "::::::::::::::::::::::::::::::::::::::::::::::::\n";
}
void aqua() {
  system("cls");
  cout << "   :      \n";
  cout << "  ::::::: \n";
  cout << " : | \\   : \n";
  cout << ":  |--\\   :\n";
  cout << " : |   \\ : \n";
  cout << ": ::::::: ::::::::::::::::::::::::::::::::::::::\n";
  cout << "::                                            ::\n";
  cout << "::    Light Blue            Light Red         ::\n";
  cout << "::                                            ::\n";
  cout << "::    Light Green          Light Yellow       ::\n";
  cout << ":: ::::::::::::::::                           ::\n";
  cout << ":: :: Light Aqua ::        Light Purple       ::\n";
  cout << ":: ::::::::::::::::                           ::\n";
  cout << "::    Reset Them              Back            ::\n";
  cout << "::                                            ::\n";
  cout << "::::::::::::::::::::::::::::::::::::::::::::::::\n";
}
void reset() {
  system("cls");
  cout << "   :      \n";
  cout << "  ::::::: \n";
  cout << " : | \\   : \n";
  cout << ":  |--\\   :\n";
  cout << " : |   \\ : \n";
  cout << ": ::::::: ::::::::::::::::::::::::::::::::::::::\n";
  cout << "::                                            ::\n";
  cout << "::    Light Blue            Light Red         ::\n";
  cout << "::                                            ::\n";
  cout << "::    Light Green          Light Yellow       ::\n";
  cout << "::                                            ::\n";
  cout << "::    Light Aqua           Light Purple       ::\n";
  cout << ":: ::::::::::::::::                           ::\n";
  cout << ":: :: Reset Them ::           Back            ::\n";
  cout << ":: ::::::::::::::::                           ::\n";
  cout << "::::::::::::::::::::::::::::::::::::::::::::::::\n";
}
void red() {
  system("cls");
  cout << "   :      \n";
  cout << "  ::::::: \n";
  cout << " : | \\   : \n";
  cout << ":  |--\\   :\n";
  cout << " : |   \\ : \n";
  cout << ": ::::::: ::::::::::::::::::::::::::::::::::::::\n";
  cout << "::                       :::::::::::::::      ::\n";
  cout << "::    Light Blue         :: Light Red ::      ::\n";
  cout << "::                       :::::::::::::::      ::\n";
  cout << "::    Light Green          Light Yellow       ::\n";
  cout << "::                                            ::\n";
  cout << "::    Light Aqua           Light Purple       ::\n";
  cout << "::                                            ::\n";
  cout << "::    Reset Them              Back            ::\n";
  cout << "::                                            ::\n";
  cout << "::::::::::::::::::::::::::::::::::::::::::::::::\n";
}
void yellow() {
  system("cls");
  cout << "   :      \n";
  cout << "  ::::::: \n";
  cout << " : | \\   : \n";
  cout << ":  |--\\   :\n";
  cout << " : |   \\ : \n";
  cout << ": ::::::: ::::::::::::::::::::::::::::::::::::::\n";
  cout << "::                                            ::\n";
  cout << "::    Light Blue            Light Red         ::\n";
  cout << "::                      ::::::::::::::::::    ::\n";
  cout << "::    Light Green       :: Light Yellow ::    ::\n";
  cout << "::                      ::::::::::::::::::    ::\n";
  cout << "::    Light Aqua           Light Purple       ::\n";
  cout << "::                                            ::\n";
  cout << "::    Reset Them              Back            ::\n";
  cout << "::                                            ::\n";
  cout << "::::::::::::::::::::::::::::::::::::::::::::::::\n";
}
void purple() {
  system("cls");
  cout << "   :      \n";
  cout << "  ::::::: \n";
  cout << " : | \\   : \n";
  cout << ":  |--\\   :\n";
  cout << " : |   \\ : \n";
  cout << ": ::::::: ::::::::::::::::::::::::::::::::::::::\n";
  cout << "::                                            ::\n";
  cout << "::    Light Blue            Light Red         ::\n";
  cout << "::                                            ::\n";
  cout << "::    Light Green          Light Yellow       ::\n";
  cout << "::                      ::::::::::::::::::    ::\n";
  cout << "::    Light Aqua        :: Light Purple ::    ::\n";
  cout << "::                      ::::::::::::::::::    ::\n";
  cout << "::    Reset Them              Back            ::\n";
  cout << "::                                            ::\n";
  cout << "::::::::::::::::::::::::::::::::::::::::::::::::\n";
}
void back() {
  system("cls");
  cout << "   :      \n";
  cout << "  ::::::: \n";
  cout << " : | \\   : \n";
  cout << ":  |--\\   :\n";
  cout << " : |   \\ : \n";
  cout << ": ::::::: ::::::::::::::::::::::::::::::::::::::\n";
  cout << "::                                            ::\n";
  cout << "::    Light Blue            Light Red         ::\n";
  cout << "::                                            ::\n";
  cout << "::    Light Green          Light Yellow       ::\n";
  cout << "::                                            ::\n";
  cout << "::    Light Aqua           Light Purple       ::\n";
  cout << "::                       ::::::::::::::       ::\n";
  cout << "::    Reset Them         ::   Back   ::       ::\n";
  cout << "::                       ::::::::::::::       ::\n";
  cout << "::::::::::::::::::::::::::::::::::::::::::::::::\n";
}
void appThem() {
  while (true) {
    char color ;
    int x = 1 , y = 1 ;
    blue();
    while (true) {
      switch (color = getch()) {
        case KEY_DOWN:
          if (x < 4) {
            x = x + 1 ;
          }
          else {
            x = 1 ;
          }
          break;
        case KEY_UP:
          if (x > 1) {
            x = x - 1 ;
          }
          else {
            x = 4 ;
          }
          break;
        case KEY_RIGHT:
          y = 2 ;
          break;
        case KEY_LEFT:
          y = 1 ;
          break;
      }
      if (x == 1 && y == 1) {
        blue();
      }
      else if (x == 2 && y == 1) {
        green();
      }
      else if (x == 3 && y == 1) {
        aqua();
      }
      else if (x == 4 && y == 1) {
        reset();
      }
      else if (x == 1 && y == 2) {
        red();
      }
      else if (x == 2 && y == 2) {
        yellow();
      }
      else if (x == 3 && y == 2) {
        purple();
      }
      else if (x == 4 && y == 2) {
        back();
      }
      if (color == 13) {
        break ;
      }
    }
    if (x == 1 && y == 1) {
      color = 'A' ;
    }
    else if (x == 2 && y == 1) {
      color = 'B' ;
    }
    else if (x == 3 && y == 1) {
      color = 'C' ;
    }
    else if (x == 4 && y == 1) {
      color = 'D' ;
    }
    else if (x == 1 && y == 2) {
      color = 'E' ;
    }
    else if (x == 2 && y == 2) {
      color = 'F' ;
    }
    else if (x == 3 && y == 2) {
      color = 'G' ;
    }
    else if (x == 4 && y == 2) {
      color = 'H' ;
    }
    if (color == 'H') {
      exit_type == false ;
      break ;
    }
    switch (color) {
      case 'A' :
        system("color 9");
        break ;
      case 'E' :
        system("color C");
        break ;
      case 'B' :
        system("color A");
        break ;
      case 'F' :
        system("color E");
        break ;
      case 'C' :
        system("color B");
        break ;
      case 'G' :
        system("color D");
        break ;
      case 'D' :
        system("color 7");
        break ;
    }
  }
}
void clearbold() {
  system ("CLS");
  cout << "   :      \n";
  cout << "  ::::::: \n";
  cout << " : | \\   : \n";
  cout << ":  |--\\   :\n";
  cout << " : |   \\ : \n";
  cout << ": ::::::: :::::::::::::::::\n";
  cout << ":: :::::::::::::::::::: ::\n" ;
  cout << ":: :: clear all data :: ::\n" ;
  cout << ":: :::::::::::::::::::: ::\n" ;
  cout << "::     change them      ::\n" ;
  cout << "::                      ::\n" ;
  cout << "::    Return to Menu    ::\n" ;
  cout << "::                      ::\n" ;
  cout << "::::::::::::::::::::::::::\n" ;
}
void thembold() {
  system ("CLS");
  cout << "   :      \n";
  cout << "  ::::::: \n";
  cout << " : | \\   : \n";
  cout << ":  |--\\   :\n";
  cout << " : |   \\ : \n";
  cout << ": ::::::: :::::::::::::::::\n";
  cout << "::                      ::\n" ;
  cout << "::    clear all data    ::\n" ;
  cout << ":: :::::::::::::::::::: ::\n" ;
  cout << ":: ::  change them   :: ::\n" ;
  cout << ":: :::::::::::::::::::: ::\n" ;
  cout << "::    Return to Menu    ::\n" ;
  cout << "::                      ::\n" ;
  cout << "::::::::::::::::::::::::::\n" ;
}
void returnbold() {
  system ("CLS");
  cout << "   :      \n";
  cout << "  ::::::: \n";
  cout << " : | \\   : \n";
  cout << ":  |--\\   :\n";
  cout << " : |   \\ : \n";
  cout << ": ::::::: :::::::::::::::::\n";
  cout << "::                      ::\n" ;
  cout << "::    clear all data    ::\n" ;
  cout << "::                      ::\n" ;
  cout << "::     change them      ::\n" ;
  cout << ":: :::::::::::::::::::: ::\n" ;
  cout << ":: :: Return to Menu :: ::\n" ;
  cout << ":: :::::::::::::::::::: ::\n" ;
  cout << "::::::::::::::::::::::::::\n" ;
}
int  setting() {
  char settingask ;
  while (true) {
    int x = 1 ;
    clearbold();
    while (true) {
      switch (settingask = getch()) {
        case KEY_DOWN:
          if (x < 3) {
            x = x + 1 ;
          }
          else {
            x = 1 ;
          }
          break;
        case KEY_UP:
          if (x > 1) {
            x = x - 1 ;
          }
          else {
            x = 3 ;
          }
          break;
      }
      if (x == 1) {
        clearbold();
      }
      else if (x == 2) {
        thembold();
      }
      else if (x == 3 ) {
        returnbold();
      }
      if (settingask == 13) {
        break ;
      }
    }
    if (x == 1) {
      settingask = 'C' ;
    }
    else if (x == 2) {
      settingask = 'T' ;
    }
    else if (x == 3) {
      settingask = 'B' ;
    }
    switch (settingask) {
      case 'B' :  back_to_menu = true ;
        break ;
      case 'T' :  appThem();
        break ;
      case 'C' :  cleardata();   return 1 ;
        break ;
      default :   invalidError();
    }
    if (back_to_menu == true) {
      break ;
    }
  }
  return 0 ;
}
//- other option
void BMI() {
  while (true) {
    system("cls");
    float height = 0.0 , weight = 0.0 , BMI;
    system("cls");
    cout << "   :      \n";
    cout << "  ::::::: \n";
    cout << " : | \\   : \n";
    cout << ":  |--\\   :\n";
    cout << " : |   \\ : \n";
    cout << ": ::::::: ::::::::::::::::::::::::::\n" ;
    cout << ":: Enter your height in meters(m) ::\n" ;
    cout << "::::::::::::::::::::::::::::::::::::\n" ;
    cout << "::  " ;
    cin >> height ;
    system("cls");
    cout << "   :      \n";
    cout << "  ::::::: \n";
    cout << " : | \\   : \n";
    cout << ":  |--\\   :\n";
    cout << " : |   \\ : \n";
    cout << ": ::::::: ::::::::::::::::::::::::::\n" ;
    cout << ":: Enter your weight in kilograms(Kg) ::\n" ;
    cout << "::::::::::::::::::::::::::::::::::::::::\n" ;
    cout << "::  " ;
    cin >> weight ;
    BMI = weight / (height * height) ;
    system("cls");
    cout << "   :      \n";
    cout << "  ::::::: \n";
    cout << " : | \\   : \n";
    cout << ":  |--\\   :\n";
    cout << " : |   \\ : \n";
    cout << ": ::::::: ::::::::::::::::::::::::\n" ;
    cout << "::  your BMI is : " << BMI << '\n' ;
    cout << "::::::::::::::::::::::::::::::::::\n" ;
    //BELOW [18.5]
    if (BMI < 18.5) {
      cout << ":: A BMI below 18.5 indicates that you are underweight, so you may need to gain some weight \n";
      cout << ":: We recommend that you seek help from your doctor or nutritionist                         \n";
    }
    //BETWEEN [18.5 & 24.9]
    else if (BMI >= 18.5 && BMI <= 24.9) {
      cout << ":: A BMI between 18.5 and 24.9 indicates that you are a good weight for your height. \n";
      cout << ":: By maintaining a healthy weight, you can prevent serious health risks.            \n";
    }
    //BETWEEN [25 & 29.9]
    else if (BMI >= 25 && BMI <= 29.9) {
      cout << ":: A BMI between 25 and 29.9 tells you that you are a little overweight and need to lose some weight. You can consult your doctor to lose weight. \n";
    }
    //ABOVE [30]
    else if ( BMI >= 30) {
      cout << ":: A BMI above 30 warns you that you are overweight. If you do not lose weight, your health will certainly be endangered. \n";
      cout << ":: Be sure to talk to your doctor or nutritionist and start dieting.                                                      \n";
    }
    cout << ":: [N] = new calculate     [E] = exit from BMI \n" ;
    cin >> exit_ask ;
    if (exit_ask == 'e' || exit_ask == 'E') {
      break;
    }
  }
}
void DECtoBIN() {
  char decask  ;
  string inputdec ;
  while (true) {
    system ("CLS");
    cout << "   :      \n";
    cout << "  ::::::: \n";
    cout << " : | \\   : \n";
    cout << ":  |--\\   :\n";
    cout << " : |   \\ : \n";
    cout << ": ::::::: ::::::::::::::::::::::::::::::::::::::\n" ;
    cout << "::  enter the number or Sentence do you want  ::\n" ;
    cout << "::::::::::::::::::::::::::::::::::::::::::::::::\n" ;
    //character
    getline(cin, inputdec);
    getline(cin, inputdec);
    for (std::size_t i = 0; i < inputdec.size(); ++i) {
      cout << bitset<8>(inputdec.c_str()[i]) << "-" ;
    }
    cout << "\n[N] = new calculate     [B] = back \n";
    cin >> decask ;
    if (decask == 'b' || decask == 'B') {
      system ("CLS");
      break ;
    }
  }
}
void AppInfo() {
  system("cls");
  cout << "   :      \n";
  cout << "  ::::::: \n";
  cout << " : | \\   : \n";
  cout << ":  |--\\   :\n";
  cout << " : |   \\ : \n";
  cout << ": ::::::: ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n";
  cout << ":: Hello users !                                                                                                                  ::\n";
  cout << ":: This program is a free software, you can use it by obtaining a license from the manufacturer (taha.hoveidapour84@gmail.com)    ::\n";
  cout << ":: or change it under legal copyright conditions.                                                                                 ::\n";
  cout << ":: Once you get the license, you can use all subsequent versions of this software.                                                ::\n";
  cout << "::                                                                                                                                ::\n";
  cout << ":: This app is an almost complete software with the name AIO means All In One .                                                   ::\n";
  cout << ":: you can use its features such as calculator - convert sentences and numbers to binary - BMI calculation - save text and ....   ::\n";
  cout << "::                                                                                                                                ::\n";
  cout << ":: Its code is written in C++ language and has no graphical environment and is for use in CMD environment.                        ::\n";
  cout << ":: If you see any bugs or need help , send a message to AIO Support.                                                              ::\n";
  cout << "::                                                                                                                                ::\n";
  cout << ":: The meaning of the name of this app is All In One (AIO)                                                                        ::\n";
  cout << ":: this app is version " << version << " and will be more updated and debugged. \n So enjoy it !!  \n from : Taha_HDP\n";
  cout << "[B] = back\n" ;
  char infoback ;
  while (true) {
    cin >> infoback ;
    if (infoback == 'b' || infoback == 'B' ) {
      system("cls");
      break ;
    }
    invalidError();
  }
}
void calculator() {
  while (true) {
    system("cls");
    float x = 0.0 , y = 0.0 , n = 0.0 ;
    char op ;
    cout << "   :      \n";
    cout << "  ::::::: \n";
    cout << " : | \\   : \n";
    cout << ":  |--\\   :\n";
    cout << " : |   \\ : \n";
    cout << ": ::::::: :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n";
    cout << ":: You have to enter your first number and then the operator from (+ - * /) you want and then your second number ::\n";
    cout << ":: [L] = log    [S] = square root                                                                                ::\n";
    cout << ":::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n";
    cout << ":: example : 25 s = 5 || 12 + 12 = 24 ::\n" ;
    cout << "::::::::::::::::::::::::::::::::::::::::\n" ;
    cin >> x ;
    system("cls");
    cout << "( * / - + ) or [L] = log    [S] = square root \n " ;
    cout << x << " " ;
    while (true) {
      cin >> op ;
      if (op == '+' || op == '-' || op == '*' || op == '/' || op == 's' || op == 'S' || op == 'l' || op == 'L') {
        system("cls");
        cout << x << " " << op << " ";
        break ;
      }
      cout << '\n' << op << "\ninvalid , enter one of operators !\n";
    }
    switch (op) {
      case '+' :
        cin >> y ;
        n = x + y ;
        break ;
      case '-' :
        cin >> y ;
        n = x - y ;
        break ;
      case '*' :
        cin >> y ;
        n = x * y ;
        break ;
      case '/' :
        cin >> y ;
        if (op == '/' && y == 0) {
          cout << "Division By Zero, Please Retry \n" ;
          break ;
        }
        n = x / y ;
        break ;
      case 'L' :
      case 'l' :
        n = log(x) ;
        break ;
      case 'S' :
      case 's' :
        n = sqrt(x) ;
        break ;
    }
    system("cls");
    cout << ":: " << x << " " << op << " " << y << " = " << n << '\n';
    cout << ":: [N] = new calculate     [E] = exit from calculator ::\n" ;
    cout << "::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n" ;
    cin >> exit_ask ;
    if (exit_ask == 'e' || exit_ask == 'E') {
      break ;
    }
  }
}
//- notepad
int  textwrite() {
  fstream filetext;
  usertext = filesname + itoa(UAPC, numstr, 10);
  filetext.open(usertext + ".txt", ios::app) ;
  //check to open file
  if ( !filetext ) {
    cout << "   :      \n";
    cout << "  ::::::: \n";
    cout << " : | \\   : \n";
    cout << ":  |--\\   :\n";
    cout << " : |   \\ : \n";
    cout << ": ::::::: :::::::::::::::::::::::::::::::::\n";
    cout << ":: some thing wrong during opening file! ::\n";
    cout << ":::::::::::::::::::::::::::::::::::::::::::\n";
    write_check = false ;
    Sleep(3000) ;
    return 1 ;
  }
  //get information from user
  write_check = false ;
  while (true) {
    getline(cin, New_Text);
    filetext << New_Text << '\n' ;
    // done or not ?
    cin >> Exit_or_Text ;
    if (Exit_or_Text == "exit") {
      filetext.close();
      return 1 ;
    }
    else {
      filetext << Exit_or_Text << " " ;
    }
  }
  return 0 ;
}
int  EIF() {
  //Extract information from file
  system("cls");
  fstream filetext;
  usertext = filesname + itoa(UAPC, numstr, 10);
  filetext.open(usertext + ".txt", ios::in) ;
  //check to open file
  if ( !filetext ) {
    cout << "   :      \n";
    cout << "  ::::::: \n";
    cout << " : | \\   : \n";
    cout << ":  |--\\   :\n";
    cout << " : |   \\ : \n";
    cout << ": ::::::: :::::::::::::::::::::::::::::::::::::::::::\n";
    cout << ":: No text file has been created in this program ! ::\n";
    cout << "::     You must create a text file first           ::\n";
    cout << ":::::::::::::::::::::::::::::::::::::::::::::::::::::\n";
    write_check = false ;
    Sleep(3000) ;
    return 1 ;
  }
  cout << "type your note tp save in your file , for exitting just type 'exit' \n\n" ;
  while (!filetext.eof()) {
    filetext >> Open_Text;
    cout << Open_Text << " " ;
  }
  filetext.close();
  return 0 ;
}
void textnotic() {
  system("CLS") ;
  cout  << "new text file created . \ntype your note tp save in your file , for exitting just type 'exit' \n";
}
void cleartext() {
  usertext = filesname + itoa(UAPC, numstr, 10);
  fstream filetext;
  filetext.open(usertext + ".txt", std::ofstream::out | std::ofstream::trunc);
  filetext.close();
  system("cls");
  cout << "   :      \n";
  cout << "  ::::::: \n";
  cout << " : | \\   : \n";
  cout << ":  |--\\   :\n";
  cout << " : |   \\ : \n";
  cout << ": ::::::: :::::::::::::::::::::::::::\n";
  cout << ":: ALL TEXT IS CLEARED             ::\n";
  cout << ":::::::::::::::::::::::::::::::::::::\n";
  Sleep(3000) ;
}
void newbold() {
  system("CLS");
  cout << "   :      \n";
  cout << "  ::::::: \n";
  cout << " : | \\   : \n";
  cout << ":  |--\\   :\n";
  cout << " : |   \\ : \n";
  cout << ": ::::::: :::::::::::::::::::::::::::::::::::::::::::::\n";
  cout << ":: :::::::::::::::::::                               ::\n";
  cout << ":: :: New text file ::          Open text file       ::\n";
  cout << ":: :::::::::::::::::::                               ::\n";
  cout << "::    Clear text in file        Back to menu         ::\n";
  cout << "::                                                   ::\n";
  cout << ":::::::::::::::::::::::::::::::::::::::::::::::::::::::\n";
}
void cleartextbold() {
  system("CLS");
  cout << "   :      \n";
  cout << "  ::::::: \n";
  cout << " : | \\   : \n";
  cout << ":  |--\\   :\n";
  cout << " : |   \\ : \n";
  cout << ": ::::::: :::::::::::::::::::::::::::::::::::::::::::::\n";
  cout << "::                                                   ::\n";
  cout << "::    New text file             Open text file       ::\n";
  cout << ":: ::::::::::::::::::::::::                          ::\n";
  cout << ":: :: Clear text in file ::     Back to menu         ::\n";
  cout << ":: ::::::::::::::::::::::::                          ::\n";
  cout << ":::::::::::::::::::::::::::::::::::::::::::::::::::::::\n";
}
void openbold() {
  system("CLS");
  cout << "   :      \n";
  cout << "  ::::::: \n";
  cout << " : | \\   : \n";
  cout << ":  |--\\   :\n";
  cout << " : |   \\ : \n";
  cout << ": ::::::: :::::::::::::::::::::::::::::::::::::::::::::\n";
  cout << "::                           ::::::::::::::::::::    ::\n";
  cout << "::    New text file          :: Open text file ::    ::\n";
  cout << "::                           ::::::::::::::::::::    ::\n";
  cout << "::    Clear text in file        Back to menu         ::\n";
  cout << "::                                                   ::\n";
  cout << ":::::::::::::::::::::::::::::::::::::::::::::::::::::::\n";
}
void back_to_menubold() {
  system("CLS");
  cout << "   :      \n";
  cout << "  ::::::: \n";
  cout << " : | \\   : \n";
  cout << ":  |--\\   :\n";
  cout << " : |   \\ : \n";
  cout << ": ::::::: :::::::::::::::::::::::::::::::::::::::::::::\n";
  cout << "::                                                   ::\n";
  cout << "::    New text file             Open text file       ::\n";
  cout << "::                           ::::::::::::::::::      ::\n";
  cout << "::    Clear text in file     :: Back to menu ::      ::\n";
  cout << "::                           ::::::::::::::::::      ::\n";
  cout << ":::::::::::::::::::::::::::::::::::::::::::::::::::::::\n";
}
void note() {
  while (true) {
    char noteask ;
    write_check = true ;
    newbold();
    int x = 1 , y = 1 ;
    while (true) {
      switch (noteask = getch()) {
        case KEY_DOWN:
          if (x < 2) {
            x = x + 1 ;
          }
          else {
            x = 1 ;
          }
          break;
        case KEY_UP:
          if (x > 1) {
            x = x - 1 ;
          }
          else {
            x = 2 ;
          }
          break;
        case KEY_RIGHT:
          y = 2 ;
          break;
        case KEY_LEFT:
          y = 1 ;
          break;
      }
      if (x == 1 && y == 1) {
        newbold();
      }
      else if (x == 2 && y == 1) {
        cleartextbold();
      }
      else if (x == 1 && y == 2) {
        openbold();
      }
      else if (x == 2 && y == 2) {
        back_to_menubold();
      }
      if (noteask == 13) {
        break ;
      }
    }
    if (x == 1 && y == 1) {
      noteask = 'N' ;
    }
    else if (x == 2 && y == 1) {
      noteask = 'C' ;
    }
    else if (x == 1 && y == 2) {
      noteask = 'O' ;
    }
    else if (x == 2 && y == 2) {
      noteask = 'B' ;
    }
    switch (noteask) {
      case 'N'  :  textnotic();   textwrite();
        break;
      case 'O'  :  EIF();  if (write_check == true ) {
          textwrite();
        }
        break;
      case 'C'  :  cleartext();
        break;
      case 'B'  :  back_to_menu = true;
        break;
      default:    invalidError();
        break;
    }
    if (back_to_menu == true) {
      break;
    }
  }
  back_to_menu = false ;
}
//- messager
int  sendmessage() {
  fstream fileaccount( "account.txt", ios::in ) ;
  for (int i = 0 ; i <= 10 ; i++) {
    fileaccount >> userch[i] ;
    fileaccount >> passch[i] ;
  }
  system("CLS");
  cout << "Which account do you want to send a message to?\n" ;
  for ( int i = 0 ; i < 10 ; i++) {
    if (userch[i] != "" && userch[i] != userch[UAPC]) {
      massch = i ;
      cout << massch + 1 << "- " << userch[massch] << '\n' ;
    }
  }
  fileaccount.close();
  cin >> contact ;
  contact = contact - 1 ;
  if (contact <= massch && contact >= 0) {
    fstream filemessage;
    string messagetext = messagename + itoa(contact, messagestr, 10);
    filemessage.open( messagetext + ".txt", ios::app) ;
    system("CLS");
    cout << "type your note tp save in your file , for exitting just type 'exit' \n\n" ;
    filemessage << "from " << userch[UAPC] << ": " ;
    while (true) {
      getline(cin, New_Text);
      filemessage << New_Text << '\n' ;
      // done or not ?
      cin >> Exit_or_Text ;
      if (Exit_or_Text == "exit") {
        filemessage.close();
        return 1 ;
      }
      else {
        filemessage << Exit_or_Text << " " ;
      }
    }
    filemessage.close();
  }
  else {
    invalidError();
  }
  return 0 ;
}
int  Incomingmessag() {
  system("CLS");
  int back = 0 ;
  string incomingtext = messagename + itoa(UAPC, incomestr, 10);
  fstream filemessage ( incomingtext + ".txt", ios::in ) ;
  if ( !filemessage ) {
    cout << "you dont have any message !!\n" ;
    Sleep(2000);
    return 1 ;
  }
  else {
    while (!filemessage.eof()) {
      filemessage >> User_Message;
      if (User_Message == "from") {
        cout << '\n' ;
      }
      cout << User_Message << " " ;
    }
    filemessage.close();
    while (true) {
      cout << "\n\nif you see message enter '1' for back \n" ;
      cin >> back ;
      if (back == 1) {
        break;
      }
      invalidError();
    }
  }
  return 0 ;
}
void clearmessage() {
  fstream filemessage;
  string incomingtext = messagename + itoa(UAPC, incomestr, 10);
  filemessage.open(incomingtext + ".txt", std::ofstream::out | std::ofstream::trunc);
  filemessage.close();
  system("cls");
  cout << "   :      \n";
  cout << "  ::::::: \n";
  cout << " : | \\   : \n";
  cout << ":  |--\\   :\n";
  cout << " : |   \\ : \n";
  cout << ": ::::::: :::::::::::::::::::::::::::\n";
  cout << ":: ALL MESSAGE IS CLEARED          ::\n";
  cout << ":::::::::::::::::::::::::::::::::::::\n";
  Sleep(3000) ;
}
void sendbold() {
  system("CLS");
  cout << "   :      \n";
  cout << "  ::::::: \n";
  cout << " : | \\   : \n";
  cout << ":  |--\\   :\n";
  cout << " : |   \\ : \n";
  cout << ": ::::::: :::::::::::::::::::::::::::::::::::::::::::::\n";
  cout << ":: :::::::::::::::::::                               ::\n";
  cout << ":: :: send Message  ::         Incoming messages     ::\n";
  cout << ":: :::::::::::::::::::                               ::\n";
  cout << "::     Clear inbox               Back to menu        ::\n";
  cout << "::                                                   ::\n";
  cout << ":::::::::::::::::::::::::::::::::::::::::::::::::::::::\n";
}
void clearinboxbold() {
  system("CLS");
  cout << "   :      \n";
  cout << "  ::::::: \n";
  cout << " : | \\   : \n";
  cout << ":  |--\\   :\n";
  cout << " : |   \\ : \n";
  cout << ": ::::::: :::::::::::::::::::::::::::::::::::::::::::::\n";
  cout << "::                                                   ::\n";
  cout << "::    send Message             Incoming messages     ::\n";
  cout << ":: :::::::::::::::::::                               ::\n";
  cout << ":: ::  Clear inbox  ::           Back to menu        ::\n";
  cout << ":: :::::::::::::::::::                               ::\n";
  cout << ":::::::::::::::::::::::::::::::::::::::::::::::::::::::\n";
}
void inboxbold() {
  system("CLS");
  cout << "   :      \n";
  cout << "  ::::::: \n";
  cout << " : | \\   : \n";
  cout << ":  |--\\   :\n";
  cout << " : |   \\ : \n";
  cout << ": ::::::: :::::::::::::::::::::::::::::::::::::::::::::\n";
  cout << "::                          :::::::::::::::::::::::  ::\n";
  cout << "::    send Message          :: Incoming messages ::  ::\n";
  cout << "::                          :::::::::::::::::::::::  ::\n";
  cout << "::     Clear inbox               Back to menu        ::\n";
  cout << "::                                                   ::\n";
  cout << ":::::::::::::::::::::::::::::::::::::::::::::::::::::::\n";
}
void returntomenubold() {
  system("CLS");
  cout << "   :      \n";
  cout << "  ::::::: \n";
  cout << " : | \\   : \n";
  cout << ":  |--\\   :\n";
  cout << " : |   \\ : \n";
  cout << ": ::::::: :::::::::::::::::::::::::::::::::::::::::::::\n";
  cout << "::                                                   ::\n";
  cout << "::    send Message             Incoming messages     ::\n";
  cout << "::                            ::::::::::::::::::     ::\n";
  cout << "::     Clear inbox            :: Back to menu ::     ::\n";
  cout << "::                            ::::::::::::::::::     ::\n";
  cout << ":::::::::::::::::::::::::::::::::::::::::::::::::::::::\n";
}
int  messager() {
  back_to_menu = false;
  while (true) {
    char messagerask ;
    sendbold();
    int x = 1 , y = 1 ;
    while (true) {
      switch (messagerask = getch()) {
        case KEY_DOWN:
          if (x < 2) {
            x = x + 1 ;
          }
          else {
            x = 1 ;
          }
          break;
        case KEY_UP:
          if (x > 1) {
            x = x - 1 ;
          }
          else {
            x = 2 ;
          }
          break;
        case KEY_RIGHT:
          y = 2 ;
          break;
        case KEY_LEFT:
          y = 1 ;
          break;
      }
      if (x == 1 && y == 1) {
        sendbold();
      }
      else if (x == 2 && y == 1) {
        clearinboxbold();
      }
      else if (x == 1 && y == 2) {
        inboxbold();
      }
      else if (x == 2 && y == 2) {
        returntomenubold();
      }
      if (messagerask == 13) {
        break ;
      }
    }
    if (x == 1 && y == 1) {
      messagerask = 'S' ;
    }
    else if (x == 2 && y == 1) {
      messagerask = 'C' ;
    }
    else if (x == 1 && y == 2) {
      messagerask = 'I' ;
    }
    else if (x == 2 && y == 2) {
      messagerask = 'B' ;
    }
    switch (messagerask) {
      case 'S'  :   if (sendmessage() == 1) {
          break;
        }
        break;
      case 'I'  :   if (Incomingmessag() == 1) {
          break;
        }
        break;
      case 'B'  :   back_to_menu = true;
        break;
      case 'C'  :   clearmessage();
        break;
      default   :   invalidError();
        break;
    }
    if (back_to_menu == true) {
      break;
    }
  }
  return 1 ;
}
//- twitter
int  twittmessage() {
  bool twittcheck = true ;
  fstream filetwitt ;
  filetwitt.open("twitter.txt", ios::app) ;

  while (true) {
    cin >> user_twitt ;
    if (user_twitt == "exit") {
      filetwitt.close();
      return 1 ;
    }
    else {
      if (twittcheck == true) {
        filetwitt << "@ " << userch[UAPC] << ": " ;
        twittcheck = false ;
      }
      filetwitt << user_twitt << " " ;

    }
  }
  filetwitt.close();
  return 1 ;
}
int  twitter() {
  fstream filetwitt( "twitter.txt", ios::in) ;
  system("CLS");
  cout << "   :      \n";
  cout << "  ::::::: \n";
  cout << " : | \\   : \n";
  cout << ":  |--\\   :\n";
  cout << " : |   \\ : \n";
  cout << ": ::::::: :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n";
  cout << ":: Welcome to Twitter, please be polite and avoid spamming otherwise you will be banned. ::\n";
  cout << ":: Type exit for back to menu                                                            ::\n";
  cout << ":: loading....                                                                           ::\n";
  cout << ":::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n";
  Sleep(5000);
  system("CLS");
  while (!filetwitt.eof()) {
    filetwitt >> twitts;
    if (twitts == "@") {
      cout << '\n' ;
    }
    cout << twitts << " " ;
  }
  filetwitt.close();
  cout << "\nyou :  " ;
  twittmessage();
  return 1 ;
}
//- game
void Setup() {
  nTail =0 ;
  width = 20 , height = 17;
  gameover = false;
  dir = STOP;
  x = width/2;
  y = height/2;
  fruitX = rand() % width; //display fruit in a random place
  fruitY = rand() % height; score=0 ;
}
void Draw() {
	system("cls");
	for (int i=0; i < width+2 ; i++){
		cout << "#";
	}
	cout << '\n';
	for (int i=0; i < height ; i++) {
    	for (int j=0; j < width; j++) {
			if (j==0){
				cout << "#"; //walls	
			}
			if (i==y && j==x)
        		cout << "*"; // snake tale
			else if (i==fruitY && j==fruitX ){
				cout << "%"; // change it to change the fruit
			}
			else {
        		bool print=false;
        		for (int k=0 ; k<nTail ; k++) {
					if (tailX[k] == j && tailY[k] == i) {
            cout << "*"; 
						print = true;
					}
        		}		
        		if (!print){
        			cout << " ";	
				}
			}
			if (j == width - 1){
				cout << "#";	
			}	
    	}
    	cout << '\n';
	}
	for (int i = 0; i < width + 2; i++){
		cout << "#";	
	}	
	cout << '\n';
	cout << "Score:" << score << '\n' ;
}
void Input (){
  if (_kbhit ()) {
    switch (_getch ()) {
      case 'a':
        dir = LEFT;
        break;
      case 'd':
        dir = RIGHT;
        break;
      case 'w':
        dir = UP;
        break;
      case 's':
        dir = DOWN ;
        break;
      case 'x':
        gameover = true;
        break;
    }
  }
}
void algorithm(){
  int prevX = tailX [0];
  int prevY = tailY [0];
  int prev2X, prev2Y;
  tailX[0] = x;
  tailY[0] = y;
  for (int i = 1; i < nTail ; i++){
    prev2X = tailX[i];
    prev2Y = tailY[i];
    tailX[i] = prevX;
    tailY[i] = prevY;
    prevX = prev2X;
    prevY = prev2Y ;
  }
  switch (dir) {
    case LEFT:
      x--;
      break;
    case RIGHT:
      x++;
      break;
    case UP:
      y--;
      break;
    case DOWN:
      y++;
      break;
    default:
      break;
  }
  if (x >= width) x = 0; else if (x < 0) x = width - 1;
  if (y >= height) y = 0; else if (y < 0) y = height - 1;
  for (int i = 0; i < nTail ; i++)
    if (tailX[i] == x && tailY[i] == y)
      gameover = true;
  if (x == fruitX && y == fruitY) {
    score += 10;
    fruitX = rand() % width;
    fruitY = rand() % height;
    nTail ++;
  }
}
void game(){
  system("CLS");
  cout << "loading...\n";
  cout << "you can move by : W,S,A,D and for end of game press x \n";
  Sleep(3000);
  Setup();
  while(true){
    char ask{} ;
    Setup();
    while (!gameover) {
      Draw ();
      Input ();
      algorithm ();
      Sleep(60);
    }
    cout << "for back too menu press [b] then enter & for play agane press any key\n";
    cin >> ask ;
    if (ask=='b'){
      break ;
    }
  }
}
//- end
void logout() {
  system("CLS");
  for (int i = 0 ; i <= 2 ; i++) {
    cout << "   :      \n";
    cout << "  ::::::: \n";
    cout << " : | \\   : \n";
    cout << ":  |--\\   :\n";
    cout << " : |   \\ : \n";
    cout << ": ::::::: :::::::\n";
    cout << ":: Loging out  ::\n" ;
    pleasewait() ;
    system("CLS");
  }
  logout_check = true ;
}
void end() {
  system("cls");
  for (int i = 1 ; i <= 2 ; i++) {
    cout << "   :      \n";
    cout << "  ::::::: \n";
    cout << " : | \\   : \n";
    cout << ":  |--\\   :\n";
    cout << " : |   \\ : \n";
    cout << ": ::::::: ::::::::::::::::::::::::\n";
    cout << ":: Tahnks for using this app :) ::\n";
    cout << ":: created by Taha_HDP          ::\n";
    cout << ":: EXITING";
    Sleep(400);
    for (int j = 1 ; j <= 3 ; j++) {
      cout << "." ;
      Sleep(400);
    }
    system("cls");
  }
  system("color 7");
  system("cls");
}
//- 