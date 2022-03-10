#include <stdio.h>
#include <string.h>

int main()
{
char s[300];

	while (1)
	{
		gets(s);
		if (s[0] == 'E') break;
		gets(s);
		int L = strlen(s);
		for (int i = 0; i < L; i ++)
			if (s[i] >= 'A' && s[i] <= 'Z')
			{
				s[i] -= 5;
				if (s[i] < 'A') s[i] += 26;
			}
		printf("%s\n" , s);
		gets(s);
	}
	return 0;
}
