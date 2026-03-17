/*
Singly Linked List (Using only head)

Description:
Implementation of a Singly Linked List using only head pointer.

Time Complexity:
Insert at Beginning : O(1)
Insert at End       : O(n)
Insert at Position  : O(n)
Delete by Value     : O(n)
Search              : O(n)
Reverse List        : O(n)
Display             : O(n)

Space Complexity:
O(n)
*/

#include <stdio.h>
#include <stdlib.h>

// Node structure
typedef struct Node
{
    int data;
    struct Node *next;
} Node;

// Function declarations
void insertBeginning(Node **, int);
void insertAtEnd(Node **, int);
void insertAtPosition(Node **, int);
void display(Node *);
void deleteValue(Node **, int);
void reverseDisplay(Node *);
void reverseList(Node **);
void search(Node *);

// 2
void insertAfterFirst(Node *ptr, int value)
{
    if (ptr == NULL)
    {
        printf("\nList is empty\n");
        return;
    }

    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = value;

    // Insert after first node
    newNode->next = ptr->next;
    ptr->next = newNode;

    printf("\nNode inserted after first node\n");
}

void insertBeforeLast(Node *ptr)
{
    if (ptr == NULL)
    {
        printf("\nList is empty\n");
        return;
    }

    Node *newNode = (Node *)malloc(sizeof(Node));
    printf("Enter value to insert: ");
    scanf("%d", &newNode->data);

    if ((ptr)->next == NULL)
    {
        newNode->next = ptr;
        ptr = newNode;
        return;
    }
    Node *temp = ptr;
    while ((temp->next)->next != NULL)
    {
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

int main()
{
    Node *head = NULL;
    int choice, value, pos;

    while (1)
    {
        system("cls");

        printf("\nSingly Linked List\n------------\n");
        printf("1. Insert at Beginning\n2. Insert at End\n3. Insert at Position\n");
        printf("4. Display\n5. Delete by Value\n6. Reverse Display\n");
        printf("7. Reverse List\n8. Search\n9. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("\nEnter value: ");
            scanf("%d", &value);
            insertBeginning(&head, value);
            break;

        case 2:
            printf("\nEnter value: ");
            scanf("%d", &value);
            insertAtEnd(&head, value);
            break;

        case 3:
            printf("\nEnter position: ");
            scanf("%d", &pos);
            insertAtPosition(&head, pos);
            break;

        case 4:
            display(head);
            break;

        case 5:
            printf("\nEnter value to delete: ");
            scanf("%d", &value);
            deleteValue(&head, value);
            break;

        case 6:
            printf("\nReverse Display: ");
            reverseDisplay(head);
            printf("\n");
            break;

        case 7:
            reverseList(&head);
            printf("\nList Reversed\n");
            break;

        case 8:
            search(head);
            break;

        case 9:
            return 0;

        default:
            printf("\nInvalid choice\n");
        }

        printf("\nPress Enter to continue...");
        getchar();
        getchar();
    }
}

// Insert at beginning
void insertBeginning(Node **head, int value)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = *head;
    *head = newNode;
}

// Insert at end (O(n))
void insertAtEnd(Node **head, int value)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;

    if (*head == NULL)
    {
        *head = newNode;
        return;
    }

    Node *temp = *head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

// Insert at position
void insertAtPosition(Node **head, int pos)
{
    int count = 0, i;
    Node *temp = *head;

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
    printf("\nEnter value: ");
    scanf("%d", &newNode->data);
    newNode->next = NULL;

    if (pos == 1)
    {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    Node *p = *head;
    for (i = 1; i < pos - 1; i++)
        p = p->next;

    newNode->next = p->next;
    p->next = newNode;
}

// Display list
void display(Node *head)
{
    if (head == NULL)
    {
        printf("\nList is empty\n");
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

// Delete by value
void deleteValue(Node **head, int value)
{
    Node *temp = *head, *prev = NULL;

    if (*head == NULL)
    {
        printf("\nList is empty\n");
        return;
    }

    if (temp->data == value)
    {
        *head = temp->next;
        free(temp);
        return;
    }

    while (temp != NULL && temp->data != value)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("\nValue not found\n");
        return;
    }

    prev->next = temp->next;
    free(temp);
}

// Reverse display (recursive)
void reverseDisplay(Node *head)
{
    if (head == NULL)
        return;

    reverseDisplay(head->next);
    printf("%d ", head->data);
}

// Reverse list
void reverseList(Node **head)
{
    Node *prev = NULL, *curr = *head, *next = NULL;

    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    *head = prev;
}

// Search element
void search(Node *head)
{
    int key;

    if (head == NULL)
    {
        printf("\nList is empty\n");
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

    printf("\n%d not found\n", key);
}