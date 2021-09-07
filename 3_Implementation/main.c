/**
 * @file main.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-09-06
 * 
 * @copyright Copyright (c) 2021
 * 
 */



#include "fun.h"

char password[8]="library";
char info[500];
char *arr="Books.txt";
FILE *pb;



void admin(void)
{
    system("cls");
    printf("\n\n\t\t Please enter the password : ");
    char str[20];
    char ch;int i=0;

    while((ch=getch())!='\r'&&i<20)
    {
        putch('*');
        str[i++]=ch;
    }
    str[i]='\0';
    if(strcmp(str,password)==0)
        {
            printf("\n\n\t\t Authentication successful");
            printf("\n\n\t\t Press any key to continue");
            getch();
        }
    else
        {
            printf("\n\n\t\t Incorrect password entered");
            printf("\n\n\t\t Press any key to continue");
            getch();
            return;
        }
    int choice;
    do
    {
        system("cls");
        printf("\n\n\t\t\t\t Book Menu");
        printf("\n\n\t\t 1. Add Book \n\t\t 2. list Book  \n\t\t  3. Exit");
        printf("\n\n\t\t Please Enter the choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:addbook();
            break;
            case 2:listbook();
            break;
           
            case 3:exitcheck();
            break;
            default: printf("\n\n\t\t Invalid Choice");
            getch();
        }
    }while(1);
}


void exitcheck(void)
{
    system("cls");
    printf("\n\n\t\t Do you really want to exit ?(Y/N) : ");
    char ch;
    scanf(" %c",&ch);
    if(ch=='Y'||ch=='y')
        exit(1);
    return;
}


int main(void)
{
    system("cls");
    printf("\n\n\n\t\t\t Library Management System \n\n\t\t\t\t\t\t\t\t mini project \n\t\t\t\t\t\t\t\t");
    printf("\n Press any key to continue");
    getch();
    admin();
    return 0;
}