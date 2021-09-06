/**
 * @file search.c
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

void searchbook(void)
{
    pb=fopen(arr,"r");
    char ch,name[20];int i;
    do
    {
        system("cls");
        i=0;
        rewind(pb);
        printf("\n\n\t\t\t\t Book Search ");
        printf("\n\t Enter the name of the book to search : ");
        scanf(" %[^\n]s",name);
        while(!feof(pb))
        {
            if(fread(&b,sizeof(struct book),1,pb)==1)
            if(strcmpi(b.name,name)==0)
            {
                i++;
                printf("\n\t Search Result : %d",i);
                printf("\n\t BookId : %d \n\t Book Name : %s \n\t Author : %s \n\t Number of copies : %d \n\t Number of copies left : %d",b.id,b.name,b.author,b.copies,b.copiesleft);
            }
        }
    if(i==0)
        printf("\n\t No such book found");
    printf("\n Do you want to search for any other book ? (Y/N)");
    scanf(" %c",&ch);
    }while(ch=='Y'||ch=='y');
    fclose(pb);
    return;
}
