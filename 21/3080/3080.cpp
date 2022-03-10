#include <stdio.h>
#include <string.h>

int main()
{
int t , i , j , ok , n , k , b;
char s[10][61] , sub[61] , res[61];

	scanf("%d" , &t);
	while (t --)
	{
		scanf("%d" , &n);
		for (i = 0; i < n; i ++) scanf("%s" , s[i]);
		b = 0;
		for (i = 60; i >= 3; i --)
		{
			for (j = 0; j < 60 - i + 1; j ++)
			{
				for (k = 0; k < i; k ++)
					sub[k] = s[0][j + k];
				sub[k] = 0;
				ok = 1;
				for (k = 1; k < n; k ++)
					if (strstr(s[k] , sub) == 0) {ok = 0; break;}
				if (ok)
				{
					b ++;
					if ((b==1) || (strcmp(sub , res) < 0)) strcpy(res , sub);
				}
			}
			if (b) break;
		}
		if (b) printf("%s\n" , res);
		else printf("no significant commonalities\n");
	}
	return 0;
}