#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

struct pt{double x , y;};
struct interval{double a , b;};

const double pi = acos(-1.0);

bool cmp(interval s1 , interval s2)
{
	return s1.a < s2.a || s1.a == s2.a && s1.b < s2.b;
}

double angle(pt p)
{
    double r , alpha;

	r = sqrt(p.x * p.x + p.y * p.y);
	alpha = acos(p.x / r);
	if (p.y < 0) alpha = 2 * pi - alpha;
	return alpha;
}

double angfun(pt p[] , int n)
{
	int i , m , t;
	interval s[110];
	double a , b ,total;

	p[n] = p[0]; m = 0;
	for (i = 0; i < n; i ++)
	{
		a = angle(p[i]);
		b = angle(p[i+1]);
		if (a > b) swap(a , b);
		if (b - a < pi)
		{
			s[m].a = a;
			s[m].b = b;
			m ++;
		}
		else
		{
			s[m].a = 0;
			s[m].b = a;
			m ++;
			s[m].a = b;
			s[m].b = 2 * pi;
			m ++;
		}
	}
	sort(s , s + m , cmp);

	t = 0;
	for (i = 1; i < m; i ++)
		if (s[i].a <= s[t].b)
		{
			if (s[t].b < s[i].b) s[t].b = s[i].b;
		}
		else s[++ t] = s[i];
	total = 0;
	for (i = 0; i <= t; i ++) total += s[i].b - s[i].a;
	return total;
}

int main()
{
double k , h;
pt p[110];
int n , i;

	scanf("%lf %lf %d" , &k , &h , &n);
	for (i = 0; i < n; i ++) scanf("%lf %lf" , &p[i].x , &p[i].y);
	printf("%.2lf\n" , k * h * angfun(p , n));
	return 0;
}
