/*
Circular Linked List (Using head and rear)

Description : Implementation of a Circular Linked List in C
              supporting insertion, deletion, searching,
              reverse display, and traversal operations.

Pointers Used:
- head : points to the first node
- rear : points to the last node
- rear->next always points to head (maintains circular structure)

Time Complexity:
Insert at Beginning : O(1)
Insert at End       : O(1)
Insert at Position  : O(n)
Delete Beginning    : O(1)
Delete End          : O(n)
Delete at Position  : O(n)
Search              : O(n)
Display             : O(n)
Reverse Display     : O(n)
Count Nodes         : O(n)

Space Complexity:
O(n)  (for n nodes in the circular linked list)
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

void insertBeginning(Node **, Node **, int);
void insertAtEnd(Node **, Node **, int);
void insertAtPosition(Node **, Node **, int);
void display(Node *);
void deleteBeginning(Node **, Node **);
void deleteEnd(Node **, Node **);
void deleteAtPosition(Node **, Node **, int);
void reverseDisplay(Node *, Node *);
void reverseList(Node **, Node **);
void linearSearch(Node *);
void count(Node *);

int main()
{
    Node *head = NULL, *rear = NULL;
    int choice, value, pos;

    while (1)
    {
        system("cls");

        printf("\nCircular Linked List\n------------\n1. Insert at Beginning\n2. Insert at End\n3. Insert at Position\n4. Delete from Beginning \n5. Delete from End\n6. Delete from Position\n7. Display List\n8. Reverse Display\n9. Search Element\n10. Count Nodes\n11. Reverse List\n12. Exit\nEnter choice: ");
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
            deleteBeginning(&head, &rear);
            break;

        case 5:
            deleteEnd(&head, &rear);
            break;

        case 6:
            printf("Enter position: ");
            scanf("%d", &pos);
            deleteAtPosition(&head, &rear, pos);
            break;

        case 7:
            display(head);
            break;

        case 8:
            if (head == NULL)
            {
                printf("\nList is empty.");
            }
            else
            {
                printf("\nReverse Display: ");
                reverseDisplay(head, rear);
            }
            printf("\n");
            break;

        case 9:
            linearSearch(head);
            break;

        case 10:
            count(head);
            break;

        case 11:
            reverseList(&head, &rear);
            break;

        case 12:
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

    if (*head == NULL)
    {
        *head = *rear = newNode;
        newNode->next = newNode;
        return;
    }
    newNode->next = *head;
    *head = newNode;
    (*rear)->next = newNode;
}

void insertAtEnd(Node **head, Node **rear, int value)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = value;
    if (*rear == NULL) // empty list
    {                  // OR *head == NULL
        *head = *rear = newNode;
        newNode->next = newNode;
        return;
    }
    newNode->next = *head;
    (*rear)->next = newNode;
    *rear = newNode;
}

void insertAtPosition(Node **head, Node **rear, int pos)
{
    int count = 1, i;
    Node *temp = *head;

    // check if list empty
    if (*head == NULL)
    {
        if (pos != 1)
        {
            printf("\nInvalid Position\n");
            return;
        }
        // we are hear only if pos = 1
        Node *newNode = (Node *)malloc(sizeof(Node));
        printf("\nEnter value to insert: ");
        scanf("%d", &newNode->data);

        *head = *rear = newNode;
        newNode->next = newNode;
        return;
    }
    // count total nodes to validate the position
    while (temp->next != *head)
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

    // insert at beginning means pos = 1
    if (pos == 1)
    {
        newNode->next = *head;
        (*rear)->next = newNode;
        *head = newNode;
        return;
    }
    // go to node where *rear is pointing
    Node *p = *head;
    for (i = 1; i < pos - 1; i++)
    {
        p = p->next;
    }
    newNode->next = p->next;
    p->next = newNode;

    // if pos is after rear (at end)
    if (p == *rear)
        *rear = newNode;
}

void display(Node *head)
{
    if (head == NULL)
    {
        printf("\nLinked List is empty\n");
        return;
    }
    Node *temp = head;
    printf("\nLinked List: ");

    do
    {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

void deleteBeginning(Node **head, Node **rear)
{
    if (*head == NULL)
    {
        printf("\nLinked List is empty.\n");
        return;
    }
    Node *temp = *head;

    if (*head == *rear)
    {
        *head = *rear = NULL;
    }
    else
    {
        *head = (*head)->next;
        (*rear)->next = *head;
    }
    free(temp);
}

void deleteEnd(Node **head, Node **rear)
{
    if (*head == NULL)
    {
        printf("\nLinked List is empty.\n");
        return;
    }
    Node *temp = *rear;

    if (*head == *rear)
    {
        *head = *rear = NULL;
    }
    else
    {
        Node *p = *head;
        while (p->next != *rear)
        {
            p = p->next;
        }
        p->next = *head; // or assign (*rear)->next;
        *rear = p;
    }
    free(temp);
}

void deleteAtPosition(Node **head, Node **rear, int pos)
{
    if (*head == NULL)
    {
        printf("\nLinked List is empty.\n");
        return;
    }
    int count = 1;
    Node *temp = *head;

    // count total nodes in CCL
    while (temp->next != *head)
    {
        count++;
        temp = temp->next;
    }

    // validate position
    if (pos < 1 || pos > count)
    {
        printf("\nInvalid Position\n");
        return;
    }
    if (pos == 1)
    {
        Node *delNode = *head;
        if (*head == *rear)
        {
            *head = *rear = NULL;
        }
        else
        {
            *head = (*head)->next;
            (*rear)->next = *head;
        }
        free(delNode);
        return;
    }
    // go to node before delete point
    Node *p = *head;
    for (int i = 1; i < pos - 1; i++)
    {
        p = p->next;
    }
    Node *delNode = p->next;
    p->next = (p->next)->next;

    // if last node deleted is at rear
    if (delNode == *rear)
    {
        *rear = p;
    }
    free(delNode);
}

void reverseDisplay(Node *head, Node *rear)
{
    if (head == rear)
    {
        printf("%d ", head->data);
        return;
    }

    reverseDisplay(head->next, rear);
    printf("%d ", head->data);
}

void reverseList(Node **head, Node **rear)
{
    if (*head == NULL || *head == *rear)
        return;

    Node *prev = *rear, *curr = *head, *next = NULL;
    Node *oldHead = *head;

    do
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    } while (curr != *head);

    *head = *rear;
    *rear = oldHead;
}

void linearSearch(Node *head)
{

    if (head == NULL)
    {
        printf("\nLinked List is empty\n");
        return;
    }
    int key;
    Node *temp = head;
    printf("\nEnter value to search: ");
    scanf("%d", &key);

    do
    {
        if (temp->data == key)
        {
            printf("\n%d found in the list\n", key);
            return;
        }
        temp = temp->next;
    } while (temp != head);

    printf("\n%d not found in the list\n", key);
}

void count(Node *head)
{
    if (head == NULL)
    {
        printf("\nLinked List is empty\n");
        return;
    }
    int count = 1;

    Node *temp = head;
    while (temp->next != head)
    {
        count++;
        temp = temp->next;
    }
    printf("\nTotal element in circular list is : %d", count);
}