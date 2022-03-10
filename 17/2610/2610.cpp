#include <stdio.h>

int main()
{
struct hole{double x , y;}holes[1000];
double dx , dy , gx , gy , dd , gd , min;
int i , n , k;

	scanf("%lf %lf %lf %lf" , &gx , &gy , &dx , &dy);
	n = 0; min = 99999999; k = -1;
	while (scanf("%lf %lf" , &holes[n].x , &holes[n].y) == 2) n ++;
	for (i = 0; i < n; i ++)
	{
		dd = (holes[i].x - dx) * (holes[i].x - dx) + (holes[i].y - dy) * (holes[i].y - dy);
		gd = (holes[i].x - gx) * (holes[i].x - gx) + (holes[i].y - gy) * (holes[i].y - gy);
		if (4 * gd < dd) {min = gd; k = i;}
	}
	if (k == -1) printf("The gopher cannot escape.\n");
	else printf("The gopher can escape through the hole at (%.3lf,%.3lf).\n" , holes[k].x , holes[k].y);
	return 0;
}