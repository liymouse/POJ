#include <stdio.h>

int main()
{
int a[100] , b[100] = {0}, tot[100] = {0};
int n , m , i , j , min , max , num;

	scanf("%d %d" , &n , &m);
	for (i = 0; i < n; i ++)
	{
    	min = 2000; max = 0;
		for (j = 0; j < m; j ++)
		{
			scanf("%d" , &a[j]);
			if (a[j] > max) max = a[j];
			if (a[j] < min) min = a[j];
		}
		for (j = 0; j < m; j ++)
		{
			if (a[j] == max) b[j] = 1;
			if (a[j] == min) tot[j] ++;
        }
	}
	num = 0;
	for (i = 0; i < m; i ++) if ((tot[i] > n/2) && (b[i] == 0)) num ++;
	if (num == 0) printf("0\n");
	else for (i = 0; i < m; i ++)
		{
			if ((tot[i] > n/2 ) && (b[i] == 0))
			{
				num --;
				if (num > 0) printf("%d " , i + 1);
                else printf("%d\n" , i + 1);
            }
		}     
	return 0;
}
