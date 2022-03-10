#include <stdio.h>
#include <string.h>

int main()
{
int g , w , i , j , L , b[5] , all , word , t , flag , k;
char name[5][200] , wish[210] , s[200];

	scanf("%d %d" , &g , &w);
	for (i = 0; i < g; i ++)
		scanf("%s\n" , name[i]);
	for (i = 0; i < w; i ++)
	{
		gets(wish);
		L = strlen(wish);
		all = 1; word = 0; t = 0; flag = 0;
		for (j = 0; j < g; j ++) b[j] = 0;
		for (j = 0; j < L; j ++)
		{
			if (('A' <= wish[j]) && (wish[j] <= 'Z')) wish[j] = wish[j] - 'A' + 'a';
			if (('a' <= wish[j]) && (wish[j] <= 'z')) s[t ++] = wish[j];
			else if (t > 0)
			{
				s[t] = 0; word ++;
				for (k = 0; k < g; k ++) if (strcmp(s , name[k]) == 0) {b[k] = 1; all = 0;}
				if (strcmp(s , "beautiful") == 0) flag = 1;
				if (strcmp(s , "pretty") == 0) flag = 1;
				if (strcmp(s , "lovely") == 0) flag = 1;
				t = 0;
			}
		}
		if (all == 1) printf("All: ");
		else
		{
			for (j = 0; j < g; j ++) if (b[j] == 1) all ++;
			for (j = 0; j < g; j ++)
			{
				if ((b[j] == 1) && (all > 1)) {all --; printf("%s " , name[j]);}
				else if (b[j] == 1) {all --; printf("%s: " , name[j]);}
			}
		}
		if (word <= 9) printf("oh\n");
		else
		{
			if (flag == 1) printf("xixi\n");
			else printf("hehe\n");
		}
	}
	return 0;
}