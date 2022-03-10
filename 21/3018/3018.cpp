#include <stdio.h>
#include <algorithm>
#include <string>
using namespace std;

int n , d;
typedef struct
{
	int size[1001];
}Box;
Box a[501];

int cmp(int &x , int &y)
{
	return x < y;
}

int cmp1(Box &x , Box &y)
{
int i;

	for (i = 0; i < d; i ++)
		if (x.size[i] == y.size[i]) continue;
		else if (x.size[i] < y.size[i]) return -1;
		else return 1;
	return 0;
}

void qu(int s , int t)
{
int i , j;
Box x , y;

	i = s; j = t; x = a[(i+j)/2];
	while (i <= j)
	{
		while (cmp1(a[i] , x) < 0) i ++;
		while (cmp1(a[j] , x) > 0) j --;
		if (i <= j)
		{
			y = a[i]; a[i] = a[j]; a[j] = y;
			i ++; j --;
		}
	}
	if (i < t) qu(i , t);
	if (s < j) qu(s , j);
}

int cmp2(Box &x , Box &y)
{
int i , b;

	b = 1;
	for (i = 0; i < d; i ++)
		if (x.size[i] >= y.size[i]) {b = 0; break;}
	if (b) return -1;
	b = 1;
	for (i = 0; i < d; i ++)
		if (x.size[i] <= y.size[i]) {b = 0; break;}
	if (b) return 1;
	return 0;
}

int main()
{
int i , j , max;
int L[501];

	while (scanf("%d %d" , &n , &d) == 2)
	{
		for (i = 0; i <= n; i ++)
		{
			for (j = 0; j < d; j ++)
				scanf("%d" , &a[i].size[j]);
			sort(a[i].size , a[i].size + d , cmp);
		}
		qu(1 , n);
		memset(L , 0 , sizeof(L));
		for (i = 1; i <= n; i ++)
			if (cmp2(a[0] , a[i]) < 0) L[i] = 1;
		for (i = 2; i <= n; i ++)
		{
			max = 0;
			for (j = 1; j < i; j ++)
				if ((L[j] > max) && (cmp2(a[j] , a[i]) < 0))
					max = L[j];
			if (max > 0) L[i] = max + 1;
		}
		max = 0;
		for (i = 1; i <= n; i ++) if (L[i] > max) max = L[i];
		if (max > 0) printf("%d\n" , max);
		else printf("Please look for another gift shop!\n");
	}
	return 0;
}