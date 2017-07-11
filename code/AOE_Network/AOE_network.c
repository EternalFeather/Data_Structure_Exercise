#include <stdio.h>

void ca_ee(int *ee, int n, int d[10][10]){
	int i,j;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(d[i][j] != 0 && ee[i] + d[i][j] > ee[j]){
				ee[j] = ee[i] + d[i][j];
			}
		}
	}	
}

void ca_le(int *le, int *ee, int n, int d[10][10]){
	int i,j;
	int len = n-1;
	le[len] = ee[len];
	for(i=len;i>=0;--i){
		for(j=len;j>=0;--j){
			if(d[i][j] != 0 && le[j] - d[i][j] < le[i]){
				le[i] = le[j] - d[i][j];
			}
		}
	}	
}

void ca_e_l(int *e, int *l, int *ee, int *le, int n, int d[10][10]){
	int i,j,k = 0;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(d[i][j] != 0){
				e[k] = ee[i];
				l[k] = le[j] - d[i][j];
				k++;
			}
		}
	}
}

int main(){
	FILE *fp;
	int i,j,n,count=0,k=1;
	fp = fopen("Sample_input.txt", "r");
	fscanf(fp, "%d", &n);
	fscanf(fp, "\n");
	
	int d[10][10];
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			fscanf(fp, "%d", &d[i][j]);
		}
		fscanf(fp, "\n");
	}
	fclose(fp);
	
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(d[i][j] != 0){
				count++;
			}
		}
	}
	int ee[n],le[n];
	for(i=0;i<n;i++){
		ee[i] = 0;
		le[i] = 99999;
	}
	ca_ee(ee, n, d);
	ca_le(le, ee, n, d);
	
	int e[count],l[count];
	ca_e_l(e, l, ee, le, n, d);
	
	printf("\"act\"\t\"e\"\t\"L\"\t\"L-e\"\t\n");
	for(i=0;i<count;i++){
		printf("a[%d]\t %d\t %d\t %d\t\n", k++, e[i], l[i], l[i]-e[i]);
	}
	
	getchar();
	getchar();
	return 0;
}


