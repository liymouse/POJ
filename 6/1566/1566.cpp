#include <stdio.h>
#include <string.h>

int main()
{
int i , L , b , j , num , p , k;
char s[201] , word[80] , bb[80];
int a[26];

	memset(a , 0 , sizeof(a));
	a['a'-'a'] = 1; a['e'-'a'] = 1; a['i'-'a'] = 1;
	a['o'-'a'] = 1; a['u'-'a'] = 1; a['y'-'a'] = 1;
	while (1)
	{
		gets(s);
		L = strlen(s);
		while (s[L-1] == ' ') L --;
		s[L] = 0;
		if (strcmp(s , "e/o/i") == 0) break;
		b = 0; j = 0; num = 0; p = 0;
		for (i = 0; i < L; i ++)
		{
			if ((s[i] >= 'a') && (s[i] <= 'z'))
			{
				word[j ++] = s[i];
			}
			else if (j > 0)
			{
				word[j] = 0;
				memset(bb , 0 , sizeof(bb));
				for (k = 0; k < j; k ++) if (a[word[k]-'a'] == 1) bb[k] = 1;
				if (bb[0] == 1) num ++;
				for (k = 1; k < j; k ++) if ((bb[k] == 1) && (bb[k-1] == 0)) num ++;
				j = 0;
				if (s[i] == '/')
				{
					if ((b == 0) && (num != 5)) {p = 1; break;}
					if ((b == 1) && (num != 7)) {p = 2; break;}
					b ++;
					num = 0;
				}
			}
		}
		if (j > 0)
		{
			word[j] = 0;
			memset(bb , 0 , sizeof(bb));
			for (k = 0; k < j; k ++) if (a[word[k]-'a'] == 1) bb[k] = 1;
			if (bb[0] == 1) num ++;
			for (k = 1; k < j; k ++) if ((bb[k] == 1) && (bb[k-1] == 0)) num ++;
		}
		if ((b == 2) && (num != 5)) p = 3;
		if (p == 0) printf("Y\n"); else printf("%d\n" , p);
	}
	return 0;
}