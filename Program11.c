#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

typedef struct Node NODE;
typedef struct Node * PNODE;
typedef struct Node ** PPNODE;

void InsertFirst(PPNODE Head , int No)
{
    PNODE newn = (PNODE)malloc(sizeof(NODE));

    newn->data = No;
    newn->next =NULL;

    if(*Head == NULL)
    {
        *Head = newn;
    }
    else
    {
        newn->next = *Head;
        *Head = newn;
    }
}
void InsertLast(PPNODE Head,int No)
{
    //Temomporary pointer for LL traversal
    PNODE Temp = *Head;

    PNODE newn = (PNODE)malloc(sizeof(NODE));

    newn->data = No;
    newn->next =NULL;

    if(*Head == NULL)
    {
        *Head = newn;
    }
    else
    {
        // Travel the LL till last node
        while(Temp->next!=NULL)
        {
            Temp = Temp -> next;
        }
        // Add the address of new node at end of last node
        Temp->next = newn;
    }
}
void Dispaly(PNODE Head)
{
    printf("Content of linked list :\n");

    while(Head != NULL)
    {
        printf("| %d | ->",Head->data);
        Head = Head->next;
    }
    printf("NULL\n");
}
int count(PNODE Head) 
{
    int icnt =0;

    while(Head != NULL)
    {
        icnt++;
        Head = Head->next;
    }

    return icnt;
}
void DeleteFirst(PPNODE Head)
{
    PNODE Temp = *Head;

    if(*Head == NULL)  //case1
    {
        return;
    }
    else if((*Head) -> next == NULL)   //case2
    {
        free(*Head);
        *Head = NULL;
    }
    else        //case3
    {
        *Head = (*Head)->next;
        free(Temp);
    }
}
void DeleteLast(PPNODE Head)
{
    PNODE Temp = *Head;

     if(*Head == NULL)      //case1
    {
        return;
    }
    else if((*Head) -> next == NULL)        //case2
    {
        free(*Head);
        *Head = NULL;
    }
    else        //case3
    {
        while(Temp->next->next != NULL)
        {
            Temp = Temp -> next;
        }
        free(Temp -> next);
        Temp -> next = NULL;
    }
}
void InsertAtPos(PPNODE Head,int No,int iPos)
{
    int size = 0;

    size = count(*Head);
    PNODE newn = NULL;
    int i=0;
    PNODE Temp = *Head;

    // case 1 : Invalid position   (Ex : 11/-2/8)
     if((iPos<1) || (iPos>size+1))
     {
        printf("Invalid Position\n");
        return;
     }
    // case 2 : first position      (Ex : 1)
    if(iPos == 1)
    {
        InsertFirst(Head,No);
    }
    // case 3 : last position       (Ex : 7)
    else if(iPos == size+1)
    {
        InsertLast(Head,No);
    }
    // case 4 : position is in between first and last (Ex : 5)
    else
    {
        newn = (PNODE)malloc(sizeof(NODE));
        newn->data = No;
        newn->next = NULL;

        for(i=1;i<iPos-1;i++)
        {
            Temp = Temp->next;
        }
        newn->next = Temp->next;
        Temp->next = newn;
    }
}
void DeleteAtPos(PPNODE Head,int iPos)
{
    int size = 0;

    size = count(*Head);
    PNODE Temp = *Head;
    PNODE targetednode = NULL;
    int i = 0;

    // case 1 : Invalid position   (Ex : 11/-2/8)
     if((iPos<1) || (iPos>size))
     {
        printf("Invalid Position\n");
        return;
     }
    // case 2 : first position      (Ex : 1)
    if(iPos == 1)
    {
        DeleteFirst(Head);
    }
    // case 3 : last position       (Ex : 6)
    else if(iPos == size+1)
    {
        DeleteLast(Head);
    }
    // case 4 : position is in between first and last (Ex : 5)
    else
    {
        for(i=1;i<iPos-1;i++)
        {
            Temp = Temp->next;
        }
        targetednode = Temp->next;

        Temp->next = Temp->next->next;
        free(targetednode);
    }
}
int main()
{
     PNODE First = NULL;
     int iRet =0;

    InsertFirst(&First,111);
    InsertFirst(&First,101);
    InsertFirst(&First,51);
    InsertFirst(&First,21);
    InsertFirst(&First,11);
    InsertFirst(&First,121);
   
    
    InsertAtPos(&First,105,5);
    Dispaly(First);
    iRet = count(First);
    printf("Number of nodes are:%d\n",iRet);

    DeleteAtPos(&First,5);
    Dispaly(First);
    iRet = count(First);
    printf("Number of nodes are:%d\n",iRet);

    
    return 0;
}