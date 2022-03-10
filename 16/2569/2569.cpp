#include <stdio.h>
#include <string.h>
#define NUM 260000

int b[NUM];

int main()
{
long tot;
char st[100] , ch;
long n , i , j , max , k;

	while (scanf("%d" , &n) == 1)
	{
		if (n == 0) return 0;
		memset(b , 0 , sizeof(b));
		getchar();
		for (i = 0; i < n; i ++)
		{
			gets(st);
			for (j = 1; j < strlen(st); j ++)
				b[st[j-1] * 1000 + st[j]] ++;
			if (i > 0) b[ch * 1000 + st[0]] ++;
			ch = st[strlen(st) - 1];
		}
		tot = 0;
		for (i = 0; i < NUM; i ++) tot += b[i];
		for (i = 0; i < 5; i ++)
		{
			max = 0;
			for (j = 0; j < NUM; j ++)
				if (b[j] > max) {max = b[j]; k = j;}
			printf("%c%c %d %.6lf\n" , k/1000 , k % 1000 , b[k] , b[k]*1.0/tot);
			b[k] = 0;
		}
		printf("\n");
	}
	return 0;
}
