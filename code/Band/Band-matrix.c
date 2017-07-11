#include <stdio.h>

void value(int n, int a, int b, int i, int j, int D[]){
	
	int k=0;
	int m=0;
	int x;
	int y;
	int e[100];
	for(x=a-1;x>=0;x--){
		for(y=x;y<n;y++){
			e[k]=D[y*n+m];
			printf("e[%d]=%d\td(%d,%d)\n", k, e[k], y, m);
			k++;
			m++;
		}
		m=0;
	}
	for(x=1;x<b;x++){
		for(y=x;y<n;y++){
			e[k]=D[m*n+y];
			printf("e[%d]=%d\td(%d,%d)\n", k, e[k], m, y);
			m++;
			k++;
		}
		m=0;
	}
	
	
	return;
} 

int main(){
	
	FILE *fp; 
	char filename[50];
	int n;
	int i = 0;
	int j = 0;
	int a;
	int b;
	int d[100];
	printf("Please input the file name(need .txt followed):");
	scanf("%s", &filename);
	printf("a: ");
	scanf("%d", &a);
	printf("b: "); 
	scanf("%d", &b);
	fp = fopen(filename, "r");
	fscanf(fp, "%d", &n);
	fscanf(fp, "\n");
	
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			fscanf(fp, "%d", &d[i*n+j]);
		}
		fscanf(fp, "\n");
	}
	
	fclose(fp);
	printf("output:\n");
	value(n, a, b, i, j, d);
	
	getchar();
	getchar();
	return 0;
}


