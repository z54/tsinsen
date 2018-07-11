#include<stdio.h>
/*
问题描述
在Windows的控制台环境中，所有的字符都是等宽的，默认情况下窗口中每行有80个字符，每个屏幕有25行，组成了一个字符矩阵。
利用控制台的这个特点，我们可以在控制台上绘制简单的图形。下面给出了一个5*7的图形的例子：
ABCDEFG
BABCDEF
CBABCDE
DCBABCD
EDCBABC
找出这个图形的特点，给出n和m，绘制一个n*m的图形。

输入格式
输入包含两个数n, m，用一个空格分隔。1<=n,m<=24

输出格式
输出与上图类似的一个n*m的图形。

样例输入
5 7

样例输出
ABCDEFG
BABCDEF
CBABCDE
DCBABCD
EDCBABC
*/

//score:100
int main() {

	int n, m;
	scanf("%d %d", &n, &m);

	int a, b = 0, c = m, d = 0, t, i;
	for (i = 0; i < n; i++) {
		for (t = b; t > d; t--) {
			printf("%c", t + 65);
		}
		b++;
		if (b > m) {
			d++;
		}
		for (a = 0; a < c; a++) {
			printf("%c", a + 65);
		}
		c--;
		printf("\n");
	}
	return 0;
}