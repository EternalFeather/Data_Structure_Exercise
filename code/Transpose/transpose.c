#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct element{
	int rows;
	int cols;
	int value;
	struct element *next;
}element;

element *create(){
	element *temp = (element *)malloc(sizeof(element));
	if(temp==NULL){
		printf("Matrix is empty!");
	return 0;
	}
	return temp;
}

element *makenode(int m, int n, int val)
{
	element *temp = create();
	temp -> rows = m;
	temp -> cols = n;
	temp -> value = val;
	temp -> next = NULL;
	return temp;
}

element *insert(element *head[], int m, int n, int val)
{
	element *ptr;
	element *temp = head;
	if(head == NULL){
		head = makenode(m, n, val);
	}
    else{
		while(temp -> next != NULL){
			temp = temp->next;
		}
		ptr = makenode(m, n, val);
		temp -> next = ptr;
	}
	return head;
}

void transpose(element *head[], int m, int n)
{
	element *trv1;
	int i, j;
	int *result[MAX];
	for(i=0; i<MAX; ++i){
		result[i] = (int *)malloc(sizeof(int)*MAX);
	}
	for (i = 0; i < m; i++) {
		trv1 = head[i] -> next;
		j = 0;
		while (trv1 != NULL) {
			result[j][i] = trv1 -> value;
			trv1 = trv1 -> next;
			j++;
		}
	}
	printf("The result of transpose is:\n");
	for (i = 0;i < n;i++){
		for (j =0;j < m;j++){
			printf("%d ", result[i][j]);
		}
		printf("\n");
	}
}

void output(element *head[], int m, int n){
	element *temp;
	int i, j;
	if(head == NULL){
		printf("Matrix is empty.");
		return 0;
	}
	temp = head;
	for(i=0; i< m; i++){
		for(j=0; j< n; j++){
			temp = temp->next;
			printf("%d\t", temp -> value);
		}
		printf("\n");
	}
}

void print_out(element *head[], int m, int n)
{
	element *out;
	int i;
	for (i = 0; i < m; ++i) {
		out = head[i] -> next;
		while (out != NULL) {
			printf("%d ", out -> value);
			out = out -> next;
		}
		printf("\n");
	}
}

int main(){
	int *arr[MAX];
	int i, j, m, n, count = 0;
	element *head[MAX];
	for(i=0; i<MAX; i++){
		arr[i] = (int *)malloc(sizeof(int)*MAX);
	}
	printf("Please input the number of row for the first matrix: ");
	scanf("%d", &m);
	printf("Please input the number of col for the first matrix: ");
	scanf("%d", &n);
	for(i=0; i<n; i++){
		head[i] = (element *)malloc(sizeof(element)*MAX);
	}
	printf("Input the value per rows:\n");
	for(i=0; i<m; i++){
		for(j=0; j<n; j++){
			scanf("%d", &arr[i][j]);
			count++;	
		}
	}
	for(i=0; i<m; i++){
		head[i] = makenode(i, n, n);
		for(j=0; j<n; j++){
			head[i] = insert(head[i], i, j, arr[i][j]);
		}
	}
	
	transpose(head, m, n);
	
	getchar();
	getchar();
	return 0;
}


