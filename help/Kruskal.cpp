//读入顶点数和图的邻接矩阵 ，输出最小生成树的边长总和 
#include <stdio.h>

typedef struct {int s , t; long w;} bian;//储存边，s起点,t终点（对有向图）,w长度 
int father[100];//并查集所要用到的父亲数组 

void qu(bian a[] , long s , long t)  //快速排序 
{
long i , j , x;
bian y;

    i = s; j = t; x = a[(i+j)/2].w;
    while (i <= j)
    {
        while (a[i].w < x) i ++;
        while (a[j].w > x) j --;
        if (i <= j)
        {
            y = a[i]; a[i] = a[j]; a[j] = y;
            i ++; j --;
        }
    }
    if (s < j) qu(a , s , j);
    if (i < t) qu(a , i , t);
}

int getfather(int x)  //找父亲 
{
int f;

	if (father[x] == x) return x;
	else
	{
		f = getfather(father[x]);
		father[x] = f;
		return f;
	}
}

int main()
{
int n;
int i , j;
long k , z , x, y;
double tot;
bian a[15000];

	scanf("%d" , &n);
	k = 0; tot = 0;
	for (i = 0; i < n; i ++)
		for (j = 0; j < n; j ++)
		{
			scanf("%ld" , &z);
			if ((i > j) && (z != 0)) {a[k].w = z; a[k].s = i; a[k].t = j; k ++;}
		}
	qu(a , 0 , k-1);
	for (i = 0; i < n; i ++) father[i] = i;
	for (i = 0; i < k; i ++)
	{
		x = getfather(a[i].s);
		y = getfather(a[i].t);
		if (x != y)
		{
			father[x] = y;
			tot += a[i].w;
		}
	}
	printf("%.0lf\n" , tot);
	return 0;
}
