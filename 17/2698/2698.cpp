#include <stdio.h>
#include <string.h>

int main()
{
int t , k , n;
struct kk{int d , no;}a[101];
int b[101] , p[101];
int i , m , tot , j , x , top , max;

	scanf("%d" , &t);
	while (t --)
	{
		scanf("%d %d" , &k , &n);
		top = 0;
		for (i = 0; i < n; i ++)
		{
			scanf("%d" , &a[i].d);
			x = -1;
			for (j = 0; j < top; j ++)
				if (a[i].d == b[j]) {x = j; break;}
			if (x == -1) {b[top ++] = a[i].d; a[i].no = top -1;}
			else a[i].no = x;
		}
		memset(b , 0 , sizeof(b));
		m = 0; tot = 0;
		for (i = 0; i < n; i ++)
			if (b[a[i].no] == 0)
			{
				tot ++;
				if (m < k) m ++;
				else
				{
					memset(p , 0 , sizeof(p));
					for (j = i + 1; j < n; j ++)
						if ((b[a[j].no] == 1) && (p[a[j].no] == 0)) p[a[j].no] = j;
					max = 0;
					for (j = 0; j < top; j ++)
						if ((b[j] == 1) && (p[j] == 0)) {x = j; break;}
						else if ((b[j] == 1) && (p[j] > max)) {max = p[j]; x = j;}
					b[x] = 0;
				}
				b[a[i].no] = 1;
			}
		printf("%d\n" , tot);
	}
	return 0;
}
