/*
Program: Circular Queue Implementation using Array
Concepts:
- Circular Queue
- FIFO
- Call by Value (front and rear returned)
*/

#include <stdio.h>
#include <stdlib.h>
#define max 5

int enqueue(int[], int, int);
int dequeue(int[], int, int);
void display(int[], int, int);
void peek(int[], int);

int main()
{
    int queue[max], front, rear, choice;
    front = rear = -1;

    while (1)
    {
        system("cls");

        printf("\n Queue\n------\n1: Insert\n2: Delete\n3: Display\n4: Peek\n5: Exit\nEnter Choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            rear = enqueue(queue, front, rear);
            if (front == -1)
                front = 0;
            break;
        case 2:
            front = dequeue(queue, front, rear);
            if (front == -1)
                rear = -1;
            break;
        case 3:
            display(queue, front, rear);
            break;
        case 4:
            peek(queue, front);
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

int enqueue(int queue[], int front, int rear)
{
    int x;
    if ((rear + 1) % max == front)
    {
        printf("\nQueue is full.\n");
    }
    else
    {
        printf("\nEnter value to insert: ");
        scanf("%d", &x);
        rear = (rear + 1) % max;
        queue[rear] = x;
    }
    return rear;
}

int dequeue(int queue[], int front, int rear)
{
    if (front == -1)
    {
        printf("\nQueue is empty.\n");
    }
    else
    {
        printf("\n%d is deleted.\n", queue[front]);
        if (front == rear) // if the element deleted was pointed by rear|front
            front = -1;    // means we deleted the last remaining element
        else
            front = (front + 1) % max;
    }
    return front;
}

void display(int queue[], int front, int rear)
{
    if (front == -1 && rear == -1)
    {
        printf("\nQueue is empty\n");
    }
    else
    {
        printf("\n");
        while (front != rear)
        {
            printf("%d ", queue[front]);
            front = (front + 1) % max;
        }
        printf("%d\n", queue[front]);
    }
}

void peek(int queue[], int front)
{
    if (front == -1)
        printf("\nQueue is empty\n");
    else
        printf("\n%d is at Front.\n", queue[front]);
}