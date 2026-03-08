// Infix to Postfix Expression conversion using Stack
#include <stdio.h>
#include <string.h>

#define MAX 50

void push(char[], int *, char);
char pop(char[], int *);
int precedence(char);
void infixToPostfix(char[], char[]);

int main()
{
    char infix[MAX], postfix[MAX]; // sc = scanned

    printf("\nEnter infix Expression: ");
    gets(infix);

    infixToPostfix(infix, postfix);

    printf("\nResultend Postfix Expression: \n");
    puts(postfix);
    printf("\n");
    return 0;
}

void push(char stack[], int *top, char x)
{
    if (*top == MAX - 1)
    {
        printf("\nStack Overflow\n");
        return;
    }
    (*top)++;
    stack[*top] = x;
}

char pop(char stack[], int *top)
{
    char x;
    x = stack[*top];
    (*top)--;
    return x;
}

int precedence(char ch)
{
    switch (ch)
    {
    case '^':
        return 5;
    case '/':
    case '*':
        return 4; // * and / are at same level
    case '+':
    case '-':
        return 3; //+ and - are at same level
    case '(':
        return 0;
    case '#':
        return -1;
    }
    return -1;
}
void infixToPostfix(char infix[], char postfix[])
{
    char stack[MAX], sc, p; // sc = scanned
    int top = -1, length, i, j = 0;

    push(stack, &top, '#');
    length = strlen(infix);

    for (i = 0; i < length; i++)
    {
        sc = infix[i];
        switch (sc)
        {
        case '(':
            push(stack, &top, sc);
            break;

        case ')':
            p = pop(stack, &top);
            while (p != '(')
            {
                postfix[j++] = p;
                p = pop(stack, &top);
            }
            break;

        case '^':
        case '/':
        case '*':
        case '+':
        case '-':
            if (precedence(sc) > precedence(stack[top]))
            {
                push(stack, &top, sc);
            }
            else
            {
                while (
                    precedence(sc) < precedence(stack[top]) ||
                    (precedence(sc) == precedence(stack[top]) && sc != '^'))
                {
                    postfix[j++] = pop(stack, &top);
                }
                push(stack, &top, sc);
            }
            break;

        default: // we got an operand in sc
            postfix[j++] = sc;
        }
    }
    // when we scanned complete infix expression,now we check is something in stack
    while (top > 0)
    {
        postfix[j++] = pop(stack, &top);
    }
    postfix[j] = '\0';
}
