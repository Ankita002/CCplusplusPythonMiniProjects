#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>
#include<string.h>
struct record
 {
char password[30];
char mail[40];
char site[40];


 };
 char page[100];
 char email[100];
 char p[100];
char e[100];
 char gu[100];
     char gp[100];


 void login();
 void regist();
  void menu();
 void got();
 void start();
 void back();
 void listrecord();
 void modifyrecord();
 void deleterecord();
 void searchrecord();
 void first();
 int main()
  {

     system("color 9f");



     first();
     return 0;
 }
 void back()
 {

     start();
 }
 void start(){

 menu();
 }
 login()
 {


     printf("Enter Username:\n");
     got(gu);
     printf("Enter password:\n");
     got(gp);
      FILE *f;
        f= fopen("project2.dat","ab+");
   if(f==NULL)
{

    printf("\n Error opening file.\a\a\a\a");
    exit(1);

}

int a=0;
while(fread(&p,sizeof(p),1,f)==1)
{

    if((strcmp(gu,e) && strcmp(gp,p))==0)
    {

       start();
    a=1;
    }

    }
    if(a!=1)
    {printf(" \nAccount not found.");
    }
    fclose(f);
    printf("\n Enter any key:");
    getch();
    system("cls");
int i;
     for(i=0;i<5;i++)
    {

        email[i]=gu[i];
    }
      FILE *fa;
     strcat(email,".dat");
    fa=fopen(email,"rb");
  fclose(fa);
first();


 }

 regist(){
     FILE *f;
      f= fopen("project2.dat","ab+");
 printf("Enter your Email ID:\n");
 got(e);
 printf("Enter your password:\n");
 got(p);

    fwrite(&p,sizeof(p),1,f);
    fflush(stdin);
    printf("\n registered");

    fclose(f);
    int i;
    for(i=0;i<5;i++)
    {

        email[i]=e[i];
    }
   FILE *fa;
     strcat(email,".dat");
    fa=fopen(email,"rb");
  fclose(fa);

    printf("\n Enter any key:");
     getch();
     system("cls");
     first();

 }
 void first(){
    printf("*************************Password Storage Application*****************");
  printf("\n\n\n\t\t\t\t Login Page\t\t\n\n");
  printf("*********************************************************************\n");
      printf("\t 1. Login \n");
  printf("\t 2. Register \n");
printf("*********************************************************************\n");
  switch(getch())
  {

      case '1':
         {

          login();
          break;
          }
      case '2':
        {regist();
        break;
        }
        default:{
        system("cls");
        printf("\n Enter your choice from 1 to 2 only ");
        printf("\n Enter any key");
        getch();
  }
  }}
 void menu()
 {
  system("cls");
  printf("*************************Password Storage Application*****************");
  printf("\n\n\n\t\t\t\t MENU \t\t\n\n");
  printf("*********************************************************************\n");
  printf("\t 1. Add New Account \n");
  printf("\t 2. Show all accounts with passwords\n");
  printf("\t 3. Exit\n");
  printf("\t 4. Modify \n");
  printf("\t 5. Search \n");
  printf("\t 6. Delete \n");
printf("*********************************************************************\n");
  switch(getch())
  {

      case '1':
         {

          addrecord();
          break;
          }
      case '2':
        {listrecord();
        break;
        }
      case '3':
        {

          exit(0);
          break;}
      case '4':
         {

          modifyrecord();
          break;}
      case '5':
       {

        searchrecord();
        break;
       }
     case '6': {deleterecord();
     break;}
     default:{
        system("cls");
        printf("\n Enter your choice from 1 to 6 only ");
        printf("\n Enter any key");
        getch();
  }

  }



  }
  void addrecord()
{

    system("cls");
    FILE *fa;
    struct record p;

    fa= fopen(email,"ab+");
    printf("Enter name of website:");
    got(p.site);
    printf("\n Enter the Email address:");
    got(p.mail);
    printf("\n Enter Password:");
    got(p.password);

    fwrite(&p,sizeof(p),1,fa);
    fflush(stdin);
    printf("\n record saved");

    fclose(fa);

    printf("\n Enter any key:");
     getch();
     system("cls");
     menu();


}

