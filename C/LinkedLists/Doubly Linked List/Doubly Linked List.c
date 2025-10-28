///Doubly Linked List

#include <stdio.h>
#include <stdlib.h>
 
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};
 
struct Node* head = NULL;
struct Node* tail = NULL;
 
// Insert at Beginning
void insert_beginning(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = head;
    if (head != NULL)
        head->prev = newNode;
    else
        tail = newNode;
    head = newNode;
    printf("Inserted %d at beginning\n", data);
}
 
// Insert at End
void insert_end(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = tail;
    if (tail != NULL)
        tail->next = newNode;
    else
        head = newNode;
    tail = newNode;
    printf("Inserted %d at end\n", data);
}
 
// Delete from Beginning
void delete_beginning() {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    struct Node* temp = head;
    head = head->next;
    if (head != NULL)
        head->prev = NULL;
    else
        tail = NULL;
    printf("Deleted %d from beginning\n", temp->data);
    free(temp);
}
 
// Delete from End
void delete_end() {
    if (tail == NULL) {
        printf("List is empty!\n");
        return;
    }
    struct Node* temp = tail;
    tail = tail->prev;
    if (tail != NULL)
        tail->next = NULL;
    else
        head = NULL;
    printf("Deleted %d from end\n", temp->data);
    free(temp);
}
 
// Display Forward
void display_forward() {
    struct Node* temp = head;
    printf("Doubly Linked List (Forward): ");
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
 
// Display Backward
void display_backward() {
    struct Node* temp = tail;
    printf("Doubly Linked List (Backward): ");
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->prev;
    }
    printf("NULL\n");
}
 
int main() {
    insert_end(10);
    insert_end(20);
    insert_beginning(5);
    insert_end(30);
    display_forward();
    display_backward();
    delete_beginning();
    delete_end();
    display_forward();
    return 0;
}