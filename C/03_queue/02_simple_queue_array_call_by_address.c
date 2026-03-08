/*
Program: Queue Implementation using Array
Concepts:
- Queue (FIFO)
- Linear Queue
- Call by Address (front and rear)

Operations:
- Enqueue
- Dequeue
- Display

Time Complexity:
- Enqueue: O(1)
- Dequeue: O(1)
- Display: O(n)
*/

#include <stdio.h>
#include <stdlib.h>

#define max 5

void enqueue(int queue[], int *front, int *rear)
{
    int data;

    if (*rear == max - 1)
    {
        printf("\nQueue is full.\n");
        return;
    }

    printf("\nEnter element to insert: ");
    scanf("%d", &data);

    (*rear)++;
    queue[*rear] = data;

    if (*front == -1)
        *front = 0;
}

void dequeue(int queue[], int *front, int *rear)
{
    if (*front == -1 || *front > *rear)
    {
        printf("\nQueue is empty.\n");
        return;
    }

    printf("\n%d is deleted.\n", queue[*front]);
    (*front)++;

    if (*front > *rear)
        *front = *rear = -1;
}

void display(int queue[], int front, int rear)
{
    if (rear == -1)
    {
        printf("\nQueue is empty.\n");
    }
    else
    {
        printf("\nQueue elements:\n");
        for (int i = front; i <= rear; i++)
            printf("%d ", queue[i]);
        printf("\n");
    }
}

int main()
{
    int queue[max], front = -1, rear = -1, choice;

    while (1)
    {
        system("cls"); // Windows only

        printf("\n Queue\n------");
        printf("\n1: Insert");
        printf("\n2: Delete");
        printf("\n3: Display");
        printf("\n4: Exit");
        printf("\nEnter Choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            enqueue(queue, &front, &rear);
            break;

        case 2:
            dequeue(queue, &front, &rear);
            break;

        case 3:
            display(queue, front, rear);
            break;

        case 4:
            printf("\nExiting...");
            return 0;

        default:
            printf("\nInvalid Choice. Try Again.\n");
        }

        printf("\nPress Enter to continue...");
        getchar();
        getchar();
    }

    return 0;
}