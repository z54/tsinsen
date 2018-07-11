
/*
问题描述
给出n个数，找出这n个数的最大值，最小值，和。
输入格式
第一行为整数n，表示数的个数。(1<=n<=10000)
第二行有n个数，为给定的n个数，每个数的绝对值都小于10000。
输出格式
输出三行，每行一个整数。第一行表示这些数中的最大值，第二行表示这些数中的最小值，第三行表示这些数的和。
样例输入
5
100 40 -30 30 1
样例输出
100
-30
141
*/

//score:100
#include<stdio.h>
int main(){
	
	int i;
	int n;//n个数
	int min, max, s = 0;//最小值，最大值，n个数的和

	while (1) {//输入n并判断合法性
		scanf ("%d", &n);
		if (n > 0 && n < 10001)
			break;
}
	
	int l[n];//n个数的数列
	while (1) {//输入数组判断合法性	
		for (i = 0; i < n; i++) {//输入
			scanf ("%d", &l[i]);
			if (l[i] < -10000 && l[i] > 10000) {
//				printf("v wrong input\ntry again\n");
				break;			
			}
		}
		if (i == n ) {
			break;
		}
	}
	
	min = max = l[0];
	
	for (i = 0; i < n; i++) {
		if (l[i] < min)
			min = l[i];
		if (l[i] > max)
			max = l[i];
		s += l[i];
	}
	printf("%d\n%d\n%d\n", max, min, s);
	
	return 0;
}