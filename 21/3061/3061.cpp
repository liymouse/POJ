#include <stdio.h>
#include <string.h>

int main()
{
int n , s , i , ans , sum , head , tail;
int x[100010];
int testn;

	scanf("%d" , &testn);
	while (testn --)
	{
		scanf("%d %d" , &n , &s);
		memset(x , 0 , sizeof(x));
		for (i = 1; i <= n; i ++) scanf("%d",&x[i]);
		ans = n + 1; sum = 0; head = 0; tail = 0;
		while (head < n)
		{
			sum -= x[head]; head ++;
			while (sum < s && tail < n) 
			{
				tail ++;
				sum += x[tail];
			}
			if (sum >= s && tail - head + 1 < ans) ans=tail-head+1;
		}
		if (ans == 0) ans = 1; else if (ans == n + 1) ans = 0;
		printf("%d\n" , ans);
	}
	return 0;
}
