#include <stdio.h>
#include <string.h>

int main()
{
struct kk {char name[100] , support[100]; int tot;}a[20];
int n , i , j , m , max , b;

char s[100];

	scanf("%d\n" , &n);
	for (i = 0; i < n; i ++)
	{
		gets(a[i].name);
		gets(a[i].support);
		a[i].tot = 0;
	}
	scanf("%d\n" , &m);
	for (i = 0; i < m; i ++)
	{
		gets(s);
		for (j = 0; j < n; j ++) if (strcmp(s , a[j].name) == 0) {a[j].tot ++; break;}
	}
	max = 0;
	for (i = 0; i < n; i ++) if (a[i].tot > max) max = a[i].tot;
	b = 0;
	for (i = 0; i < n; i ++) if (a[i].tot == max) b = 1;
	if (b > 0) printf("tie\n");
	else
	{
		for (i = 0; i < n; i ++) if (a[i].tot == max) {j = i; break;}
		printf("%s\n" , a[j].support);
	}
	return 0;
}