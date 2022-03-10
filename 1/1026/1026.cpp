#include <stdio.h>
#include <string.h>

int main()
{
int n , k;
int a[200];
char ss[500] , s1[250] , s2[250];
char *p , *q , *s;
int i , j , x , m , bo;

    scanf("%d" , &n);
	for (i = 0; i < n; i ++) scanf("%d" , &a[i]);
	while (1)
	{
		scanf("%d" , &k);
		if (k == 0) break; 
		getchar();
		gets(ss);
		for (i = 0; i < n; i ++)
            s1[i] = ss[i];
        s1[n] = 0; ss[n] = 0;
        p = s1; q = s2; bo = 0; x = 0;
        for (i = 0; i < k; i ++)
        {
            x ++;
            for (j = 0; j < n; j ++)
                q[a[j]-1] = p[j];
            q[n] = 0;
            if ((strcmp(ss , q) == 0) && (x > k/2)) {bo = 1; break;}
            else {s = p; p = q; q = s;}
        }
        if (bo) 
        {
            m = k % x;
            s = p; p = q; q = s;
            for (i = 0; i < k; i ++)
            {
                for (j = 0; j < n; j ++)
                    q[a[j]-1] = p[j];
                q[n] = 0;
                s = p; p = q; q = s;
            }    
            printf("%s\n" , p);
        }
        else printf("%s\n" , p);
    }    
    return 0;
}
