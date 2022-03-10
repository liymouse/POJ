#include <stdio.h>

int main()
{
	int t , n;
	scanf("%d" , &t);
	while (t --)
	{
		int m1 = 0, m2 = 0, m3 = 0;
		scanf("%d" , &n);
		for (int i = 0; i < 10; i ++)
		{
			int x;
			scanf("%d" , &x);
			if (x >= m1)
			{
				m3 = m2; m2 = m1; m1 = x;
			}
			else if (x >= m2)
			{
				m3 = m2; m2 = x;
			}
			else if (x >= m3)
				m3 = x;
		}
		printf("%d %d\n" , n , m3);
	}
	return 0;
}
