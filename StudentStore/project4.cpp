 #include<fstream>
#include<string.h>
#include<conio.h>
#include<iomanip>
#include<dos.h>
#include<iostream>
 #include <cstdlib>
 #include<cmath>
using namespace std;
#include <time.h>
#include<ctype.h>
#include <windows.h>
#include <process.h>
#include <unistd.h>
#include<string.h>
 #define clrscr() system("cls");


 #define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77

char num[10] = {'o','1','2','3','4','5','6','7','8','9'};

int checkwin();



int win()
{
    if (num[1] == num[2] && num[2] == num[3])

        return 1;
    else if (num[4] == num[5] && num[5] == num[6])

        return 1;
    else if (num[7] == num[8] && num[8] == num[9])

        return 1;
    else if (num[1] == num[4] && num[4] == num[7])

        return 1;
    else if (num[2] == num[5] && num[5] == num[8])

        return 1;
    else if (num[3] == num[6] && num[6] == num[9])

        return 1;
    else if (num[1] == num[5] && num[5] == num[9])

        return 1;
    else if (num[3] == num[5] && num[5] == num[7])

        return 1;
    else if (num[1] != '1' && num[2] != '2' && num[3] != '3'
                    && num[4] != '4' && num[5] != '5' && num[6] != '6'
                  && num[7] != '7' && num[8] != '8' && num[9] != '9')

        return 0;
    else
        return -1;
}



void game()     //Function to draw the player's game board along with there input
{
    system("cls");
    cout << "\n\n\tTic Tac Toe\n\n";

    cout << "Player 1 (X)  -  Player 2 (O)" << endl << endl;
    cout << endl;

    cout << "     |     |     " << endl;
    cout << "  " << num[1] << "  |  " << num[2] << "  |  " << num[3] << endl;

    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;

    cout << "  " << num[4] << "  |  " << num[5] << "  |  " << num[6] << endl;

    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;

    cout << "  " << num[7] << "  |  " << num[8] << "  |  " << num[9] << endl;

    cout << "     |     |     " << endl << endl;
}

struct coordinate{
    int x;
    int y;
    int direction;
};

typedef struct coordinate coordinate;

