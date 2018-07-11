// 逻辑没问题，输入数据后，输出与样例不一致

/*
样例输入
4 1.0
1.0 2.0 3.0 4.0
4.0 3.0 2.0 1.0
1 1.0
2 1.0
3 1.0
4 1.0
样例输出
D
2.23
样例输入
4 1.0
1.0 2.0 3.0 4.0
4.0 3.0 2.0 1.0
1 2.0
2 1.0
3 2.0
4 1.0
样例输出
R
3.19
*/

# include <stdio.h>

int main(int argc, char const *argv[]) {

    int n;
    float T;
    float vt1, vt2, vt3, vt4;
    float vr1, vr2, vr3, vr4;
    int Ti;
    float Tts, Trs; // 分段时间， 总时间
    float Li; // 分段路程， 总路程
    int i;

    Tts = Trs = 0;

    scanf ("%d %f", &n, &T);
    scanf ("%f %f %f %f", &vt1, &vt2, &vt3, &vt4);
    scanf ("%f %f %f %f", &vr1, &vr2, &vr3, &vr4);

    for (i = 0; i < n; i++) {
        scanf ("%d %f", &Ti, &Li); // 场地类型， 长度
        switch (Ti) {
            printf("%d\n", Ti);
            case 1:
                Tts += (Li / vt1);
                Trs += (Li / vr1);
                break;
            case 2:
                Tts += Li / vt2;
                Trs += Li / vr2;
                break;
            case 3:
                Tts += Li / vt3;
                Trs += Li / vr3;
                break;
            case 4:
                Tts += Li / vt4;
                Trs += Li / vr4;
                break;
        }
        printf("%f %f\n", Tts, Trs);
    }

    if (Trs < Tts) {
        printf("R\n");
        printf("%.2f\n", Tts);
    } else if (Trs > Tts){
        printf("T\n");
        printf("%.2f\n", Trs);
    } else {
        printf("D\n");
        printf("%.2f\n", Tts);
    }

    return 0;
}
