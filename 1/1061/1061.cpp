#include <stdio.h>
#include <math.h>

__int64 p , q;

__int64 exgcd(__int64 a , __int64 b)
{
__int64 t , z;

    if (b == 0) {z = a; p = 1; q = 0; return z;}
    else
    {
        z = exgcd(b , a % b);
		t = p; 
		p = q; 
		q = t - (a / b) * q;
		return z;
    }
}

int main()
{
__int64 x , y , m , n , L , a , b , c , k , change;

	scanf("%I64d %I64d %I64d %I64d %I64d" , &x , &y , &m , &n , &L);
	a = m - n; b = L; c = y - x; change = 0;
	if (fabs(a) < fabs(b)) {k = a; a = b; b = k; change = 1;}
	k = exgcd(a , b);
	if (k == 0) printf("Impossible\n");
	else if ((c % k) != 0) printf("Impossible\n");
	else 
	{
		p = c / k * p; q = c / k * q;
		b = b / k; a = a / k;
		if (change == 1) {k = p; p = q; q = k; k = a;}
		else k = b;
		if (k < 0) k = -k;
		if (p < 0) {c = -p / k + 1; p += c * k;}
		else {c = p / k; p -= c * k;}
		printf("%I64d\n" , p);
	}
	return 0;
}