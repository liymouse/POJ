#include <iostream.h>
#include <string.h>

int n , i , j , k , t , p , x , y , done;
char a[3][12] , b[3][12] , s[10];
int c[3] , w[12];

void right(char z[] , int ww)
{
    done = 1;
    for (t = 0; t < 12; t ++) w[t] = 0;
    w[z[k] - 'A'] = ww;
    for (t = 0; t < 3; t ++)
    {
        x = 0; y = 0;
        for (p = 0; p < strlen(a[t]); p ++)
            x += w[a[t][p] - 'A'];
        for (p = 0; p < strlen(b[t]); p ++)
            y += w[b[t][p] - 'A'];
        if (x - y != c[t]) {done = 0; break;}
    }
}

void output (char x)
{
    cout << x;
    cout << " is the counterfeit coin and it is ";
    if (w[x - 'A'] > 0) cout << "heavy.\n";
    else cout << "light.\n";
}
        
int main()
{
    cin >> n;
    for (i = 0; i < n; i ++)
    {
        for (j = 0; j < 3; j ++)
        {
            cin >> a[j] >> b[j] >> s;
            if (s[0] == 'e') c[j] = 0;
            else if (s[0] == 'u') c[j] = 1;
                else if (s[0] == 'd') c[j] = -1;
        }
        for (j = 0; j < 3; j ++)
            if (c[j] != 0)
            {
                k = -1;
                while (a[j][++k] != 0)
                {
                    right(a[j] , 1);
                    if (done) {output(a[j][k]); break;}
                    right(a[j] , -1);
                    if (done) {output(a[j][k]); break;}
                    right(b[j] , 1);
                    if (done) {output(b[j][k]); break;}
                    right(b[j] , -1);
                    if (done) {output(b[j][k]); break;}
                }
                if (done) break;
            }    
    }    
    return 0;
}
