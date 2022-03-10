#include <stdio.h>
#include <string.h>

#define M 510
int main()
{
int n , de , pl[10] , i , j;
int by[4] , ni[4] , byn , nin , x;
char s[10];
int p[] = {1 , 2 , 4 , 8 , 16 , 32 , 64 , 128};

	while (scanf("%s %d" , s , &n) == 2)
	{
		de = 0; 
		for (i = 0; i < n; i ++) pl[i] = 255;
		memset(by , 0 , sizeof(by));
		memset(ni , 0 , sizeof(ni));
		for (i = 0; i < 2; i ++)
		{
			scanf("%s" , s);
			for (j = 7; j >= 0; j --)
				de += (s[j] - '0') * p[7-j];
		}
		for (i = 0; i < n; i ++)
		{
			scanf("%s" , s);
			for (j = 7; j >= 0; j --)
				pl[i] += (s[j] - '0') * p[7-j];
		}
		for (i = 0; i < 4; i ++)
		{
			scanf("%s" , s);
			for (j = 7; j >= 0; j --)
				by[i] += (s[j] - '0') * p[7-j];
		}
		for (i = 0; i < 4; i ++)
		{
			scanf("%s" , s);
			for (j = 3; j >= 0; j --)
				ni[i] += (s[j] - '0') * p[3-j];
		}
		scanf("%s" , s);
		printf("HAND %d\n" , n);
		byn = 0; nin = 0; x = 0;
		for (i = 0; i < n; i ++) if (pl[i] <= M) break;
		if (i == n) {printf("Win!\n"); continue;}
		while (de < 382 && x < 4)
		{
			for (i = 0; i < n; i ++) if (de < pl[i]) break;
			if (i == n) break;
			printf("Byte me!\n");
			de += by[byn ++];
			x ++;
		}
		while (de <= 500 && x < 4)
		{
			for (i = 0; i < n; i ++) if (de < pl[i]) break;
			if (i == n) break;
			printf("Nibble me!\n");
			de += ni[nin ++];
			x ++;
		}
		for (i = 0; i < n; i ++) if (de < pl[i]) break;
		if (i == n && de <= M) printf("Win!\n");
		else if (de > M) printf("Bust!\n");
		else printf("Lose!\n");
	}
	return 0;
}
