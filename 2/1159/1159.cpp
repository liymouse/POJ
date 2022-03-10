#include <stdio.h>
#include <string.h>

int a[128] , b[128] , n , min;
char s[5001];

void deal(int x , int y)
{
int i , tot;

	memset(a , 0 , sizeof(a));
	memset(b , 0 , sizeof(b));
	tot = 0;
	for (i = 0; i < x; i ++) a[s[i]] ++;
	for (i = y; i < n; i ++) b[s[i]] ++;
	for (i = 0; i < 128; i ++) 
		if (a[i] > b[i]) tot += a[i] - b[i];
		else if (a[i] < b[i]) tot += b[i] - a[i];
	if (tot < min) min = tot;
}

int main()
{
int i , t;

	freopen("\1159Input\input.txt" , "r" , stdin);
	scanf("%d\n" , &n);
	for (i = 0; i < n; i ++) scanf("%c" , &s[i]);
	t = 0; min = 6000;
	while (t < n)
	{
		deal(t , t + 1);
		t ++;
		if ((t < n) && (s[t - 1] == s[t])) deal(t - 1 , t + 1);
	}
	printf("%d\n" , min);
	return 0;
}