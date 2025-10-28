#include <stdio.h>
#include <stdlib.h> // Required for exit()

// Define the maximum size the array can hold
#define MAX_SIZE 100

// --- Function Prototypes ---
// Functions are declared here so main() knows they exist.
void printArray(int arr[], int n);
void insertElement(int arr[], int *n);
void deleteElement(int arr[], int *n);
void searchElement(int arr[], int n);

int main() {
    int arr[MAX_SIZE]; // The array to store elements
    int n = 0;         // Variable to store the current number of elements
    int choice;

    printf("--- Array Operations Menu ---\n");
    printf("This program starts with an empty array.\n");
    printf("Use option 1 to create the initial array.\n\n");

    // The main menu loop. It will run forever until the user chooses to exit.
    while (1) {
        printf("------------------------------------\n");
        printf("Select an operation:\n");
        printf("1. Create/Re-create the Array\n");
        printf("2. Print the Array\n");
        printf("3. Insert an Element\n");
        printf("4. Delete an Element\n");
        printf("5. Search for an Element\n");
        printf("6. Exit\n");
        printf("------------------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // A switch statement to call the correct function based on user's choice
        switch (choice) {
            case 1:
                printf("Enter the number of elements to create: ");
                scanf("%d", &n);
                if (n > MAX_SIZE || n <= 0) {
                    printf("Error: Number of elements must be between 1 and %d\n", MAX_SIZE);
                    n = 0; // Reset count
                } else {
                    printf("Enter %d elements:\n", n);
                    for (int i = 0; i < n; i++) {
                        scanf("%d", &arr[i]);
                    }
                    printf("Array created successfully.\n");
                }
                break;
            case 2:
                printArray(arr, n);
                break;
            case 3:
                insertElement(arr, &n); // Pass address of n to modify it
                break;
            case 4:
                deleteElement(arr, &n); // Pass address of n to modify it
                break;
            case 5:
                searchElement(arr, n);
                break;
            case 6:
                printf("Exiting the program. Goodbye!\n");
                exit(0); // Exits the program cleanly
            default:
                printf("Invalid choice. Please enter a number between 1 and 6.\n");
        }
    }

    return 0;
}

/**
 * brief Prints all the elements currently in the array.
 * param arr The array to print.
 * param n The current number of elements in the array.
 */
void printArray(int arr[], int n) {
    if (n == 0) {
        printf("The array is empty. Please use option 1 to input elements.\n");
        return;
    }

    printf("Array elements are: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

/**
 ** brief Inserts an element at a specified position in the array.
 * param arr The array.
 * param n Pointer to the current number of elements.
 */
void insertElement(int arr[], int *n) {
    int position, element;

    // Check if the array is full
    if (*n >= MAX_SIZE) {
        printf("Error: Array is full. Cannot insert.\n");
        return;
    }

    printf("Enter the element to insert: ");
    scanf("%d", &element);
    printf("Enter the position (index) to insert at (0 to %d): ", *n);
    scanf("%d", &position);

    // Validate the position
    if (position < 0 || position > *n) {
        printf("Error: Invalid position.\n");
        return;
    }

    // Shift elements to the right from the insertion point
    for (int i = *n - 1; i >= position; i--) {
        arr[i + 1] = arr[i];
    }

    // Insert the new element
    arr[position] = element;

    // Increment the count of elements
    (*n)++;

    printf("Element %d inserted successfully at position %d.\n", element, position);
}

/**
 * brief Deletes an element from a specified position in the array.
 * param arr The array.
 * param n Pointer to the current number of elements.
 */
void deleteElement(int arr[], int *n) {
    int position;

    // Check if the array is empty
    if (*n == 0) {
        printf("Error: Array is empty. Cannot delete.\n");
        return;
    }

    printf("Enter the position (index) of the element to delete (0 to %d): ", *n - 1);
    scanf("%d", &position);

    // Validate the position
    if (position < 0 || position >= *n) {
        printf("Error: Invalid position.\n");
        return;
    }
    
    int deletedElement = arr[position];

    // Shift elements to the left from the position after the deleted one
    for (int i = position; i < *n - 1; i++) {
        arr[i] = arr[i + 1];
    }

    // Decrement the count of elements
    (*n)--;

    printf("Element %d at position %d deleted successfully.\n", deletedElement, position);
}

/**
 * brief Searches for an element in the array using linear search.
 * param arr The array.
 * param n The current number of elements.
 */
void searchElement(int arr[], int n) {
    int element;

    if (n == 0) {
        printf("The array is empty. Cannot search.\n");
        return;
    }
    
    printf("Enter the element to search for: ");
    scanf("%d", &element);

    for (int i = 0; i < n; i++) {
        if (arr[i] == element) {
            printf("Element %d found at position (index) %d.\n", element, i);
            return; // Exit the function once found
        }
    }

    // If the loop finishes, the element was not found
    printf("Element %d was not found in the array.\n", element);
}

