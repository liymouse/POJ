#include <stdio.h>
#include <string.h>

int main()
{
char s[1000];
int n , k , i;

	while (scanf("%s" , s) == 1)
	{
		if (s[0] == '0') return 0;
		if (strlen(s) == 1) printf("%s\n" , s);
		else
		{
			n = 0;
			for (i = 0; i < strlen(s); i ++)
				n += s[i] - '0';
			while (n > 9)
			{
				k = 0;
				while (n > 0) {k += n % 10; n /= 10;}
				n = k;
			}
			printf("%d\n" , n);
		}
	}
}