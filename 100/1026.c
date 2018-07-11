/*
问题描述
给定一个由小写字母组成的字符串（长度在1至100之间）, 统计各个字母在这个字符串中出现的次数。
输入格式
有一行，表示要统计的字符串
输出格式
有若干行，每行输出一个字符以及它在字符串中出现的次数，中间用一个空格符分隔。 
在输出时注意以下两点： 
1、没有在字符串中出现的字符不要输出 
2、输出的每个字符应按照字母顺序排列 
样例输入
baazza
样例输出
a 3
b 1
z 2 
*/

/*
输入
for遍历字符串，每碰到一个字母在对应n数组相应位置+1
	(a-z 97-122)
*/

#include <stdio.h>
#include <string.h>

int count(char s[], int n[])
{
	int i, j, k, f = 1, length;
	length = strlen(s);
	for (i = 0; i < length; i++){
		f = 1;
		for (k = 0; k < i; k++){
			if (s[k] == s[i]){
				f = 0;
				break;
			}
		}
		if (f == 1){
			for (j = i; j < length; j++){
				if (s[i] == s[j]){
					n[i]++;
				}
			}
		}
	}
	return 0;
}

int sort(char s[], int n[])
{
	int i, j; 
	char t1;
	int t2;

	for (i = 0; i < strlen(s) - 1; i++){
		for (j = i + 1; j < strlen(s); j++){
			if (s[i] > s[j]){
				t1 = s[i];
				s[i] = s[j];
				s[j] = t1;

				t2 = n[i];
				n[i] = n[j];
				n[j] = t2;
			}
		}
	}


	return 0;
}

int output(char s[], int n[])
{
	int i;
	int length = strlen(s);
	for (i = 0; i < length; i++){
		if (n[i] != 0){
			printf("%c %d\n", s[i], n[i]);
		}
	}

	return 0;
}

int main(int argc, char const *argv[])
{
	char s[100] = {0};
	int n[100] = {0};

	int i, f = 1;	
	while (f == 1){
		scanf ("%s", s);
		for (i = 0, f = 0; i < strlen(s); i++){
			if (s[i] > 96 && s[i] < 123){

			} else {
				f = 1;
			}
		}
	}

	count(s, n);

	sort(s, n);

	output(s, n);

	return 0;
}