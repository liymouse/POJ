#include <stdio.h>

typedef struct {int s , t; long w;} bian;
int father[500];

void qu(bian a[] , long s , long t)
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

int getfather(int x)
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
int n , h , t;
int i , j;
long k , z , max , x, y;
bian a[50000];

	scanf("%d" , &t);
	for (h = 0; h < t; h ++)
	{
		scanf("%d" , &n);
		k = 0;
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
				max = a[i].w;
			}
		}
		printf("%ld\n" , max);
	}
}
