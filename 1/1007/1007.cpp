#include <iostream.h>

int main()
{
char s[100][60] , c;
int a[100];
int m , n , i , j , k;

    cin >> n >> m;
    for (i = 0; i < m; i ++)
    {
        cin >> s[i];
        a[i] = 0;
        for (j = 0; j < n; j ++)
            for (k = j+1; k < n; k ++)
                if (s[i][j] > s[i][k]) a[i] ++;
    }
    for (i = 0; i < m; i ++)
        for (j = 1; j < m - i; j ++)
            if (a[j-1] > a[j])
            {
                for (k = 0; k < n; k ++) 
                {
                    c = s[j-1][k];
                    s[j-1][k] = s[j][k];
                    s[j][k] = c;
                }
                k = a[j-1]; a[j-1] = a[j]; a[j] = k;
            }
    for (i = 0; i < m; i ++)
        cout << s[i] << endl;
    cin >> n;
    return 0;
}    
