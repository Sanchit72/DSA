#include<stdio.h>
#include<stdlib.h>

struct Node
{
   int data;
   struct Node *next;
   struct  Node *prev;    //#  
};
typedef struct Node NODE;
typedef struct Node * PNODE;
typedef struct Node ** PPNODE;

void InsertFirst(PPNODE Head,int No)
{
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = No;
    newn->next =NULL;
    newn->prev = NULL;      //#

    if(*Head==NULL)
    {
        *Head=newn;
    }
    else
    {
        newn->next=*Head;
        (*Head)->prev=newn;         //#
        *Head=newn;
    }
}
void InsertLast(PPNODE Head,int No)
{
     PNODE newn = NULL;
     PNODE Temp = *Head;

    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = No;
    newn->next =NULL;
    newn->prev = NULL;      //#

    if(*Head==NULL)
    {
        *Head=newn;
    }
    else
    {
        while (Temp->next!=NULL)
        {
            Temp = Temp->next;
        }
         Temp->next=newn;
         newn->prev=Temp;       //#
    }
}

void DeleteFirst(PPNODE Head)
{
    if(*Head==NULL)
    {
        return;
    }
    else if(((*Head)->next == NULL) && ((*Head)->prev==NULL))       //#
    {
        free(*Head);
        *Head=NULL;
    }
    else
    {
        *Head=(*Head)->next;
        free((*Head)->prev);                //#
        (*Head)->prev=NULL;                //#
    }
}
void DeleteLast(PPNODE Head)
{
    PNODE Temp = *Head;

     if(*Head==NULL)
    {
        return;
    }
    else if(((*Head)->next == NULL) && ((*Head)->prev==NULL))       //#
    {
        free(*Head);
        *Head=NULL;
    }
    else
    {
        while (Temp->next->next!=NULL)
        {
            Temp = Temp->next;
        }
         free(Temp->next);
          Temp->next=NULL;          //#
    }
}
void Dispaly(PNODE Head)
{
    printf("Content of linked list are :\n");

    printf("NULL <=> ");
    while(Head !=NULL)
    {
        printf("| %d | <=> ",Head->data);
        Head = Head->next;
    }
    printf("NULL\n");
}
int Count(PNODE Head)
{
    int icnt = 0;

    while (Head != NULL)
    {
        icnt++;
        Head= Head->next;
    }
    
    return icnt;
}
void InsertATPos(PPNODE Head,int No,int Pos)
{
    int isize = 0;
    isize = Count(*Head);
    PNODE newn = NULL;
    PNODE Temp = *Head;

    if((Pos<1)||(Pos > (isize+1)))
    {
        printf("Invalid position \n");
        return;
    }
     if(Pos == 1)
     {
        InsertFirst(Head,No);
    }
    else if(Pos == isize+1)
      {
        InsertLast(Head,No);
    }
     else
    {
        newn = (PNODE)malloc(sizeof(NODE));
        newn->data=No;
        newn->next = NULL;
        newn->next = NULL;              //#

        for(int i=1;i<Pos-1;i++)
        {
            Temp = Temp ->next;
        }
        newn->next = Temp->next;
        Temp->next->prev = newn;        //#
        Temp->next=newn;
        newn->prev = Temp;              //#
}
}
void DeleteAtPos(PPNODE Head,int Pos)
{
    int isize = 0;
    isize = Count(*Head);
    PNODE newn = NULL;
    PNODE Temp = *Head;

    if((Pos<1)||(Pos > (isize))) 
    {
        printf("Invalid position \n");
        return;
    }
    if(Pos == 1)
    {
          DeleteFirst(Head);
    }
    else if(Pos == isize)
    {  
           DeleteLast(Head);
    }
    else
    { 
        for(int i=1;i<Pos-1;i++)
        {
           Temp = Temp ->next;
        }
        Temp->next = Temp->next->next;
        free(Temp->next->prev); 
        Temp->next->prev=Temp;

    }
}
int main()
{
    PNODE First = NULL ;
    int iRet = 0;

    InsertFirst(&First,51);
    InsertFirst(&First,21);
    InsertFirst(&First,11);
    Dispaly(First);
    iRet = Count(First);
    printf("Number of element : %d\n",iRet);

    InsertLast(&First,101);
    InsertLast(&First,111);
    InsertLast(&First,121);
    Dispaly(First);
    iRet = Count(First);
    printf("Number of element : %d\n",iRet);

    DeleteFirst(&First);
    Dispaly(First);
    iRet = Count(First);
    printf("Number of element : %d\n",iRet);

    DeleteLast(&First);
    Dispaly(First);
    iRet = Count(First);
    printf("Number of element : %d\n",iRet);

    InsertATPos(&First,105,5);
    Dispaly(First);
    iRet = Count(First);
    printf("Number of element : %d\n",iRet);

    DeleteAtPos(&First,5);
    Dispaly(First);
    iRet = Count(First);
    printf("Number of element : %d\n",iRet);



    return 0;
}