void listrecord()
{

    struct record p;
    FILE *fa;
    fa=fopen(email,"rb");
    if(fa==NULL)
    {

        printf("\n File is Empty.");
        exit(1);
    }


    while(fread(&p,sizeof(p),1,fa)==1)
    {

printf("\n\n\n Your Account Details:\n\n ");
printf("*********************************************************************\n");
  printf("\n Website=%s\n Email ID=%s\n  Password=%s\n ",p.site,p.mail,p.password);
printf ("\n Press any key to see next Account Details \n");

getch();
system("cls");

    }
    fclose(fa);
    printf("\n Enter any key");
    getch();
    system("cls");
    menu();

}

void searchrecord(){
struct record p;
FILE *fa;
char id[100];
fa=fopen(email,"rb");
if(fa==NULL)
{

    printf("\n Error opening file.\a\a\a\a");
    exit(1);

}

printf("\n Enter Email ID to search \n");
got(id);
int a=0;
while(fread(&p,sizeof(p),1,fa)==1)
{

    if(strcmp(p.mail,id)==0)
    {

        printf("\n Account Details %s",id);
                printf("\n Website=%s\n Email ID=%s\n   Password=%s\n  ",p.site, p.mail,p.password);
    a=1;
    }

    }
    if(a!=1)
    {printf(" \nAccount not found.");
    }
    fclose(fa);
    printf("\n Enter any key:");
    getch();
    system("cls");
    menu();
}

void deleterecord()
{
    struct record p;
    FILE *fa,*ft;
	int flag;
	char site[100];
	fa=fopen(email,"rb");
	if(fa==NULL)
		{

			printf("ACCOUNT'S DATA NOT ADDED YET.");

		}
	else
	{
		ft=fopen("tempose.dat","wb");
		if(ft==NULL)

            printf("file opening error");
		else

        {


		printf("Enter name of website:");
		got(site);

		fflush(stdin);
		while(fread(&p,sizeof(p),1,fa)==1)
		{
			if(strcmp(p.site,site)!=0)
				fwrite(&p,sizeof(p),1,ft);
			if(strcmp(p.site,site)==0)
                flag=1;
		}
	fclose(fa);
	fclose(ft);
	if(flag!=1)
	{
		printf("NO ACCOUNT'S RECORD TO DELETE.");
		remove("tempose.dat");
	}
		else
		{
			remove("page.dat");
			rename("tempose.dat",email);
			printf("\n \t ACCOUNT DELETED SUCCESSFULLY.");

		}
	}
}
 printf("\n Enter any key");

	 getch();
    system("cls");
menu();
}

    void modifyrecord(){

    int c;
    FILE *fa;

    int flag=0;

    struct record p,s;
    char site[50];
    fa=fopen(email,"rb+");

    if(fa==NULL)
    {

        printf("Account's data is not added yet.");
        exit(1);

    }

    else{
        system("cls");
        printf("\n Enter website name to modify: \n");
        got(site);
        while(fread(&p,sizeof(p),1,fa)==1){

            if(strcmp(site,p.site)==0)
            {
                 printf("Enter name of site:");
    got(s.site);
    printf("\n Enter the Email ID/Username:");
    got(s.mail);
    printf("\n Enter password:");
    got(s.password);

    fseek(fa,-sizeof(p),SEEK_CUR);
    fwrite(&s,sizeof(p),1,fa);
    flag=1;
    break;

            }



            fflush(stdin);
        }

        if(flag=1)
        {


        printf("\n Your account is modified.");
    }

    else{
        printf("\n Account is not found.");



    }

    fclose(fa);





    }

    printf("\n Enter any key:");
    getch();
    system("cls");
    menu();

}


void got(char *name)
{

   int i=0,j;
    char c,ch;
    do
    {
        c=getch();
                if(c!=8&&c!=13)
                {
                    *(name+i)=c;
                        putch(c);
                        i++;
                }
                if(c==8)
                {
                    if(i>0)
                    {
                        i--;
                    }
                   // printf("h");
                    system("cls");
                    for(j=0;j<i;j++)
                    {
                        ch=*(name+j);
                        putch(ch);

                    }

                }
    }while(c!=13);
      *(name+i)='\0';
}


