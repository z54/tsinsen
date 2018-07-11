/*
问题描述
Tom教授正在给研究生讲授一门关于基因的课程，有一件事情让他颇为头疼：
一条染色体上有成千上万个碱基对，它们从0开始编号，到几百万，几千万，甚至上亿。
比如说，在对学生讲解第1234567009号位置上的碱基时，光看着数字是很难准确的念出来的。
所以，他迫切地需要一个系统，然后当他输入12 3456 7009时，会给出相应的念法：
十二亿三千四百五十六万七千零九
用汉语拼音表示为
shi er yi san qian si bai wu shi liu wan qi qian ling jiu
这样他只需要照着念就可以了。
你的任务是帮他设计这样一个系统：给定一个阿拉伯数字串，你帮他按照中文读写的规范转为汉语拼音字串，
相邻的两个音节用一个空格符格开。
注意必须严格按照规范，比如说“10010”读作“yi wan ling yi shi”而不是“yi wan ling shi”，
“100000”读作“shi wan”而不是“yi shi wan”，“2000”读作“er qian”而不是“liang qian”。

输入格式
有一个数字串，数值大小不超过2,000,000,000。

输出格式
是一个由小写英文字母，逗号和空格组成的字符串，表示该数的英文读法。

样例输入
1234567009

样例输出
shi er yi san qian si bai wu shi liu wan qi qian ling jiu
*/
#include "stdio.h"
#include "string.h"

int nssw(char ns[], char nns[], int nslen)//number string switch
{
	int i;

	for (i = 0; i < nslen; i++) {
		nns[10 - i - 1] = ns[nslen - i - 1];
	}

	return 0;
}

int spknum(char c)//speak number
{
	switch (c) {
	case '0':
		printf("ling");
		break;
	case '1':
		printf("yi");
		break;
	case '2':
		printf("er");
		break;
	case '3':
		printf("san");
		break;
	case '4':
		printf("si");
		break;
	case '5':
		printf("wu");
		break;
	case '6':
		printf("liu");
		break;
	case '7':
		printf("qi");
		break;
	case '8':
		printf("ba");
		break;
	case '9':
		printf("jiu");
		break;
	}
	printf(" ");
	return 0;
}

int spkun(int j)
{
	switch (j) {
	case 2:
		printf("shi");
		break;
	case 3:
		printf("bai");
		break;
	case 4:
		printf("qian");
		break;
	}
	printf(" ");
	return 0;
}

int spk(char nns[], int st, int ed, int nslen)//string start, end
{
	int i, j;
	int n;

	j = 10 - st;
	if (j > 8) {
		j -= 8;
	} else if (j > 4) {
		j -= 4;
	}

	for (i = st; i < ed + 1; i++) {
		spknum(nns[i]);
		spkun(j);// speak unit
		j--;
	}

	n = nslen / 4;
	if (n == 2) {
		printf("yi");
	} else if ((nslen - 1 ) / 4  == 1) {
		printf("wan");
	}

	return nslen;
}

int dif(char nns[], int nslen, int n)
{
	int st;

	st = 10 - nslen;//ns = 123, nslen = 3, ns[] = 10, st = 7 = 10 - 3

	// 01 2345 6789
	if (nslen > 8) {
		spk(nns, st, 1, nslen);
		n -= 1;
	} else if (nslen > 4) {
		spk(nns, st, 5, nslen);
		n -= 1;
	} else {
		spk(nns, st, 9, nslen);
	}
	return n;
}

int main(int argc, char const *argv[])
{
	char ns[10], nns[10];//number string, new number string
	int nslen;// number string length
	int n;

	//input
	scanf("%s", ns);

	//cal length and switch location
	nslen = strlen(ns);
	n = (nslen - 1) / 4;
	nssw(ns, nns, nslen);// number string switch

	do {
		n = dif(nns, nslen, n);
	} while (n > 0);

	printf("\n%c %s %c %s\n", ns[0], ns, nns[7], nns);
	return 0;
}