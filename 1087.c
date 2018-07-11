/*
【问题描述】
输入两个整数a和b，输出这两个整数的和。a和b都不超过100位。
【算法描述】
由于a和b都比较大，所以不能直接使用语言中的标准数据类型来存储。对于这种问题，一般使用数组来处理。
定义一个数组A，A[0]用于存储a的个位，A[1]用于存储a的十位，依此类推。同样可以用一个数组B来存储b。
计算c = a + b的时候，首先将A[0]与B[0]相加，如果有进位产生，则把进位（即和的十位数）存入r，把和的个位数存入C[0]，即C[0]等于(A[0]+B[0])%10。然后计算A[1]与B[1]相加，这时还应将低位进上来的值r也加起来，即C[1]应该是A[1]、B[1]和r三个数的和．如果又有进位产生，则仍可将新的进位存入到r中，和的个位存到C[1]中。依此类推，即可求出C的所有位。
最后将C输出即可。
【输入格式】
输入包括两行，第一行为一个非负整数a，第二行为一个非负整数b。两个整数都不超过100位，两数的最高位都不是0。
【输出格式】
输出一行，表示a + b的值。
【样例输入】
20100122201001221234567890
          2010012220100122
【样例输出】
20100122203011233454668012
*/

/*

*/

#include <stdio.h>
#include <string.h>

/*
位数分两种情况：
	1，a,b位数相同，只考虑进位
	2，a比b位数多或b比a多

步骤（不进位）
		01234
		32100
		26
		62123
	1，定义两个字符数组a,b, 分别存放两个100位数，从数组头开始存储开始顺序存储,如123从0开始存储为123
	结果r[100]逆序存储，如123从0开始存储为321
	2，将a的最后一位（数组长度）和b的最后一位相加，存入r的0位，依次向前，b指针到0结束，得到结果最大为b长度+1的r（+1为进位）
		01234
		   00
		   26
		62
	3，a长度减去b长度即a未相加位数，r当前位直接赋值（当前位为零）
		01234
		321

		  123

步骤（进位）
		01234
		32181
		26
		70223
	1，定义两个字符数组a,b, 分别存放两个100位数，从数组头开始存储开始顺序存储,如123从0开始存储为123
	结果r[100]逆序存储，如123从0开始存储为321
	2，将a的最后一位（数组长度）和b的最后一位相加，存入r的0位，有进位则r[i+1]+1（先做简单进位，不会连续进位），后期再考虑极端情况），
	依次向前，b指针到0结束，得到结果最大为b长度+1的r（+1为进位）
		01234
		   81
		   26
		70
	3，a长度减去b长度即a未相加位数，与r当前位相加（当前位不为零）
		01234
		321
		  1
		  223
	
考虑进位极端情况,一直在进位
	01234
	9999
	1
	00001
测试目标
v	2+3
v	12+23 12345+12344
	12+3
	1+23
*/

int paste(char a[], char r[], int sub, int len_b)//subtraction
{
	/*
	01234
	----
	33333
	12
	----
	54333
	*/

	int i, j;
	int s;
	int l;	
	printf("paste\n");
	for (i = sub - 1, j = len_b; i >= 0 && j <= strlen(a); i--, j++){
		printf("1 r[%d]%c+a[%d]%c\n", j, r[j], i, a[i]);
		s = (int)(a[i]) + 1 - 48;

		if (s > 9){
			s -= 10;
			l = j + 1;
			r[l] = '1';
		}
		printf("\tcarry s=%d j=%d r[%d]=%c\n", s, j, l, r[l]);

		if (r[j] == '1'){
			r[j] = r[j] + s - 48;
		} else {
			r[j] = a[i];
		}
		printf("2 r[%d]%c a[%d]%c\n", j, r[j], i, a[i]);
	}
	return 0;

}

int add(char a[], char b[], char r[])
{
	int i, j;
	int k = 0;// 结果填充当前位
	int l;//进位位置
	int s = 0;//summary, Carrying进位
	
	for (i = strlen (a) - 1, j = strlen (b) - 1; i >= j && j >= 0; i--, j--){		
		
		printf("round %d\na[%d]=%c b[%d]=%c\n%c+%c\n", k, i, a[i], j, b[j], a[i], b[j]);
		//
		s = (int)(a[i]) + (int)(b[j]) - 96;//不进位本位加减
		printf("\ts=%d\n", s);
		if (s > 9){
			s -= 10;
			l = k + 1;
			r[l] = '1';
			printf("\tcarry r[%d]=%c\n", l, r[l]);
			/*while ((int)(r[l]) + 1 > 9){//应对特殊情况连续进位9999+1
				r[++l] += 1;				
			}*/
		}

		/*
		7890
		  22
		7912

		*/
		printf("\tcheck current value %c\n", r[k]);
		
		// r[k] = r[k] + s + c + 48;
		// 当前位计算：原本值 + a当前位 + b当前位
		// 结果数组，低位在前高位在后，如个位最前
		
		if (r[k] == '1'){
			r[k] = r[k] + s + 48 - 48;// 当前位计算，结果数组，个位最前
		} else {
			r[k] = s + 48;
		}
		//
		printf("\tcheck 2 s=%d r[%d]=%c %d\n", s, k, r[k], r[k]);
		puts(r);
		printf("\n");
		k++;
	}	
	
	return 0;
}

int main(int argc, char const *argv[])
{
	char a[100] = {0}, b[100] = {0}, r[100] = {0};
	int len_a, len_b;

	scanf("%s", a);
	scanf("%s", b);
	printf("scan a=%s b=%s\n\n", a, b);

	len_a = strlen(a);
	len_b = strlen(b);

	if (len_a >= len_b){
		add(a, b, r);
		paste(a, r, strlen(a) - strlen(b), strlen(b));
	} else {
		add(b, a, r);
		paste(b, r, strlen(b) - strlen(a), strlen(a));
	}

	/*for (i = strlen(r) - 1; i >= 0; i++){
		printf("%c\n", r[i]);
	}*/
	printf("%s\n",strrev(r));
	puts(r);
	// printf("%s %s\n", a, b);
	// printf("%c %c\n", a[0], b[0]);

	return 0;
}