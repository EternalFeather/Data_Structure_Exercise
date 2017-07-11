#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int const MAX = 40; 

int RandomNum(int n, int m){  
    int pos;
	int dis;
    if(m == n){
    	return m;
	}
    else if(m > n){
        pos = n;
        dis = m - n + 1;
        return rand() % dis + pos;
    }
    else{
        pos = m;
        dis = n - m + 1;
        return rand() % dis + pos;
    }
}

int imov[8];
int jmov[8];

void InitalMove(int *imove, int *jmove){
	
	imove[0] = -1;
    jmove[0] = 1;
    imove[1] = 0;
    jmove[1] = 1;
    imove[2] = 1;
    jmove[2] = 1;
    imove[3] = 1;
    jmove[3] = 0;  
    imove[4] = 1;  
    jmove[4] = -1; 
    imove[5] = 0;  
    jmove[5] = -1;
    imove[6] = -1;  
    jmove[6] = -1;
    imove[7] = -1;
    jmove[7] = 1;
}

int WorkOut(int* arr[],int n,int m) { 
	int i;
	int j; 
    for(i=0;i<n;i++)  
    {  
        for(j=0;j<m;j++)  
        {  
            if(!arr[i][j]) 
                return 0;  
        }
    }
    return 1;
} 

void RandomWalk(int *arr[], int n, int m, int ibug, int jbug){
	
	srand((int)time(NULL));
	InitalMove(imov, jmov);
	arr[ibug][jbug]++;
	int i;
	int j;
	int nexti;
	int nextj;
	int count;
	while(1){
		int move = RandomNum(0, 7);
		nexti = ibug + imov[move];
		nextj = jbug + jmov[move];
		while(nexti < 0 || nextj < 0 || nexti > n || nextj > m){
			move = RandomNum(0, 7);
			nexti = ibug + imov[move];
			nextj = jbug + jmov[move];
		}
		arr[nexti][nextj]++;
		ibug = nexti;
		jbug = nextj;
		count++;
		if(WorkOut(arr, n, m)){
			printf("Total of %d steps\n", count);
			for(i=0;i<n;i++){
				for(j=0;j<m;j++){
					printf("%d\t", arr[i][j]);
				}
			printf("\n");
			}
			return;
		}
		if(count > 50000){
			printf("The count of walk has already reached 50000!\n");
			printf("Total of %d steps\n", 50000);
			for(i=0;i<n;i++){
				for(j=0;j<m;j++){
					printf("%d\t", arr[i][j]);
				}
			printf("\n");
			}
			return;
		}
	}
}

int main(){
	int *arr[MAX];
	int i;
	int j;
	for(i=0;i<MAX;i++){
		arr[i] = (int *)malloc(sizeof(int)*MAX);
	}
	for(i=0;i<MAX;i++){
		for(j=0;j<MAX;j++){
			arr[i][j] = 0;
		}
	}
	int n;
	int m;
	int ibug;
	int jbug;
	printf("please input the contents\n");
	printf("Attention:the range limitation is 2<n<=40 and 2<m<=20\n");
	printf("N:");
	scanf("%d", &n);
	printf("M:");
	scanf("%d", &m);
	printf("Initial bug position X:");
	scanf("%d", &ibug);
	printf("Initial bug position Y:");
	scanf("%d", &jbug);
	
	RandomWalk(arr, n, m, ibug, jbug);
	for(i=0;i<MAX;i++){
		free(arr[i]);
	}
	getchar();
	getchar();
	return 0;
}
