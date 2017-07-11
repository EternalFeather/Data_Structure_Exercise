# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# include <time.h>
#define MAX_ELEMENTS 100

typedef struct{
	int key
} element;
element heap[MAX_ELEMENTS];
int n = 0;

void printHeap(){
	int i, j, k = 1;
	for(i = 1; i <= n; i++){
		j = (int)pow(2, k);
		
		if(i < j){
			printf("%d ", heap[i].key);
		}
		else{
			printf("\n%d ", heap[i].key);
			k++;
		}
	}
}
int heapFull(){
	if(n == MAX_ELEMENTS){
		return 1;
	}
	return 0;
}

void push(element item){
	int i;
	if(heapFull(n)){
		printf("The heap is full.\n");
		return 0;
	}
	i = ++n;
	while(i!=1 && item.key > heap[i/2].key){
		heap[i] = heap[i/2];
		i /= 2;
	}
	heap[i] = item;
}

int searchHeap(int item){
	int i;
	for(i=1;i<=n;i++){
		if(heap[i].key == item){
			return i;
		}
	}
	return 0;
}

void changePriority(int item){
	int pos, newpri, parent, child;
	clock_t begin, end;
	element newitem;
	pos = searchHeap(item);
	if(!(pos)){
		printf("%d is not in the max heap.\n", item);
		return 0;
	}
	else{
		printf("Change priority to:");
		scanf("%d", &newpri);
		begin = clock();
		newitem.key = newpri;
		if(pos!=1 && newitem.key > heap[pos/2].key){
			while(pos!=1 && newitem.key > heap[pos/2].key){
				heap[pos] = heap[pos/2];
				pos /= 2;
			}
			heap[pos] = newitem;
		}
		else{
			parent = pos;
			child = pos * 2;
			printf("%d , %d\n", child, n);
			while(child <= n){
				if(child < n && heap[child].key < heap[child+1].key){
					child++;
				}
				if(newitem.key >= heap[child].key){
					break;
				}
				else{
					heap[parent] = heap[child];
					parent = child;
					child *= 2;
				}
				heap[parent] = newitem;
			}
		}
	}
	Sleep(1); 
	end = clock();
	printf("Max Heap:\n");
	printHeap();
	printf("\nSpend time:%lf sec", (end-begin)/(double)(CLOCKS_PER_SEC));
}

int main(){
	int i, item, k = 2 ,n = 1;
	FILE *fp, *ts;
	char ans, c;
	element result[100];
	fp = fopen("in.txt", "r");
	while(!feof(fp)){
		c = fgetc(fp);
		if(c == ','){
			n++;
		}
	}
	fclose(fp);
	ts = fopen("in.txt", "r");
	printf("Create Max Heap:\n");
	printf("Max Heap:\n");
	
	fscanf(ts, "%d", &result[1].key);
	push(result[1]);
	for(i = 2; i <= n; i++){
		fscanf(ts, ",%d", &result[i].key);
		push(result[i]);
	}
	fclose(ts);
	printHeap();
	while(1){
		printf("\nChange priority?(Y/N):");
		scanf("%s", &ans);
		if (ans == 'N' || ans == 'n') {
			break;
		}
		else{
			printf("Choice priority:");
			scanf("%d", &item);
			changePriority(item);
		}
	}
	
	getchar();
	return 0;
}
