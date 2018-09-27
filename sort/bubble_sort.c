#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    int i, j, t;
    int list[5]= {2,5,3,4,1};
    int length;

    length = strlen(list);
    printf("%d\n", length);
    for (j = 0; j < length - 1; j++) { // 次数
        for (i = 0; i < length - 1 - j; i++) { // 参与排序的数字个数
            if (list[i] > list[i+1]){
                t = list[i];
                list[i] = list[i+1];
                list[i+1] = t;
            }
        }
    }

    for (i = 0; i < 5; i++) {
        printf("%d\t", list[i]);
    }
    printf("\n");

    return 0;
}
