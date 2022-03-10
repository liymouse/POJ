#include <stdio.h>
#include <string.h>

int fun(char v , char w , char x , char y , char z)
{
int a , b , c , d , e;

	a = v - 'A' + 1; b = w - 'A' + 1; c = x - 'A' + 1;
	d = y - 'A' + 1; e = z - 'A' + 1;
	return a - b * b + c * c * c - d * d * d * d + e * e * e * e * e;
}

int main()
{
int target , i , j , L;
int v , w , x , y , z , b;
char s[13] , c;

	while (scanf("%d %s" , &target , s) == 2)
	{
		if ((target == 0) && (strcmp(s , "END") == 0)) break;
		L = strlen(s);
		for (i = 0; i < L; i ++)
			for (j = 1; j < L; j ++)
				if (s[j-1] < s[j]) {c = s[j-1]; s[j-1] = s[j]; s[j] = c;}
		b = 0;
		for (v = 0; v < L; v ++)
		{
			for (w = 0; w < L; w ++)
				if (w != v)
				{
					for (x = 0; x < L; x ++)
						if ((x != w) && (x != v))
						{
							for (y = 0; y < L; y ++)
								if ((y != x) && (y != w) && (y != v))
								{
									for (z = 0; z < L; z ++)
										if ((z != v) && (z != w) && (z != x) && (z != y))
											if (fun(s[v] , s[w] , s[x] , s[y] , s[z]) == target) {b = 1; break;}
									if (b) break;
								}
								if (b) break;
						}
						if (b) break;
				}
			if (b) break;
		}
		if (b == 0) printf("no solution\n");
		else printf("%c%c%c%c%c\n" , s[v] , s[w] , s[x] , s[y] , s[z]);
	}
	return 0;
}