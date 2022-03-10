#include <iostream.h>

int main()
{
long m;
int k , i , n , done , out;

    while (cin >> k)
    {
        if (k == 0) break; 
        m = k; n = 2 * k;
        while (1)
        {
            done = 1;
            do
                m ++;
            while ((m % n >= 1) && (m % n <= k));
            out = 1;
            for (i = 0; i < k; i ++)
            {
                out = (out - 1 + m) % (n - i);
                if (out == 0) out = n - i;
                if (out <= k) {done = 0; break;}
            }
            if (done) {cout << m << endl; break;}
        }    
    }    
    return 0;
}    
