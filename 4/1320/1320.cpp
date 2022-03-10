#include <stdio.h>
#include <math.h>

int main()
{
int tot;
double n , x , t;

	freopen("1320.txt" , "w" , stdout);
	printf("         6         8\n");
	printf("        35        49\n");
	n = 50; tot = 2;
	while (tot < 10)
	{
		t = (n * n + n) / 2;
		if (floor(sqrt(t)) * floor(sqrt(t)) == t) 
		{
			x = floor(sqrt(t));
			printf("%10.0lf%10.0lf\n" , x , n);
			tot ++;
		}
		n ++;
	}
	return 0;
}