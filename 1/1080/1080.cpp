#include <iostream.h>

int main()
{
int v[5][5] = {{5 , -1 , -2 , -1 , -3} ,
			   {-1 , 5 , -3 , -2 , -4} ,
			   {-2 , -3 , 5 , -2 , -2} ,
			   {-1 , -2 , -2 , 5 , -1} ,
			   {-3 , -4 , -2 , -1 , 0}};
int f[101][101] , a[101] , b[101] , L1 , L2;
int n , i , j , h , tot , max;
char s[101];

    cin >> n;
	for (h = 0; h < n; h ++)
	{
		for (i = 0; i < 101; i ++) {a[i] = 0; b[i] = 0;}
		cin >> L1 >> s;
		for (i = 0; i < L1; i ++)
			if (s[i] == 'A') a[i] = 0;
			else if (s[i] == 'C') a[i] = 1;
				else if (s[i] == 'G') a[i] = 2;
					else if (s[i] == 'T') a[i] = 3;
		cin >> L2 >> s;
		for (i = 0; i < L2; i ++)
			if (s[i] == 'A') b[i] = 0;
			else if (s[i] == 'C') b[i] = 1;
				else if (s[i] == 'G') b[i] = 2;
					else if (s[i] == 'T') b[i] = 3;
		for (i = 0; i < 101; i ++) for (j = 0; j < 101; j ++) f[i][j] = 0;
		tot = 0;
		for (i = 0; i < L1; i ++) tot += v[a[i]][4];
		for (i = 0; i < L1; i ++)
		{
			f[i][L2] = tot;
			tot -= v[a[L1-i-1]][4];
		}
		tot = 0;
		for (i = 0; i < L2; i ++) tot += v[b[i]][4];
		for (i = 0; i < L2; i ++)
		{
			f[L1][i] = tot;
			tot -= v[b[L2-i-1]][4];
		}
		/*
		for (i = 0; i < L1; i ++)
            for (j = i; j < L1; j ++)
                f[i][L2] += v[a[j]][4];
        for (j = 0; j < L2; j ++)
            for (i = j; i < L2; i ++)
                f[L1][j] += v[b[i]][4];
        */
		for (i = L1 - 1; i >= 0; i --)
			for (j = L2 - 1; j >= 0; j --)
			{
				max = -10000;
				if (f[i+1][j] + v[a[i]][4] > max)
                    max = f[i+1][j] + v[a[i]][4];
                if (f[i][j+1] + v[b[j]][4] > max)
                    max = f[i][j+1] + v[b[j]][4];
				if (f[i+1][j+1] + v[a[i]][b[j]] > max)
					max = f[i+1][j+1] + v[a[i]][b[j]];
				f[i][j] = max;
            }
        cout << f[0][0] << endl;
    }
    return 0;
}

