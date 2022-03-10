#include <iostream.h>
#include <string.h>

int main()
{
char s[10][50] , ss[50];
int L[10];
int n , i , j , x , bo , k , num;

    num = 0;
    while (cin >> s[0])
    {
        num ++;
        L[0] = strlen(s[0]);
        n = 0;
        do
        {
            n ++;
            cin >> s[n];
            L[n] = strlen(s[n]);
        }
        while (s[n][0] != '9');
        for (i = 0; i < n; i ++)
            for (j = 1; j < n - i; j ++)
                if (L[j-1] > L[j])
                {
                    x = L[j-1]; L[j-1] = L[j]; L[j] = x;
                    strcpy(ss , s[j-1]); strcpy(s[j-1] , s[j]); strcpy(s[j] , ss);
                }
		bo = 1;
		cout << "Set " << num;
		for (i = 0; i < n; i ++)
		{
			for (j = i + 1; j < n; j ++)
				if (L[i] < L[j])
				{
					bo = 0;
					for (k = 0; k < L[i]; k ++)
						if (s[i][k] != s[j][k]) {bo = 1; break;}
					if (bo == 0)
					{
						cout << " is not immediately decodable" << endl;
						break;
					}
				}
			if (bo == 0) break;
		}
		if (bo) cout << " is immediately decodable" << endl;
	}
    return 0;
}    
