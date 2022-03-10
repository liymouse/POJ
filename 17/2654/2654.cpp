#include <stdio.h>
#include <string.h>

int cmp(char s1[] , char s2[])
{
	if (strcmp(s1 , s2) == 0) return 0;
	if ((strcmp(s1 , "rock") == 0) && (strcmp(s2 , "scissors") == 0)) return 1;
	if ((strcmp(s1 , "scissors") == 0) && (strcmp(s2 , "paper") == 0)) return 1;
	if ((strcmp(s1 , "paper") == 0) && (strcmp(s2 , "rock") == 0)) return 1;
	return -1;
}

int main()
{
int n , k , i , x , y;
char s1[10] , s2[10];
struct {int win , lost;}a[101];

	while (scanf("%d %d" , &n , &k) == 2)
	{
		memset(a , 0 , sizeof(a));
		for (i = 0; i < k*n*(n-1)/2; i ++)
		{
			scanf("%d %s %d %s" , &x , s1 , &y , &s2);
			if (cmp(s1 , s2) > 0) {a[x].win ++; a[y].lost ++;}
			else if (cmp(s1 , s2) < 0) {a[x].lost ++; a[y].win ++;}
		}
		for (i = 1; i <= n; i ++)
			if (a[i].win + a[i].lost == 0) printf("-\n");
			else printf("%.3lf\n" , a[i].win * 1.0 / (a[i].win + a[i].lost));
		printf("\n");
	}
	return 0;
}