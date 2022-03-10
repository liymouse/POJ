#include <stdio.h>
#define NUM 65

int main()
{
int p[NUM] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,
101,103,107,109,113,127,131,137,139,149,151,157,163,167,173,179,181,191,193,197,199,211,223,227,229,
233,239,241,251,257,263,269,271,277,281,283,293,307,311,313};
int m , a , b;
int i , j , k , done , x , y;

	while (scanf("%d %d %d" , &m , &a , &b) == 3)
	{
		if (m == 0) break;
		done = 0;
		for (i = m; i >= 4; i --)
		{
			k = i; x = -1; y = -1;
			for (j = 0; j < NUM; j ++)
				if ((k != p[j]) && (k % p[j] == 0)) {k /= p[j]; x = j; break;}
			if (x >= 0)
			{
				for (j = x; j < NUM; j ++)
					if (k % p[j] == 0) {k /= p[j]; y = j; break;}
				if ((y >= 0) && (k == 1)) y = p[y];
				else if (y == -1) y = k;
					else y = -1;
				if ((y >= 0) && (p[x] * 1.0 / y >= a * 1.0 / b)) done = 1;
			}
			if (done) break;
		}
		printf("%d %d\n" , p[x] , y);
	}
	return 0;
}
