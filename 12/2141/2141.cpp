#include <stdio.h>

int main()
{
char s[81];
int i , a[26];

	gets(s);
	for (i = 0; i < 26; i ++) a[i] = s[i] - 'a' - i;
	gets(s);
	i = 0;
	while (s[i])
	{
		if ((s[i] >= 'A') && (s[i] <= 'Z')) s[i] += a[s[i]-'A'];
		else if ((s[i] >= 'a') && (s[i] <= 'z')) s[i] += a[s[i]-'a'];
		i ++;
	}
	puts(s);
	return 0;
}