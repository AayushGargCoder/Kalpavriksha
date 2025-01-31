// 1. createNode()            -> O(1) and O(1)  // Allocates memory for a new node
// 2. initializeStack()        -> O(1) and O(1)  // Initializes stack with null head and zero size
// 3. push()                   -> O(1) and O(1)  // Adds a new node to the top of the stack
// 4. isEmpty()                -> O(1) and O(1)  // Checks if the stack is empty
// 5. pop()                    -> O(1) and O(1)  // Removes the top node and frees its memory
// 6. top()                    -> O(1) and O(1)  // Returns the data of the top node
// 7. printStack()             -> O(n) and O(n)  // Prints the stack using recursion with stack space
// 8. freeStack()             -> O(n) and O(1)  // Frees all the nodes in the stack
// 7. Total Elements           ->O(1) and O(1)  // Directly accesses the size

#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
} Node;

typedef struct
{
    Node *head;
    int size;
} Stack;
Node *createNode()
{
    int data;
    printf("Enter value to be Added:");
    scanf("%d", &data);
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
void initializeStack(Stack *stack)
{
    stack->head = NULL;
    stack->size = 0;
}
void push(Stack *stack, Node *newNode)
{
    newNode->next = stack->head;
    stack->head = newNode;
    stack->size++;
}
int isEmpty(Stack *stack)
{
    return stack->head == NULL;
}
void pop(Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack Underflow\n");
        return;
    }
    Node *tempNode = stack->head;
    stack->head = stack->head->next;
    stack->size--;
    free(tempNode);
}

int top(Stack *stack)
{
    if (isEmpty(stack))
        return -1;
    return stack->head->data;
}
void printStack(Stack *stack)
{
    if (isEmpty(stack))
        return;
    printf("%d ", top(stack));
    Node *tempHead = stack->head;
    stack->head = stack->head->next;
    printStack(stack);
    stack->head = tempHead;
}

void printStackHelper(Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Empty Stack\n");
        return;
    }
    printf("Your current stack status is:");
    printStack(stack);
    printf("\n");
}
void printTopHelper(Stack *stack)
{
    if (isEmpty(stack))
        printf("Empty stack\n");
    else
        printf("Top element:%d", top(stack));
}
void performOperations(Stack *stack, int *operationNumber)
{
    printf("Enter Operation Number:");
    scanf("%d", operationNumber);
    switch (*operationNumber)
    {
    case 1:
        push(stack, createNode());
        break;
    case 2:
        pop(stack);
        break;
    case 3:
        printTopHelper(stack);
        break;
    case 4:
        printf(isEmpty(stack) ? "Empty Stack\n" : "Having some elements\n");
        break;
    case 5:
        printf("Total Elements In stack:%d\n", stack->size);
        break;
    case 6:
        printStackHelper(stack);
        break;
    case 7:
        return;
    default:
        printf("Invalid Choice\n");
    }
}
void freeStack(Stack *stack)
{
    while (stack->head)
    {
        Node *tempHead = stack->head;
        stack->head = stack->head->next;
        free(tempHead);
    }
}
int main()
{
    Stack stack;
    initializeStack(&stack);
    int operationNumber;
    do
    {
        printf("\nPress1:Push\n");
        printf("Press2:Pop\n");
        printf("Press3:Get top element\n");
        printf("Press4:check for empty\n");
        printf("Press5:Get Total Elements in Stack\n");
        printf("Press6:Print stack\n");
        printf("Press7:Exit\n\n");
        performOperations(&stack, &operationNumber);
    } while (operationNumber != 7);
    freeStack(&stack);
}