#include <stdio.h>

int iterTest(int n);
int recurTest(int n);

int main()
{
	int n;
	while (n >= 0){ 
	printf("Please enter a number bigger then 0. enter '-1' to end program.\n");
	scanf("%d", &n);
		if(n > 0)
		{
			printf("iterative : %d.\n", iterTest(n));
			printf("recursive : %d.\n", recurTest(n));
		} 
    }
    return 0;
}

int iterTest(int n)
{
	if (n == 1){
		return 1;
	}
	else{
		return n*iterTest(n-1);
	}
}

int recurTest(int n){
	int i;
	int answer = 1;
	for (i=n;i>0;i--){
		answer *= i;
		}
	return answer;
}
