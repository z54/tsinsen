/*
NOIP1996 普及组
【问题描述】
编制一个乘法运算的程序。
从键盘读入2个100以内的正整数，进行乘法运算并以竖式输出。
【输入】
输入只有一行，是两个用空格隔开的数字，均在1~99之间（含1和99）。
【输出】
输出4行或7行，符合乘法的竖式运算格式。
【输入样例1】
89 13
【输出样例1】
  89
* 13
----
 267
 89
----
1157

【输入输出样例1解释】
3×89=267，则第四行267右侧对准个位输出。1×89=89，则第五行89右侧对准十位输出。267+890=1157，则1157右侧对准个位输出。
【输入样例2】
16 8
【输出样例2】
  16
*  8
----
 128
【输入输出样例2解释】
8×16=128，则第四行128右侧对准个位输出。计算完成，不再输出。
*/

/*
输入两数，保存较长的数字的长度到 lt
第一次a乘b的个位，第二次a乘b的十位，依次，将结果保存到动态数组li中
将li中的所有元素相加
*/

/* solved
1 2
10 12
89 13
16 8
99 99

*/
/**/

#include <stdio.h>
#include <stdlib.h>

int step_process(int a, int b, int pl, int li[]);
int p_out(int a, int b, int pl, int li[], int bl, int p);
int prt_tab(int a, int pl, int f);
int draw_line(int bl);

int main(int argc, char const *argv[])
{
	int a, b;
	int p, pl = 0; // product length
	int bl;
	int i;

	int *li;
	li = (int *)malloc(sizeof(int));

	scanf("%d %d", &a, &b);
	p = a * b;
	i = p;
	while (i) {
		pl++;
		i /= 10;
	}

	bl = step_process(a, b, pl, li);
	p_out(a, b, pl, li, bl, p);

	return 0;
}

int step_process(int a, int b, int pl, int li[])
{
	int bl = 0, *bli, bt;
	int i, j;

	bli = (int *)malloc(sizeof(int));

	i = b;
	while (i) {
		bl++;
		i /= 10;
	}

	i = 0, j = 10, bt = b;
	while (bt) {
		bt /= j;
		bli[i] = b - bt * j;
		while (bli[i] > 10){
			bli[i] /= 10;
		}
		bt *= j;
		i++;
		j *= 10;
	}
	/*
	b = 12,
		b/10=1, bli=12-1*10=2, bt=10
		b/100=0, bli=10-0*100=10, bt=0

	b = 123,
		b/10=12, bli=123-12*10=3 , bt=120
		bt/100=1, bli=120-1*100=23, bt=100
		bt/1000=0, bli=100-0*1000=100, bt=0
	*/

	for (i = 0; i < bl; i++) {
		li[i] = a * bli[i];
	}

	// printf("prt bli\n");
	// for (i = 0; i < bl; i++) {
	// 	printf("%d\n", bli[i]);
	// }
	// printf("prt bli\n");

	return bl;
}

int p_out(int a, int b, int pl, int li[], int bl, int p)
{
	int i, j, k;

	prt_tab(a, pl, 0);
	printf("%d\n", a);

	prt_tab(b, pl, 1);
	printf("%d\n", b);

	draw_line(pl);

	if (bl > 1) {
		for (i = 0; i < bl; i++) {
			k = 0;
			j = li[i];
			while (j){
				j /= 10;
				k++;
			}
			if (pl < 4){
				printf(" ");
			}
			while (pl - k - i > 0){
				printf(" ");
				k++;
			}
			printf("%d\n", li[i]);
		}
		draw_line(pl);
	}
	prt_tab(p, pl, 0);
	printf("%d\n", p);
	return 0;
}

int prt_tab(int a, int pl, int f)
{
	int i = 0, t;

	t = a;
	while (t) {
		t /= 10;
		i++;
	}
	if (f == 1) {
		printf("*");
		while (pl - i - 1 > 0){
			printf(" ");
			i++;
		}
	} else {
		while (pl - i > 0){
			printf(" ");
			i++;
		}
		if (pl < 2){
			printf(" ");
		}
	}
	if (pl < 3){
		printf(" ");
	}
	if (pl < 4){
		printf(" ");
	}

	return 0;
}

int draw_line(int pl)
{
	int i;
	printf("----");
	if (pl > 4){
		for (i = 0; i < pl - 4; i++){
			printf("-");
		}
	}
	/*
	bl=5, i
	*/
	printf("\n");
	return 0;
}
