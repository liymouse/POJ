#include <iostream.h>

int main()
{
int n , h , time;
int f[26] , d[26] , t[26] , fish[26] , ti[26] , maxt[26];
int i , j , tot , ans , max , k , bo;

	while (cin >> n)
    {
        if (n == 0) break;
        cin >> h;
        ans = 0;
        for (i = 0; i < n; i ++) cin >> f[i];
        for (i = 0; i < n; i ++) cin >> d[i];
        for (i = 0; i < n-1; i ++) cin >> t[i];
		for (i = 0; i < n; i ++) maxt[i] = 0;
		for (i = 0; i < n; i ++)
		{
			tot = 0; time = h * 60;
			for (j = 0; j <= i; j ++) fish[j] = f[j];
			for (j = 0; j < n; j ++) ti[j] = 0;
			for (j = 0; j < i; j ++) time -= t[j] * 5;
			while (time > 0)
			{
				max = 0;
				for (j = 0; j <= i; j ++)
					if (fish[j] > max) {max = fish[j]; k = j;}
				if (max != 0)
				{
					tot += fish[k]; fish[k] -= d[k];
					ti[k] += 5; time -= 5;
				}
				else break;
			}
			if (tot > ans)
			{
				ans = tot;
				for (j = 0; j < n; j ++) maxt[j] = ti[j];
				if (time > 0) maxt[0] += time;
			}
			else if (tot == ans)
			{
			    ti[0] += time; bo = 0;
			    for (j = 0; j < n; j ++) 
                     if (ti[j] < maxt[j]) {bo = 1; break;}
                     else if (ti[j] > maxt[j]) break;
                if (bo == 0)
                    for (j = 0; j < n; j ++) maxt[j] = ti[j];
			}
		}
		for (i = 0; i < n-1; i ++) cout << maxt[i] << ", ";
		cout << maxt[n-1] << endl;
		cout << "Number of fish expected: "<< ans << endl << endl;
	}
	return 0;
}

