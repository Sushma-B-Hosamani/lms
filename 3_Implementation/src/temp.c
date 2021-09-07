
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
extern char info[500];

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
            scanf(" %s",b.name);
            printf("\n\t Author : ");
            scanf(" %s",b.author);
            printf("\n\t Number of copies :");
            scanf("%d",&b.copies);
            b.copiesleft=b.copies;
  
            fprintf(pb,"\n%d\t%s\t%s\t%d\t%d\t",b.id,b.name,b.author,b.copies,b.copiesleft);

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
    char info[500];
    pb=fopen(arr,"a++");
    system("cls");
    printf("\n\n\t\t Book Record");
    printf("\n %s %10s %10s %5s %11s","Id","Book Name","Author Name","No.of Copies","Copies Left");
    while(!feof(pb))
    {
        fgets(info,500,pb);
        printf("%5s\n",info);
    }
    fclose(pb);
    printf("\n\n\t Press any key to continue");
    getch();
    return;
}



