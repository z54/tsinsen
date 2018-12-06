#include <stdio.h>
#include <string.h>
#include <math.h>

int print_int_array(int *x, int n)
{
	int i;
	printf("print array start\n\t");
	for (i = 0; i < n; i++)
	{
		printf("%d\t", x[i]);
	}
	printf("\nprint array end\n");
	return 0;
}

int hcd(char *h) // Hexadecimal conversion decimal
{

	int i, j;
	int decimal = 0;

	for (i = strlen(h) - 1, j = 0; i >= 0; i--) {

		if (h[i] < 65) { // 0 ~ 9 48 ~ 57 0 ~ 9
			decimal += ((h[i] - 48) * pow(16, j));
		} else { // A ~ F 65 ~ 70 10 ~ 15
			decimal += ((h[i] - 55) * pow(16, j));
			//decimal += ((h[i] - 87) * pow(16, j));
		}

		j++;
	}

	return decimal;
}

int dco(int decimal, char *o) // Decimal conversion octal
{
	// printf("dco:decimal=%d\n", decimal);
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

int rvs(char *l, int len) // reversal 反转,将倒序数组摆成正序
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