#include <stdio.h>
#include <math.h>

int main()
{
char s1[20] , s[3];
int n , tot;

	tot = 0;
	while (scanf("%s" , s1) == 1)
	{
		if (s1[0] == '#') break;
		if (s1[0] == '0') {printf("%d\n" , tot); tot = 0;}
		else
		{
			scanf("%s %d %s" , s1 , &n , s);
			switch (s[0])
			{
				case 'F' : tot += n * 2; break;
				case 'B' : tot += n + (n + 1) / 2; break;
				case 'Y' : tot += (n <= 500) ? 500 : n; break;
			}
		}
	}
	return 0;
}