// 1. initializeQueueMembers() -> O(1) and O(n)  // Initializes queue members (with dynamic memory allocation for size n)
// 2. isEmpty()                 -> O(1) and O(1)  // Checks if the stack is empty
// 3. pop()                     -> O(1) and O(1)  //Increment front pointer directly
// 4. top()                     -> O(1) and O(1)  // Direct access to front pointer to get top
// 5. push()                   -> O(n) and O(n)  // Inserts element at back and again add dequeued element and there is wastage of space of prev elements
// 6.size()                   ->O(1) and O(1)  //Simple subtraction operation with no extra space
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int *queueArray;
    int rear, front, capacity;
} Queue;

void initializeQueueMembers(Queue *queue, int capacity)
{
    queue->rear = -1;
    queue->front = -1;
    queue->capacity = capacity;
    queue->queueArray = (int *)calloc(capacity, sizeof(int));
}

void initializeQueue(Queue *queue)
{
    int capacity;
    printf("Enter size of stack: ");
    scanf("%d", &capacity);
    if (capacity <= 0)
        exit(0);
    initializeQueueMembers(queue, capacity);
}

void enqueue(Queue *queue, int data)
{
    if (queue->rear == queue->capacity - 1)
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
    queue->front++;
    if (queue->front > queue->rear)
    {
        queue->front = -1;
        queue->rear = -1;
    }
}

void pop(Queue *queue)
{
    if (isEmpty(queue))
    {
        printf("stack Underflow\n");
        return;
    }
    dequeue(queue);
}

void top(Queue *queue)
{
    int topElement = front(queue);
    if (topElement == -1)
        printf("Stack Underflow\n");
    else
        printf("Top element of stack:%d\n", topElement);
}
int size(Queue *queue)
{
    if (isEmpty(queue))
        return 0;
    return queue->rear - queue->front + 1;
}

void push(Queue *queue)
{
    int data;
    printf("Enter value to be added: ");
    scanf("%d", &data);
    int prevSize = size(queue);
    enqueue(queue, data);
    for (int i = 0; i < prevSize; i++)
    {
        enqueue(queue, front(queue));
        dequeue(queue);
    }
    printf("New value added to stack\n");
}

void performOperations(Queue *queue, int *operationNumber)
{
    printf("Enter operation number: ");
    scanf("%d", operationNumber);
    switch (*operationNumber)
    {
    case 1:
        push(queue);
        break;
    case 2:
        pop(queue);
        break;
    case 3:
        top(queue);
        break;
    case 4:
        printf(isEmpty(queue) ? "Empty stack\n" : "stack has some elements\n");
        break;
    case 5:
        printf("Total elements in stack: %d\n", size(queue));
        break;
    case 6:
        return;
    default:
        printf("Invalid choice\n");
    }
}

int main()
{
    Queue queue;
    initializeQueue(&queue);
    int operationNumber;
    do
    {
        printf("\nPress 1: Push\n");
        printf("Press 2: Pop\n");
        printf("Press 3: Get Top Element\n");
        printf("Press 4: Check if stack is Empty\n");
        printf("Press 5: Total Elements in Stack\n");
        printf("Press 6: Exit\n\n");
        performOperations(&queue, &operationNumber);
    } while (operationNumber != 6);

    free(queue.queueArray);
}
