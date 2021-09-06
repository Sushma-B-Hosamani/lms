/**
 * @file list.c
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

void listbook(void)
{
    pb=fopen(arr,"r");
    system("cls");
    printf("\n\n\t\t Book Record");
    printf("\n %5s %20s %20s %12s %11s","Id","Book Name","Author Name","No.of Copies","Copies Left");
    while(!feof(pb))
    {
        if(fread(&b,sizeof(struct book),1,pb)==1)
        printf("\n %5d %20s %20s %12d %11d",b.id,b.name,b.author,b.copies,b.copiesleft);
    }
    fclose(pb);
    printf("\n\n\t Press any key to continue");
    getch();
    return;
}


