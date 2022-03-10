#include <stdio.h>
#include <string.h>

int main()
{
int t , n , i , j , k , La , Ls , max , x , y , L , h;
char s1[101] , s2[101] , s[101] , *a , *b , *c;

	scanf("%d" , &t);
	while (t --)
	{
		scanf("%d" , &n);
		scanf("%s" , s1); a = s1; La = strlen(s1); c = s2;
		for (k = 1; k < n; k ++)
		{
			max = 0;
			if (La == 0) continue;
			scanf("%s" , s);
			Ls = strlen(s);
			for (i = 0; i < La; i ++)
				for (j = 0; j < Ls; j ++)
					if (a[i] == s[j])
					{
						x = i; y = j; L = 0;
						while ((x < La) && (y < Ls) && (a[x] == s[y])) {L ++; x ++; y ++;}
						if (L > max)
						{
							max = L;
							for (h = i; h < i + L; h ++) c[h-i] = a[h];
						}
						x = i; y = j; L = 0;
						while ((x < La) && (y >= 0) && (a[x] == s[y])) {L ++; x ++; y --;}
						if (L > max)
						{
							max = L;
							for (h = i; h < i + L; h ++) c[h-i] = a[h];
						}
					}
			c[max] = 0;
			b = a; a = c; c = b; La = max;
		}
		printf("%d\n" , La);
	}
	return 0;
}