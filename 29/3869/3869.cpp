#include <stdio.h>
#include <string.h>

int main()
{
char s[110];
int sl , sd , L;
int rl , rd;

	scanf("%s" , s);
	L = strlen(s);
	rl = 0; rd = 0;
	for (int i = 0; i < L; i ++)
		if (s[i] == '0') rl ++; else rd ++;
	s[L] = s[0];
	sl = 0; sd = 0;
	for (int i = 0; i < L; i ++)
		if (s[i] == '0')
		{
			if (s[i+1] == '0') sl ++;
			else sd ++;
		}
	double r = 1.0 * rl / (rl + rd);
	double ss = 1.0 * sl / (sl + sd);
	if (r > ss) printf("ROTATE\n");
	else if (r < ss) printf("SHOOT\n");
	else printf("EQUAL\n");
	return 0;
}
