#include <stdio.h>

int main()
{
int p[14] = {0,6,12,90,360,2040,10080,54810,290640,1588356,8676360,47977776,266378112,1488801600};
int t , n;

	scanf("%d" , &t);
	while (t --)
	{
		scanf("%d" , &n);
		printf("%d\n" , p[n-1]);
	}
	return 0;
}