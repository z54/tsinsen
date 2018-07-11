/*
问题描述
不同的进制数在自然科学中发挥着巨大的作用。人类最早时由于手指是十个所以广泛采用了十进制计数。
在计算机科学中，由于电路一般为开和关两种状态，所以在机器内部都是使用二进制。人们为了方便处理二进制，使用了十六进制、八进制。
其实对于任何大于等于2的正整数p，p进制都存在。
给定一个非负整数a，请将a表示成p进制的形式。
这个问题有一个通用的处理方法，可以使用短除法来完成。它的规则是：除p取余倒数
以将6转换成二进制为例。我们首先将6写下来，然后在它的左边写上2，将6除2的商3写在6下面，余数0写在右边。
然后再对3做同样的操作，直到商变为0为止。如下图所示：

下图中给出了一个将11转换成三进制数的例子：

在p进制数中，有0,1,...,p-1这p个最基本的符号，当p>10时，使用数字无法合理的表示，所以引入A,B,...来表示这些大于等于10的符号，
其中A表示10，B表示11，C表示12，依此类推。

输入格式
输入包含两个非负整数a和p，表示要转换的数和所用的进制。0<=a<=2147483647，2<=p<=36

输出格式
输出整数a的p进制表示

样例输入
30 16

样例输出
1E
*/

/*
2147483647(D)=1111111111111111111111111111111(B)

*/
//score:100
#include <stdio.h>

int exec(int *t, int a, int p)
{
    int s, m;// result, remainder
    int i = 1;

    t[0] = m = a % p;
    s = a / p;

    while (s != 0) {
        t[i] = m = s % p;
        s = s / p;
        //printf("t[%d]=%d\n", i, t[i]);
        i++;
    }

    return 0;
}

int main(int argc, char const *argv[])
{

    int a, p;
    int t[32];// target array
    int i, j;

    for ( i = 0; i < 32; i++)  //initialize
        t[i] = '*';

    while (1) { //input

        scanf("%d %d", &a, &p);

        if (a >= 0 && a < 2147483648 && p > 1 && p < 37)
            break;
    }

    exec( t, a, p);

    for ( i = 0; i < 32; i++) {
        if (t[i] == 42)
            break;
    }

    for ( j = i - 1; j >= 0; j--) {//output
        if ( t[j] < 10) {
            printf("%d", t[j]);
        } else {
            printf("%c", (char)(t[j] + 55));
        }
    }
    return 0;
}