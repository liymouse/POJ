#include <iostream.h>

main()
{
int n;
int y[20] , a[20] , b[20] , t[20];
int i , k , min , bo , tot , max;

    tot = 0;
    while (cin >> n)
    {
        if (n == 0) break;
        tot ++;
        for (i = 0; i < n; i ++)
        {
            cin >> y[i] >> a[i] >> b[i];
            t[i] = b[i] - a[i];
            while (y[i] - b[i] >= 0) y[i] -= b[i];
        }
        while (1)
        {
            bo = 0;
            for (i = 1; i < n; i ++)
                if (y[i] != y[i - 1]) {bo = 1; break;}
            if (bo == 0) break;
            min = 10000; max = 0;
            for (i = 0; i < n; i ++)
            {
                if (y[i] < min) {min = y[i]; k = i;}
                if (y[i] > max) max = y[i];
            }    
            while (y[k] < max) y[k] += t[k];
            if (y[k] >= 10000) {bo = 1; break;}
        }
        cout << "Case #" << tot << ":" << endl;
        if (bo) cout << "Unknown bugs detected." << endl;
        else cout << "The actual year is " << y[0] << "." << endl;
        cout << endl;
    }
    return 0;
}
