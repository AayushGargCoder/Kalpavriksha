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
    printf("Enter size of Queue:");
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
        printf("Queue Overflow\n");
        return;
    }
    (*stack).stackArray[++(*stack).top] = data;
}
void pop(Stack *stack)
{
    --(*stack).top;
}
int isEmpty(Stack *stack)
{
    return (*stack).top == -1;
}
int top(Stack *stack)
{
    return (*stack).stackArray[(*stack).top];
}
void printQueue(Stack *stack)
{
    if (isEmpty(stack))
        return;
    int data = top(stack);
    (*stack).top--;
    printQueue(stack);
    printf("%d ", data);
    (*stack).top++;
}
void enqueue(Stack *stack)
{
    int data;
    printf("Enter value to be Added:");
    scanf("%d", &data);
    push(stack, data);
    printf("new Value Added:%d\n", top(stack));
}
void dequeue(Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Queue Underflow\n");
        return;
    }
    int topElement = top(stack);
    pop(stack);
    if (isEmpty(stack))
        return;
    dequeue(stack);
    push(stack, topElement);
}
int front(Stack *stack)
{
    if (isEmpty(stack))
        return -1;
    int topElement = top(stack);
    pop(stack);
    int frontElement = front(stack);
    if (isEmpty(stack))
    {
        push(stack, topElement);
        return topElement;
    }
    push(stack, topElement);
    return frontElement;
}
void printQueueHelper(Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Empty Queue\n");
        return;
    }
    printf("Your current Queue status is:");
    printQueue(stack);
    printf("\n");
}
void printFrontHelper(Stack *stack)
{
    if (isEmpty(stack))
        printf("Empty Queue\n");
    else
        printf("Front element:%d", front(stack));
}
void performOperations(Stack *stack, int *operationNumber)
{
    printf("Enter Operation Number:");
    scanf("%d", operationNumber);
    switch (*operationNumber)
    {
    case 1:
        enqueue(stack);
        break;
    case 2:
        dequeue(stack);
        break;
    case 3:
        printFrontHelper(stack);
        break;
    case 4:
        printf(isEmpty(stack) ? "Empty Queue\n" : "Having some elements\n");
        break;
    case 5:
        printf("Total Element In Queue:%d\n", (*stack).top + 1);
        break;
    case 6:
        printQueueHelper(stack);
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
        printf("Press3:Get front element\n");
        printf("Press4:check for empty\n");
        printf("Press5:Total Elements In queue:\n");
        printf("Press6:Print queue\n");
        printf("Press7:Exit\n\n");
        performOperations(&stack, &operationNumber);
    } while (operationNumber != 7);
    free(stack.stackArray);
}