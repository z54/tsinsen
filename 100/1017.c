//1017 计算价格
/*问题描述

香蕉3元/斤，橘子2元/斤，葡萄8元/斤。买a斤香蕉、b斤橘子、c斤葡萄，问需要多少钱？



输入格式

输入包括三行，每行一个0至200的整数，分别表示a,b,c。 


输出格式

输出所需要的钱数。 


样例输入

1
2
3 


样例输出

31
*/

/*
香蕉3元/斤
橘子2元/斤
葡萄8元/斤
买a斤香蕉、b斤橘子、c斤葡萄，问需要多少钱
*/

// score:100
#include "stdio.h"

int main(int argc, char const *argv[])
{
	int f1 = 3, f2 = 2, f3 = 8;
	int a, b, c;
	scanf("%d", &a);
	scanf("%d", &b);
	scanf("%d", &c);
	printf("%d\n", a * f1 + b * f2 + c * f3);
	return 0;
}



