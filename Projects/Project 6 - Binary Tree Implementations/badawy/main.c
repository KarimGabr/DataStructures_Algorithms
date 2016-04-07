// copyright © Karem Badawy & Mohamed Amr & Mohamed Farag 2013-2014
// ID : 2392 , 2525 , 27
// Study @ Faculty of Engineering, Alexandria University, Egypt
// Final Project for Lab (Data Dtructures)

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Tree.h"

#define TYPE int
#define STACKSIZE 1000

typedef struct
{
    int top;
    TYPE items[STACKSIZE];
}Stack;

void initialize(Stack *s)
{
    s->top=0;
}
void push(Stack *s,TYPE value)
{
    s->items[s->top++]=value;
}
TYPE pop(Stack *s)
{
    return s->items[--s->top];
}
int isfull(Stack *s)
{
    return s->top<STACKSIZE?0:1 ;
}
int isempty(Stack *s)
{
    return s->top==0?1:0;
}
void error()
{
    printf("error");
}

void head()
{
    printf("\t \t   Wlcome to Treety Program !\n");
    printf("****************************************************************\n");
    printf("*\t\t       The program giude\t\t       * \n");
    printf("*--------------------------------------------------------------*\n");
    printf("*-if u want to insert press    [a] \t  \t    \t       * \n");
    printf("*-if u want to search press    [q] \t  \t  \t       * \n");
    printf("*-if u want to print  press    [p]    \t    \t     \t       * \n");
    printf("*-if u want to delete press    [d] \t    \t               * \n");
    printf("*-if u want to modify press    [m] \t    \t               * \n");
    printf("*-if u want to find min press  [i] \t    \t               * \n");
    printf("*-if u want to find max press  [x] \t    \t               * \n");
    printf("*-if u want to load file press [l] \t \t \t       * \n");
    printf("*-if u want to save press      [s]    \t    \t  \t       * \n");
    printf("*-to exit without saving press [e]        \t               * \n");
    printf("****************************************************************\n");  //how to use the program
    printf("\n");
    printf("\n");
    printf("enter what u want ! \n");
}
int main()
{
    InitializeComponent();
    int g;
    FILE *pfk;
    char x;
    char path[100];
    head();
    scanf("%c",&x);
    getchar();
    while(x!='e')
    {
        switch(x)
        {
        case 'l':
        {
            printf("Enter the path of the file u want to load it ! \n");
            gets(path);
            LOAD(path,pfk,root1,root2);
        }
        break;
        case 's':
        {
            SAVE(path,pfk);
            getchar();
        }
        break;
        case 'a':
        {
            int i;
            printf("Enter the name of the student !! \n");
            char name[100];

            gets(name);
            for(i=0; name[i]!='\0'; i++)
            {
                if (!((name[i]>='a' && name[i]<='z'|| name[i]>='A' && name[i]<='Z')||name[i]==' '))
                {
                    printf("Sorry this is not a valid name !!\n \n Please enter the correct name ! \n");

                    gets(name);
                    i=0;
                }
            }
            printf("Enter the ID of the student !! \n");
            char id[10];
            struct Node1* s3;
            gets(id);
            s3=search1(root1,id);
            if (strcmpi(id, s3->id) == 0)
            {
                printf("The ID you have entered has been entered before.\n Please Enter the correct id!!\n");
                int i,j=0;
                for(i=0; j!=5; i++)
                {
                    char id[10];
                    struct Node1* s3;
                    gets(id);
                    s3=search1(root1,id);
                    if (strcmpi(id, s3->id) == 0)
                    {
                        printf("The ID you have entered has been entered before.\n Please Enter the correct id!!\n");

                        gets(id);
                        i=0;
                    }
                    else
                        j=5;
                }
            }
            else
            {
                for(i=0; id[i]!='\0'; i++)
                {
                    if (!(id[i]<='9' && id[i]>='0'))
                    {
                        printf("Sorry this is not a valid ID !!\n \n Please enter the correct ID ! \n");

                        gets(id);
                        i=0;
                    }
                }
                // printf(" %s  %s\n",id ,name);
                root1=insert1(root1,id,name);
                root2=insert2(root2,id,name);
                // printf(" %s  %s\n",root1->id ,root1->name);
                //  printf(" %s  %s\n",root2->id ,root2->name);
            }
        }
        break;
        case'q':
        {
            if(root1==NULL)
            {
                printf("please isert data first \n Press Enter to go to the main menu !\n");
                getchar();
                break;
            }
            printf("Do u want to search By Name or ID ? \n N:Name \t I:ID\n");
            char what;
            scanf("%c",&what);
            getchar();
            if((what=='N')||(what=='n'))
            {
                if(root2==NULL)
                {
                    printf("please isert data first \n");
                    break;
                }
                char searching[100];
                printf("Enter the name u want to search ! \n");
                gets(searching);
                struct Node2* s2;
                s2=search2(root2,searching);
                if(s2==NULL)
                {
                    printf("the name not found\n");
                    break;
                }
//                strcpy(s2->id,ser[i].Id);
  //              strcpy(s2->name,ser[i].Name);
                printf("%s \t %s\n",s2->id,s2->name);
getchar();
            }
            else if((what=='I')||(what=='i'))
            {
                if(root1==NULL)
                {
                    printf("please isert data first \n");
                    break;
                }
                char searching[100];
                struct Node1* s1;
                printf("Enter the id u want to search ! \n");
                gets(searching);
                s1=search1(root1,searching);
                if(s1==NULL)
                {
                    printf("the id not found\n");
                    break;
                }
                printf("%s \t %s\n",s1->id,s1->name);
                getchar();
            }
        }
        break;
        case 'p':
        {
            if(root1==NULL)
            {
                printf("please isert data first \n Press Enter to go to the main menu !\n");
                getchar();
                break;
            }
            printf("Do you want to print by order of NAME or ID ?!! \n N:Name \t I:ID\n");
            char ptype;
            scanf("%c",&ptype);
            getchar();
            if((ptype=='n')||(ptype=='N'))
            {
                printf("Choose the Order pleas !!\n P:postorder \t I:inorder \t R:preorder");
                char order;
                scanf("%c",&order);
                getchar();
                if((order=='p')||(order=='P'))
                {
                    postorder1(root1);
                    printf("Press Enter to go to the main menu ! \n");
                    getchar();
                    break;
                }
                else if((order=='I')||(order=='i'))
                {
                    inorder2(root2);
                    printf("Press Enter to go to the main menu ! \n");
                    getchar();
                    break;
                }
                else if((order=='r')||(order=='R'))
                {
                    preorder2(root2);
                    printf("Press Enter to go to the main menu ! \n");
                    getchar();
                    break;
                }
            }
            else if((ptype=='i')||(ptype=='I'))
            {
                printf("Choose the Order pleas !!\n P:postorder \t I:inorder \t R:preorder\n");
                char order;
                scanf("%c",&order);
                getchar();
                if((order=='p')||(order=='P'))
                {
                    postorder2(root2);
                    printf("Press Enter to go to the main menu ! \n");
                    getchar();
                    break;
                }
                else if((order=='I')||(order=='i'))
                {
                    inorder1(root1);
                    printf("Press Enter to go to the main menu ! \n");
                    getchar();
                    break;
                }
                else if((order=='r')||(order=='R'))
                {
                    preorder1(root1);
                    printf("Press Enter to go to the main menu ! \n");
                    getchar();
                    break;
                }

            }
        }
        break;
        case 'd':
        {
            if(root1==NULL)
            {
                printf("please isert data first \n Press Enter to go to the main menu !\n");
                getchar();
                break;
            }
            printf("Do u want to DELET By Name or ID ? \n N:Name \t I:ID\n");
            char what;
            scanf("%c",&what);
            getchar();
            if((what=='N')||(what=='n'))
            {
                if(root2==NULL)
                {
                    printf("please insert data first \n");
                    getchar();
                    break;
                }
                char deletingo[100];
                printf("Enter the name u want to delete ! \n");
                gets(deletingo);
                struct Node2* s4;
                s4=search2(root2,deletingo);
                if(s4==NULL)
                {
                    printf("the name not found\n");
                    getchar();
                    break;
                }
                root1=deleten(root1,s4->id);
                root2=deleten2(root2,s4->name);
                printf("Done\n");
                getchar();
            }
            else if((what=='I')||(what=='i'))
            {
                if(root1==NULL)
                {
                    printf("please isert data first \n");
                    getchar();
                    break;
                }
                char deletingo[100];
                struct Node1* s5;
                printf("Enter the id u want to search ! \n");
                gets(deletingo);
                s5=search1(root1,deletingo);
                if(s5==NULL)
                {
                    printf("the name not found\n");
                    getchar();
                    break;
                }
                root1=deleten(root1,s5->id);
                root2=deleten2(root2,s5->name);
                printf("Done\n");
                getchar();
            }
        }
        break;
        case 'i':
        {
            if(root1==NULL)
            {
                printf("please isert data first \n Press Enter to go to the main menu !\n");
                getchar();
                break;
            }
            printf("Chose do u want to find min of id or name ? \n N:Name \t I:ID\n");
            char what;
            scanf("%c",&what);
            getchar();
            if((what=='i')||(what=='I'))
            {
                struct Node1* mino;
                mino=findmin1(root1);
                printf("The min ID is : %s",mino->id);
                getchar();
            }
            else if((what=='n')||(what=='N'))
            {
                struct Node1* mino;
                mino=findmin2(root2);
                printf("The min Name is : %s",mino->name);
                getchar();
            }
        }
        break;
        case 'x':
        {
            if(root1==NULL)
            {
                printf("please isert data first \n Press Enter to go to the main menu !\n");
                getchar();
                break;
            }
            printf("Chose do u want to find max of id or name ? \n N:Name \t I:ID\n");
            char what;
            scanf("%c",&what);
            getchar();
            if((what=='i')||(what=='I'))
            {
                struct Node1* maxo;
                maxo=findmax1(root1);
                printf("The min ID is : %s",maxo->id);
                getchar();
            }
            else if((what=='n')||(what=='N'))
            {
                struct Node1* maxo;
                maxo=findmax2(root2);
                printf("The min Name is : %s",maxo->name);
                getchar();
            }
        }
        break;
        case 't':
        {
            if(root1==NULL)
            {
                printf("please isert data first \n Press Enter to go to the main menu !\n");
                getchar();
                break;
            }
            printf("Do u want to search By Name or ID to edit data ? \n N:Name \t I:ID\n");
            char what;
            scanf("%c",&what);
            getchar();
            if((what=='N')||(what=='n'))
            {
                char searching[100];
                printf("Enter the name u want to search ! \n");
                gets(searching);
                struct Node2* v2;
                v2=search2(root2,searching);
                if(v2==NULL)
                {
                    printf("the name not found\n");
                    break;
                }
//                edit2(root2,v2->id,s2->name);
            }
            else if((what=='I')||(what=='i'))
            {
                char searching[100];
                struct Node1* v1;
                printf("Enter the id u want to search ! \n");
                gets(searching);
                v1=search1(root1,searching);
                if(v1==NULL)
                {
                    printf("the id not found\n");
                    break;
                }
                v1=edit1(root1,v1->id,v1->name);
          }

            }
            break;
//        else if (x== 's' )
            //  SAVE(path,pfk);

//        else if(x== 'm')
            //MODIFY();
//        else
            default :
            {
                printf("wrong ! \n press enter \n");
                getchar();
            }
        }
        system("cls");
        head();
        scanf("%c",&x);
        getchar();

    }
    /*
    int i;
    for(i=0;i<3;i++)
    {
        char a;
        printf("Enter name id\n");
        char x[100];
        int id;
        gets(x);
        scanf("%d",&id);
        a=getchar();
        root1=insert1(root1,id,x);
        root2=insert2(root2,id,x);
    }
    printf("Enter seaarxh \n");
    char y[100];
    char s;
    gets(y);
    strcpy(search2(root2,y)->name,y);
    printf("%s",y);
      inorder1(root1);
      inorder2(root2);*/
    return 0;
}
