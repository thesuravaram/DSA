#include <stdio.h>
#include <stdlib.h>

int arr[10];
int n;
int i;

int main() 
{
    printf("\n No. of Elements: ");
    scanf("%d", &n);

    printf("Input Array elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("\n Array elements are: ");
    for (int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    
}