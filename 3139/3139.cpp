// 3139.cpp : ¥³¥ó¥½©`¥ë ¥¢¥×¥ê¥±©`¥·¥ç¥ó¤Î¥¨¥ó¥È¥ê ¥Ý¥¤¥ó¥È¤ò¶¨Áx¤·¤Þ¤¹¡£
//

#include "stdafx.h"

#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

int b[16];
vector<int> a[10241];
int us[16];

void dfs(int x , int s)
{
int i , k;

	if (x == 0)
	{
		k = 0;
		for (i = 0; i < 16; i ++)
			if (us[i]) k += (1 << i);
		a[s].push_back(k);
		return;
	}
	for (i = 0; i < 16; i ++)
		if (us[i] == 0)
		{
			us[i] = 1;
			dfs(x - 1 , s + b[i] * x);
			us[i] = 0;
		}
}

int main()
{
int i , j , k , res , cas = 0 , L;
int ba[65536];

	//freopen("3139.in" , "r" , stdin);
	//freopen("3139.out" , "w" , stdout);
	while (scanf("%d" , &b[0]) == 1)
	{
		if (b[0] == 0) break;
		cas ++;
		for (i = 0; i < 10241; i ++) a[i].clear();
		for (i = 1; i < 16; i ++) scanf("%d" , &b[i]);
		memset(us , 0 , sizeof(us));
		//sort(b , b+16);
		dfs(4 , 0);
		memset(ba , 0 , sizeof(ba));
		for (i = 0; i < 10241; i ++)
		{
			L = a[i].size();
			for (j = 0; j < L-1; j ++)
				for (k = j+1; k < L; k ++)
					if ((a[i][j] & a[i][k]) == 0)
						ba[a[i][j] | a[i][k]] ++;
		}
		res = 0;
		for (i = 0; i < 65536; i ++)
			if (ba[i] > 0 && ba[65535 ^ i] > 0)
			{
				res += ba[i] * ba[65535 ^ i];
				ba[i] = 0;
				ba[65535 ^ i] = 0;
			}
		printf("Case %d: %d\n" , cas , res);
	}
	return 0;
}

