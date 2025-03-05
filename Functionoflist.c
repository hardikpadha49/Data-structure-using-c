#include <stdio.h>
#include <stdlib.h>
void delete(int **arr, int *n, int *capacity)
{
    int key, flag = 0;
    printf("Enter the element you want to delete = ");
    scanf("%d", &key);
    if (*n == 0)
    {
        printf("array is empty \n");
        return;
    }
    for (int i = 0; i < *n; i++)
    {
        if ((*arr)[i] == key)
        {
            for (int j = i; j < *n - 1; j++)
            {
                (*arr)[j] = (*arr)[j + 1];
            }
            (*n)--;
            flag = 1;
            break;
        }
    }
    if (!flag)
    {
        printf("Element not found in the array\n");
        return;
    }
    if (*n < *capacity / 2)
    {
        *capacity /= 2;
        int *temp = realloc(*arr, (*capacity) * sizeof(int));
        if (!temp)
        {
            printf("Memory alloaction failed\n");
            return;
        }
        *arr = temp;
    }
    printf("Array after deleting the element is:\n");
    for (int i = 0; i < *n; i++)
    {
        printf("%d ", (*arr)[i]);
    }
    printf("\n");
}
void insert(int **arr, int *n, int *capacity)
{
    int key, index;
    printf("Enter the element you want to insert ");
    scanf("%d", &key);
    printf("Enter the index where you want to insert the element ");
    scanf("%d", &index);
    if (index > *n || index < 0)
    {
        printf("Invalid position!!!!\n");
        return;
    }
    if (*n >= *capacity)
    {
        *capacity *= 2;
        int *temp = realloc(*arr, (*capacity) * sizeof(int));
        if (!temp)
        {
            printf("Memory allocation is failed\n");
            return;
        }
        *arr = temp;
    }
    if (index == *n)
    {
        (*arr)[*n] = key;
        (*n)++;
    }
    else
    {
        for (int i = *n - 1; i >= index; i++)
        {
            (*arr)[i + 1] = (*arr)[i];
        }
        (*arr)[index] = key;
        (*n)++;
    }
    printf("Array after inserting the elemeny is:\n");
    for (int i = 0; i < *n; i++)
    {
        printf("%d ", (*arr)[i]);
    }
    printf("\n");
}
void update(int *arr, int n)
{
    int val, index;
    printf("Enter the element you want to update: ");
    scanf("%d", &val);
    printf("Enter the index of the element you want yo update: ");
    scanf("%d", &index);
    if (index >= n || index < 0)
    {
        printf("Invalid position !!!!\n");
        return;
    }
    arr[index] = val;
    printf("List after updating the element is:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
void search(int *arr, int n)
{
    int val, flag = 0;
    printf("Enter the element you want to search = ");
    scanf("%d", &val);
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == val)
        {
            printf("Element found at index %d\n", i);
            flag = 1;
            break;
        }
    }
    if (!flag)
    {
        printf("Element not found in the list !!\n");
    }
}
void traverse(int *arr, int n)
{
    if (n == 0)
    {
        printf("list is empty\n");
        return;
    }
    printf("Element of the list are :");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
int main()
{
    int choice, n, capacity;
    printf("Enter the size of the array :");
    scanf("%d", &n);
    if (n <= 0)
    {
        printf("Invalid list!!!\n");
        return 1;
    }
    capacity = n + 10;
    int *arr = (int *)malloc(capacity * sizeof(int));
    if (!arr)
    {
        printf("Memory allocation failed!!\n");
        return 1;
    }
    printf("Enter the element of the list: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    while (1)
    {
        printf("\nEnter the operation you want to perform:\n");
        printf("1. Delete an element \n2.Insert an element\n");
        printf("3. Update an element\n4. Search an element\n5. Traverse an element\n6.Exit\n");
        printf("Your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            delete (&arr, &n, &capacity);
            break;
        case 2:
            insert(&arr, &n, &capacity);
            break;
        case 3:
            update(arr, n);
            break;
        case 4:
            search(arr, n);
            break;
        case 5:
            traverse(arr, n);
            break;
        case 6:
            free(arr);
            return 0;
        default:
            printf("Invalid choice !! try again \n");
        }
    }
    return 0;
}