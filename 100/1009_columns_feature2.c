#include<stdio.h>
/*
问题描述
给出n个数，找出这n个数的第二大值，第二小值，平方和。
 
输入格式
第一行为整数n，表示数的个数。(2<=n<=100)
第二行有n个数，为给定的n个数，每个数的绝对值都小于1000。
 
输出格式
输出三行，每行一个整数。
第一行表示这些数中的第二大值，
第二行表示这些数中的第二小值，
第三行表示这些数的平方和。
 
样例输入
5
100 100 -30 30 1
 
样例输出
100
1
21801
*/
//score:100
int main(){
	
	int i, j;
	int n;//n个数
	int s = 0;//最小值，最大值，n个数的和
	int t;
	while (1) {//输入n并判断合法性
		scanf ("%d", &n);
		if (n > 1 && n < 101)
			break;
		/*
 		else
			printf("n wrong input\ntry again\n");
		*/
	}
	
	
	int l[n];//n个数的数列l
	while (1) {//输入数组判断合法性	
		for (i = 0; i < n; i++) {//输入
			scanf ("%d", &l[i]);
			if (l[i] < -999 && l[i] > 999) {
//				printf("v wrong input\ntry again\n");
				break;			
			}
		}
		if (i == n ) {
			break;
		}
	}
	/*
	printf("old\n");
	for (i = 0; i < n; i++){
		printf("%d ", l[i]);
	}
	printf("\n");
	*/
	for (i = 0; i < n; i++){//sort
		for (j = i + 1; j < n; j++){
			if (l[i] > l[j]){
				t = l[i]; l[i] = l[j]; l[j] = t;
			}
		}
	}
	/*
	printf("new\n");
	for (i = 0; i < n; i++){
		printf("%d ", l[i]);
	}
	printf("\n");
	*/
	for (i = 0; i < n; i++) {//这些数的平方和
		s += (l[i]*l[i]);
	}

	// printf("%d\n%d\n%d\n", smax, smin, s);
	printf("%d\n%d\n%d\n", l[n-2], l[1], s);
 	
 	
	return 0;
}