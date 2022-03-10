#include <stdio.h>
#include <string.h>

int main()
{
int n , h , i , L , j , x , mink;
char s[10001] , s1[10001] , min[10001];
	
	scanf("%d" , &n);
	for (h = 0; h < n; h ++)
	{
		scanf("%s" , s);
		L = strlen(s);
		strcpy(min , s); mink = 0;
		for (i = 1; i < L; i ++)
		{
			x = i; j = 0;
			while (j < L) {s1[j ++] = s[x]; x ++; if (x == L) x = 0;}
			if (strcmp(s1 , min) < 0) {strcpy(min , s1); mink = i;}
		}
		printf("%d\n" , mink + 1);
	}
	return 0;
}
