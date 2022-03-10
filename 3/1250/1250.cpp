#include <stdio.h>
#include <string.h>

int main()
{
int n , a[26] , i , L , tot , num;
char s[60];

	while (scanf("%d %s" , &n , s) == 2)
	{
		memset(a , 0 , sizeof(a));
		L = strlen(s); tot = 0; num = 0;
		for (i = 0; i < L; i ++)
		{
			if ((a[s[i]-'A'] == 0) && (tot < n)) {a[s[i]-'A'] = 1; tot ++;}
			else if (a[s[i]-'A'] == 1) tot --;
				else if ((a[s[i]-'A'] == 0) && (tot >= n)) {num ++; a[s[i]-'A'] = -1;}
		}
		if (num == 0) printf("All customers tanned successfully.\n");
		else printf("%d customer(s) walked away.\n" , num);
	}
	return 0;
}