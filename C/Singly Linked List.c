//Singly Linked List (Insert, Delete, Search, Display)
 

#include <stdio.h>
#include <stdlib.h>
 
struct Node {
    int data;
    struct Node* next;
};
 
struct Node* head = NULL;
 
// Insert at Beginning
void insert_beginning(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = head;
    head = newNode;
    printf("Inserted %d at beginning\n", data);
}
 
// Insert at End
void insert_end(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    if (head == NULL) {
        head = newNode;
        return;
    }
    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
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
    printf("Deleted %d from beginning\n", temp->data);
    free(temp);
}
 
// Delete from End
void delete_end() {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    struct Node* temp = head, *prev = NULL;
    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }
    if (prev == NULL)
        head = NULL;
    else
        prev->next = NULL;
    printf("Deleted %d from end\n", temp->data);
    free(temp);
}
 
// Search Element
void search(int key) {
    struct Node* temp = head;
    int pos = 1;
    while (temp != NULL) {
        if (temp->data == key) {
            printf("Element %d found at position %d\n", key, pos);
            return;
        }
        temp = temp->next;
        pos++;
    }
    printf("Element %d not found\n", key);
}
 
// Display List
void display() {
    struct Node* temp = head;
    if (temp == NULL) {
        printf("List is empty!\n");
        return;
    }
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
 
int main() {
    insert_end(10);
    insert_end(20);
    insert_beginning(5);
    insert_end(30);
    display();
    delete_beginning();
    delete_end();
    display();
    search(20);
    search(50);
    return 0;
}