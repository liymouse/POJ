#include <iostream.h>

int main()
{
int a[16] , b[16] , c[16];
int x , y , z , k;
long d , min;
int i , j;

    for (i = 0; i < 16; i ++)
        cin >> a[i] >> b[i] >> c[i];
    while (cin >> x >> y >> z)
    {
        if ((x == -1) && (y == -1) && (z == -1)) break;
        min = 10000000;
        for (i = 0; i < 16; i ++)
        {
            d = (a[i]-x)*(a[i]-x)+(b[i]-y)*(b[i]-y)+(c[i]-z)*(c[i]-z);
            if (d < min) {min = d; k = i;}
        }
        cout << "(" << x << "," << y << "," << z << ")";
        cout << " maps to ";
        cout << "(" << a[k] << "," << b[k] << "," << c[k] << ")\n";
    }    
    return 0;
}    
