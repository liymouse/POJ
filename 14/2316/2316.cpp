#include <stdio.h>
#include <string.h>

int main()
{
char s[11];
int a[10] ={0} , i , k , n;

	while (scanf("%s" , s) == 1)
	{
		n = strlen(s);
		for (i = 0; i < n; i ++) { k = s[i] - '0'; a[i] += k; }
	}
	for (i = 0; i < n; i ++) printf("%d" , a[i] % 10);
	printf("\n");
	return 0;
}

