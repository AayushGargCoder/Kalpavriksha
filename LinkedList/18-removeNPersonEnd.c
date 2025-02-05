#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
	char *name;
	struct node *next;
} Node;

Node *deleteNthFromLast(Node *head, int k)
{
	Node *fast = head, *slow = head;
	while (k--)
		fast = fast->next;

	if (!fast)
	{
		Node *temp = head->next;
		free(head->name);
		free(head);
		return temp;
	}
	while (fast->next)
		fast = fast->next, slow = slow->next;
	Node *temp = slow->next;
	slow->next = slow->next->next;
	free(temp->name);
	free(temp);
	return head;
}

void freeList(Node *head)
{
	while (head)
	{
		Node *temp = head;
		head = head->next;
		free(temp->name);
		free(temp);
	}
}
void printList(Node *head)
{
	while (head)
	{
		printf("%s ", head->name);
		head = head->next;
	}
}
Node *createNode(char *name)
{
	Node *newNode = (Node *)malloc(sizeof(Node));
	newNode->next = NULL;
	newNode->name = name;
	return newNode;
}
Node *takeInput(int *kPtr)
{
	int nodeCount = 1;
	char *name = (char *)calloc(100, 1);
	Node *head = NULL, *tail = NULL;
	printf("Enter %d person name (enter to exit):", nodeCount);
	scanf("%[^\n]", name);
	while (name[0] != '\0')
	{
		getchar();
		Node *newNode = createNode(name);
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
		name = (char *)calloc(100, 1);
		printf("Enter %d person name (enter to exit)", nodeCount + 1);
		scanf("%[^\n]", name);
		nodeCount++;
	}
	nodeCount--;
	if (!nodeCount)
		exit(0);
	printf("Enter value of k:");
	scanf("%d", kPtr);
	if (nodeCount < (*kPtr))
	{
		printf("Your List remains same:");
		printList(head);
		freeList(head);
		exit(0);
	}
	return head;
}

int main()
{
	int k;
	Node *head = takeInput(&k);
	head = deleteNthFromLast(head, k);
	printf("Your List After deleting:");
	printList(head);
	freeList(head);
}