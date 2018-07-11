/*

*/

#include "stdio.h"

int pr(int a)
{

	return a;
}

int cal(int a)
{
	int i = 5, j = 0;
	int p[] = {2, 3, 5, 7, 11, 13, 17, 19};

	if (a < 3){ //1->2, 2->3
		return a + 1;
	}

	while(1){//candidate
		//3->5
		if (a % p[j] == 0){
			i++;
			j = 0;
			continue;
		}
	}

	return b;
}

int main(int argc, char const *argv[])
{
	int a, b;

	scanf("%d", &a);



	printf("%d\n", b);


	return 0;
}