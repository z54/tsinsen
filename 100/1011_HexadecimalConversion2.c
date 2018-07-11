//Hexadecimal conversion 2
/*
问题描述
十六进制数是在程序设计时经常要使用到的一种整数的表示方式。它有0,1,2,3,4,5,6,7,8,9,A,B,C,D,E,F共16个符号，分别表示十进制数的0至15。十六进制的计数方法是满16进1，所以十进制数16在十六进制中是10，而十进制的17在十六进制中是11，以此类推，十进制的30在十六进制中是1E。
给出一个非负整数，将它表示成十六进制的形式。
输入格式
输入包含一个非负整数a，表示要转换的数。0<=a<=2147483647
输出格式
输出这个整数的16进制表示
样例输入
30
样例输出
1E
*/
/*
将输入除以16，得到的商保留整数，余数换算为16进制，写入结果的最右一位
将保留的商继续除以16，依此直到商小于16
*/
//score:100
#include<stdio.h>

char conversion(int t);

int exec();

int main()
{
    exec();

    return 0;
}

int exec()
{
    int d;//Decimal
    int s, m = 1;//reSult, reMainder, third alphabet
    char h[8];
    int i = 7, j;

    m = 1, i = 7;
    for (j = 0; j < 8; j++) { //initialize
        h[j] = '0';
    }

    while (1) { //input
    	scanf("%d", &d);
    	if (d >= 0 && d < 2147483648) {
    		break;
    	}
    	//printf("input again\n");
    }

    s = d;

    if(s < 10) { //转换一位数
        //printf("single\n");
        h[7] = '0' + s;
        printf("%c", h[7]);
    } else { //转换多位数
        //printf("mul\n");
        while (s > 0) {
            m = s % 16;
            //printf("m=%d\n",m);
            s = s / 16;
            //printf("s=%d\n",s);
            if(m == 0) {//余数为0直接存入数组
                h[i] = '0';
                //printf("h[%d]=%d\n", i, h[i]);
                i--;
            } else if (m < 10) { //余数为一位数直接存入数组
                h[i] = '0' + m;
                //printf("h[%d]=%d\n", i, h[i]);
                i--;
            } else { //余数为两位数，用子函数变为对应字符再存入数组
                h[i] = conversion(m);
                //printf("h[%d]=%d\n", i, h[i]);
                i--;
            }
        }
        
        /*商s小于10*/
        if (s < 10) {
            h[i] = '0' + s;
        } else {
            h[i] = conversion(s);
            //printf("h[%d]=%d\n", i, h[i]);
        }

        /*Hexadecimal output*/
        for (i = 0; i < 8; i++) {
            if (h[i] != '0') {
                break;
            }
        }
        for (; i < 8; i++) {
            printf("%c", h[i]);
        }
    }

    printf("\n");

    return 0;
}

char conversion(int t)
{
    /*将大于10的余数转化为A等*/
    t -= 10;
    switch (t) {
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
