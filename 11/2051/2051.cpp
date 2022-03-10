#include <stdio.h>
#include <algorithm>
using namespace std;

struct kk {int id , pre , time;} a[3000];

bool cmp(kk &x , kk &y)
{
	return x.id < y.id;
}

int main()
{
int k , min , i , n , b[3000] , t;
char s[10];

	n = 0;
	while (scanf("%s" , s) == 1)
	{
		if (s[0] == '#') break;
		scanf("%d %d" , &a[n].id , &a[n].pre);
		a[n].time = a[n].pre; n ++;
	}
	scanf("%d" , &k);
	sort(a , a + n , cmp);
	while (1)
	{
		min = 99999999; t = 0;
		for (i = 0; i < n; i ++) if (a[i].time < min) min = a[i].time;
		for (i = 0; i < n; i ++) if (a[i].time == min) b[t ++] = i;
		for (i = 0; i < t; i ++) 
		{
			k --; 
			if (k >= 0) {printf("%d\n" , a[b[i]].id); a[b[i]].time += a[b[i]].pre;}
			else break;
		}
		if (k < 0) break;		
	}
	return 0;
}