coordinate head, bend[500],food,body[30];

  class book_store
  {
     public:

         char code[10],b_name[20],w_name[20];

         float price;

         void get_data()
         {
          cout<<"\nBook name   :";
          cin>>b_name;

          cout<<"\nBook code   : ";
          cin>>code;

          cout<<"\nWriter name :";
          cin>>w_name;


 cout<<"\nPrice       :";
          cin>>price;
          cout<<endl;


         };

  };


  class book_file:public book_store
  {
     public:
        void fil()
        {
         fstream file("All_Books.txt",ios::out|ios::app);

         file.width(20);
         file<<setiosflags(ios::left);
         file<<b_name;

         file.width(20);
         file<<setiosflags(ios::left);
         file<<w_name;

         file.width(10);
         file<<setiosflags(ios::right);
         file<<code;

         file.width(10);
         file<<setiosflags(ios::right);
         file<<price;



         file.close();
        }
        void file();



  };
        void book_file::file()
         {
           char fil[20];

           get_data();
           strcpy(fil,code);
           strcat(fil,".txt");

           ofstream file(fil);
           file<<"Book Name   :"<<b_name<<endl;
           file<<"Writer Name :"<<w_name<<endl;
           file<<"Book Code   :"<<code<<endl;
           file<<"Price       :"<<price<<endl;

           file.close();

           }





  class T1:public book_file
  {
       public:

          void book_data()
           {
           fstream file1("Literature.txt",ios::out|ios::app);
           file1<<endl;
           file1<<"Book Name   :"<<b_name<<endl;
           file1<<"Writer Name :"<<w_name<<endl;
           file1<<"Book Code   :"<<code<<endl;
           file1<<"Price       :"<<price<<endl;

           file1.close();
           }
  };


  class T2:public book_file
  {
       public:

          void book_data()
           {
           fstream file1("Philosophy.txt",ios::out|ios::app);
           file1<<endl;
           file1<<"Book Name   :"<<b_name<<endl;
           file1<<"Writer Name :"<<w_name<<endl;
           file1<<"Book Code   :"<<code<<endl;
           file1<<"Price       :"<<price<<endl;

           file1.close();
           }
  };

  class T3:public book_file
  {
       public:

          void book_data()
           {
           fstream file1("Science.txt",ios::out|ios::app);
           file1<<endl;
           file1<<"Book Name   :"<<b_name<<endl;
           file1<<"Writer Name :"<<w_name<<endl;
           file1<<"Book Code   :"<<code<<endl;
           file1<<"Price       :"<<price<<endl;

           file1.close();
           }
  };

  class T4:public book_file
  {
       public:

          void book_data()
           {
           fstream file1("Comics.txt",ios::out|ios::app);
           file1<<endl;
           file1<<"Book Name   :"<<b_name<<endl;
           file1<<"Writer Name :"<<w_name<<endl;
           file1<<"Book Code   :"<<code<<endl;
           file1<<"Price       :"<<price<<endl;

           file1.close();
           }
  };                                               //T4 class ends


  class add_books
  {
   public:
   add_books();
  };

   add_books::add_books()

   {

    T1 t1;
    T2 t2;
    T3 t3;
    T4 t4;
    int choice;

     while(1)
     {
      clrscr();
      cout<<"....................Add Books................";
      cout<<"\n1.Literature Books \n2.Philosophy books \n3.Science Books \n4.Comics books \n5.Exit \n";
      cout<<"\nChoice:";
      cin>>choice;

       if(choice==1)
       {
    t1.file();
    t1.book_data();
    t1.fil();

       }

       if(choice==2)
       {
    t2.file();
    t2.book_data();
    t2.fil();

       }

       if(choice==3)
       {
    t3.file();
    t3.book_data();
    t3.fil();

       }

       if(choice==4)
       {
    t4.file();
    t4.book_data();
    t4.fil();

       }

       if(choice==5)
       {
    break;
       }

     }                               //while ends

   }                                  //add_books fn ends




  class display
  {
   public:
   display();
  };
  class tic
  {
   public:
   tic();
  };


   display::display()
   {
    int choice;
    char code[10],ch;
     while(1)
     {
      cout<<"\n\n...................DISPLAY.....................\n\n";

      cout<<"1.Literature"<<endl;
      cout<<"2.Philosophy"<<endl;
      cout<<"3.Science"<<endl;
      cout<<"4.Comics"<<endl;
      cout<<"5.Exit"<<endl;

  //...................................................................
     cout<<"\nEnter Ur Choice:" ;
     cin>>choice;


      if(choice==1)
      {
       clrscr();
       fstream file("Literature.txt",ios::in);
       file.seekg(0);
       cout<<"\n";
       while(file)
    {
     file.get(ch);

     cout<<ch;
    }
    file.close();
    getch();

      }

      if(choice==2)
      {
       clrscr();
       fstream file("Philosophy.txt",ios::in);
       file.seekg(0);
       cout<<"\n";
       while(file)
    {
     file.get(ch);

     cout<<ch;
    }
    file.close();
    getch();
      }

      if(choice==3)
      {
       clrscr();
       fstream file("Science.txt",ios::in);
       file.seekg(0);
       cout<<"\n";
       while(file)
    {
     file.get(ch);

     cout<<ch;
    }
    file.close();
    getch();
      }

      if(choice==4)
      {
       clrscr();
       fstream file("Comics.txt",ios::in);
       file.seekg(0);
       cout<<"\n";
       while(file)
    {
     file.get(ch);

     cout<<ch;
    }
    file.close();
    getch();
      }

      if(choice==5)
      break;

     }                                   // while (choice) ends
   }                                    // display class ends


  class search
  {
   public:
   search();
  };
   class calc
  {
   public:
   calc();
  };


   search::search()
   {
    int choice;
    char fil[20];
    char ch,code[10];
    while(1)
    {
    clrscr();
    cout<<"\n\n....................SEARCH...................\n\n";
    cout<<"1.Search";
    cout<<"\n2.Exit\n";
    cout<<"\nChoice:";
    cin>>choice;
      if(choice==1)
      {
      cout<<"Enter Code:";
      cin>>code;
      cout<<endl;
      strcpy(fil,code);
      strcat(fil,".txt");
      fstream file(fil,ios::in);
      while(file)
      {
       file.get(ch);
       cout<<ch;
      }
      file.close();
      getch();
      }
      if(choice==2)
      break;
    }


   }

  class start
  {
   public:
    start();

  };

   start::start()
   {
    int choice;
    system("color A1");


    while(1)
    {
    clrscr();
    cout<<"Welcome to the Student Bookstore "<<endl;
    cout<<"***************************************************************"<<endl;
    cout<<"\n\n.........Enter Ur Choice........\n\n";
    cout<<"1.Add Books\n";
    cout<<"2.Display\n";
    cout<<"3.Search\n";
    cout<<"4.Exit\n";
    cout<<"Choice:";
    cin>>choice;

    if(choice==1)
    { add_books a;}

    if(choice==2)
    { display d;}

    if(choice==3)
     {search s; }

    if(choice==4)
     break;

    }

              //while ends

   }                           // start fn ends


int ch;

  int opt;
