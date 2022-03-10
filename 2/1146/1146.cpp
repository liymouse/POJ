#include <stdio.h>
#include <string.h>

int main()
{
char s[51];
int a[26] , i , k;

	while (scanf("%s" , s) == 1)
	{
		if (s[0] == '#') break;
		memset(a , 0 , sizeof(a));
		k = strlen(s) - 2; a[s[k + 1] - 'a'] ++;
		while ((k >= 0) && (s[k] >= s[k+1])) {a[s[k] - 'a'] ++; k --;}
		if (k < 0) printf("No Successor\n");
		else
		{
			a[s[k] - 'a'] ++;
			for (i = s[k] - 'a' + 1; i < 26; i ++) 
				if (a[i] > 0) {a[i] --; s[k] = i + 'a'; break;}
			k ++;
			for (i = 0; i < 26; i ++)
				while (a[i] > 0) {s[k ++] = i + 'a'; a[i] --;}
			printf("%s\n" , s);
		}
	}
	return 0;
}