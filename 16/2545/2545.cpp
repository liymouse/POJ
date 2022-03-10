#include <stdio.h>

int main()
{
__int64 a[10000];
int x , y , z , n , i;
__int64 p1 , p2 , p3;
	
	a[0] = 1; x = 0; y = 0; z = 0;
	scanf("%I64d %I64d %I64d %d" , &p1 , &p2 , &p3 , &n);
	for (i = 1; i <= n; i ++)
	{
		if (a[x] * p1 <= a[i-1]) x ++;
		if (a[y] * p2 <= a[i-1]) y ++;
		if (a[z] * p3 <= a[i-1]) z ++;
		if (a[x] * p1 < a[y] * p2)
		{
			if (a[x] * p1 < a[z] * p3) {a[i] = a[x] * p1; x ++;}
			else {a[i] = a[z] * p3; z ++;}
		}
		else
		{
			if (a[y] * p2 < a[z] * p3) {a[i] = a[y] * p2; y ++;}
			else {a[i] = a[z] * p3; z ++;}
		}
	}
	printf("%I64d\n" , a[n]);
	return 0;
}