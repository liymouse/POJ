#include <stdio.h>

int main()
{
char st[20];
int n , s , t , b;

	while (scanf("%d\n" , &n) == 1)
	{
		if (n == 0) return 0;
		s = 1; t = 10; b = 1;
		while (1)
		{
			scanf("%s" , st); scanf("%s" , st);
			if (st[0] == 'o') break;
			if ((st[0] == 'h') && (n <= t)) t = n - 1;
			else if ((st[0] == 'l') && (n >= s)) s = n + 1;
			//else b = 0;
			if (s > t) b = 0;
			scanf("%d\n" , &n);
		}
		if ((n < s) || (n > t)) b = 0;
		if (b == 0) printf("Stan is dishonest\n"); else printf("Stan may be honest\n");
	}
	return 0;
}