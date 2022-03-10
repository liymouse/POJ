#include <iostream.h>

int main()
{
int t , m , k;
int x , y , i , j;

	cin >> t;
	for (k = 0; k < t; k ++)
	{
		cin >> m;
		if (m % 2 == 1)
		{
			for (i = 0; i < m; i ++) cin >> j;
			cout << "YES" << endl;
		}
		else
		{
			x = 0; y = 0;
			for (i = 0; i < m; i ++)
			{
				cin >> j;
				if ((j == 1) && (i % 2 == 0)) x ++;
				else if ((j == 1) && (i % 2 == 1)) y ++;
			}
			if ((x == y + 1) || (x == y)) cout << "YES" << endl;
			else cout << "NO" << endl;
		}
	}
    return 0;
}
