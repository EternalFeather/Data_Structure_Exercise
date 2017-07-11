// Noncircular queue

#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 4

typedef struct {
	int data[MAX_QUEUE_SIZE];
	int front;
	int rear;
	int size;
}element;

int IsFullQ(element *queue){
	if (queue -> rear == (int)MAX_QUEUE_SIZE-1){
		return 1;
	}
	else return 0;
}

int IsEmptyQ(element *queue){
	if (queue -> front == queue -> rear){
		return 1;
	}
	else return 0;
}

void AddQ(element *queue, int item){
	if (IsFullQ(queue)){
		printf("Queue is full!\n");
		return;
	}
	else{
		queue -> rear++;
		queue -> data[queue -> rear] = item;
		queue -> size++;
	}
}

element DeleteQ(element *queue){
	if (IsEmptyQ(queue)){
		printf("Queue is empty!\n");
		return;
	}
	else {
		queue -> front++;
		queue -> data[queue -> front] = NULL;
		queue -> size--;
		if (queue -> size == 0){
			queue -> rear = -1;
			queue -> front = -1;
		} 
		return queue[queue -> front];
	}
}

void PrintQueue(element *queue){
	int i;
	if (IsEmptyQ(queue)){
		return;
	}
	else {
		printf("Queue:");
		int i;
		for (i=0;i<MAX_QUEUE_SIZE;i++){
			if(queue -> data[i] == NULL){
				printf("[ ]");
			}
			else
				printf("[%d]", queue -> data[i]);
		}
		printf("\n");
	}
}

void select(element *queue, int c){
	int k;
	int l;
	int i;
	int test;
	if(c == 1){
		printf("Insert number:");
		scanf("%d", &k);
		if(IsFullQ(queue) && queue -> size < MAX_QUEUE_SIZE){
			l = MAX_QUEUE_SIZE - queue -> size;
			for(i=queue -> front+1;i<=queue -> rear;i++){
				queue -> data[i-l] = queue -> data[i];
				queue -> data[i] = NULL;
			}
			queue -> front = -1;
			queue -> rear = queue -> rear - l;
		}
		AddQ(queue, k);
		printf("Front=%d,Rear=%d\n", queue -> front, queue -> rear);
	}
	else if(c == 2){
		test = queue -> data[queue -> front+1];
		DeleteQ(queue);
		printf("Front=%d,Rear=%d\n", queue -> front, queue -> rear);
		printf("delete:%d\n", test);
	}
	else{
		printf("Your input is wrong!\n");
	}
}

int main(){
	
	int i;
	element queue[MAX_QUEUE_SIZE];
	for (i=0;i<MAX_QUEUE_SIZE;i++){
		queue -> data[i] = NULL;
	}
	queue -> rear = -1;
	queue -> front = -1;
	queue -> size = 0;
	
	int c;
	while (1){
		printf("Insert(1)delete(2):");
		scanf("%d", &c);
		select(queue, c);
		PrintQueue(queue);
	}
	
	getchar();
	getchar();
	return 0;
}









