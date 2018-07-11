//查找整数

/*
问题描述

给出一个包含n个整数的数列，问整数a在数列中的第一次出现是第几个。



输入格式

第一行包含一个整数n，1<=n<=1000。
第二行包含n个非负整数，为给定的数列，数列中的每个数都不大于10000。
第三行包含一个整数a，为待查找的数。


输出格式

如果a在数列中出现了，输出它第一次出现的位置(位置从1开始编号)，否则输出-1。


样例输入

6
1 9 4 8 3 9
9


样例输出

2
*/

// score:100
#include "stdio.h"
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	int n, s;
	int *list;
	int i;

	scanf("%d", &n);
	list = (int*)malloc(n * sizeof(int));
	for (i = 0; i < n; i++) {
		scanf("%d", &list[i]);
	}
	scanf("%d", &s);

	for (i = 0; i < n; i++) {
		if (list[i] == s) {
			printf("%d\n", i + 1);
			return 0;
		}
	}

	printf("-1");
	return 0;
}