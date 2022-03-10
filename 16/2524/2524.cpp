#include <stdio.h>

__int64 father[50010] , b[50010];
__int64 n , m;

__int64 getfather(__int64 x)
{
__int64 f;
    
    if (father[x] == x) return x;
    else
    {
        f = getfather(father[x]);
        father[x] = f;
        return f;
    }
}

int main()
{
__int64 i , s , t , h;

	h = 0;
	while (scanf("%I64d %I64d" , &n , &m) == 2)
	{
		h ++;
		if (n == 0) return 0;
		for (i = 1; i <= n; i ++) {father[i] = i; b[i] = 0;}
		for (i = 0; i < m; i ++)
		{
			scanf("%I64d %I64d" , &s , &t);
			s = getfather(s);
			t = getfather(t);
			if (father[s] == t);
		}
		for (i = 1; i <= n; i ++) b[getfather(i)] = 1;
		s = 0;
		for (i = 1; i <= n; i ++) if (b[i] > 0) s ++;
		printf("Case %I64d: %I64d\n" , h , s);
    }
    return 0;
}
