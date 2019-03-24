#include <stdio.h>
#include <stdlib.h>


struct node{
	int data;
	struct node * link;
};

int enqueue();
int printQueue();
void removeFromQueue();


struct node * root = NULL;
struct node * last = NULL;


int main(void) {

	int inputsize;
	int deletesize;
	int * inputs;
	int * deletes;

	scanf("%d", &inputsize);

	inputs = malloc(sizeof(int) * inputsize);


	for(int i = 0; i < inputsize; i++){
		scanf("%d",&inputs[i]);
	}

	scanf("%d", &deletesize);

	deletes = malloc(sizeof(int) * deletesize);

	for(int i = 0; i < deletesize; i++){
		scanf("%d",&deletes[i]);
	}

	for(int i = 0; i < inputsize; i++){

		// enqueue(root, last, inputs[i]);
		struct node * newnode;

		newnode = (struct node *)malloc(sizeof(struct node));

		newnode->data = inputs[i];

		if(root == NULL){
			root = newnode;
			last = newnode;
		}else{
			last->link = newnode;
			last = newnode;
		}
	}

	for(int i = 0; i < deletesize; i++){
		removeFromQueue(deletes[i]);
	}

	printQueue();

	free(inputs);

}

int printQueue(){

	struct node * temp = root;

	if(temp == NULL){
		return 0;
	}else{
		while(temp != NULL){
			printf("%d ",temp->data);
			temp = temp->link;
		}
		return 1;
	}

}


// int enqueue(struct node * root, struct node * last, int newdata){

// 	struct node * newnode;

// 	newnode = (struct node *)malloc(sizeof(struct node));

// 	if(newnode == NULL){
// 		return 0;
// 	}

// 	newnode->data = newdata;

// 	if(root == NULL){
// 		root = newnode;
// 		last = newnode;
// 		return 1;
// 	}else{
// 		newnode->link = root;
// 	 	root = newnode;
// 	 	printf("%d\n", newnode->data);
// 		return 1;
// 	}
// }


void removeFromQueue(int delete_data){
	
	struct node * temp = root;

	if(temp->data == delete_data){
		root = temp->link;
		free(temp);
		return;

	}else{
		struct node * p;
		p = temp->link;

		while(p != NULL && p->data != delete_data){
			temp = p;
			p = p->link;
		}
		temp->link = p->link;
		if(temp->link == NULL){
			last = temp;
		}
		free(p);
		return;
	}
}




			// if(p->data == delete_data){
			// 	temp->link = p->link;
			// 	p->link = NULL;
			// 	free(p);
			// 	return 1;
			// }









