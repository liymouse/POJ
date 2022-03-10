#include <stdio.h>

int main()
{
int a[30][30] , num[30] , b[30];
int n;
int x , y , t , k;
char s1[10] , s2[10];

	scanf("%d" , &n);
	for (int i = 0; i < n; i ++) { a[i][0] = i; num[i] = 1; b[i] = i;}
	while (scanf("%s" , s1) == 1)
	{
		if (s1[0] == 'q') break;
		scanf("%d %s %d" , &x , s2 , &y);
		int t , k;
		int p;

		//x is at t-th column's k-th
		//y is at p-th column
		t = b[x]; p = b[y];
		if (t == p) continue;
		if (s1[0] == 'm')
		{
			while (num[t] > 0)
			{
				if (a[t][num[t] - 1] != x)
				{
					num[t] --;
					b[a[t][num[t]]] = a[t][num[t]];
					num[a[t][num[t]]] = 1;
				}
				else break;
			}
		}
		for (int i = 0; i < num[t]; i ++)
			if (a[t][i] == x) {k = i; break;}

		
		if (s2[1] == 'n')
		{
			while (num[p] > 0)
			{
				if (a[p][num[p]-1] != y)
				{
					num[p] --;
					b[a[p][num[p]]] = a[p][num[p]];
					num[a[p][num[p]]] = 1;
				}
				else break;
			}
		}
		
		for (int i = k; i < num[t]; i ++)
		{
			b[a[t][i]] = p;
			a[p][num[p]] = a[t][i];
			num[p] ++;
		}
		num[t] = k;
	}
	for (int i = 0; i < n; i ++)
	{
		printf("%d:" , i);
		for (int j = 0; j < num[i]; j ++)
			printf(" %d" , a[i][j]);
		printf("\n");
	}
	return 0;
}
