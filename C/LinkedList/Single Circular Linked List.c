#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
}*head, *tail, *dummy;

void init()
{
    head = tail = NULL;
}

struct Node *createNode()
{
    return (struct Node *)malloc(sizeof(struct Node));
}

void insert(int key)
{
    struct Node *newNode;
    newNode = createNode();
    newNode->data = key;
    newNode->next = NULL;

    if (head==NULL)
    {
        dummy = createNode();
        head = tail = newNode;
        dummy->next = head;
    }
}

void display()
{
    struct Node *temp;
    temp = dummy;
    printf("\n Head Address is : %p", head);
    printf("\n");
    while (temp->next != head)
    {
        printf(" | %d | %hx | ->", temp->data, temp->next);
    }
    printf(" | %d | %hx | ", temp->data, temp->next);
    
}
int key;
int main()
{
    init();
    
     while(1)
    {
        printf("\n **** MENU ****");
        printf("\n 1. Insert");
        printf("\n 2. Delete");
        printf("\n 3. Search");
        printf("\n 4. Display");
        printf("\n 5. Exit");
        printf("\n --------------\n");
        printf("\n Enter your Choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1: printf("\n Enter Element to Insert: ");
            scanf("%d", &key);
            insert(key);
            break;

            case 2: printf("\n Enter Element to Delete: ");
            scanf("%d", &key);
            delete(key);
            break;

            case 3: printf("\n Enter Element to Search: ");
            scanf("%d", &key);
            struct Node *addr;
            *addr = search(key);
            if (addr)
                printf("\n Element is Found!");
            else
                printf("\n Element is Not Found!");
            break;

            case 4: display();
            break;

            case 5:
        }
    }
}