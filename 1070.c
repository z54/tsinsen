/*
问题描述
给出一个多项式，求出它的k阶导数。
输入格式
第一行为一个整数k，表示要求多项式的k阶导数。
第二行为一个整数n，表示要求导的多项式含有n项。
接下来输入多项式的各个非零项，每一项占一行，含两个整数a、b，表示多项式含有a*x^b这一项，其中b>=0，a不为0。
n,k<=100，结果中的所有系数不会超过int范围。
输出格式
按照书写习惯输出多项式，具体格式请严格参照样例。
样例输入1
1
4
-3 4
4 2
-2 1
7 0
样例输出1
f'(x)=-12*x^3+8*x-2
样例输入2
3
3
1 10
2 50
-3 30
样例输出2
f'''(x)=720*x^7+235200*x^47-73080*x^27
*/

#include <stdio.h>
#include <String.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	int k, n;
	int *a, *b;
	
	int i, j;

	while (1){
		scanf ("%d", &k);
		scanf ("%d", &n);
		if (k <= 100 && n <= 100 && n >= 0 && k > 0){
			break;
		}
	}

	a = (int*)malloc(sizeof(int)*n);
	b = (int*)malloc(sizeof(int)*n);

	while (1){
		for (i = 0; i < n; i++){
			scanf ("%d %d", &a[i], &b[i]);

		}
		if (b >= 0 && a != 0){
			break;
		}
	}
	for (j = 0; j < k; j++){
		for (i = 0; i < n; i++){
			if (b[i] == 0){
				a[i] = 0;
			} else {
				// printf("1.%d,%d\n", a[i],b[i]);
				a[i] = a[i] * b[i];
				b[i] = b[i] - 1;
				// printf("2.%d,%d\n", a[i],b[i]);
			}
		}
	}
	char r[100] = "f"; 
	if (k < 4){
		for (i = 0; i < k; i++){
			strcat (r, "'");
		}
	}
	strcat (r, "(x)=");
	
	char t[10];

	for (i = 0; i < n; i++){
		//已知a!=0,b>=0
		//若a=0，设b=0，则f=0
		//若a=1，设b=0，则f=1
		//若a=1，设b=1，则f=x
		//若a=1，设b=z，则f=x^b
		//若a=z，设b=0，则f=a
		//若a=z，设b=1，则f=ax
		//若a=z，设b=z，则f=ax^b
		if (a[i] == 0){
			// printf("a=0\n");
			if (n == 1)
				strcat (r, "0");
		} else if (a[i] == 1){
			// printf("a=1\n");
			if (b[i] == 0){
				strcat (r, "1");
			} else if (b[i] == 1){
				strcat (r, "x");
			} else {
				strcat (r, "x^");
				sprintf(t, "%d", b[i]);
				strcat (r, t);
			}
		} else {
			// printf("a=z\n");
			if (b[i] == 1){
				// printf("b=1\n");
				sprintf(t, "%d", a[i]);
				strcat (r, t);
				strcat (r, "*x");
			} else if (b[i] == 0){
				// printf("b=0\n");
				sprintf(t, "%d", a[i]);
				strcat (r, t);
			} else if (b[i] < 0){
				// printf("b<0\n");
				strcat (r, "0");
			} else {
				// printf("b=z\n");
				sprintf(t, "%d", a[i]);
				strcat (r, t);
				strcat (r, "*x^");
				sprintf(t, "%d", b[i]);
				strcat (r, t);
			} 
			
		} 

		if (i != n - 1 && a[i+1] > -1 && a[i+1] != 0)
			strcat (r, "+");	
	}
	puts(r);
	return 0;
}