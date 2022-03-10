#include <stdio.h>

int main()
{
int a[1000] , t , up , n , i;
double ave;

	scanf("%d" , &t);
	while (t --)
	{
		scanf("%d" , &n);
		ave = 0; up = 0;
		for (i = 0; i < n; i ++) {scanf("%d" , &a[i]); ave += a[i];}
		ave = ave / n;
		for (i = 0; i < n; i ++) if (a[i] > ave) up ++;
		printf("%.3lf%%\n" , up * 100.0 / n);
	}
	return 0;
}