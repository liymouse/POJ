#include <stdio.h>
#include <math.h>
#define Pi 3.14159265

int main()
{
int n , i , year;
float x , y , d;

    scanf("%d" , &n);
    year = 0;
    for (i = 0; i < n; i ++)
    {
        scanf("%f %f" , &x , &y);
        printf("Property %d: This property will begin eroding in year " , i + 1);
        d = x * x + y * y;
        year = floor(d * Pi / 100) + 1;
        printf("%d.\n" , year);
    }
    printf("END OF OUTPUT.\n");
    /*
    getchar(); getchar();
    */
    return 0;
}    
