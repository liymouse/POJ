#include<stdio.h>
#include<string.h>
int h[3010],l[3010],r[3010];

int fun(int n)
{
int i , temp , ans; 
	
	for (int i = 1; i <= n; i ++)
		l[i] = r[i] = i;
	h[0] = -1; h[n+1] = -1;
	for (int i = 1; i <= n; i ++)
		while (h[l[i]-1] >= h[i]) l[i] = l[l[i]-1];
	ans = 0;
	for (int i = n; i >= 1; i --)
	{
		while (h[r[i]+1] >= h[i]) r[i] = r[r[i]+1];
		temp = h[i] * (r[i] - l[i] + 1);
		if (temp > ans) ans = temp;
	}
	return ans;
}
int main()
{
	int n , m , max , x;

	while(scanf("%d %d" , &m , &n) == 2)
	{
		max=0;
		memset(h , 0 , sizeof(h));
		for(int i = 1; i <= m; ++ i)
		{
			int temp;
			for(int j = 1; j <= n; ++ j)
			{
				scanf("%d" , &x); 
				if(x==1) h[j]++;
				else h[j]=0; 
			}
			temp = fun(n);
			if(max < temp) max = temp;
		}
		printf("%d\n" , max);
	}
	return 0;
}
