//A1019. 枚举字串
/*问题描述

如果一个单词只使用A、B、C、D四个字符，当长度为2时它有16种可能：
AA
AB
AC
AD
BA
BB
BC
BD
CA
CB
CC
CD
DA
DB
DC
DD
请按字典的顺序将长度为4的所有单词输出。


输出格式

按字典序每行输出一个单词。输出的前几行应该为：
AAAA
AAAB
AAAC
AAAD
AABA
AABB
AABC*/

//score:100
#include "stdio.h"

int sub(int i) {
	char s;
	s = (char)i;
	switch (s + 48) {
	case '1':
		printf("A");
		break;
	case '2':
		printf("B");
		break;
	case '3':
		printf("C");
		break;
	case '4':
		printf("D");
		break;
	default:
		printf("X");
		break;
	}

	return 0;
}

int main(int argc, char const *argv[])
{
	int i1, i2, i3, i4;

	for (i1 = 0; i1 < 4; i1++) {
		for (i2 = 0; i2 < 4; i2++) {
			for (i3 = 0; i3 < 4; i3++) {
				for (i4 = 0; i4 < 4; i4++) {
					sub(i1 + 1);
					sub(i2 + 1);
					sub(i3 + 1);
					sub(i4 + 1);
					printf("\n");
				}
			}
		}
	}

	return 0;
}