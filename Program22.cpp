// Singly Linear Linked List.

#include<iostream>
using namespace std;

typedef struct node
{
    int data;
    struct node *next;
}NODE, *PNODE, **PPNODE;

class SinglyLL
{
    private:
        PNODE first;
        int Count;

    public:
        SinglyLL();
        void InsertFirst(int no);
        void InsertLast(int no);
        void Display();
        int CountNode();
        void DeleteFirst();
        void DeleteLast();
        void InsertAtpos(int no,int Pos);
        void DeleteAtpos(int Pos);
};

SinglyLL::SinglyLL()
{
    cout<<"Inside constructor\n";
    first = NULL;
    Count = 0;
}

void SinglyLL::InsertFirst(int no)
{
    PNODE newn = NULL;

    newn = new NODE;   
    newn->data = no;
    newn->next = NULL;

    if(first == NULL)   // if(Count == 0)
    {
        first = newn;
    }
    else
    {
        newn->next = first;
        first = newn;
    }
    Count++;
}

void SinglyLL::InsertLast(int no)
{
    PNODE newn = NULL;
    PNODE temp = first;

    newn = new NODE;   
    newn->data = no;
    newn->next = NULL;

    if(first == NULL)   // if(Count == 0)
    {
        first = newn;
    }
    else
    {
        while(temp -> next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
    }
    Count++;
}

void SinglyLL::Display()
{
    PNODE temp = first;

    cout<<"Elements of the linked list are : \n";
    
    while(temp != NULL) // Type 1
    {
        cout<<"| "<<temp->data<<" | -> ";
        temp = temp ->next;
    }
    cout<<"NULL \n";
}

int SinglyLL::CountNode()
{
    return Count;
}
void SinglyLL::DeleteFirst()
{
    PNODE temp = first;

    if(first == NULL)
    {
        return;
    }
    else if(first->next == NULL)
    {
        delete first;
        first = NULL;
    }
    else
    {
        first=first->next;
        delete temp;

    }
    Count--;
}
void SinglyLL::DeleteLast()
{
    if(first == NULL)
    {
        return;
    }
    else if(first->next == NULL)
    {
        delete first;
        first = NULL;
    }
    else
    {
        PNODE Temp = first;
        while(Temp->next->next!=NULL)
        {
            Temp = Temp->next;
        }
        delete Temp->next;
        Temp->next=NULL;
    }
    Count--;
}
void SinglyLL::InsertAtpos(int no,int Pos)
{
    if((Pos<1) || (Pos>Count+1))
    {
        return;
    }
    if(Pos==1)
    {
        InsertFirst(no);
    }
    else if(Pos==Count+1)
    {
        InsertLast(no);
    }
    else
    {
        PNODE newn = new NODE;
        newn->data = no;
        newn->next = NULL;

        PNODE Temp =first;
        int i=0;

        for(i=1;i<Pos-1;i++)
        {
            Temp=Temp->next;
        }
        newn->next = Temp->next;
        Temp->next = newn;

        Count++;
    }
}
void SinglyLL::DeleteAtpos(int Pos)
{

    if((Pos<1) || (Pos>Count+1))
    {
        return;
    }
    if(Pos==1)
    {
        DeleteFirst();
    }
    else if(Pos==Count+1)
    {
        DeleteLast();
    }
    else
    {
        PNODE Temp =first;
        int i=0;

        for(i=1;i<Pos-1;i++)
        {
            Temp=Temp->next;
        }
        PNODE targetednode = Temp->next;
        Temp->next = Temp->next->next;
        delete targetednode;

        Count--;
    }
}
int main()
{
    SinglyLL obj;
    int iRet = 0;

    obj.InsertFirst(111);
    obj.InsertFirst(101);
    obj.InsertFirst(51);
    obj.InsertFirst(21);
    obj.InsertFirst(11);
    
    obj.InsertLast(121);
    obj.InsertLast(151);
    obj.InsertLast(201);
     
     obj.InsertAtpos(105,5);
     obj.Display();
     iRet = obj.CountNode();
     cout<<"Number of elements in the linked list are : "<<iRet<<"\n";
     
     obj.DeleteAtpos(5);
     obj.Display();
     iRet = obj.CountNode();
     cout<<"Number of elements in the linked list are : "<<iRet<<"\n";

     obj.DeleteFirst();

     obj.DeleteLast();
    
     obj.Display();

     iRet = obj.CountNode();
     cout<<"Number of elements in the linked list are : "<<iRet<<"\n";

    return 0;
}