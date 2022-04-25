#include <stdio.h>
#include <stdlib.h>

int jumlah=0;

typedef struct{
	int info;
}DATA;

typedef struct node{
	DATA data;
	struct node* next;
} NODE;

void init(NODE** head) {
	*head=NULL;
}

void print_list(NODE* head){
	NODE * temp;
	for (temp = head; temp; temp=temp->next)
		printf("%5d", temp->data.info);
}

NODE* add(NODE* node, DATA data){
	NODE* temp = (NODE*) malloc(sizeof(NODE));
	if (temp == NULL){
		exit(0);
	}
	temp->data=data;
	temp->next=node;
	node=temp;
	return node;
}

void remove_node(NODE* head){
	NODE* temp=(NODE*) malloc(sizeof(NODE));
	if (temp == NULL){
		exit(EXIT_FAILURE);
	}
	temp=head->next;
	head->next=head->next->next;
	free(temp);
}

NODE *free_list(NODE *head){
	NODE *tmpPtr = head;
	NODE *followPtr;
	while (tmpPtr != NULL){
		followPtr = tmpPtr;
		tmpPtr = tmpPtr->next;
		free(followPtr);
	}
	return NULL;
}

int main(){
	int i;
	NODE* head;
	NODE* node;
	DATA element;
	printf("Add Elements to List:\n");
	init(&head);
	for (i=53; i<=63; i++){
		element.info=i;
		printf("Add Element %2d To The List.\n", element.info);
		head=add(head, element);
	}
	printf("\nPrint The List:\n");
	print_list(head);
	printf("\nRemove Element From The List:\n");
	node=head->next->next;
	remove_node(node);
	head=free_list(head);
	printf("Press any key to continue...");
	int ch = getchar();
	return (EXIT_SUCCESS);
}
