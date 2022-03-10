#include <stdio.h>
#include <string.h>

int p[4][2] = {{10 , 0} , {0 , -10} , {-10 , 0} , {0 , 10}};
int main()
{
long x , y , i;
int f;
char st[201];

	while (scanf("%s" , st) == 1)
	{
		x = 310; y = 420; f = 0;
		printf("300 420 moveto\n");
		printf("310 420 lineto\n");
		for (i = 0; i < strlen(st); i ++)
		{
			if (st[i] == 'A')
			{
				f ++; if (f == 4) f = 0;	
			}
			else
			{
				f --; if (f < 0) f = 3;
			}
			x += p[f][0]; y += p[f][1];
			printf("%ld %ld lineto\n" , x , y);
		}
		printf("stroke\n");
		printf("showpage\n");
	}
	return 0;
}
