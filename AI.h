#pragma once
int isend(int a[3][3]);
struct point//AI函数返回两个值：X，Y
{
	int x;
	int y;
};
struct point* AI(int a[3][3], int R);