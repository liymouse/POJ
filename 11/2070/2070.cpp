#include <stdio.h>

int main()
{
double x[3] = {4.5 , 150 , 200};
double y[3] = {6.0 , 300 , 500};
double z[3] = {5.0 , 200 , 300};
double a , b , c;
int have;

	while (scanf("%lf %lf %lf" , &a , &b , &c) == 3)
	{
		if (a == 0) break;
		have = 0;
		if ((x[0] >= a) && (x[1] <= b) && (x[2] <= c)) {printf("Wide Receiver"); have ++;}
		if ((y[0] >= a) && (y[1] <= b) && (y[2] <= c)) {if (have) printf(" "); printf("Lineman"); have ++;}
		if ((z[0] >= a) && (z[1] <= b) && (z[2] <= c)) {if (have) printf(" "); printf("Quarterback"); have ++;}
		if (!have) printf("No positions");
		printf("\n");
	}
	return 0;
}