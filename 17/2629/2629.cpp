#include <stdio.h>
#include <string.h>

int main()
{
int num1[26] , num2[26] , i;
char s[1010];

	while (gets(s))
	{
		for (i = 0; i < 26; i ++) {num1[i] = 0; num2[i] = 0;}
		i = 0;
		while (s[i] > 0) {if ((s[i] >= 'a') && (s[i] <= 'z')) num1[s[i] - 'a'] ++; i ++;}
		gets(s);
		i = 0;
		while (s[i] > 0) {if ((s[i] >= 'a') && (s[i] <= 'z')) num2[s[i] - 'a'] ++; i ++;}
		for (i = 0; i < 26; i ++)
			while ((num1[i] --) && (num2[i] --))
				printf("%c" , i + 'a');
		printf("\n");
	}
	return 0;
}