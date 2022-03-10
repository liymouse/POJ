#include <stdio.h>

int main()
{
int a[5843];
int n , i , j , min , k;
int x[4];
int p[4] = {2 , 3 , 5 , 7};

	a[1] = 1;
	x[0] = 1; x[1] = 1; x[2] = 1; x[3] = 1;
	i = 2;
	while (i <= 5843)
	{
		min = a[x[0]] * p[0]; k = 0;
		for (j = 1; j < 4; j ++)
			if (a[x[j]] * p[j] < min) {min = a[x[j]] * p[j]; k = j;}
		a[i] = min; x[k] ++;
		for (j = 1; j < i; j ++) if (min == a[j]) break;
		if (j == i) i ++;
	}
	while (scanf("%d" , &n) == 1)
	{
		if (n == 0) break;
		printf("The %d" , n);
		if ((n % 100) / 10 == 1) printf("th");
		else if (n % 10 == 1) printf("st");
		else if (n % 10 == 2) printf("nd");
			else if (n % 10 == 3) printf("rd");
				else printf("th");
		printf(" humble number is %d.\n" , a[n]);
	}
	return 0;
}