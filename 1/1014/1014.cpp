#include <iostream.h>

int main()
{
int a[7] , i , j , done;
long tot , n;

    n = 0;
    while (cin >> a[1])
    {
		tot = a[1];
		for (i = 2; i <= 6; i ++)
		{cin >> a[i]; tot += a[i] * i;}
		if (tot == 0) break;
		cout << "Collection #" << ++n << ":" << endl;
		if (tot % 2 == 1) cout << "Can't be divided." << endl << endl;
		else
		{
            done = 1;
            for (i = 6; i >= 1; i --)
                if (a[i] % 2 != 0)
                {
                    done = 0;
                    for (j = i-1; j >= i/2; j --)
                        if ((a[j] > 0) && (a[i-j] > 0))
                        {
                            done = 1;
                            a[j] --; a[i-j] --;
                            break;
                        }
                   if (done == 0) 
                   {
                       cout << "Can't be divided." << endl << endl;
                       break;
                   }    
                }
            if (done) cout << "Can be divided." << endl << endl;
        }    
    }    
    return 0;
}    
