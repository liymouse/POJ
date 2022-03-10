#include <stdio.h>

int main()
{
char s[21] , i , b[20] , n;

	while (scanf("%s" , s) == 1)
	{
		i = 0;
		while (s[i] > 0)
		{
			switch(s[i])
			{
				case 'A': case 'E': case 'I': case 'O': case 'U': case 'H': case 'W': case 'Y': b[i] = 0; break;
				case 'B': case 'F': case 'P': case 'V': b[i] = 1; break;
				case 'C': case 'G': case 'J': case 'K': case 'Q': case 'S': case 'X': case 'Z': b[i] = 2; break;
				case 'D': case 'T': b[i] = 3; break;
				case 'L': b[i] = 4; break;
				case 'M': case 'N': b[i] = 5; break;
				case 'R': b[i] = 6; break;
			}
			i ++;
		}
		n = i; if (b[0] > 0) printf("%d" , b[0]);
		for (i = 1; i < n; i ++)
			if ((b[i] != 0) && (b[i] != b[i-1]))
				printf("%d" , b[i]);
		printf("\n");
	}
	return 0;
}