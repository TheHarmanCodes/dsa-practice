/*
Program: Queue Implementation using Array (Linear Queue)

Concepts:
- Queue (FIFO)
- Array-based implementation
- Call by Value (front and rear)

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

int enqueue(int queue[], int rear)
{
    int data;
    if (rear == max - 1)
    {
        printf("\nQueue is full.\n");
    }
    else
    {
        printf("\nEnter element to insert: ");
        scanf("%d", &data);
        queue[++rear] = data;
    }
    return rear;
}

int dequeue(int queue[], int front)
{
    if (front == -1)
        printf("\nQueue is empty.\n");
    else
        printf("\n%d is deleted.\n", queue[front++]);
    return front;
}

void display(int queue[], int front, int rear)
{
    if (rear == -1)
    {
        printf("\nQueue is empty.\n");
    }
    else
    {
        printf("\n");
        for (int i = front; i <= rear; i++)
            printf("%d ", queue[i]);
        printf("\n");
    }
}

int main()
{
    int queue[max], front, rear, choice;
    front = rear = -1;

    while (1)
    {
        system("cls"); // windows only

        printf("\n Queue\n------\n1: Insert\n2: Delete\n3: Display\n4: Exit\nEnter Choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            rear = enqueue(queue, rear);
            if (rear == 0)
                front = 0;
            break;
        case 2:
            front = dequeue(queue, front);
            if (front > rear)
                front = rear = -1;
            break;
        case 3:
            display(queue, front, rear);
            break;
        case 4:
            printf("\nExiting...");
            return 0;
        default:
            printf("\nInvalid Choice\tTry Again\n");
            break;
        }
        printf("\nPress Enter to continue... ");
        getchar();
        getchar();
    }
    return 0;
}