#include <stdio.h>
#include <string.h>

struct kk
{
	char name[80]; 
	int tot;
}a[20];
int person[1000][20] , queue[1000] , flag[20];

int main()
{

	int n , i , j , m , max , t , done , min , temp;
	scanf("%d\n" , &n);
	memset(flag , 0 , sizeof(flag));
	for (i = 0; i < n; i ++)
		gets(a[i].name);
	m = 0;
	while (scanf("%d" , &person[m][0]) == 1)
	{
		for (j = 1; j < n; j ++) 
			scanf("%d" , &person[m][j]);
		m++;
	}
	memset(queue , 0 , sizeof(queue));
	done = 0;
	while (1)
	{
		for (i = 0; i < n; i ++) 
			a[i].tot = 0;
		for (i = 0; i < m; i ++) 
			if (queue[i] < n)
			{
				while ((flag[person[i][queue[i]] - 1]) && (queue[i] < n)) 
					queue[i] ++;
				if (queue[i] < n) 
					a[person[i][queue[i]] - 1].tot ++;
			}
		max = 0;
		for (i = 0; i < n; i ++)
			if ((flag[i] == 0) && (a[i].tot > max)) 
			{
				max = a[i].tot; 
				t = i;
			}
		if (max > m / 2) 
		{
			printf("%s\n" , a[t].name); 
			done = 1; 
			break;
		}
		min = 2000;
		for (i = 0; i < n; i ++)
			if ((flag[i] == 0) && (a[i].tot < min)) 
				min = a[i].tot;
		temp = 0;
		for (i = 0; i < n; i ++) 
			if ((flag[i] == 0) && (a[i].tot > min)) 
			{
				temp = 1; 
				break;
			}
		if (temp == 0) 
			break;
		for (i = 0; i < n; i ++)
			if ((flag[i] == 0) && (a[i].tot == min)) 
				flag[i] = 1;
	}
	if (done == 0)
	{
		for (i = 0; i < n; i ++)
			if (flag[i] == 0) 
				printf("%s\n" , a[i].name);
	}
	return 0;
}



