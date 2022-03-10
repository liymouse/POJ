#include <stdio.h>

int main()
{
int a[9] , i , t;

	while (scanf("%d" , &a[8]) == 1)
	{
		for (i = 7; i >= 0; i --) scanf("%d" , &a[i]);
		t = 0;
		for (i = 8; i >= 2; i --) if (a[i] != 0) break;
		if (i >= 2)
		{
			t = 1;
			if (a[i] > 0)
			{
				if (a[i] == 1) printf("x^%d" , i);
				else printf("%dx^%d" , a[i] , i);
			}
			else
			{
				if (a[i] == -1) printf("-x^%d" , i);
				else printf("%dx^%d" , a[i] , i);
			}
			i --;
			while (i >= 2)
			{
				if (a[i] > 0)
				{
					printf(" + ");
					if (a[i] == 1) printf("x^%d" , i);
					else printf("%dx^%d" , a[i] , i);
				}
				else if (a[i] < 0)
				{
					printf(" - ");
					if (a[i] == -1) printf("x^%d" , i);
					else printf("%dx^%d" , -a[i] , i);
				}
				i --;
			}
		}
		if (a[1] > 0)
		{
			if (t == 1) printf(" + ");
			if (a[1] == 1) printf("x");
			else printf("%dx" , a[i]);
			t = 1;
		}
		else if (a[1] < 0)
		{
			if (t == 1) 
			{
				printf(" - ");
				if (a[1] == -1) printf("x");
				else printf("%dx" , -a[i]);
			}
			else
			{
				if (a[i] == -1) printf("-x");
				else printf("%dx" , a[i]);
			}
			t = 1;
		}
		if (a[0] > 0)
		{
			if (t == 1) printf(" + ");
			printf("%d" , a[0]);
			t = 1;
		}
		else if (a[0] < 0)
		{
			if (t == 1) printf(" - %d" , -a[0]);
			else printf("%d" , a[0]);
			t = 1;
		}
		if (t == 0) printf("0");
		printf("\n");
	}
	return 0;
}