/*
问题描述
       给定n个十六进制正整数(H)，输出它们对应的八进制数(O)。

输入格式
输入的第一行为一个正整数n （1<=n<=10）。
接下来n行，每行一个由0~9、大写字母A~F组成的字符串，表示要转换的十六进制正整数，每个十六进制数长度不超过100000。

输出格式
输出n行，每行为输入对应的八进制正整数。

【注意】
输入的十六进制数不会有前导0，比如012A。
输出的八进制数也不能有前导0。

样例输入
2
39
123ABC

样例输出
71
4435274

【提示】
       先将十六进制数转换成某进制数，再由某进制数转换成八进制。
*/

/*
十六进制转十进制 Hexadecimal conversion decimal
十进制转八进制 Decimal conversion octal
*/
/*
8 - 10 v
F - 17 v
10 - 20 v
111 - 421 v
fff - 7777 v
fffffff -  1777777777
11111111 - 2104210421
*/

// 二维数组赋值失败，详见90,96行，数组同样位置输出不一样

//score:0
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int hcd(char *h);
int dco(int decimal, char *o);
int rvs(char *l, int len); // reversal 反转

int main(int argc, char const *argv[])
{
	int n;
	scanf("%d", &n);

	int i;
	// int i, j;
	int arr_lt = 8; // 初始数组长度

	char temp[100000];
	int temp_lt;

	char **h, **o;
	h = (char **)malloc(n * sizeof(char *)); // 输入库，所有输入的16进制数都作为二维数组中的一行
	o = (char **)malloc(n * sizeof(char *)); // 输出库，8进制
	for (i = 0; i < n; i++) {
		h[i] = (char*)malloc(arr_lt * sizeof(char)); // 初始分配8bit
		o[i] = (char*)malloc(arr_lt * sizeof(char));
	}

	//input
	for (i = 0; i < n; i++) {

		/* 输入暂存数组并测量长度 */
		scanf("%s", temp);
		temp_lt = strlen(temp);
		// printf("length t:%d\n", j);

		while (temp_lt > arr_lt) {
			arr_lt*=2;
			h[i] = (char*)realloc(h[i], arr_lt * sizeof(char));
			o[i] = (char*)realloc(o[i], arr_lt * 2 * sizeof(char));
		}

		h[i] = temp;
		printf("input:h[%d]=%s\n", i, h[i]);
	}

	/*input check*/
	for (i = 0; i < n; i++) {
		// printf("o[i][0]=%c\n", o[i][0]);
		printf("check:h[%d]%s\n", i, h[i]);
	}

	/* conversion */
	for (i = 0; i < n; i++) {
		dco(hcd(h[i]), o[i]);
	}

	/* print */
	for (i = 0; i < n; i++) {
		// printf("o[i][0]=%c\n", o[i][0]);
		printf("%s\n", o[i]);
	}
	return 0;
}

int hcd(char *h)
{

	int i, j;
	int decimal = 0;

	for (i = strlen(h) - 1, j = 0; i >= 0; i--) {

		if (h[i] < 65) { // 0 ~ 9 48 ~ 57 0 ~ 9
			decimal += ((h[i] - 48) * pow(16, j));
		} else { // A ~ F 65 ~ 70 10 ~ 15
			decimal += ((h[i] - 87) * pow(16, j));
		}

		j++;
	}

	return decimal;
}

int dco(int decimal, char *o)
{
	printf("dco:decimal=%d\n", decimal);
	int d = decimal;
	int i = 0;

	o[0] = d % 8 + 48;
	// printf("o[0] = %c\n", o[0]);
	d /= 8;
	if (d > 0) {
		for (i = 1; d > 0; i++) {

			o[i] = d % 8 + 48;
			// printf("o[%d] = %c\n", i, o[i]);
			d /= 8;
		}
		rvs(o, i);
	} else {
		o[1] = '\0';
	}

	return 0;
}

int rvs(char *l, int len) // reversal 反转
{
	// printf("rvs %s\n", l);
	int i;
	char t;
	for (i = 0; i < len / 2; i++) { // 2/2=1 8/2=4 9/2=4 10/2=5
		// 012345
		// 71
		// 17
		// printf("i=%d\n",i);
		t = l[i];
		// printf("1 %c\n", l[i]);
		l[i] = l[len - i - 1];
		// printf("2 %c len - i - 1=%d\n", l[i], len - i - 1);
		l[len - i - 1] = t;
	}
	l[len] = '\0';

	return 0;
}
