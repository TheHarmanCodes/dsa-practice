// Problem Statement: C program to implement Stack (ADT) using Array, Mixed: Call by Address, call by value of top

#include <stdio.h>
#include <stdlib.h>

#define max 5

int push(int[], int);
int pop(int[], int);
void peek(int[], int);
void display(int[], int);

int main()
{
    int stack[max], top = -1, choice;

    while (1)
    {
        system("cls");

        printf("\n Stack\n------\n1: Push\n2: Pop\n3: Peek\n4: Display\n5: Exit\nEnter Choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            top = push(stack, top);
            break;
        case 2:
            top = pop(stack, top);
            break;
        case 3:
            peek(stack, top);
            break;
        case 4:
            display(stack, top);
            break;
        case 5:
            printf("\nExiting...");
            return 0;
        default:
            printf("\nInvalid Choice\tTry Again\n");
            break;
        }
        printf("\nPress Enter to continue...");
        getchar();
        getchar();
    }
    return 0;
}

int push(int stack[], int top)
{
    int data;
    if (top == max - 1)
    { // Stack overflow
        printf("\nStack is full.\n");
    }
    else
    {
        printf("\nEnter a number: ");
        scanf("%d", &data);
        top++;
        stack[top] = data;
    }
    return top;
}

int pop(int stack[], int top)
{
    if (top == -1)
    { // stack underflow
        printf("\nStack is empty.\n");
    }
    else
    {
        printf("\n%d is deleted.\n", stack[top]);
        top--;
    }
    return top;
}

void peek(int stack[], int top)
{
    if (top == -1)
    {
        printf("\nStack is empty.\n");
    }
    else
    {
        printf("\nTop element is: %d\n", stack[top]);
    }
}

void display(int stack[], int top)
{
    if (top == -1)
    {
        printf("\nStack is empty.\n");
    }
    else
    {
        printf("\n");
        while (top >= 0)
        {
            printf("%d ", stack[top]);
            top--;
        }
    }
}