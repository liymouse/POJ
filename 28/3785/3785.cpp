#include <stdio.h>
#include <string.h>
int main()
{
	int cas , t;
	char s[1000];
	int a[10];
	scanf("%d" , &cas);
	while (cas --)
	{
		scanf("%d %s" , &t , s);
		int L = strlen(s);
		int k = -1;
		for (int i = L-1; i > 0; i --)
		{
			if (s[i] > s[i-1]) {k = i-1; break;}
		}
		if (k == -1) {printf("%d BIGGEST\n" , t); continue;}
		memset(a , 0 , sizeof(a));
		for (int i = k; i < L; i ++)
			a[s[i]-'0'] ++;
		for (int i = s[k]-'0' + 1; i < 10; i ++)
			if (a[i] > 0)
			{
				a[i] --;
				s[k] = i + '0';
				break;
			}
		int j = k + 1;
		for (int i = 0; i < 10; i ++)
			while (a[i] > 0) { a[i] --; s[j++] = i + '0'; }
		printf("%d %s\n" , t , s);
	}
	return 0;
}
