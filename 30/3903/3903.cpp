#include <stdio.h>
#include <string.h>

typedef long long i64d;

i64d a[100000] , f[100000];
int main()
{
    int n;
	while (scanf("%d" , &n) == 1)
    {
	    for (int i = 0; i < n; i ++) scanf("%lld" , &a[i]);
	    int L = 0;
        memset(f , 0 , sizeof(f));
	    for (int i = 0; i < n; i ++)
	    {
		    i64d k = a[i];
		    if (k > f[L])
		    {
			    L ++; f[L] = k;
		    }
		    else
		    {
			    int x = 1 , y = L;
			    while (x < y)
			    {
				    int z = (x + y) / 2;
				    if (k > f[z]) x = z + 1;
				    else y = z - 1;
			    }
			    if ((f[(x + y) / 2 - 1] < k) && (f[(x + y) / 2] > k)) f[(x+y)/2] = k;
			    else if ((f[(x + y) / 2] < k) && (f[(x + y) / 2 + 1] > k)) f[(x+y)/2+1] = k;
		    }
	    }
	    printf("%d\n" , L);
    }
	return 0;
}
