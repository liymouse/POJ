#include <stdio.h>
#include <string.h>

int main()
{
char s[21];
int num[26] , b , i , L;

	memset(num , 0 , sizeof(num));
	num['a'-'a'] = 1; num['e'-'a'] = 1; num['i'-'a'] = 1; num['o'-'a'] = 1; num['u'-'a'] = 1;
	while (scanf("%s" , s) == 1)
	{
		if (strcmp("end" , s) == 0) break;
		L = strlen(s); b = 0;
		for (i = 0; i < L; i ++) if (num[s[i]-'a'] == 1) {b = 1; break;}
		if (b)
		{
			for (i = 1; i < L; i ++) if ((s[i-1] == s[i]) && (s[i] != 'e') && (s[i] != 'o')) {b = 0; break;}
			if (b)
			{
				for (i = 2; i < L; i ++)
					if ((num[s[i-2]-'a'] == num[s[i-1]-'a']) && (num[s[i-1]-'a'] == num[s[i]-'a']))
					{b = 0; break;}
			}
		}
		if (b) printf("<%s> is acceptable.\n" , s);
		else printf("<%s> is not acceptable.\n" , s);
	}
	return 0;
}