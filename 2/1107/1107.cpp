#include <stdio.h>
#include <string.h>

int main()
{
char s[100] , news[100] , temp[100];
int k1 , k2 , k3;
int i , j , t , k , x , next[100] , L;

	while (scanf("%d %d %d" , &k1 , &k2 , &k3) == 3)
	{
		if ((k1 || k2 || k3) == 0) return 0;
		scanf("%s" , s);
		L = strlen(s);
		news[L] = 0;
		t = 0;
		for (i = 0; i < L; i ++)
			if (('a' <= s[i]) && (s[i] <= 'i')) 
			{
				temp[t ++] = s[i]; 
				x = i;
				break;
			}
		for (i = x + 1; i < L; i ++)
			if (('a' <= s[i]) && (s[i] <= 'i'))
			{
				temp[t] = s[i];
				next[t-1] = i;
				t ++;
			}
		next[t-1] = x;
		if (t > 0) k1 %= t;
		i = t - k1;
		if (i == t) i = 0;
		for (j = 0; j < t; j ++)
		{
			if (j == 0)	news[next[t-1]] = temp[i];
			else news[next[j-1]] = temp[i];
			i ++; if (i == t) i = 0;
		}
		t = 0;
		for (i = 0; i < L; i ++)
			if (('j' <= s[i]) && (s[i] <= 'r')) 
			{
				temp[t ++] = s[i]; 
				x = i;
				break;
			}
		for (i = x + 1; i < L; i ++)
			if (('j' <= s[i]) && (s[i] <= 'r'))
			{
				temp[t] = s[i];
				next[t-1] = i;
				t ++;
			}
		next[t-1] = x;
		if (t > 0) k2 %= t;
		i = t - k2;
		if (i == t) i = 0;
		for (j = 0; j < t; j ++)
		{
			if (j == 0)	news[next[t-1]] = temp[i];
			else news[next[j-1]] = temp[i];
			i ++; if (i == t) i = 0;
		}
		t = 0;
		for (i = 0; i < L; i ++)
			if ((('s' <= s[i]) && (s[i] <= 'z')) || (s[i] == '_')) 
			{
				temp[t ++] = s[i]; 
				x = i;
				break;
			}
		for (i = x + 1; i < L; i ++)
			if ((('s' <= s[i]) && (s[i] <= 'z')) || (s[i] == '_'))
			{
				temp[t] = s[i];
				next[t-1] = i;
				t ++;
			}
		next[t-1] = x;
		if (t > 0) k3 %= t;
		i = t - k3;
		if (i == t) i = 0;
		for (j = 0; j < t; j ++)
		{
			if (j == 0)	news[next[t-1]] = temp[i];
			else news[next[j-1]] = temp[i];
			i ++; if (i == t) i = 0;
		}
		printf("%s\n" , news);
	}
	return 0;
}