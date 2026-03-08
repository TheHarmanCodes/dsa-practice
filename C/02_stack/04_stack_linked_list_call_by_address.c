// Problem Statement: C program to implement Stack (ADT) using Linked List (Dynamic Memory Allocation) with call by Address concept.
// Objective: To learn the concept of Stack using Linked List.

#include <stdio.h>
#include <stdlib.h>

typedef struct stack
{
    int data;
    struct stack *next;
} S;

void push(S **);
void pop(S **);
void display(S *);
void peek(S *);

int main()
{
    S *top = NULL;
    int choice;

    while (1)
    {
        system("cls"); // only works in windows

        printf(" Stack\n------\n1: Push\n2: Pop\n3: Peek\n4: Display\n5: Exit\nEnter Choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            push(&top);
            break;
        case 2:
            pop(&top);
            break;
        case 3:
            peek(top);
            break;
        case 4:
            display(top);
            break;
        case 5:
            printf("\nExiting...");
            return 0;
        default:
            printf("\nInvalid Choice\tTry Again\n");
            break;
        }
        printf("\nPress Enter to continue...  ");
        getchar();
        getchar();
    }
    return 0;
}

void push(S **top)
{
    S *newNode = NULL;
    newNode = (S *)malloc(sizeof(S));
    if (newNode != NULL) // memory allocated successfully to newNode
    {
        printf("\nEnter data to insert: ");
        scanf("%d", &newNode->data);
        newNode->next = *top;
        *top = newNode;
    }
}

void pop(S **top)
{
    if (*top == NULL)
    {
        printf("\nStack is empty.\n");
        return;
    }
    S *temp = NULL;
    printf("\n%d is deleted.\n", (*top)->data);
    temp = *top;
    *top = (*top)->next;
    free(temp);
}

void display(S *top) // display from top to bottom
{
    if (top == NULL)
    {
        printf("\nStack is empty.\n");
        return;
    }
    printf("\nStack : \n");
    while (top != NULL)
    {
        printf("%d\n", top->data);
        top = top->next;
    }
    printf("\n");
}

void peek(S *top)
{
    if (top == NULL)
    {
        printf("\nStack is empty.\n");
        return;
    }
    printf("\n%d is at top.\n", top->data);
}