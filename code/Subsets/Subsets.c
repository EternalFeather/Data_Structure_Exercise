#include <stdio.h>

void printMainSet (int array[], char ary[], int size){
    int i;
	printf("{ ");
    for (i=1;i<=size;i++)
        printf("%c ", ary[array[i]-1]);
    printf("}.\n");

    return;
}

void printPowerset (char array[], int n){
    
	int t[10],k;
    t[0] = 0;
    k = 0;
	
    while(1){
        if (t[k]<n){
            t[k+1] = t[k] + 1;
            k++;
        }

        else{
            t[k-1]++;
            k--;
        }

        if (k==0)
            break;

        printMainSet(t,array,k);
    }

    return;
}

int main(){
    
    char n[100];
	int j;
	int count = 0;
	while(1){
	printf("please input an array:");
	scanf("%s.\n", n);
	for(j=1;j<100;j++){
		count ++;
		if(n[j] == 0){
			break;
		}
	}
	printf("{ }.\n");
	printPowerset(n, count);
	count = 0;
	getchar();
	}
    return 0;
}
