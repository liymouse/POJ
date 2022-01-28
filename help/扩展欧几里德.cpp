/////////////////////////////
//可以快速的求出一组整数解 //
/////////////////////////////
#include <stdio.h>
#include <math.h>

int exgcd(int a , int b , int *x , int *y)
{
int t , z;

    if (b == 0) {z = a; *x = 1; *y = 0; return z;}
    else
    {
        z = exgcd(b , a % b , x , y);
		t = *x; *x = *y; *y = t - (a / b) * *y;
		return z;
    }
}

int main()
{
int a , b , c , k , x , y , change = 0;

    printf("Please input a , b , c (aX + bY = c) : ");
    scanf("%d %d %d" , &a , &b , &c);
    if (fabs(a) < fabs(b)) {k = a; a = b; b = k; change = 1;}
    k = exgcd(a , b , &x , &y);
    if ((c % k) != 0) printf("No solution\n");
    else 
    {
        x = x * c / k; y = y * c / k;
        if (change == 1) {k = x; x = y; y = k;}
        printf("X = %ld Y = %ld\n" , x , y);
    }
    getchar(); getchar();
    return 0;
}
