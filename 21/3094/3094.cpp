#include <stdio.h>

int main()
{
char s[300];
int i , tot;

	while (gets(s))
	{
		if (s[0] == '#') break;
		i = 0; tot = 0;
		while (s[i])
		{
			if ((s[i] >= 'A') && (s[i] <= 'Z')) tot += (i + 1) * (s[i] - 'A' + 1);
			i ++; 
		}
		printf("%d\n" , tot);
	}
	return 0;
}


