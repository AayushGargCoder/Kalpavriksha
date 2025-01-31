// 1. initializeStack()        -> O(1) and O(n)  // Allocates memory for stack array
// 2. push()                   -> O(1) and O(1)  // Inserts element at the top in constant time
// 3. isEmpty()                -> O(1) and O(1)  // Checks if stack is empty
// 4. pop()                    -> O(1) and O(1)  // Removes top element in constant time
// 5. top()                    -> O(1) and O(1)  // Returns top element without modification
// 6. printStack()             -> O(n) and O(n)  // Recursively prints stack elements
// 7. Total Elements           ->O(1) and O(1)  // Directly accesses the top index
#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int *stackArray;
    int top;
    int size;
} Stack;
void initializeStack(Stack *stack)
{
    (*stack).top = -1;
    int size;
    printf("Enter size of stack:");
    scanf("%d", &size);
    if (size <= 0)
        exit(0);
    (*stack).size = size;
    (*stack).stackArray = (int *)calloc(size, sizeof(int));
}
void push(Stack *stack, int data)
{
    if ((*stack).top == (*stack).size - 1)
    {
        printf("Stack Overflow\n");
        return;
    }
    (*stack).stackArray[++(*stack).top] = data;
}
int isEmpty(Stack *stack)
{
    return (*stack).top == -1;
}
void pop(Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack Underflow\n");
        return;
    }
    --(*stack).top;
}

int top(Stack *stack)
{
    if (isEmpty(stack))
        return -1;
    return (*stack).stackArray[(*stack).top];
}
void printStack(Stack *stack)
{
    if (isEmpty(stack))
        return;
    int data = top(stack);
    printf("%d ", data);
    (*stack).top--;
    printStack(stack);
    (*stack).top++;
}
void pushData(Stack *stack)
{
    int data;
    printf("Enter value to be Added:");
    scanf("%d", &data);
    push(stack, data);
    printf("new Value Added:%d\n", top(stack));
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
        pushData(stack);
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
        printf("Total Elements In stack:%d\n", (*stack).top + 1);
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
        printf("Press5:Total Elements In stack:\n");
        printf("Press6:Print stack\n");
        printf("Press7:Exit\n\n");
        performOperations(&stack, &operationNumber);
    } while (operationNumber != 7);
    free(stack.stackArray);
}