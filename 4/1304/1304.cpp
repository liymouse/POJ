#include <stdio.h>
#include <sstream>
using namespace std;
int main()
{
    char type[20];
    int n;
    int bus[20][10], tot[20], num[20];
    char s[1024];
    while (scanf("%s", type) == 1)
    {
        if (type[0] == 'E') break;
        scanf("%d", &n); gets_s(s);
        for (int i = 0; i < n; i++)
        {
            tot[i] = 0;
            gets_s(s);
            num[i] = 0;
            stringstream ss;
            ss.str(string(s));
            while (ss >> bus[i][num[i]])
            {
                tot[i] += bus[i][num[i]];
                if (num[i] > 0) bus[i][num[i]] += bus[i][num[i] - 1];
                num[i]++;
            }
        }
        int arr;
        scanf("%d", &arr);
        scanf("%s", type); //END
        int res = 1 << 30;
        for (int i = 0; i < n; i++)
        {
            int r = arr % tot[i];
            if (r == 0) { res = 0; break; }
            for (int j = 0; j < num[i]; j ++)
                if (r <= bus[i][j]) {
                    if (bus[i][j]-r < res) res = bus[i][j]-r;
                    break;
                }
        }
        printf("%d\n", res);
    }
    return 0;
}