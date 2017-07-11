#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TRUE 1
#define FALSE 0
#define MAX 100

int start_i;
int start_j;
int end_i;
int end_j;
int non_zero_element_count;
int e;
int f;

typedef struct{
	short int vert;
	short int horiz;
}offsets;
offsets move[8];

void InitMove(offsets *mov){
	mov[0].vert=-1;
	mov[0].horiz=0;
  	mov[1].vert=-1;
	mov[1].horiz=1;
  	mov[2].vert=0; 
	mov[2].horiz=1;
  	mov[3].vert=1;
	mov[3].horiz=1;
  	mov[4].vert=1;
	mov[4].horiz=0;
  	mov[5].vert=1;
	mov[5].horiz=-1;
  	mov[6].vert=0;
	mov[6].horiz=-1;
  	mov[7].vert=-1;
	mov[7].horiz=-1;
}

typedef struct{
	short int row;
	short int col;
	short int dir;
}element;

element stack[MAX];

void push(int *top, element item){
	if(*top >= MAX - 1){
		printf("The stack is full!\n");
		return;
	}
	stack[++ *top]=item;
}

element pop(int *top){
	
  if(*top == -1)
  {
   printf("The stack is empty!\n");
   exit(1);
  }
   return stack[(*top)--];
}

void next_column(int *current_i, int *current_j, int *line_ended) {
	*current_j = *current_j + 1;
	if (*line_ended) {
		*current_i = *current_i + 1;
	    *current_j = 0;
	    *line_ended = 0;
	}
}

void set_dimensions(FILE *fp) {
	int current_char;
	int current_i = 0;
	int current_j = -1;
	int line_ended = 0;
	while(!feof(fp)) {
		current_char = fgetc(fp);
		switch(current_char) {
			case 's':
			    printf("s");
				next_column(&current_i, &current_j, &line_ended);
				start_i = current_i;
				start_j = current_j;
				non_zero_element_count += 1;
				break;
			case 'd':
			    printf("d");
				next_column(&current_i, &current_j, &line_ended);
				end_i = current_i;
				end_j = current_j;
				non_zero_element_count += 1;
				break;
			case '\n':
			    printf("\n");
				line_ended = 1;
				break;
			case '1':
			    printf("1");
				next_column(&current_i, &current_j, &line_ended);
				break;
			case '0':
			    printf("0");
				next_column(&current_i, &current_j, &line_ended);
				non_zero_element_count += 1;
				break;
			default:
			    break;
		}		
	}
	e = current_i + 1;
	f = current_j + 1;
	printf("\n");
}

void path(int m, int n, char *filename, int start_i, int start_j, int end_i, int end_j)
{
  	int row, col, nextRow, nextCol, dir, found=FALSE;
  	element position;
  	int top = 0;
  	int count = 1;
  	int mark[m+2][n+2];
  	int EXIT_ROW = m;
  	int EXIT_COL = n;
  	stack[0].row = start_i;
  	stack[0].col = start_j;
 	stack[0].dir = 0;
  	InitMove(move);
  	int i = 1;
	int j = 0;
  	FILE *fstream;
	fstream = fopen(filename, "r");
	int maze[m+2][n+2];
	int test[m][n];
	int k = 0;	
	int current_char;
	int p;
	int q;
	for (p = 1; p < m+1; p++) {
		for (q = 1; q < n+1; q++) {
			current_char = fgetc(fstream);
			if (current_char == 's' | current_char == 'd' | current_char == '0') {
				maze[p][q] = 0;
			}
			else {
				maze[p][q] = 1;
			}
		}
		fscanf(fstream, "\n");
	}
	fclose(fstream);
	
	for(i=0;i<m+2;i++){
		for(j=0;j<n+2;j++){
			maze[0][j]=1;
  			maze[i][0]=1; 
  			maze[m+1][j]=1;
  			maze[i][n+1]=1; 
		}
	}
	
	maze[end_i][end_j] = 4;
	maze[start_i][start_j] = 5;
	
	for(i=0;i<m+2;i++){
		for(j=0;j<n+2;j++){
			mark[i][j] = maze[i][j];
		}
	}
	
  	
    while(top > -1 && !found){ 
     	position=pop(&top);
     	row = position.row; 
     	col = position.col; 
     	dir = position.dir;
     	mark[row+move[dir-1].vert][col+move[dir-1].horiz] = 0;
		count--;
		
    	while(dir < 8 && !found){
       		nextRow = row + move[dir].vert;
       		nextCol = col + move[dir].horiz;
       		if(nextCol==end_i && nextRow==end_j){
      			found = TRUE;
      			count++;
      		}
      		else if(!maze[nextRow][nextCol] && !mark[nextRow][nextCol]){
            	mark[nextRow][nextCol] = 3;
            	count++;
            	position.row = row;
            	position.col = col;
            	position.dir = ++dir;
            	push(&top , position);
            	row = nextRow;
            	col = nextCol;
            	dir = 0;
     		}
      		else ++dir;
    	}
	}
	FILE *wr;
	wr = fopen("output.txt", "w");
  	if(found){
		printf("successful!\n");
		mark[start_i][start_j] = 5;
		mark[end_i][end_j] = 4;
		for(i=1;i<m+1;i++){
			for(j=1;j<n+1;j++){
				test[i-1][j-1] = mark[i][j];
			}
		}
		int k = 0;
		int l = 0;
		while(k < m) {
			switch(test[k][l]) {
				case 5:
			    	printf("s");
			    	fprintf(wr, "s");
					break;
				case 4:
			    	printf("d");
			    	fprintf(wr, "d");
					break;
				case '\n':
			    	printf("\n");
					break;
				case 1:
			    	printf("1");
			    	fprintf(wr, "%d", 1);
					break;
				case 0:
			    	printf("0");
			    	fprintf(wr, "%d", 0);
					break;
				case 3:
					printf("*");
					fprintf(wr, "*");
					break;
				default:
			    	break;
			}
			l++;
			if (l == n){
				printf("\n");
				fprintf(wr, "\n");
				l = 0;
				k++;
			}
		}
		printf("Total %d steps", count);
		fprintf(wr, "Total %d steps", count);
  	}
  	else{
    	printf("The maze does not have a path!");
    	fprintf(wr, "The maze dose not have a path!");
	}
    fclose(wr);
}

int main(){
	
	FILE *fp;
	char filename[50];
	printf("Please input the maze file name(need .txt followed):");
	scanf("%s", &filename);
	fp = fopen(filename, "r");
	int m,n;
	int lineCnt = 0;
	char c[100];
	while (fgets(c, 100, fp))
        lineCnt++;
    fclose(fp);
	m = lineCnt;
	n = strlen(c);
	
	FILE *fstream;
	fstream = fopen(filename, "r");
	set_dimensions(fstream);
	fclose(fp);
	start_i++;
	start_j++;
	end_i++;
	end_j++;
	path(m, n, filename, start_i, start_j, end_i, end_j);
	
	getchar();
	getchar();
	return 0;
}




