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

element *makenode(int m, int n, int val){
	element *temp = create();
	temp->rows = m;
	temp->cols = n;
	temp->value = val;
	temp->next = NULL;
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

void MultiplyMatrix(element *head1[], element *head2[], int m, int n, int o, int p) {
    int i, j, sums, k=0;
    element *temp, *trans, *out, *row, *col;
    int *result[MAX], *sum[MAX];
    element *head3[MAX];
    for(i=0; i<p; i++){
		head3[i] = (element *)malloc(sizeof(element)*MAX);
	}
    for(i=0; i< MAX; ++i){
		result[i] = (int *)malloc(sizeof(int)*MAX);
		sum[i] = (int *)malloc(sizeof(int)*MAX);
	}
	for (i = 0; i < o; i++) {
		trans = head2[i] -> next;
		j = 0;
		while (trans != NULL) {
			result[j][i] = trans -> value;
			trans = trans -> next;
			j++;
		}
	}
	for (i = 0;i < p;i++){
		head3[i] = makenode(i, p, p); 
		for (j =0;j < o;j++){
			head3[i] = insert(head3[i], i, j, result[i][j]);
		}
	}
	
	if(n != o){
		printf("These two matrices can not be multiply!");
		return 0;
	}
	else{
		for (i=0;i<m;i++){
			for (j=0;j<p;j++){
				sums = 0;
				int count = 0;
				row = head1[i] -> next;
				col = head3[j] -> next;
				while (count < o){
					sums += col -> value * row -> value;
					col = col -> next;
					row = row -> next;
					count++;
				}
			sum[i][j] = sums;
			}
		}
	}
	printf("The result is: \n");
	for(i=0;i<m;i++){
		for(j=0;j<p;j++){
			printf("%d\t", sum[i][j]);
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

int main(){
	int *arr1[MAX], *arr2[MAX];
	int i, j, m, n, o, p, count1, count2 = 0;
	element *head1[MAX];
	element *head2[MAX];
	for(i=0; i<MAX; i++){
		arr1[i] = (int *)malloc(sizeof(int)*MAX);
		arr2[i] = (int *)malloc(sizeof(int)*MAX);
	}
	printf("Please input the number of row for the first matrix: ");
	scanf("%d", &m);
	printf("Please input the number of col for the first matrix: ");
	scanf("%d", &n);
	for(i=0; i<n; i++){
		head1[i] = (element *)malloc(sizeof(element)*MAX);
	}
	printf("Input the value:\n");
	for(i=0; i<m; i++){
		for(j=0; j<n; j++){
			scanf("%d", &arr1[i][j]);
			printf("(%d,%d)\t%d\n", i, j, arr1[i][j]);
			count1++;	
		}
		// printf("%d and %d\n", n, &arr1[i][n-1]);
//		if (&arr1[i][n-1] > 1000000){
//			print("The size of matrix is incorrect!");
//			break;
//		}
	}
	for(i=0; i<m; i++){
		head1[i] = makenode(i, n, n);
		for(j=0; j<n; j++){
			head1[i] = insert(head1[i], i, j, arr1[i][j]);
		}
	}
	
	printf("Please input the number of row for the second matrix: ");
	scanf("%d", &o);
	printf("Please input the number of col for the second matrix: ");
	scanf("%d", &p);
	for(i=0; i<p; i++){
		head2[i] = (element *)malloc(sizeof(element)*MAX);
	}
	printf("Input the value:\n");
	for(i=0; i<o; i++){
		for(j=0; j<p; j++){
			scanf("%d", &arr2[i][j]);
			count2++;
		}
//		if (&arr2[i][p-1] > 1000000){
//			print("The size of matrix is incorrect!");
//			break;
//		}
	}
	for(i=0; i<o; i++){
		head2[i] = makenode(i, p, p);
		for(j=0; j<p; j++){
			head2[i] = insert(head2[i], i, j, arr2[i][j]);
		}
	}
	
	MultiplyMatrix(head1, head2, m, n, o, p);
	getchar();
	getchar();
	return 0;
}


