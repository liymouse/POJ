#include <stdio.h>
#include <string.h>

int main()
{
int t , i , L , k , x , res , j;
char te[1000] , s[1000];
int a[26] , b[26];

	scanf("%d\n" , &t);
	while (t --)
	{
		gets(te);
		for (i = 0; i < 26; i ++) a[i] = -10000;
		memset(b , 0 , sizeof(b));
		L = strlen(te);
		k = 0; x = 0;
		for (i = 0; i < L; i ++)
			if (te[i] != ' ') s[k ++] = te[i];
		s[k] = 0; L = k;
		printf("Expression: %s\n" , te);
		for (i = 0; i < L; i ++)
			if ((s[i] >= 'a') && (s[i] <= 'z'))
			{
				k = s[i]-'a';
				a[k] = k+1;
				if (i > 1)
				{
					if ((s[i-2] == '-') && (s[i-1] == '-'))
					{
						a[k] --;
						if (i > 2) te[x ++] = s[i-3];
					}
					else if  ((s[i-2] == '+') && (s[i-1] == '+'))
					{
						a[k] ++;
						if (i > 2) te[x ++] = s[i-3];
					}
					else te[x ++] = s[i-1];
				}
				else if (i > 0)
				{
					te[x ++] = s[i-1];
				}
				if (i < L-2)
				{
					if ((s[i+1] == '+') && (s[i+2] == '+')) b[k] = 1;
					else if ((s[i+1] == '-') && (s[i+2] == '-')) b[k] = -1;
				}
				te[x ++] = s[i];

			}
		res = 0; k = 0;
		if ((te[0] >= 'a') && (te[0] <= 'z')) {res = a[te[0] - 'a']; a[te[0] - 'a'] += b[te[0] - 'a']; k ++;}
		for (i = k; i < x; i += 2)
		{
			if (te[i] == '+') res += a[te[i+1] - 'a'];
			else res -= a[te[i+1] - 'a'];
			a[te[i+1] - 'a'] += b[te[i+1] - 'a'];
		}
		printf("value = %d\n" , res);
		for (i = 0; i < 26; i ++)
			if (a[i] != -10000)
				printf("%c = %d\n" , i + 'a' , a[i]);
	}
	return 0;
}
