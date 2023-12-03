#include<stdio.h>
#include<stdlib.h>

//structure Declaration
struct Node
{
    int Data;               // 4 byte
    struct node *next;      //8 byte
};
typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;
int main()
{
    PNODE First = NULL;


    return 0;
}