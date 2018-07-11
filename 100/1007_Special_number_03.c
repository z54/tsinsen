
/*
问题描述
123321是一个非常特殊的数，它从左边读和从右边读是一样的。
输入一个正整数n， 编程求所有这样的五位和六位十进制数，满足各位数字之和等于n 。
输入格式
输入一行，包含一个正整数n。

输出格式
按从小到大的顺序输出满足条件的整数，每个整数占一行。

样例输入
52

样例输出
899998
989989
998899
数据规模与约定
1<=n<=54。
*/

//score:100
#include <stdio.h>

int main(){
	int n;
	scanf("%d", &n);
	
		if (n > 0 && n < 55){
			int i, t; 
			int ht, m, k, h, d, u;
			for (i = 10000; i < 1000000; i++){//u-unit d-decade h-hundred k-kilobit m-myriabit ht-hundred thousand
				ht = i / 100000;
				t = i - ht * 100000;
				m = t / 10000;
				t = t - m * 10000;
				k = t / 1000;
				t = t - k * 1000;
				h = t / 100;
				t = t - h * 100;
				d = t / 10;
				u = t - d * 10;
				if (ht + m + k + h + d + u == n){
					if (ht == 0){
						if (m == u && k == d)
							printf("%d\n", i);
					} else {
						if (ht == u && m == d && k== h)
							printf("%d\n", i);
					}
					
				}
			}
		} else {
			printf("wrong input\ntry again\n");
		}

	return 0;
}