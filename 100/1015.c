/*
问题描述

杨辉三角形又称Pascal三角形，它的第i+1行是(a+b)i的展开式的系数。
它的一个重要性质是，三角形中的每个数字等于它两肩上的数字相加。
下面给出了杨辉三角形的前4行：
1
1 1
1 2 1
1 3 3 1
给出n，输出它的前n行。 

 

输入格式

输入包含一个数n。1<=n<=34 

 

输出格式

输出杨辉三角形的前n行。(空格的多少不作要求，只要使用单个空格分隔即可。) 

 

样例输入

4 

 

样例输出

1
1 1
1 2 1
1 3 3 1
*/


//score: 100
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) 
{
    int n;
    int *p, *q;
    int i, j, k;

    scanf("%d", &n);

    p = (int*)malloc(n * sizeof(int*));
    q = (int*)malloc(n * sizeof(int*));

    for (i = 0; i < n; i++) {
        p[i] = 0;
        q[i] = 0;
    }

    if (n == 1){
        printf("1\n");
    } else if (n == 2){
        printf("1\n1 1\n");
    } else if (n > 2){
        printf("1\n1 1\n");
        p[0] = 1;
        p[1] = 1;
/*      01234
        1
        11
        121
        1331
        14641 */
        for (i = 2; i < n; i++) { // 第i+1行，此行至多有i+1个数字，其中0和i已确认为1
            q[0] = 1;
            q[i] = 1;
            printf("1 ");
            for (j = 1; j < i; j++) { // 第i行有i+1个,首尾已确定,0行1个，1行2个
                q[j] = p[j-1] + p[j];
                /*
                1-1=0 1-0=1
                2-1=1 2-0=2
                3-1=2 3-0=3
                4-1=3 4-0=4
                */
               printf("%d ", q[j]);
            }
            printf("1\n");  

            //p = q;

            for (k = 0; k < n; k++){
                p[k] = q[k];
            }
        }  
    }

    printf("\n");
    return 0;
}
