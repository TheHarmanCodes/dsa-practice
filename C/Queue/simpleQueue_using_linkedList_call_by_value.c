// Problem Statement: C Program to implement Simple Queue (Abstract Data Type) using Linked List (dynamic memory allocation) with call by value concept.
// Objective: To learn the concept of Queue using Linked List.

#include <stdio.h>
#include <stdlib.h>

typedef struct Queue
{
    int data;
    struct Queue *next;
} Q;

Q *enqueue(Q *);
Q *dequeue(Q *);
void display(Q *);
void displayReverse(Q *);

int main()
{
    Q *F = NULL, *R = NULL;
    int choice;
    while (1)
    {
        system("cls"); // works in windows only
        printf(" Queue\n------\n1: Insert\n2: Delete\n3: Display\n4: Reverse Display\n5: Exit\nEnter Choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            R = enqueue(R);
            if (F == NULL)
                F = R;
            break;
        case 2:
            F = dequeue(F);
            if (F == NULL)
                R = NULL;
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
                printf("\n");
            }
            break;
        case 5:
            printf("\nExiting...");
            return 0;
        default:
            printf("\nInvalid Input\nTry Again");
        }
        printf("\nPress Enter to continue...  ");
        getchar();
        getchar();
    }
}

Q *enqueue(Q *rear)
{
    Q *newNode = (Q *)malloc(sizeof(Q));
    if (newNode != NULL)
    {
        printf("\nEnter value to insert: ");
        scanf("%d", &newNode->data);
        newNode->next = NULL;
        if (rear != NULL) // means current node is not a first node.
            rear->next = newNode;

        rear = newNode;
    }
    return rear;
}

Q *dequeue(Q *front)
{
    if (front == NULL)
    {
        printf("\nQueue is empty.\n");
        return front;
    }

    Q *temp = front;
    printf("\n%d is deleted.\n", front->data);

    front = front->next;
    free(temp);
    return front;
}

void display(Q *front)
{
    if (front == NULL)
    {
        printf("\nQueue is empty.\n");
        return;
    }
    printf("\nQueue is : ");
    while (front != NULL)
    {
        printf("%d ", front->data);
        front = front->next;
    }
    printf("\n");
}

void displayReverse(Q *front)
{
    if (front == NULL)
    {
        return;
    }
    displayReverse(front->next);
    printf("%d ", front->data);
}