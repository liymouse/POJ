#include <stdio.h>
#include <string.h>

int main()
{
char s1[15] , s2[15] , c;
int a[11] , b[11];
int i , L , tot;

	while (scanf("%s %s" , s1 , s2) == 2)
	{
		if ((s1[0] == '0') && (s2[0] == '0')) return 0;
		else
		{
			L = strlen(s1);
			for (i = 0; i < L / 2; i ++)
			{
				c = s1[i]; s1[i] = s1[L - i - 1]; s1[L - i - 1] = c;
			}
			memset(a , 0 , sizeof(a));
			for (i = 0; i < L; i ++) a[i] = s1[i] - '0';
			L = strlen(s2);
			for (i = 0; i < L / 2; i ++)
			{
				c = s2[i]; s2[i] = s2[L - i - 1]; s2[L - i - 1] = c;
			}
			memset(b , 0 , sizeof(b));
			for (i = 0; i < L; i ++) b[i] = s2[i] - '0';
			if (strlen(s1) > strlen(s2)) L = strlen(s1); else L = strlen(s2);
			tot = 0;
			for (i = 0; i < L; i ++)
			{
				b[i] = b[i] + a[i];
				if (b[i] > 9) {tot ++; b[i+1] ++; b[i] -= 10;}
			}
		}
		switch (tot)
		{
			case 0 : printf("No carry operation.\n");
			break;
			case 1 : printf("1 carry operation.\n");
			break;
			default : printf("%d carry operations.\n" , tot);
			break;
		}
	}
	return 0;
}
