/**
 * @file add.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-09-06
 * 
 * @copyright Copyright (c) 2021
 * 
 */


#include "fun.h"
extern char *arr;
extern FILE *pb;
void addbook(void)
{
    pb=fopen(arr,"a");
    char ch;
    do
    {
        label:
        system("cls");
        printf("\n\n\t\t\t Add Book");
        printf("\n\n\t\t Please Enter the following details");
        printf("\n\n\t BookId : ");
        scanf("%d",&b.id);
        if(bidcheck(b.id)==0)
        {
            printf("\n\t Book Name : ");
            scanf(" %[^\n]s",b.name);
            printf("\n\t Author : ");
            scanf(" %[^\n]s",b.author);
            printf("\n\t Number of copies :");
            scanf("%d",&b.copies);
            b.copiesleft=b.copies;
            fwrite(&b,sizeof(struct book),1,pb);
            printf("\n\t Book Successfully added");
            printf("\n\t Do you want to enter details of another book? (Y/N)");
            scanf(" %c",&ch);
        }
        else
        {
            printf("\n\t BookId already exists ");
            printf("\n\t Press any key to continue ");
            getch();
            goto label;
        }
    }while(ch=='Y'||ch=='y');
    fclose(pb);
    return;
}
