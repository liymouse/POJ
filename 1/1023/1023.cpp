#include <stdio.h>

int main()
{
int group;
int k;
char s[70];
__int64 n;
int a[64] , i;

	scanf("%d" , &group);
	while (group --)
	{
		scanf("%d\n" , &k);
		scanf("%s" , s);
		scanf("%I64d" , &n);
		if (n < 0)
		{
			n = -n;
			i = 0; while (s[i]) {if (s[i] == 'n') s[i] = 'p'; else s[i] = 'n'; i ++;}
		}
		i = k-1;
		while (i >= 0)
		{
			if (n % 2 == 1)
			{
				a[i] = 1;
				if (s[i] == 'n') n ++; else n --;
			}
			else a[i] = 0;
			n /= 2; i --;
		}
		if (n != 0) printf("Impossible");
		else for (i = 0; i < k; i ++) printf("%d" , a[i]);
		printf("\n");
	}
	return 0;
}