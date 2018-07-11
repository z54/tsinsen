/*
问题描述
给出两个整数集合A、B，求出他们的交集、并集以及B在A中的余集。

输入格式
第一行为一个整数n，表示集合A中的元素个数。
第二行有n个互不相同的用空格隔开的整数，表示集合A中的元素。
第三行为一个整数m，表示集合B中的元素个数。
第四行有m个互不相同的用空格隔开的整数，表示集合B中的元素。
集合中的所有元素均为int范围内的整数，n、m<=1000。


输出格式
第一行按从小到大的顺序输出A、B交集中的所有元素。
第二行按从小到大的顺序输出A、B并集中的所有元素。
第三行按从小到大的顺序输出B在A中的余集中的所有元素。


样例输入1
5
1 2 3 4 5
5
2 4 6 8 10


样例输出1
2 4
1 2 3 4 5 6 8 10
1 3 5


样例输入2
4
1 2 3 4
3
5 6 7


样例输出2

1 2 3 4 5 6 7
1 2 3 4
*/

/*
交并余集
排序
*/

#include <stdio.h>
#include <stdlib.h>

int sort();
int intersection(int *a, int *b, int n, int m); // 交集
int iunion(int *a, int *b);						// 并集 union
int complement(int *a, int *b);					// 补集

int main(int argc, char const *argv[])
{
	int n, m;
	int *A, *B;

	scanf("%d", &n);
	scanf("%d", &m);

	A = (int *)malloc(n * sizeof(int *));
	B = (int *)malloc(m * sizeof(int *));

	intersection(A, B, n, m);

	iunion(A, B);

	complement(A, B);

	return 0;
}

int sort(int *l)
{
	return 0;
}

int intersection(int *a, int *b, int n, int m)
{
	int i, j, k = 0, l;
	int *c;

	if (n > m)
	{
		c = (int *)malloc(m * sizeof(int *));
		l = m;
	}
	else
	{
		c = (int *)malloc(n * sizeof(int *));
		l = n;
	}

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			if (a[i] == b[j])
			{
				c[k] = a[i];
				k++;
			}
		}
	}
	sort();
	for (i = 0; i < l; i++)
	{
		printf("%d\t", c[i]);
	}
	return 0;
}

int iunion(int *a, int *b)
{
	return 0;
}

int complement(int *a, int *b)
{
	return 0;
}