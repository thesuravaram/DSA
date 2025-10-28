#include <stdio.h>
#include <stdlib.h>

struct Node
{
    struct Node *prev;
    int data;
    struct Node *next;
}*head;

void init()
{
    head = tail =NULL;
}
struct Node *createNode()
{
    /* data */
};

void create()
{
    struct Node *createNode;

    int i;
    for(i=0; i<n; i++)
    {
        newNode = createNode();
        newNode->prev = newNode->next = NULL;
        newNode->data = a[i];

        if (head==NULL)
        {

        }

    }
}

void display()
{
    struct Node *temp;
    temp = head;
    printf("\n Head Address is: %h")
}

int main()
{
    init();

    while(1)
    {
        printf("\n **** MENU ****");
        printf("\n 1. Create");
        printf("\n 2. Insert");
        printf("\n 3. Search");
        printf("\n 4. Delete");
        printf("\n 5. Display");
        printf("\n 6. Exit");


        int choice()
        {

        }

    }
}
void Insert(int pos, int ele)
{
    struct Node *newNode;
    if (pos==0)
    {
        //Insert at Head
    }
    int i=1;
    struct Node *curr;
    curr = head;
    for (; i<=pos; i++)
    {
        if (curr!=NULL){
            curr = curr->next
        }
        else
        {
            printf("\n Insertion is not Possible")
        }
    }
    if (curr->next == NULL)
    {
        newNode = createNode();
        newNode->data = ele;
        newNode->prev = curr;
        curr-> 
    }
}