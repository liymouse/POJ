#include <stdio.h>
#include <string.h>

int main()
{
double a , r;
int n , i;
char un[10];
char name[30] , less[5][30];

	n = 0;
	while (scanf("%lf" , &a) == 1)
	{
		if (a < 0) break;
		scanf("%s" , un);
		scanf("%lf " , &r);
		gets(name);
		i = strlen(name);
		while (name[i-1] == ' ') {name[i-1] = 0; i --;}
		if (a * 100 / r >= 1) printf("%s %.1lf %s %.0lf%%\n" , name , a , un , a * 100 / r);
		else strcpy(less[n++] , name);
	}
	printf("Provides no significant amount of:\n");
	for (i = 0; i < n; i ++) printf("%s\n" , less[i]);
	return 0;
}