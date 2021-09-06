
#include "fun.h"

struct book
{
    int id;
    char name[20];
    char author[20];
    int copies;
    int copiesleft;
}b,bc;


extern char *arr;
extern FILE *pb;


int bidcheck(int id)
{
    FILE *b;
    int i=0;
    b=fopen(arr,"r");
    while(!feof(b))
    {
        if(fread(&bc,sizeof(struct book),1,b)==1)
            if(bc.id==id)
        {
            i=1;
            break;
        }
    }
    fclose(b);
    return i;
}

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





