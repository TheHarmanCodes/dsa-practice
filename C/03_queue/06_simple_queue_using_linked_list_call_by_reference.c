// Problem Statement: C Program to implement Simple Queue (Abstract Data Type) using Linked List (dynamic memory allocation) with call by REFERENCE concept.
// Objective: To learn the concept of Simple Queue using Linked List.

#include <stdio.h>
#include <stdlib.h>

typedef struct Queue
{
    int data;
    struct Queue *next;
} Q;

void enqueue(Q **, Q **);
void dequeue(Q **, Q **);
void display(Q *);
void displayReverse(Q *);

int main()
{
    Q *F = NULL, *R = NULL;
    int choice;
    while (1)
    {
        system("cls"); // specific to windows only
        printf("\n Queue\n------\n1: Insert\n2: Delete\n3: Display\n4: Reverse Display\n5: Exit\nEnter Choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            enqueue(&F, &R);
            break;
        case 2:
            dequeue(&F, &R);
            break;
        case 3:
            display(F);
            break;
        case 4:
            if (F == NULL)
            {
                printf("\nQueue is empty.\n");
                break;
            }
            else
            {
                printf("\nReverse Queue: ");
                displayReverse(F);
            }
            break;
        case 5:
            printf("\nExiting...\n");
            return 0;
        default:
            printf("\nInvalid Input\nTry Again");
        }
        printf("\nPress Enter to continue...");
        getchar();
        getchar();
    }
}

void enqueue(Q **front, Q **rear)
{
    Q *newNode = (Q *)malloc(sizeof(Q));
    if (newNode != NULL)
    {
        printf("\nEnter value to insert: ");
        scanf("%d", &newNode->data);
        newNode->next = NULL;
        if (*front == NULL)
        {
            *front = *rear = newNode;
        }
        else
        {
            (*rear)->next = newNode;
            *rear = newNode;
        }
    }
}

void dequeue(Q **front, Q **rear)
{
    Q *temp = NULL;
    if (*front == NULL && *rear == NULL)
    {
        printf("\nQueue is empty.\n");
    }
    else
    {
        printf("\n%d is deleted.\n", (*front)->data);
        temp = *front;
        if (*front == *rear)
            *front = *rear = NULL;
        else
            *front = (*front)->next;
        free(temp);
    }
}

void display(Q *Front)
{
    if (Front == NULL)
    {
        printf("\nQueue is empty.\n");
        return;
    }
    printf("\nQueue is : ");
    while (Front != NULL)
    {
        printf("%d ", Front->data);
        Front = Front->next;
    }
    printf("\n");
}

void displayReverse(Q *Front)
{
    if (Front == NULL)
    {
        return;
    }
    displayReverse(Front->next);
    printf("%d ", Front->data);
}