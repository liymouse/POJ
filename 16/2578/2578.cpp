#include <stdio.h>

int main()
{
int x;

	while (scanf("%d" , &x) == 1)
	{
		if (x < 168) {printf("CRASH %d\n" , x); scanf("%d %d" , &x , &x); continue;}
		scanf("%d" , &x);
		if (x < 168) {printf("CRASH %d\n" , x); scanf("%d" , &x); continue;}
		scanf("%d" , &x);
		if (x < 168) {printf("CRASH %d\n" , x); continue;}
		printf("NO CRASH\n");
	}
	return 0;
}
