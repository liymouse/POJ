#include <stdio.h>
#include <string.h>

int line[500002];

int main()
{
int i , n , w , x , y , ceng, ans;

	while (scanf("%d %d" , &n , &w) == 2)
	{
		memset(line , 0 , sizeof(line));
		ceng = 1; ans = 0;
		for (i = 0; i < n; i ++)
		{
			scanf("%d %d" , &x , &y);
			while (y < line[ceng-1]) { ans ++; ceng --;	}
			if (y > line[ceng-1]) {	line[ceng] = y;	ceng ++; }
		}
		while (line[ceng-1] > 0) { ans ++; ceng --;	}
		printf("%d\n" , ans);
	}
}
