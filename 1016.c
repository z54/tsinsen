/*
问题描述
Fred正在考虑在路易斯安那州找一块土地在上面建造他的房子。在调查过程中，他了解到路易斯安那州的陆地正以每年50平方英里的速度缩小，原因是密西西比河对陆地的侵蚀。由于Fred希望他的余生都能居住在这所房子里，所以他需要知道他的土地是否会被河水侵蚀。
Fred做了更多的研究后发现，正在损失的陆地呈现出一个半圆形的形状，这个半圆是以(0,0)为圆心的圆的X轴以上的部分，X轴以下的区域是河水，在第一年开始时这个半圆的面积是0。(如下图所示)

输入格式
第一行是一个正整数表示接下来有多少组数据，以下的每一行代表一组数据，每组数据由两个浮点数组成，以空格隔开，分别代表Fred房子在平面内的坐标X和Y，单位是英里，其中Y>=0。

输出格式
对于每一组输入数据，输出一个整数Z，代表Fred的房子会在第Z年中被河水侵蚀。如果在第Z年结束时Fred的房子正好在半圆的边界上，那么应该算作是在第Z+1年被侵蚀，返回Z+1。每个返回结果占一行。

样例输入
2
1.0 1.0
25.0 0.0

样例输出
1
20
*/

/*
面积s=3.14*r*r/2

次方 pow() 求 x 的 y 次幂（次方），其原型为： double pow(double x, double y);
开方 求1/3次方，double a=pow(8,1.0/3);

第一年 s=3.14*r*r/2=50 r=5.6
第二年 	s=s+=50
		s=3.14*r*r/2 r= 7.98
半径r变化率<1且持续减小

若x，y不在x，y轴上，则弧上点r^2=x^2+y^2

测试数据
5
1 1
4 4
8 8
2 8
6 0
*/

//score:0
#include <stdio.h>
#include <math.h>

float pour(int s)
{
	float r = sqrt(s * 2.0 / 3.14);
	printf("r=%f\n", r);
	return r;
}

int cal(float x, float y)
{
	int z = 1;

	float t = sqrt(x * x + y * y);//预定倾蚀半径
	int s = 50;
	printf("t=%f\n", t);
	while (pour(s) <= t){
		s+=50;
		z++;
		// printf("s=%d z=%d\n", s, z);
	}

	return z;
}

int main(int argc, char const *argv[])
{
	int n;
	float x, y;
	int z;
	scanf ("%d", &n);
	while (n < 0){
		scanf ("%d", &n);
	}
	while (n > 0) {
		scanf ("%f %f", &x, &y);
		if (y < 0){
			continue;
		}
		z = cal(x, y);
		printf("%d\n", z);
		n--;
	}
	
	return 0;
}