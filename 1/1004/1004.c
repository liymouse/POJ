#include <stdio.h>

int main()
{
float a[12];
int i;
float ave = 0;

    for (i = 0; i < 12; i ++)
    {
        scanf("%f" , &a[i]);
        ave += a[i];
    }    
    ave = ave / 12.0;
    printf("$%.2f\n" , ave);
    return 0;
}
