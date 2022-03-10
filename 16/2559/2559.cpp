#include <stdio.h>

int a[100010] , left[100010] , right[100010];
int main()
{
int n , i;
int top , stack[100000];
__int64 res , s;

	while (scanf("%d" , &n) == 1)
	{
		if (n == 0) break;
		for (i = 1; i <= n; i ++) scanf("%d" , &a[i]);
		a[0] = -1; a[n+1] = -1;
		top = 1; stack[top] = 0;
		for (i = 1; i <= n; i ++)
		{
			while (a[i] <= a[stack[top]]) top --;
			left[i] = stack[top] + 1;
			top ++;
			stack[top] = i;
		}
		top = 1; stack[top] = n + 1;
		for (i = n; i >= 1; i --)
		{
			while (a[i] <= a[stack[top]]) top --;
			right[i] = stack[top] - 1;
			top ++;
			stack[top] = i;
		}
		res = 0;
		for (i = 1; i <= n; i ++)
		{
			s = (__int64)(right[i] - left[i] + 1) * (__int64)a[i];
			if (s > res) res = s;
		}
		printf("%I64d\n" , res);
	}
	return 0;
}