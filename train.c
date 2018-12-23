//train

#include <stdio.h>

int transfer(int ss, int ts, int *rt)
{
	/*	if 直达路线 存在
		所有直达路线存入＊路线
		if 满意 return
	if 一次换乘路线 存在
		选择换乘车站
		（最短总里程，总时间排序，其中时间包括同站换乘等待时间及同地其他交通工具换乘时间）
		选择后所有一次换乘路线存入＊路线
		if 满意 return
	if 二次换乘路线 存在
	if 三次换乘路线 存在
	*/
	int i;
	for(i = 0; i < )
	return 0;
}

int main(int argc, char const *argv[])
{
	/*
	int 起点站，终点站
	int *换乘站
	int *路线

	输入起点站，终点站

	sub（起点站，终点站，＊路线）
	遍历＊路线
	*/

	int StartingStation, Terminalstation;
	int *TransferStation;
	int *route;

	printf("输入起点站，终点站\n");
	scanf("%d %d", &StartingStation, &Terminalstation);

	transfer(StartingStation, Terminalstation, *route);

	return 0;
}