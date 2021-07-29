#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
int isend(int a[3][3])//棋局未结束返回2，玩家A胜返回1，玩家B胜返回-1，平局返回0
{
	for (int i = 0; i < 3; i++)
	{
		int t = a[i][0];
		for (int j = 0, k = 3; j < 3; j++)
		{
			if (a[i][j] == t)
				k--;
			if (k == 0 && t != 0)
				return t;
		}
	}
	//行胜利
	for (int i = 0; i < 3; i++)
	{
		int t = a[0][i];
		for (int j = 0, k = 3; j < 3; j++)
		{
			if (a[j][i] == t)
				k--;
			if (k == 0 && t != 0)
				return t;
		}
	}
	//列胜利
	int k = 3, t = a[0][0];
	for (int i = 0, j = 0; i < 3; i++, j++)
	{
		if (a[i][j] == t)
			k--;
		if (k == 0 && t != 0)
			return t;
	}
	k = 3, t = a[0][2];
	for (int i = 0, j = 2; i < 3; i++, j--)
	{
		if (a[i][j] == t)
			k--;
		if (k == 0 && t != 0)
			return t;
	}
	//X胜利
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
		{
			if (a[i][j] == 0)
				return 2;
		}
	//平局
	return 0;
}
/*下面是AI算法*/
struct point//AI函数返回两个值：X，Y
{
	int x;
	int y;
};
struct leaf//决策树节点
{
	int pob;
	int all;
	/* （pob/all） 表示获胜几率 */
	bool tra;//不败判定
};
void load(int b[3][3], int a[3][3])//辅助函数
{
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			b[i][j] = a[i][j];
}
int che(int R)//辅助函数
{
	if (R == 1)
		return -1;
	else if (R == -1)
		return 1;
}
void isone(int b[3][3], int R)//辅助函数
{
	int ii, jj, kk = 0, iii, jjj;
	for (ii = 0; ii < 3; ii++)
	{
		for (jj = 0; jj < 3; jj++)
			if (b[ii][jj] == 0)
			{
				kk++;
				iii = ii;
				jjj = jj;
			}
	}
	if (kk == 1)
		b[iii][jjj] = che(R);
}
/*下面是真 * AI算法*/
struct point* AI(int a[3][3], int R)//通过决策树返回 X Y 坐标
{
	void load(int b[3][3], int a[3][3]);
	int che(int R);
	struct leaf* tree(int a[3][3], int R);
	int b[3][3];
	float k = -1;
	struct point* dec = (struct point*)malloc(sizeof(struct point));
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			if (a[i][j] == 0)
			{
				dec->x = i;
				dec->y = j;
				break;
			}
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
		{
			load(b, a);
			if (b[i][j] == 0)
			{
				b[i][j] = R;
				struct leaf L = *tree(b, che(R));
				if (L.tra)
				{
					float t = (float)L.pob / L.all;
					if (t > k)
					{
						k = t;
						dec->x = i;
						dec->y = j;
					}
				}
			}
		}
	return dec;
}
struct leaf* tree(int a[3][3], int R)//递归方法生成决策树
{
	int isend(int a[3][3]);
	void load(int b[3][3], int a[3][3]);
	int che(int R);
	void isone(int b[3][3], int R);
	struct leaf* k = (struct leaf*)malloc(sizeof(struct leaf));
	struct leaf* p = (struct leaf*)malloc(sizeof(struct leaf));
	k->all = 0; k->pob = 0;
	if (R == -1)
		k->tra = true;
	if (R == 1)
		k->tra = false;
	int b[3][3];
	int t = isend(a);
	if (t == 2)
	{
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
			{
				load(b, a);
				if (b[i][j] == 0)
				{
					b[i][j] = R;
					if (isend(b) == 2)
						isone(b, R);
					p = tree(b, che(R));
					k->pob = k->pob + p->pob;
					k->all = k->all + p->all;
					if (R == -1 && p->tra == false)
						k->tra = false;
					if (R == 1 && p->tra == true)
						k->tra = true;
				}
			}
	}
	else
	{
		switch (t)
		{
		case 1:
			k->pob = 2;
			k->tra = true;
			break;
		case -1:
			k->pob = 0;
			k->tra = false;
			break;
		case 0:
			k->pob = 1;
			k->tra = true;
			break;
		}
		k->all = 2;
	}
	return k;
}