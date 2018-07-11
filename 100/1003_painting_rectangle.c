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
找出这个图形的特点，绘制一个25*18的图形。


输出格式
输出与上图类似的一个25*18的图形。
*/
//score:100
int main() {

	int a, b = 0, c = 18, d = 0, t, i;
	for (i = 0; i < 25; i++) {
		for (t = b; t > d; t--) {
			printf("%c", t + 65);
		}
		b++;
		if (b > 18) {
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