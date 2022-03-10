#include <stdio.h>

int main()
{
int tot , i , k , n;
char c;

	while (scanf("%c" , &c) == 1)
	{
		n = 0; tot = 0;
		while (1)
		{
			if ((c >= '0') && (c <= '9')) k = c - '0';
			else if ((c >= 'A') && (c <= 'Z')) k = 10 + c - 'A';
			else if ((c >= 'a') && (c <= 'z')) k = 36 + c - 'a';
			else if (c == '\n') break;
			if (k > n) n = k;
			tot += k;
			scanf("%c" , &c);
		}
		k = 0;
		for (i = n + 1; i < 63; i ++)
			if (tot % (i - 1) == 0) {k = 1; printf("%d\n" , i); break;}
		if (k == 0) printf("such number is impossible!\n");
	}
	return 0;
}