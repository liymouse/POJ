#include <iostream.h>
#include <string.h>

int main()
{
char s1[19][10] = {"pop", "no", "zip", "zotz", "tzec", 
                "xul", "yoxkin", "mol", "chen", "yax", 
                "zac", "ceh", "mac", "kankin", "muan", 
                "pax", "koyab", "cumhu", "uayet"};
char s2[20][10] = {"imix", "ik", "akbal", "kan", "chicchan", 
                "cimi", "manik", "lamat", "muluk", "ok", 
                "chuen", "eb", "ben", "ix", "mem", 
                "cib", "caban", "eznab", "canac", "ahau"};
long n , i , j , k;
long d , y , m;
long tot;
char ss[30] , str[30] , c;

	cin >> n; cout << n << endl;
	for (i = 0; i < n; i ++)
	{
		cin >> d >> c >> str >> y;
		for (j = 0; j < 19; j ++)
		{
			k = 0;
			if (strcmp(s1[j] , str) == 0) {m = j; break;}
		}
		tot = y * 365;
		tot += m * 20 + d + 1;
		d = tot % 13;
		if (d == 0) d = 13;
        m = tot % 20;
        if (m == 0) m = 20;
        y = tot / 260;
        if (tot % 260 == 0) y --;
        cout << d << " " << s2[m-1] << " " << y << endl;
    }
    return 0;
}
