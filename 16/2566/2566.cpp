#include <algorithm>
#include <cassert>
#include <iostream.h>

using namespace std;

static int seq[131072] , psum[131072] , perm[131072];

bool psum_cmp (const int a , const int b)
{
	return (psum[a] <= psum[b]);
}

int min (int x , int y)
{
	return x > y ? y : x;
}

int max (int x , int y)
{
	return x > y ? x : y;
}

int main ()
{
int n , k , i , t , bestT , bestLo , bestHi , p1 , p2 , sum;

	while (cin >> n >> k)
	{
		if (n == 0) break;
		for (i = 0 ; i < n ; i++) cin >> seq[i];
		for (i = 0 ; i < n ; i++) psum[0] = 0;
		for (i = 0 ; i < n ; i++) psum[i+1] = psum[i] + seq[i];
		for (i = 0 ; i <= n ; i++) perm[i] = i;
		sort (perm, perm+n+1, psum_cmp);
		while (k--)
		{
			cin >> t;
			bestT = psum[perm[1]] - psum[perm[0]];
			bestLo = perm[0];
			bestHi = perm[1];
			p1 = 0;
			p2 = 1;
			while (p2 <= n)
			{
				sum = psum[perm[p2]] - psum[perm[p1]];
				if (abs (sum - t) < abs (bestT - t))
				{
					bestT = sum;
					bestLo = perm[p1];
					bestHi = perm[p2];
				}
				if (p1 + 1 == p2 || sum < t) p2++;
				else p1++;
			}
			cout << bestT << " " << min (bestLo, bestHi) + 1 << " " << max (bestLo, bestHi) << endl;
		}
	}
	return 0;
}
