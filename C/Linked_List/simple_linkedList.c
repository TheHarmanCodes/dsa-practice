/*
Program Name : Singly Linked List (Using head and rear)
Description  : Implementation of a Singly Linked List in C
               supporting insertion, deletion, searching,
               reversing, and display operations.

Data Structure Used : Singly Linked List

Pointers Used:
- head : points to the first node
- rear : points to the last node

Time Complexity:
Insert at Beginning : O(1)
Insert at End       : O(1)
Insert at Position  : O(n)
Delete by Value     : O(n)
Search              : O(n)
Reverse List        : O(n)
Display             : O(n)

Space Complexity:
O(n)  (for n nodes in the linked list)
*/
#include <stdio.h>
#include <stdlib.h>

// Linked List Node definition
typedef struct Node
{
    int data;
    struct Node *next;
} Node;

void insertBeginning(Node **, Node **, int);
void insertAtEnd(Node **, Node **, int);
void insertAtPosition(Node **, Node **, int);
void display(Node *);
void deleteValue(Node **, Node **, int);
void reverseDisplay(Node *);
void reverseList(Node **, Node **);
void search(Node *);

int main()
{
    Node *head = NULL, *rear = NULL;
    int choice, value, pos;

    while (1)
    {
        system("cls");

        printf("\nSingly Linked List\n------------\n1. Insert at Beginning\n2. Insert at End\n3. Insert at Position\n4. Display\n5. Delete by Value\n6. Reverse Display\n7. Reverse List\n8. Search\n9. Exit\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("\nEnter value: ");
            scanf("%d", &value);
            insertBeginning(&head, &rear, value);
            break;

        case 2:
            printf("\nEnter value: ");
            scanf("%d", &value);
            insertAtEnd(&head, &rear, value);
            break;

        case 3:
            printf("\nEnter position: ");
            scanf("%d", &pos);
            insertAtPosition(&head, &rear, pos);
            break;

        case 4:
            display(head);
            break;

        case 5:
            printf("\nEnter value to delete: ");
            scanf("%d", &value);
            deleteValue(&head, &rear, value);
            break;

        case 6:
            if (head == NULL)
            {
                printf("\nList is empty.");
            }
            else
            {

                printf("\nReverse Display: ");
                reverseDisplay(head);
            }
            printf("\n");
            break;

        case 7:
            reverseList(&head, &rear);
            printf("\nList Reversed\n");
            break;

        case 8:
            search(head);
            break;

        case 9:
            printf("\nExiting...\n");
            return 0;

        default:
            printf("\nInvalid choice\n");
        }

        printf("\nPress Enter to continue...");
        getchar();
        getchar();
    }
}
void insertBeginning(Node **head, Node **rear, int value)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = *head;

    if (*head == NULL) // empty list
        *rear = newNode;

    *head = newNode;
}

void insertAtEnd(Node **head, Node **rear, int value)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;

    if (*head == NULL) // means empty list
    {
        *head = *rear = newNode;
    }
    else
    {
        (*rear)->next = newNode;
        *rear = newNode;
    }
}

void insertAtPosition(Node **head, Node **rear, int pos)
{
    int count = 0, i;
    Node *temp = *head;

    // Count total nodes
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }

    if (pos < 1 || pos > count + 1)
    {
        printf("\nInvalid Position\n");
        return;
    }

    Node *newNode = (Node *)malloc(sizeof(Node));
    printf("\nEnter value to insert: ");
    scanf("%d", &newNode->data);
    newNode->next = NULL;

    if (*head == NULL)
    {
        *head = *rear = newNode;
        return;
    }

    // Insert at beginning
    if (pos == 1)
    {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    // Traverse to (pos - 1)
    Node *p = *head;
    for (i = 1; i < pos - 1; i++)
        p = p->next;

    newNode->next = p->next;
    p->next = newNode;

    // If inserted at end, update rear
    if (pos == count + 1)
        *rear = newNode;
}

void display(Node *head)
{
    if (head == NULL)
    {
        printf("\nLinked List is empty\n");
        return;
    }

    printf("\nLinked List: ");
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

void deleteValue(Node **head, Node **rear, int value)
{
    Node *p, *q;

    if (*head == NULL)
    {
        printf("\nLinked List is empty\n");
        return;
    }

    // Delete first node
    if ((*head)->data == value)
    {
        q = *head;
        *head = (*head)->next;

        if (*head == NULL) // list became empty
            *rear = NULL;

        free(q);
        return;
    }

    // Delete middle or last node
    p = *head;
    q = p->next;

    while (q != NULL)
    {
        if (q->data == value)
        {
            p->next = q->next;

            if (q == *rear) // deleting last node
                *rear = p;

            free(q);
            return;
        }
        p = q;
        q = q->next;
    }

    printf("\nValue not found in the list\n");
}

void reverseDisplay(Node *head)
{
    if (head == NULL)
        return;

    reverseDisplay(head->next);
    printf("%d ", head->data);
}

void reverseList(Node **head, Node **rear)
{
    Node *prev = NULL, *curr = *head, *next = NULL;
    Node *oldHead = *head;

    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    *head = prev;
    *rear = oldHead;
}

void search(Node *head)
{
    int key;
    if (head == NULL)
    {
        printf("\nLinked List is empty\n");
        return;
    }

    printf("\nEnter value to search: ");
    scanf("%d", &key);

    while (head != NULL)
    {
        if (head->data == key)
        {
            printf("\n%d found in the list\n", key);
            return;
        }
        head = head->next;
    }

    printf("\n%d not found in the list\n", key);
}