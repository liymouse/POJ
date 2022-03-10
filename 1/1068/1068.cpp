#include <iostream.h>

int main()
{
int t , n , i , j , k , b , L , x , y , tot;
char s[100];
int a[20] , c[20];

    cin >> t;
    for (i = 0; i < t; i ++)
    {
        cin >> n;
        for (j = 0; j < n; j ++)
            cin >> a[j];
		k = 0; L = 0;
		for (j = 0; j < n; j ++)
		{
			for (b = k; b < a[j]; b ++)
                s[L++] = '(';
            s[L++] = ')';
            k = a[j];
        }
        tot = 0;
        for (j = 0; j < L; j ++)
        {
            if (s[j] == ')')
            {
                k = 1; x = 1; b = j;
                do
                {
                    b --;
                    if (s[b] == ')') {k ++; x ++;}
                    else if (s[b] == '(') x --;
                }    
				while (x != 0);
				c[tot++] = k;
			}
		}
        for (j = 0; j < n - 1; j ++)
            cout << c[j] << " ";
        cout << c[n-1] << endl;
    }    
    return 0;
}    
