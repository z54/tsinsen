#include<stdio.h>
/*
问题描述
1221是一个非常特殊的数，它从左边读和从右边读是一样的，编程求所有这样的四位十进制数。


输出格式
按从小到大的顺序输出满足条件的四位十进制数。
*/
//score:100
int main() {

	int i, k, h, d, u;
	for (i = 1000; i < 10000; i++) { //u-unit d-decade h-hundred k-kilobit
		k = i / 1000;
		h = (i - k * 1000) / 100;
		d = (i - k * 1000 - h * 100 ) / 10;
		u = i - k * 1000 - h * 100 - d * 10;
		if (k == u && h == d) {
			printf("%d\n", i);
		}
	}
	return 0;
}