#include <stdio.h>
#include <string.h>

int main()
{
int n , a , b , c , i , L;
char s1[10] , s2[10] , s[10];

	scanf("%d" , &n);
	while (n --)
	{
		scanf("%s %s" , s1 , s2);
		a = 0;
		i = 0; L = strlen(s1);
		while (i < L)
		{
			if ((s1[i] >= '0') && (s1[i] <= '9'))
			{
				if (s1[i+1] == 'm') a += (s1[i]-'0') * 1000;
				else if (s1[i+1] == 'c') a += (s1[i]-'0') * 100;
					else if (s1[i+1] == 'x') a += (s1[i]-'0') * 10;
						else if (s1[i+1] == 'i') a += s1[i]-'0';
				i += 2;
			}
			else
			{
				if (s1[i] == 'm') a += 1000;
				else if (s1[i] == 'c') a += 100;
					else if (s1[i] == 'x') a += 10;
						else a ++;
				i ++;
			}
		}
		b = 0;
		i = 0; L = strlen(s2);
		while (i < L)
		{
			if ((s2[i] >= '0') && (s2[i] <= '9'))
			{
				if (s2[i+1] == 'm') b += (s2[i]-'0') * 1000;
				else if (s2[i+1] == 'c') b += (s2[i]-'0') * 100;
					else if (s2[i+1] == 'x') b += (s2[i]-'0') * 10;
						else if (s2[i+1] == 'i') b += s2[i]-'0';
				i += 2;
			}
			else
			{
				if (s2[i] == 'm') b += 1000;
				else if (s2[i] == 'c') b += 100;
					else if (s2[i] == 'x') b += 10;
						else b ++;
				i ++;
			}
		}
		c = a + b;
		i = 0;
		if (c / 1000 == 1) s[i++] = 'm';
		else if (c / 1000 > 1) {s[i++] = c / 1000 + '0'; s[i ++] = 'm';}
		c %= 1000;
		if (c / 100 == 1) s[i++] = 'c';
		else if (c / 100 > 1) {s[i ++] = c / 100 + '0'; s[i ++] = 'c';}
		c %= 100;
		if (c / 10 == 1) s[i++] = 'x';
		else if (c / 10 > 1) {s[i ++] = c / 10 + '0'; s[i ++] = 'x';}
		c %= 10;
		if (c == 1) s[i++] = 'i';
		else if (c > 1) {s[i ++] = c + '0'; s[i ++] = 'i';}
		s[i] = 0;
		printf("%s\n" , s);
	}
	return 0;
}

