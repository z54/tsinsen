#include<stdio.h>
/*问题描述
153是一个非常特殊的数，它等于它的每位数字的立方和，即153=1*1*1+5*5*5+3*3*3。编程求所有满足这种条件的三位十进制数。


输出格式
按从小到大的顺序输出满足条件的三位十进制数，每个数占一行。
*/

//score:100
int main() {

	int i, u, d, h; //u-unit d-decade h-hundred
	for (i = 100; i < 1000; i++) {
		h = i / 100;
		d = (i - h * 100 ) / 10;
		u = i - h * 100 - d * 10;
		if (h * h * h + d * d * d + u * u * u == i) {
			printf("%d\n", i);
		}
	}
	return 0;
}