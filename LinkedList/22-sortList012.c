#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
	int data;
	struct node *next;
} Node;

void swap(Node *node1, Node *node2)
{
	int temp = node1->data;
	node1->data = node2->data;
	node2->data = temp;
}
void segregate(Node *head)
{
	Node *zero = head;
	while (head)
	{
		if (head->data == 0)
		{
			swap(zero, head);
			zero = zero->next;
		}
		head = head->next;
	}
	Node *one = zero;
	while (zero)
	{
		if (zero->data == 1)
		{
			swap(zero, one);
			one = one->next;
		}
		zero = zero->next;
	}
}
Node *createNode(int val)
{
	Node *newNode = (Node *)malloc(sizeof(Node));
	newNode->next = NULL;
	newNode->data = val;
	return newNode;
}
Node *takeInput()
{
	int nodeCount = 2, input;
	Node *head = NULL, *tail = NULL;
	printf("Enter 1 node value (enter -1 to exit):");
	scanf("%d", &input);
	while (input != -1)
	{
		Node *newNode = createNode(input);
		if (head == NULL)
		{
			head = newNode;
			tail = newNode;
		}
		else
		{
			tail->next = newNode;
			tail = newNode;
		}
		printf("Enter %d node value (enter -1 to exit):", nodeCount);
		scanf("%d", &input);
	}
	return head;
}
void printList(Node *head)
{
	if (!head)
	{
		printf("Empty List");
		return;
	}
	printf("Your List After sorting:");
	while (head)
	{
		printf("%d ", head->data);
		head = head->next;
	}
}

void freeList(Node *head)
{
	while (head)
	{
		Node *temp = head;
		head = head->next;
		free(temp);
	}
}
int main()
{
	Node *head = takeInput();
	segregate(head);
	printList(head);
	freeList(head);
}