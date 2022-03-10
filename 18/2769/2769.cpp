#include <stdio.h>
#include <algorithm>
using namespace std;
#define MAX 1000000

int a[300];
int b[300];
int n;

int cmp(int &x , int &y)
{
	return x < y;
}

int ok(int x)
{
int i;

	for (i = 0; i < n; i ++) b[i] = a[i] % x;
	sort(b , b + n , cmp);
	for (i = 1; i < n; i ++) if (b[i-1] == b[i]) return 0;
	return 1;
}

int main()
{

int t , i , m;

	scanf("%d" , &t);
	while (t --)
	{
		scanf("%d" , &n);
		for (i = 0; i < n; i ++) scanf("%d" , &a[i]);
		for (i = n; i < 1000000; i ++) if (ok(i)) break;
		printf("%d\n" , i);
	}
	return 0;
}


