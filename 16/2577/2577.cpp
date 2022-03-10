#include <stdio.h>
#include <string.h>
int main()
{
int p[1000] = {0} , rg[10] = {0};
int n , ps , r , a , b , c;
	
	n = 0; r = 1; ps = 0;
	while (scanf("%d" , &p[n ++]) == 1);
    while(p[ps] != 100)
    {
        r ++;
		a = p[ps] / 100;
		b = (p[ps] % 100) / 10;
		c = p[ps] % 10;
        switch(a)
        {
            case 2:
                rg[b]=c; 
                break;
            case 3:
                rg[b] = (rg[b] + c) % 1000; 
                break;
            case 4:
                rg[b] = (rg[b] * c) % 1000; 
                break;
            case 5:
                rg[b] = rg[c]; 
                break;
            case 6:
                rg[b] = (rg[b] + rg[c]) % 1000;
                break;
            case 7:
                rg[b] = (rg[b] * rg[c]) % 1000; 
                break;
            case 8:
                rg[b] = p[rg[c]]; 
                break;
            case 9:
                p[rg[c]] = rg[b]; 
                break;
            case 0:
                if (rg[c]) ps = rg[b] - 1;
                break;
        }    
        ps ++;
    }
    printf("%d\n" , r);
    return 0;
}