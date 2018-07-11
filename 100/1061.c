/*
问题描述
给定一个正整数n，求它的因子个数。

输入格式
只有一行，为正整数n。其中n<=100000。

输出格式
只有一行，为n的因子个数。

样例输入
6

样例输出
4
*/

#include <stdio.h>

int main(int argc, char const *argv[])
{
	int i;
	int n;
	int r = 1;

	scanf("%d", &n);

	for (i = 2; i < n + 1; i++) {
		if (n % i == 0) {
			r++;
		}
	}

	printf("%d\n", r);

	return 0;
}