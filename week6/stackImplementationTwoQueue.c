// 1. initializeQueueMembers() -> O(1) and O(n)  // Initializes queue members (with dynamic memory allocation for size n)
// 2. isEmpty()                 -> O(1) and O(1)  // Checks if the stack is empty
// 3. auxillaryToQueue()        -> O(n) and O(n)  // Recursively transfers elements from auxiliary to main queue
// 4. pop()                     -> O(n) and O(n)  // Removes elements until only one remains, and moves it to auxiliary queue
// 5. top()                     -> O(n) and O(n)  // Recursively finds the top element, moving elements to auxiliary queue
// 6. printStack()             -> O(n) and O(n)  // Prints all elements by recursively dequeuing them and enqueueing them back

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int *queueArray;
    int rear, front, size;
} Queue;

void initializeQueueMembers(Queue *queue, int size)
{
    queue->rear = -1;
    queue->front = -1;
    queue->size = size;
    queue->queueArray = (int *)calloc(size, sizeof(int));
}

void initializeQueue(Queue *queue)
{
    int size;
    printf("Enter size of stack: ");
    scanf("%d", &size);
    if (size <= 0)
        exit(0);
    initializeQueueMembers(queue, size);
}

void enqueue(Queue *queue, int data)
{
    if (queue->rear == queue->size - 1)
    {
        printf("stack Overflow\n");
        return;
    }
    queue->queueArray[++queue->rear] = data;
    if (queue->front == -1)
        queue->front = 0;
}

int isEmpty(Queue *queue)
{
    return queue->rear == -1;
}

int front(Queue *queue)
{
    if (isEmpty(queue))
        return -1;
    return queue->queueArray[queue->front];
}

void dequeue(Queue *queue)
{
    if (isEmpty(queue))
        return;

    queue->front++;
    if (queue->front > queue->rear)
    {
        queue->front = -1;
        queue->rear = -1;
    }
}

void auxillaryToQueue(Queue *queue, Queue *auxillary)
{
    if (isEmpty(auxillary))
        return;
    enqueue(queue, front(auxillary));
    dequeue(auxillary);
    auxillaryToQueue(queue, auxillary);
}

void pop(Queue *queue, Queue *auxillary)
{
    if (isEmpty(queue))
    {
        printf("stack Underflow\n");
        return;
    }
    if (queue->front == queue->rear)
    {
        dequeue(queue);
        auxillaryToQueue(queue, auxillary);
        return;
    }
    enqueue(auxillary, front(queue));
    dequeue(queue);
    pop(queue, auxillary);
}

int top(Queue *queue, Queue *auxillary)
{
    if (isEmpty(queue))
    {
        printf("stack Underflow\n");
        return -1;
    }
    if (queue->front == queue->rear)
    {
        int topElement = front(queue);
        enqueue(auxillary, topElement);
        dequeue(queue);
        auxillaryToQueue(queue, auxillary);
        return topElement;
    }
    enqueue(auxillary, front(queue));
    dequeue(queue);
    int topElement = top(queue, auxillary);
    return topElement;
}

void printStack(Queue *queue, Queue *auxillary)
{
    if (isEmpty(queue))
        return;
    printf("%d ", front(queue));
    enqueue(auxillary, front(queue));
    dequeue(queue);
    printStack(queue, auxillary);
}

void push(Queue *queue)
{
    int data;
    printf("Enter value to be added: ");
    scanf("%d", &data);
    enqueue(queue, data);
    printf("New value added to stack\n");
}

void printStackHelper(Queue *queue, Queue *auxillary)
{
    if (isEmpty(queue))
    {
        printf("Empty stack\n");
        return;
    }
    printf("Your current stack status is: ");
    printStack(queue, auxillary);
    auxillaryToQueue(queue, auxillary);
    printf("\n");
}

void printTopHelper(Queue *queue, Queue *auxillary)
{
    if (isEmpty(queue))
        printf("Empty stack\n");
    else
        printf("Top element: %d\n", top(queue, auxillary));
}

void performOperations(Queue *queue, Queue *auxillary, int *operationNumber)
{
    printf("Enter operation number: ");
    scanf("%d", operationNumber);
    switch (*operationNumber)
    {
    case 1:
        push(queue);
        break;
    case 2:
        pop(queue, auxillary);
        break;
    case 3:
        printTopHelper(queue, auxillary);
        break;
    case 4:
        printf(isEmpty(queue) ? "Empty stack\n" : "stack has some elements\n");
        break;
    case 5:
        printf("Total elements in stack: %d\n", isEmpty(queue) ? 0 : queue->rear - queue->front + 1);
        break;
    case 6:
        printStackHelper(queue, auxillary);
        break;
    case 7:
        return;
    default:
        printf("Invalid choice\n");
    }
}

int main()
{
    Queue queue, auxillaryQueue;
    initializeQueue(&queue);
    initializeQueueMembers(&auxillaryQueue, queue.size);
    int operationNumber;
    do
    {
        printf("\nPress 1: Push\n");
        printf("Press 2: Pop\n");
        printf("Press 3: Get Top Element\n");
        printf("Press 4: Check if stack is Empty\n");
        printf("Press 5: Total Elements in Stack\n");
        printf("Press 6: Print Stack\n");
        printf("Press 7: Exit\n\n");
        performOperations(&queue, &auxillaryQueue, &operationNumber);
    } while (operationNumber != 7);

    free(queue.queueArray);
    free(auxillaryQueue.queueArray);
}
