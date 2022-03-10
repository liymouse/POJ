#include <stdio.h>
#include <string.h>

int main()
{
int n;
char s[50];
char res[50];
int h , L;
char x;

	scanf("%d" , &n);
	for (int i = 0; i < n; i ++)
	{
		scanf("%s" , s);
		L = 0;
		for (int j = 5; j < 10; j ++)
			res[L++] = s[j];
		res[L++] = '/';
		for (int j = 0; j < 4; j ++)
			res[L++] = s[j];
		res[L++] = '-';
		h = (s[11] - '0') * 10 + s[12] - '0';
		if (h < 12) x = 'a';
		else {h -= 12; x = 'p';}
		if (h == 0) h = 12;
		res[L++] = h/10 + '0';
		res[L++] = h%10 + '0';
		for (int j = 13; j < 19; j ++)
			res[L++] = s[j];
		res[L++] = x;
		res[L++] = 'm';
		res[L++] = 0;
		printf("%s\n" , res);
	}
	return 0;
}
