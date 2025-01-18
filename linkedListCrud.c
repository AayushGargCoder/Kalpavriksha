#include <stdio.h>
#include<stdlib.h>
typedef struct Node {
	int data;
	struct Node* next;
} node;
int getNodeCnt(node *head) {
	int cnt=0;
	while(head!=NULL) {
		cnt++;
		head=head->next;
	}
	return cnt;
}
node* reachToPos(node *head,int pos) {
	for(int i=1; i<pos; i++) head=head->next;
	return head;
}
node* getNewNode(){
    int val;
	scanf("%d",&val);
	node* newNode=(node*)malloc(sizeof(node));
	newNode->data=val;
	newNode->next=NULL;
	return newNode;
}
void insertAtEnd(node **head) {
	node* newNode=getNewNode();
	if(*head==NULL) *head=newNode;
	else {
	    node *tail=*head;
        while(tail->next!=NULL) tail=tail->next;
		tail->next=newNode;
	}
}
void insertAtBeginning(node **head) {
	node* newNode=getNewNode();
	if(*head==NULL)*head=newNode;
	else {
		newNode->next=*head;
		*head=newNode;
	}
}
void insertAtPos(node **head) {
	int pos;
	scanf("%d",&pos);
	if(pos<1){
	    printf("Invalid input:position should always be positive\n");
	    return;
	}
	int nodeCnt=getNodeCnt(*head);
	if(nodeCnt+1<pos){
	    printf("Invalid input:List is not enough to insert at this pos\n");
	    return;
	}
	
	if(pos==1) insertAtBeginning(head);
	else if(pos==nodeCnt+1) insertAtEnd(head);
	else {
	    node *newNode=getNewNode(),*prevNode=reachToPos(*head,pos-1);
	    newNode->next=prevNode->next;
	    prevNode->next=newNode;
	}

}
void display(node *head) {
	while(head!=NULL) {
		printf("%d ",head->data);
		head=head->next;
	}
	printf("\n");
}
void updateAtPos(node *head) {
	int val,pos;
	scanf("%d %d",&pos,&val);
	if(pos<1){
	    printf("Invalid input:position should always be positive\n");
	    return;
	}
	int nodeCnt=getNodeCnt(head);
	if(nodeCnt<pos) printf("Invalid input:List is not enough to update at this pos\n");
	else{
	    node *currNode=reachToPos(head,pos);
    	currNode->data=val;
    	display(head);
	}	
	
}
void deleteAtBeginning(node **head) {
	int nodeCnt=getNodeCnt(*head);
	if(!nodeCnt){
	    printf("Invalid input:List is empty\n");
	    return;
	}
	node* temp=(*head)->next;
	free(*head);
	*head=temp;
}
void deleteAtEnd(node **head) {
	int nodeCnt=getNodeCnt(*head);
	if(!nodeCnt) printf("Invalid input:List is empty\n");
	else if(nodeCnt==1) deleteAtBeginning(head);
	else{
	    node *lastSecondNode=reachToPos(*head,nodeCnt-1),*lastNode=lastSecondNode->next;
    	lastSecondNode->next=NULL;
    	free(lastNode);
	}
}
void deleteAtPos(node **head) {
	int pos;
	scanf("%d",&pos);
	if(pos<1){
	    printf("Invalid input:position should always be positive\n");
	    return;
	}
	int nodeCnt=getNodeCnt(*head);
	if(nodeCnt<pos){
	    printf("Invalid input:List is not enough to delete at this pos\n");
	    return;
	}
	
	if(pos==1) deleteAtBeginning(head);
	else if(pos==nodeCnt) deleteAtEnd(head);
	else{
    	node *prevNode=reachToPos(*head,pos-1);
    	node* temp=prevNode->next;
    	prevNode->next=prevNode->next->next;
    	free(temp);
	}
}
void chooseOption(node **head) {
	int ops;
	scanf("%d",&ops);
	switch(ops){
		case 1:
    	    insertAtEnd(head);
    	    break;
        case 2:
        	insertAtBeginning(head);
        	break;
        case 3:
        	insertAtPos(head);
        	break;
        case 4:
        	display(*head);
        	break;
        case 5:
        	updateAtPos(*head);
        	break;
        case 6:
        	deleteAtBeginning(head);
        	break;
        case 7:
        	deleteAtEnd(head);
        	break;
        case 8:
        	deleteAtPos(head);
        	break;
        default:
            printf("No valid operation, choose option from 1 to 8");
	}
}
int numOfOperations(){
    int n;
    scanf("%d",&n);
    return n;
}
int main()
{
	int n=numOfOperations();
	node *head=NULL;
	while(n--) chooseOption(&head);
	
}