int i=0;
string pwd;
          string pass;

    int main()
    {
    while(1)
    {


clrscr();
system("Color F0");
 cout<<"Welcome to the Student Bookstore "<<endl;
    cout<<"***************************************************************"<<endl;

cout<<"Either enter a password or set/change password! \n";
cout<<"1.Enter password \n";
cout<<"2.Set/Change password \n";
cin>>opt;
if(opt==1){

int i=0;
cout<<"Please enter password:-";
cin>>pwd;
cout<<endl;
ifstream ou;    // Create an input file stream.
                ou.open("pass.txt");  // Use it to read from a file named data.txt.
ou>>pass;

if (pwd==pass)
{
clrscr();
system("Color B0");
    cout<<"Press 1 to go to bookstore\nPress 2 to use calculator\nPress 3 to play tic tac toe game";
    cout<<endl<<endl<<endl;
    cout<<"1.Go To Book Store \n";
     cout<<"2.Open Calculator \n";
     cout<<"3.Play Tic Tac Toe \n";
     cout<<"4.Exit \n";
     cout<<"Enter Your Choice:";
cin>>ch;



//------calculating the requested equation for inputs-------------
//-------at the same time printing the results on screen-----------
     if(ch==1){
         start s;


     }
     if(ch==2){
            clrscr();
             calc c;
             }

      if(ch==3)
          {


clrscr();
             tic t;

          }


if(ch==4){
    break;
}
   ou.close();


}
else{
cout<<"wrong password! Try to set or change password!";
}


}

if(opt==2)
{
 cout<<"Enter password:"<<endl;
cin>>pass;

           ofstream on;    // Create an input file stream.
                on.open("pass.txt");  // Use it to read from a file named data.txt.
                on << pass;    // Read the first item from the file into an integer variable x.


on.close();
}


}
        }

calc::calc()
{
    system("Color E0");
//-------defining variables and initializing them-------------
    double num1,num2;
    char operation,redo;
//--------Printing my name on screen----------------
    cout<<"Welcome to the calculater program "<<endl;
    cout<<"***************************************************************"<<endl;
    cout<<endl<<endl<<endl;
//--here do loop is used so that the program can be used more then one time
//without exiting the run screen---------------------------
    do
    {
 //----receiving the variables from input--------------
    cout<<" Please enter an operation which you like to calculate (+,-,*,/,s)";
    cout<<"[s stands for swap]:";
    cin>>operation ;
    cout<<endl<<endl;
     cout<<" Please enter two numbers to apply your requested operation(";
    cout<<operation<<"):"<<endl<<"1st num:";
    cin>>num1;
    cout<<"2nd num:" ;
    cin>>num2;
    cout<<endl;
 //---used switch function so thet the operater can be decided------------
    switch (operation)
    {
//------calculating the requested equation for inputs-------------
//-------at the same time printing the results on screen-----------
     case'+':
             cout<<"The addition of two numbers ("<<num1<<","<<num2<<"):";
             cout<<num1+num2<<endl;
             break;
     case'-':
             cout<<"The substraction of two numbers ("<<num1<<","<<num2<<"):";
             cout<<num1-num2<<endl;
             break;
      case'*':
             cout<<"The multiplication of two numbers ("<<num1<<","<<num2<<"):";
             cout<<num1*num2<<endl;
             break;
      case'/':
             cout<<"The division of two numbers ("<<num1<<","<<num2<<"):";
             if(num2==0)
             {
             cout<<"not valid"<<endl;
             }
             cout<<(num1/num2)<<endl;
             break;
      case's':
             cout<<"The swap of two numbers ("<<num1<<","<<num2<<"):";
             swap(num1,num2);
             cout<<"1stnumber="<<num1<<"and 2nd number="<<num2<<endl<<endl;
           break;
      default:
              cout<<"unknown command"<<endl;

           }
 //----now once again the program will ask the user if want to continue or not
           cout<<"enter y or Y to continue:";
           cin>>redo;
           cout<<endl<<endl;
           }
           while(redo=='y'||redo=='Y');

   system("pause");


    }






tic::tic(){

 system("Color D0");



    int player = 1,i,ch;

    char m;
    do
    {
        game();
        player=(player%2)?1:2;

        cout << "Player " << player << ", enter a number:  ";
        cin >> ch;

        m=(player == 1) ? 'X' : 'O';

        if (ch == 1 && num[1] == '1')

            num[1] = m;
        else if (ch == 2 && num[2] == '2')

            num[2] = m;
        else if (ch == 3 && num[3] == '3')

            num[3] = m;
        else if (ch == 4 && num[4] == '4')

            num[4] = m;
        else if (ch == 5 && num[5] == '5')

            num[5] = m;
        else if (ch == 6 && num[6] == '6')

            num[6] = m;
        else if (ch == 7 && num[7] == '7')

            num[7] = m;
        else if (ch == 8 && num[8] == '8')

            num[8] = m;
        else if (ch == 9 && num[9] == '9')

            num[9] = m;
        else
        {
            cout<<"Invalid move ";

            player--;
            cin.ignore();
            cin.get();
        }
        i=win();

        player++;
    }while(i==-1);
    game();
    if(i==1)

        cout<<"==>\aPlayer "<<--player<<" win ";
    else
        cout<<"==>\aGame draw";

    cin.ignore();
    cin.get();
   }



/*******************************************************************
     FUNCTION TO DRAW BOARD OF TIC TAC TOE WITH PLAYERS MARK
********************************************************************/


int check(char a[5],char b[5])
{int i;
    for(i=0;i<5;i++)
    {
        if(a[i]!=b[i])
        {
        break;
        }
    }
    if(i==5)
    return 1;
    else
    return 0;
}











