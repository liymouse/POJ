#include <algorithm>
#include <string>
#include <stdio.h>
using namespace std;

int cmp(int x , int y)
{
	return x < y;
}

int main()
{
int tot , min;
int a[51] , b[51];
int n , i , x , y;

	scanf("%d" , &n);
	for (i = 0; i < n; i ++) scanf("%d" , &a[i]);
	memset(b , 0 , sizeof(b));
	sort(a , a + n , cmp);
	tot = 0;
	while (n)
	{
		if (n == 1) {tot += a[0]; break;}
		else if (n == 2) {tot += a[1]; break;}
		else if (n == 3) {tot += a[0] + a[1] + a[2]; break;}
		else 
		{
			x = a[n-1] + a[n-2] + 2 * a[0];
			y = a[1] + a[0] + a[n-1] + a[1];
			tot += x < y ? x : y;
			n -= 2;
		}
	}
	printf("%d\n" , tot);
}