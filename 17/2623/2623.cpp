#include <stdio.h>
#include <algorithm>
using namespace std;

bool cmp(int &x , int &y)
{
	return x < y;
}

int main()
{
int n , i;
int a[250000];
double s;
	
	scanf("%d" , &n);
	for (i = 0; i < n; i ++) scanf("%d" , &a[i]);
	sort(a , a + n , cmp);
	if (n % 2 == 1) printf("%d.0\n" , a[n/2]);
	else 
	{
		s = (double)a[n/2-1] + (double)a[n/2]; 
		printf("%.1lf\n" , s / 2); 
	}
	return 0;
}