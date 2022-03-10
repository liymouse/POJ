#include <stdio.h>
#include <algorithm>
#define MAXSIZE 1000010
using namespace std;


typedef struct
{
	int a , b;
}kk;

kk a[1000010];
int L[1000010],tmp[1000010];
int k;
__int64 tot;

void merge(int s1,int e1,int s2,int e2)
{
	int ls=s1;		
	while (s1<=e1 && s2<=e2)
	{
		if (tmp[s1]<=tmp[s2])
		{
			L[ls]=tmp[s1];
			s1++;
			ls++;
		}
		else
		{
			L[ls]=tmp[s2];
			s2++;
			ls++;
	 		tot += e1 - s1 + 1;
		}
	}
	if (s1>e1)
	{
		for (int i=s2; i<=e2; i++)
		{
			L[ls]=tmp[i];
			ls++;
		}
	}
	else
	if (s2>e2)
	{
		for (int i=s1; i<=e1; i++)
		{
			L[ls]=tmp[i];
			ls++;
		}
	}
}

void msort(int s,int t)
{               
	int m=(s+t)/2;
	int i;	
	if (s==t) tmp[s]=L[s];
	else
	{
		msort(s,m);
		msort(m+1,t);		
		merge(s,m,m+1,t);			
		for (i=s; i<=t; i++) tmp[i]=L[i];
	}
}

int cmp(kk &x , kk &y)
{
	if (x.a == y.a) return x.b < y.b;
	else return x.a < y.a;
}

int main()
{
int t , n , m , i , h;

	scanf("%d" , &t);
	for (h = 1; h <= t; h ++)
	{
		scanf("%d %d %d" , &n , &m , &k);
		for (i = 1; i <= k; i ++)
			scanf("%d %d" , &a[i].a , &a[i].b);
		sort(a + 1 , a + k + 1 , cmp);
		for (i = 1; i <= k; i ++) L[i] = a[i].b;
		tot = 0;
		msort(1,k);
		printf("Test case %d: %I64d\n" , h , tot);
	}
	return 0;
}
