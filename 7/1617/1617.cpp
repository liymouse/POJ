#include <stdio.h>
#include <string.h>

int main()
{
char key[11] , s[101];
struct word{char f[100]; int no;} a[10] , y;
int L , n , m , i , j , num , min , b[10];

	while (scanf("%s" , key) == 1)
	{
		if (strcmp(key , "THEEND") == 0) break;
		n = strlen(key);
		scanf("%s" , s);
		L = strlen(s);
		m = L / n;
		for (i = 0; i < n; i ++)
			for (j = 0; j < m; j ++)
				a[i].f[j] = s[i * m + j];
		num = 0;
		memset(b , 0 , sizeof(b));
		while (num < n)
		{
			min = 100;
			for (i = 0; i < n; i ++)
				if ((b[i] == 0) && (key[i] < min)) min = key[i];
			for (i = 0; i < n; i ++)
				if (key[i] == min) {a[num ++].no = i; b[i] = 1;}
		}
		for (i = 0; i < n; i ++)
			for (j = 1; j < n - i; j ++)
				if (a[j-1].no > a[j].no)
					{y = a[j-1]; a[j-1] = a[j]; a[j] = y;}
		for (j = 0; j < m; j ++)
			for (i = 0; i < n; i ++)
				printf("%c" , a[i].f[j]);
		printf("\n");
	}
	return 0;
}
