//Hexadecimal conversion
/*
问题描述
十六进制数是在程序设计时经常要使用到的一种整数的表示方式。
它有0,1,2,3,4,5,6,7,8,9,A,B,C,D,E,F共16个符号，分别表示十进制数的0至15。
十六进制的计数方法是满16进1，所以十进制数16在十六进制中是10，而十进制的17在十六进制中是11，
以此类推，十进制的30在十六进制中是1E。
在这个问题中，你需要将一个十进制在16和255之间的数转换为十六进制数。转换后一定是一个两位的十六进制数。
设原数为a，转换的方法为，令b为a整除16的值，c为a除16的余数。则将b的十六进制表示和c的十六进制表示连接起来就是a的十六进制表示。
其中，整除可以直接用/实现，在C++语言中两个整数的除就是整除的意思，要想表示实数的除需要先将两个数转换成实数类型。
求a除16的余数可以用 a%16 来表示，其中%表示取余的意思。例如 30%16的值为14。
输入格式
输入包含一个整数a，表示要转换的数。16<=a<=255
输出格式
输出这个整数的16进制表示
样例输入
30
样例输出
1E
*/
//将一个十进制在16和255之间的数转换为十六进制数。转换后一定是一个两位的十六进制数。

//score:100
#include<stdio.h>
char conversion();
int main(){
	int d;//Decimal
	int b, c;
	char bc, cc;
	char h[8];
	while(1){
		scanf("%d",&d);
		if(d > 15 && d < 256) {
			break;
		}
		printf("input again\n");
	}
	b = d / 16;
	c = d % 16;
	if(b < 10){
		printf("%d", b);
	} else {
		bc = conversion(b);
		printf("%c", bc);
	}
	if(c < 10){
		printf("%d", c);
	} else {
		cc = conversion(c);
		printf("%c", cc);
	}
	printf("\n");
	return 0;
}
char conversion(t){
	t -= 10;
	switch(t){
		case 0:
		t = 'A';
		break;
		case 1:
		t = 'B';
		break;
		case 2:
		t = 'C';
		break;
		case 3:
		t = 'D';
		break;
		case 4:
		t = 'E';
		break;
		case 5:
		t = 'F';
		break;
	}
	return t;
}
