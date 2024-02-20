// Queue Problem = Enqueue & Dequeue.

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};
typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node** PPNODE;

//void InsertFirst(PPNODE Head)
void Enqueue(PPNODE Head,int No)
{
    PNODE newn = NULL;
    PNODE Temp = *Head;

    newn = (PNODE)malloc(sizeof(NODE));
    newn->data=No;
    newn->next=NULL;

    if(*Head==NULL)
    {
        *Head= newn;
    }
    else
    {
       while(Temp->next!=NULL)
       {
        Temp=Temp->next;
       }
       Temp->next = newn;
    }
}
// void DeleteFirst(PPNODE Head)
int Dequeue(PPNODE Head)
{
    int value = -1;
    PNODE Temp = *Head;

    if((*Head) == NULL)
    {
        printf("Queue is empty..");
        return value;
    }
    else
    {
        value = (*Head)->data;
        *Head = (*Head)->next;
        free(Temp);
    }

    return value;

}
void Dispaly(PNODE Head)
{
    printf("Element of stack are :\n");

    while(Head!=NULL)
    {
        printf("| %d |\t",Head->data);
        Head = Head->next;
    }
}
int main()
{

    PNODE first = NULL;
    int iRet  = 0;

    Enqueue(&first,11);
    Enqueue(&first,21);
    Enqueue(&first,51);
    Enqueue(&first,101);
    Enqueue(&first,111);

    Dispaly(first);
    iRet = Dequeue(&first);
    printf("Removed element from queue is :%d\n",iRet);

    iRet = Dequeue(&first);
    printf("Removed element from queue is :%d\n",iRet);

    return 0;
}