#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
	char *name;
	struct node *next;
} Node;


Node* deleteNthFromLast(Node *head, int k)
{
	Node *fast = head, *slow = head;
	while(k--) fast = fast -> next;

	if(!fast) {
		Node* temp=head->next;
		free(head->name);
		free(head);
		return temp;
	}
	while(fast -> next)
		fast = fast -> next, slow = slow -> next;
	Node* temp=slow->next;
	slow -> next = slow -> next -> next;
	free(temp->name);
	free(temp);
	return head;
}

Node *createNode()
{
	Node *newNode = (Node *)malloc(sizeof(Node));
	newNode->next = NULL;
	newNode->name = (char*)malloc(100);
	scanf("%s",newNode->name);
	return newNode;
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
Node *takeInput(int *kPtr)
{
	int totalPersons, track;
	printf("Total persons in line:");
	scanf("%d", &totalPersons);
	if (totalPersons <= 0)
	{
		printf("You have a empty list:");
		exit(0);
	}
	track = totalPersons;
	Node *head = NULL, *tail = NULL;
	int input;
	while (totalPersons--)
	{
		printf("Enter %d person:", track - totalPersons);
		Node *newNode = createNode();
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
	}
	printf("Enter value of k:");
	scanf("%d", kPtr);
	if(track<(*kPtr)) {
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
	head=deleteNthFromLast(head,k);
	printf("Your List After deleting:");
	printList(head);
	freeList(head);
}