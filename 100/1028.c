/*
问题描述
输入三个整数x，y，z。
根据z的值的不同对x和y进行计算：
z=1：输出x+y的值;
z=2：输出x-y的值;
z=3：输出x*y的值;
z=4：输出x/y的值（若除不尽取整数部分）;
z=5：输出x%y的值
z=6：输出x和y的最大公约数
z=7：输出x和y的最小公倍数 
 
输入格式
只有一行，包括三个整数，x,y,z，其中2<=x,y<=200，1<=z<=7，相邻的两个数之间用空格符隔开。
 
输出格式
只有一个数，表示计算后的值
 
样例输入
100 80 6
 
样例输出
20
*/


#include <stdio.h>
#include <string.h>

int cal_divisor(int x, int y, int flag)
{
	int pn[] = {2, 3, 5, 7, 11, 13, 17, 19};//Prime number
	int i, gcd = 1, d;//Divisor

	if (x == y){
		return x;
	} else if (x > y){
		return cal_divisor(y, x, flag);
	} else {
		/*
		2 | 100 80
		2 | 50 40
		5 | 25 20
		  | 5 4
		2*2*5=20
		*/
		
		for (i = 0, d = pn[0]; i < sizeof(pn) / 4;i++, d = pn[i]){
			// printf("1 i=%d d=%d x=%d y=%d r=%d\n", i, d, x, y, gcd);
			while (x % d == 0 && y % d == 0){
				// printf("2 i=%d d=%d x=%d y=%d r=%d\n", i, d, x, y, gcd);
				x /= d;
				y /= d;
				gcd *= d;				
				// printf("3 i=%d d=%d x=%d y=%d r=%d\n", i, d, x, y, gcd);
			}
		}
	}
	if (flag == 1)
		return gcd;
	else 
		return x * y * gcd;

}


int cal_gcd(int x, int y) //Greatest Common Divisor
{
	return cal_divisor(x, y, 1);
}

int cal_lcm(int x, int y) //Least Common Multiple
{
	return cal_divisor(x, y, 2);
}

int main(int argc, char const *argv[])
{
	int x, y, z;
	scanf("%d %d %d", &x, &y, &z); //2<=x,y<=200，1<=z<=7

	switch (z){
		case 1:
		printf("%d\n", x+y); break;
		case 2:
		printf("%d\n", x-y); break;
		case 3:
		printf("%d\n", x*y); break;
		case 4:
		printf("%d\n", x/y); break;
		case 5:
		printf("%d\n", x%y); break;
		case 6: //Greatest Common Divisor
		printf("%d\n", cal_gcd(x, y)); break;
		case 7: //Least Common Multiple
		printf("%d\n", cal_lcm(x, y)); break;

	}
	return 0;
}