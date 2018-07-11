/*


*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
    int n;
    int *p, *q;
    int i, j, k = 1, m;

    scanf("%d", &n);

    p = (int*)malloc(n * sizeof(int*));
    q = (int*)malloc(n * sizeof(int*));

    for (i = 0; i < n; i++) {
        p[i] = 0;
        q[i] = 0;
    }
    // for (i = 0; i < n; i++) {
    //     printf("%d", p[i]);
    // }
    // printf("\n");
    // for (i = 0; i < n; i++) {
    //     printf("%d", q[i]);
    // }printf("\n");

    if (n == 1){
        printf("1\n");
    } else if (n > 1){
        p[0] = 1;
/*      01234
        1
        11
        121
        1331
        14641 */
        for (i = 0; i < n; i++) { // n行

            for (j = 0; j < i + 1; j++) { // 第i行有i+1个,0行1个，1行2个

                if (j == 0 || j == k){ // 行首行末均为1
                    q[j] = 1;
                } else {
                    q[j] = p[j/2] + p[j/2+1];
                    // printf("\nq[%d] = p[%d] + p[%d];--%d = %d + %d\n", j, j/2, j/2+1, q[j], p[j/2], p[j/2+1]);
                    /*
                   -0 0 0
                    1 0 1
                    2 1 2
                    3 1 2
                    4 2 3
                    */
                }
                printf("%d ", q[j]);

            }
            for (m = 0; m < k; m++) {
                printf("%d\n", q[m]);
            }
            printf("\n");
            for (m = 0; m < k; m++) {
                printf("%d\n", q[m]);
            }
            printf("\n");
            for (m = 0; m < k; m++) {
                p[m] = q[m];
            }
            k = j;

            printf("\n");


        }
    }

    return 0;
}
