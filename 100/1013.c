/*
【问题描述】
从键盘输入一个不超过8位的正的十六进制数字符串，将它转换为正的十进制数后输出。
注：十六进制数中的10~15分别用大写的英文字母A、B、C、D、E、F表示。
【样例输入】
FFFF
【样例输出】
65535
*/

/*
2AF5 --> 5 * 16^0 + F * 16^1 + A * 16^2 + 2 * 16^3 = 10997
*/

//score:100
#include <stdio.h>
#include <string.h>
#include <math.h>

int main(int argc, char const *argv[])
{
    char h[8];
    double d = 0;
    int i, j = 0;

    gets(h);

    for (i = strlen(h) - 1; i >= 0; i--) {
        if (h[i] < 65) { // 0 ~ 9 48 ~ 57 0 ~ 9
            d += ((h[i] - 48) * pow(16, j));
        } else { // A ~ F 65 ~ 70 10 ~ 15
            d += ((h[i] - 55) * pow(16, j));
        }
        j++;
    }

    printf("%.0lf\n", d);
    return 0;
}
