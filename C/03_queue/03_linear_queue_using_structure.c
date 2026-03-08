/*
Program: Queue Implementation using Structure
Concepts:
- Linear Queue
- Array-based implementation
- Structure usage
- Multiple queue instances

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

struct queue
{
    int data[max];
    int front;
    int rear;
};

void enqueue(struct queue *);
void dequeue(struct queue *);
void display(struct queue);

int main()
{
    int choice;

    struct queue q1, q2;
    q1.front = q1.rear = -1;
    q2.front = q2.rear = -1;

    while (1)
    {
        system("cls"); // windows only

        printf("\n Queue\n------\n1: Insert in 1st Queue\n2: Insert in 2nd Queue\n3: Delete from 1st Queue\n4: Delete from 2nd Queue\n5: Display 1st Queue\n6: Display 2nd Queue\n7: Exit\nEnter Choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            enqueue(&q1);
            break;
        case 2:
            enqueue(&q2);
            break;
        case 3:
            dequeue(&q1);
            break;
        case 4:
            dequeue(&q2);
            break;
        case 5:
            display(q1);
            break;
        case 6:
            display(q2);
            break;
        case 7:
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

void enqueue(struct queue *q)
{
    int x;
    if (q->rear == max - 1)
    {
        printf("\nQueue is full.\n");
    }
    else
    {
        printf("\nEnter element to insert: ");
        scanf("%d", &x);
        q->rear++;
        q->data[q->rear] = x;
        if (q->front == -1)
            q->front = 0;
    }
}

void dequeue(struct queue *q)
{
    if (q->front == -1)
    {
        printf("\nQueue is empty.\n");
    }
    else
    {
        printf("\n%d is deleted.\n", q->data[q->front]);
        q->front++;
    }
    if (q->front > q->rear)
        q->front = q->rear = -1;
}

void display(struct queue q)
{
    if (q.front == -1)
    {
        printf("\nQueue is empty.\n");
    }
    else
    {
        printf("\nQueue elements: ");
        for (int i = q.front; i <= q.rear; i++)
            printf("%d ", q.data[i]);
        printf("\n");
    }
}