#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct  node *next;

} NODE,*PNODE,**PPNODE;

void Inserfirst(PPNODE Head,PPNODE Tail,int NO)
{
    PNODE newn = NULL;
     
     newn = (PNODE)malloc(sizeof(NODE));

     newn->data = NO;
     newn->next = NULL;

     if((*Head==NULL) && (*Tail==NULL))     //LL is empty
     {
        *Head=newn;
        *Tail=newn;
        (*Tail)->next=*Head;        //#
     }
     else           //LL contains atleast 1 node
     {
        newn->next=*Head;
        *Head=newn;
        (*Tail)->next=*Head;        //#
     }
}
void InserLast(PPNODE Head,PPNODE Tail,int NO)
{
     PNODE newn = NULL;
     
     newn = (PNODE)malloc(sizeof(NODE));

     newn->data = NO;
     newn->next = NULL;

     if((*Head==NULL) && (*Tail==NULL))     //LL is empty
     {
        *Head=newn;
        *Tail=newn;
        (*Tail)->next=*Head;
     }
     else           //LL contains atleast 1 node
     {
        (*Tail)->next=newn;
        (*Tail)=newn;
     }
}
void DeleteFirst(PPNODE Head,PPNODE Tail)
{

    if(*Head== NULL && *Tail==NULL)
    {
        return;
    }
    else if(*Head == *Tail)
    {
        free(*Head);
        *Head = NULL;
        *Tail = NULL;
    }
    else
    {
        (*Head)=(*Head)->next;
        free((*Tail)->next);
    }
    (*Tail)->next=*Head;
}
void DeleteLast(PPNODE Head,PPNODE Tail)
{
    PNODE Temp = *Head;
    if(*Head== NULL && *Tail==NULL)
    {
        return;
    }
    else if(*Head == *Tail)
    {
        free(*Head);
        *Head = NULL;
        *Tail = NULL;
    }
    else
    {
       while (Temp->next!=*Tail)
       {
        Temp=Temp->next;
       }
       free(*Tail);
       *Tail=Temp;
    }
    (*Tail)->next=*Head;
}
void Display(PNODE Head,PNODE Tail)
{
  printf("element of Linked list are :\n");

  if((Head !=NULL) && (Tail != NULL))
  {
    do
    {
        printf("| %d |->",Head->data);
        Head = Head ->next;
    } while (Head != Tail->next);
    printf("Address of first node \n");
  }
}
int count(PNODE Head,PNODE Tail)
{
    int icnt = 0;

    if ((Head != NULL) && (Tail!=NULL))
    {
        do
        {
            icnt++;
        Head= Head->next;
        }
         while (Head!=Tail->next);
    }
    
    return icnt;
}
void InserAtPos(PPNODE Head,PPNODE Tail,int No,int Pos)
{
    int size = 0;
    size = count(*Head,*Tail);
    PNODE newn = NULL;
    int i=0;
    PNODE Temp = *Head;

     if((Pos<1) || (Pos>size+1))
     {
        printf("Invalid Position\n");
        return;
     }
    if(Pos == 1)
    {
        Inserfirst(Head,Tail,No);
    }
    else if(Pos == size+1)
    {
        InserLast(Head,Tail,No);
    }
    else
    {
        newn = (PNODE)malloc(sizeof(NODE));
        newn->data = No;
        newn->next = NULL;

        for(i=1;i<Pos-1;i++)
        {
            Temp = Temp->next;
        }
        newn->next = Temp->next;
        Temp->next = newn;
    }
}
void DeleteAtpos(PPNODE Head,PPNODE Tail,int Pos)
{
    int size = 0;

    size = count(*Head,*Tail);
    PNODE Temp = *Head;
    PNODE targetednode = NULL;
    int i = 0;

     if((Pos<1) || (Pos>size))
     {
        printf("Invalid Position\n");
        return;
     }
    if(Pos == 1)
    {
        DeleteFirst(Head,Tail);
    }
    else if(Pos == size)
    {
        DeleteLast(Head,Tail);
    }
    else
    {
        for(i=1;i<Pos-1;i++)
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
    PNODE first =NULL;
    PNODE last = NULL;    //#
    int iRet = 0;
  
   Inserfirst(&first,&last,51);
   Inserfirst(&first,&last,21);
   Inserfirst(&first,&last,11);
   Display(first,last);
   iRet = count(first,last);
   printf("number of element are :%d\n",iRet);

   InserLast(&first,&last,101);
   InserLast(&first,&last,111);
   InserLast(&first,&last,121);
   Display(first,last);
   iRet = count(first,last);
   printf("number of element are :%d\n",iRet);

    InserAtPos(&first,&last,105,5);
   Display(first,last);
   iRet = count(first,last);
   printf("number of element are :%d\n",iRet);

    DeleteAtpos(&first,&last,5);
   Display(first,last);
   iRet = count(first,last);
   printf("number of element are :%d\n",iRet);
   
   DeleteFirst(&first,&last);
   Display(first,last);
   iRet = count(first,last);
   printf("number of element are :%d\n",iRet);

    DeleteLast(&first,&last);
   Display(first,last);
   iRet = count(first,last);
   printf("number of element are :%d\n",iRet);

   

    return 0;
}