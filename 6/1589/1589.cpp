#include <stdio.h>
#include <string.h>

char word[100][61];

void qu(int s , int t)
{
int i , j;
char x[61] , y[61];

	i = s; j = t; strcpy(x , word[(i + j)/2]);
	while (i <= j)
	{
		while (strcmp(word[i] , x) < 0) i ++;
		while (strcmp(word[j] , x) > 0) j --;
		if (i <= j)
		{
			strcpy(y , word[i]); strcpy(word[i] , word[j]); strcpy(word[j] , y);
			i ++; j --;
		}
	}
	if (s < j) qu(s , j);
	if (i < t) qu(i , t);
}

int main()
{

int n , L , p , i , j , k , q , x;

	while (scanf("%d" , &n) == 1)
	{
		L = 0;
		for (i = 0; i < n; i ++)
		{
			scanf("%s" , word[i]);
			p = strlen(word[i]);
			if (p > L) L = p;
		}
		qu(0 , n - 1);
		p = 60 / (L + 2);
		if (L + 2 > 60) p = 1;
		q = (n-1) / p + 1;
		printf("------------------------------------------------------------\n");
		for (i = 0; i < q; i ++)
		{
			for (j = i; j < n; j += q)
			{
				printf("%s" , word[j]);
				x = strlen(word[j]);
				for (k = x; k < L; k ++) printf(" ");
				if (j + q < n) printf("  ");
			}
			printf("\n");
		}
	}
	return 0;
}