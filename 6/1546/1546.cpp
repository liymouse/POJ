#include <stdio.h>
#include <string.h>

int main()
{
char s[8] , a[8];
int p[7] , i , L , b1 , b2;
int n , k , e;

	while (scanf("%s %d %d" , s , &b1 , &b2) == 3)
	{
		n = 0;
		p[0] = 1;
		for (i = 1; i < 7; i ++) p[i] = p[i-1] * b1;
		L = strlen(s);
		for (i = 0; i < L; i ++)
		{
			if ((s[i] >= '0') && (s[i] <= '9'))
				n += (s[i] - '0') * p[L - i - 1];
			else n += (s[i] - 'A' + 10) * p[L - i - 1];
		}
		if (n == 0) printf("      0\n");
		else
		{
			k = 0;
			while (n > 0) 
			{
				a[k] = '0' + n % b2; if (a[k] > '9') a[k] = 'A' + a[k] - '9' - 1;
				n /= b2; k ++;
				if (k > 7) break;
			}
			if (k > 7) printf("  ERROR\n");
			else {a[k] = 0;	strrev(a); printf("%7s\n" , a);}
		}
	}
	return 0;	
}