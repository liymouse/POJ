#include <stdio.h>
#include <algorithm>
using namespace std;

typedef long long i64d;

i64d a[420000] , luck[350000];
int size; //
int pn;  //a[0]~a[pn-1]为所有由4,7组成的数

void dog(i64d x , int start)
{
    for(int i = start; i < pn; i ++)
		if ((double)x * a[i] <= 1e12)
		{
			i64d tmp = x * a[i];
			a[size ++] = tmp;
			dog(tmp , i);
		}
		else return;
}

int main()
{
	a[0] = 4; a[1] = 7; pn = 2;
	int begin = 0 , end = 1;
	for (int k = 2; k <= 12; k ++)
	{
		for (int i = begin; i <= end; i ++)
		{
			a[pn ++] = a[i] * 10 + 4;
			a[pn ++] = a[i] * 10 + 7;
		}
		begin = end + 1;
		end = pn - 1;
	}
	//printf("%d\n" , pn);
	size = pn;
	for (int i = 0; i < pn; i ++) dog(a[i] , i);
	//printf("%d\n" , size);
	sort(a , a + size);
	int ns = 1;
	luck[0] = a[0];
	for (int i = 1; i < size; i ++)
		if (a[i] != a[i-1])
		{
			luck[ns ++] = a[i];
		}
	luck[ns ++] = 1000000000001LL;
	//printf("%d\n" , ns);
	int n;
	scanf("%d" , &n);
	while (n --)
	{
		i64d A , B;
		scanf("%lld %lld" , &A , &B);
		int res = 0 , start , end;
		int l = 0 , h = ns-1 , m;
		while (l < h)
		{
			m = (l+h) >> 1;
			if (luck[m] >= A) h = m;
			else if (luck[m] < A) l = m+1;
		}
		start = h;
		l = 0; h = ns - 1;
		while (l < h)
		{
			m = (l+h) >> 1;
			if (luck[m] > B) h = m;
			else if (luck[m] <= B) l = m+1;
		}
		end = h;
		printf("%d\n" , end - start);
	}
	return 0;
}