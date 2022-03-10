#include <stdio.h>

char s[10];
int a[4] , tot , done;
int p[4] = {25 , 10 , 5 , 1};

void find(int x , int num)
{
int i;

	if (num > tot) return;
	else if (num == tot) 
	{
		done = 1;
		for (i = 0; i <= x; i ++) a[i] = 0;
		return;
	}
	if (x == -1) return;
	for (i = 0; i <= a[x]; i ++)
	{
		if (num + i * p[x] <= tot)
		{
			find(x - 1 , num + i * p[x]);
			if (done == 1) {a[x] = i; return;}
		}
		else return;
	}
}

int main()
{
int i;

	while (scanf("%s" , s) == 1)
	{
		tot = 0; i = 0;
		while (s[i] != 0)
		{
			if ((s[i] >= '0') && (s[i] <= '9')) tot = tot * 10 + s[i] - '0';
			i ++;
		}
		for (i = 0; i < 4; i ++) scanf("%d" , &a[i]);
		done = 0;
		find(3 , 0);
		if (done) 
		{
			for (i = 0; i < 3; i++) printf("%d " , a[i]); 
			printf("%d\n" , a[3]);
		}
		else printf("NO EXACT CHANGE\n");
	}
	return 0;
}
