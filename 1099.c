/*
【问题描述】
 突然有一天，你忘记了今天是星期几，中国人凑吉利，所以你找来了八个人，让他们每人说两句话，第一句为今天星期几，另一句为今天不是星期几，并且两句中一句真，
 一句假。可能第一句是真，也可能第二句是真。最后请你确定今天是星期几，并输出。
【输入格式】
8行，每行是两个星期几的英文单词，用空格分开，星期几的英文不考虑大小写，即可能是大小写夹杂的单词形式（并非只有首字母大写）。
【输出格式】
 一行英文，表示今天星期几，要求是规范的英文单词，即首字母要大写，之后小写
【输入样例】
MONDAY TuEsday
Tuesday Saturday
Wednesday Thursday
Friday Monday
Sunday Sunday
Monday Friday
Monday Thursday
Thursday Tuesday
【输出样例】
 Sunday
【样例说明】
 输入相当于：
 A说：今天是星期一，今天不是星期二
 B说：今天是星期二，今天不是星期六
 C说：今天是星期三，今天不是星期四
 D说：今天是星期五，今天不是星期一
 E说：今天是星期日，今天不是星期日
 F说：今天是星期一，今天不是星期五
 G说：今天是星期一，今天不是星期四
 H说：今天是星期四，今天不是星期二
【数据说明】
 测试数据保证合法，没有多余空格，并且保证只有一种可能答案
*/


/* 特征，第一句是肯定句，第二句是否定句
v 输入存入二维字符数组w[16]，相应英文转化为数字存入整型数组n[16](范围0-6)，并以A w[0]w[1]，B w[2]w[3]方式存储
若第一句为真，则第二句去掉不，若第二句去掉不与第一句相悖，则第一句定为假，第二句定为真
设w[0]为真，找到数组中其他相同项设为真，另一项为假，以此推论，若推论失败则确定w[0]定为假
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int trans_num(char s[], int n[], int loc);
int r_out(char **w, int *n);

int main(int argc, char const *argv[])
{
	//ok
	char **w;
	w = (char **)malloc(16 * sizeof(char *));
	int n[16]={0};
	int r[7]={0};
	int i, j, k, loc = 0;
	int flag; // 0为假，1为真，2为模糊
	int c0, c1;

	for (i = 0; i < 16; i++){
		w[i] = (char *)malloc(10 * sizeof(char)); // 表示星期几的最长字母数为9
	}

	for (i = 0; i < 16; i += 2){
		scanf("%s %s", w[i], w[i + 1]);
		trans_num(w[i], n, loc++);
		trans_num(w[i + 1], n, loc++);
	}

	r_out(w, n);

	// for (k = 0; k < 8; k++) {
		for (i = 1; i < 16; i+=2) {

			r[n[i]] = 0; // 设A的第二句为真
			r[n[i - 1]] = 0; // 则A的第一句为假
			for (j = 0; j < 7; j++) { // 使用非操作,
				if (j != n[i] && j != n[i - 1]){
					r[j] = 2;
				}
			}
			/*
			0123456
			2002222
			*/
			c0 = c1 = 0;
			for (i = 0; i < 7; i++) {
				if (r[i] == 1){
					c1++;
				} else if (r[i] == 0){
					c0++;
				}
			}
			if (c1 > 1){ // 为真数据大于1个则失败
				continue;
			}
			if (c0 == 6){
				break; // 为假数据达到6个则测试完成
			}
			for (i = 2; i < 8; i++) {
				r[n[i]] = 0; // 设b的第二句为真
				r[n[i - 1]] = 0; // 则b的第一句为假
				for (j = 0; j < 7; j++) { // 使用非操作,
					if (j != n[i] && j != n[i - 1]){
						r[j] = 2;
					}
				}

				c0 = c1 = 0;
				for (i = 0; i < 7; i++) {
					if (r[i] == 1){
						c1++;
					} else if (r[i] == 0){
						c0++;
					}
				}
				if (c1 > 1){
					continue;
				}
				if (c0 == 6){
					break;
				}
			}
			/*
			0123456
			2002220
			0123456
			2000000
			*/
		}
	// }






	/*for (i = 0; i < 16; i+=2){
		printf("%d %d\n", n[i], n[i+1]);
	}*/

	//设s[0]为真， f=s[0]
	// flag = s[1];
	// for (i = 3; i < 16; i+=2){
	// 	if (flag == s[i]){
	//
	// 	}
	// }

	r_out(w, n);

	return 0;
}


// int trans_num(char w[], int n[]){
int trans_num(char *w, int n[], int loc){

	int i;

	// trans char to num
	for (i = 0; i < 10; i++){
		if (w[i] >= 'A' && w[i] <= 'Z'){
			w[i] = w[i] + 32;
		}

	}

	//save to int array n
	if (strcmp (w, "sunday") == 0){
		n[loc] = 0;
	} else if (strcmp (w, "monday") == 0){
		n[loc] = 1;
	} else if (strcmp (w, "tuesday") == 0){
		n[loc] = 2;
	} else if (strcmp (w, "wednesday") == 0){
		n[loc] = 3;
	} else if (strcmp (w, "thursday") == 0){
		n[loc] = 4;
	} else if (strcmp (w, "friday") == 0){
		n[loc] = 5;
	} else if (strcmp (w, "saturday") == 0){
		n[loc] = 6;
	}
	// printf("%d\n", n[loc]);
	return 0;
}

int r_out(char **w, int *n){
	int i;
	for (i = 0; i < 16; i++){
		printf("%s\t", w[i]);
	}
	printf("\n");
	for (i = 0; i < 16; i++){
		printf("%d\t", n[i]);
	}
	return 0;
}

// int judge_week(int *n)
// {
// 	int i, j;
// 	for (i = 0; i < count; i++) {
// 		/* code */
// 	}
// 	return i;
// }
