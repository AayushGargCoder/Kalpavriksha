#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int *stackArray;
    int top;
    int size;
} Stack;
void initializeStackMembers(Stack *stack, int size)
{
    stack->size = size;
    stack->top = -1;
    (*stack).stackArray = (int *)calloc(size, sizeof(int));
}
void initializeStack(Stack *stack)
{
    int size;
    printf("Enter size of Queue:");
    scanf("%d", &size);
    if (size <= 0)
        exit(0);
    initializeStackMembers(stack, size);
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

void enqueue(Stack *stack)
{
    int data;
    printf("Enter value to be Added:");
    scanf("%d", &data);
    push(stack, data);
    printf("new Value Added:%d\n", top(stack));
}

void stackTransfer(Stack *stack1, Stack *stack2)
{
    while (!isEmpty(stack1))
    {
        push(stack2, top(stack1));
        pop(stack1);
    }
}
void dequeue(Stack *stack, Stack *auxillaryStack)
{
    if (isEmpty(stack))
    {
        printf("Queue Underflow\n");
        return;
    }
    stackTransfer(stack, auxillaryStack);
    pop(auxillaryStack);
    stackTransfer(auxillaryStack, stack);
}
int front(Stack *stack, Stack *auxillaryStack)
{
    if (isEmpty(stack))
        return -1;
    stackTransfer(stack, auxillaryStack);
    int frontElement = top(auxillaryStack);
    stackTransfer(auxillaryStack, stack);
    return frontElement;
}
void printQueue(Stack *stack, Stack *auxillaryStack)
{
    if (isEmpty(stack))
    {
        printf("Empty Queue\n");
        return;
    }
    printf("Your current Queue status is:");
    stackTransfer(stack, auxillaryStack);
    while (!isEmpty(auxillaryStack))
    {
        int frontElement = top(auxillaryStack);
        printf("%d ", frontElement);
        push(stack, frontElement);
        pop(auxillaryStack);
    }
    printf("\n");
}
void printFrontHelper(Stack *stack, Stack *auxillaryStack)
{
    if (isEmpty(stack))
        printf("Empty Queue\n");
    else
        printf("Front element:%d", front(stack, auxillaryStack));
}
void performOperations(Stack *stack, Stack *auxillaryStack, int *operationNumber)
{
    printf("Enter Operation Number:");
    scanf("%d", operationNumber);
    switch (*operationNumber)
    {
    case 1:
        enqueue(stack);
        break;
    case 2:
        dequeue(stack, auxillaryStack);
        break;
    case 3:
        printFrontHelper(stack, auxillaryStack);
        break;
    case 4:
        printf(isEmpty(stack) ? "Empty Queue\n" : "Having some elements\n");
        break;
    case 5:
        printf("Total Element In Queue:%d\n", (*stack).top + 1);
        break;
    case 6:
        printQueue(stack, auxillaryStack);
        break;
    case 7:
        return;
    default:
        printf("Invalid Choice\n");
    }
}
int main()
{
    Stack stack, auxillaryStack;
    initializeStack(&stack);
    initializeStackMembers(&auxillaryStack, stack.size);
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
        performOperations(&stack, &auxillaryStack, &operationNumber);
    } while (operationNumber != 7);
    free(stack.stackArray);
    free(auxillaryStack.stackArray);
}