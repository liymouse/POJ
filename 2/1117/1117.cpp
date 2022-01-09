#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long lld;

lld p10[10] = { 1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000 };

int cmp(pair<int, int> &x, pair<int, int> &y)
{
    if (x.first == y.first) return x.second < y.second;
    return x.first < y.first;
}
int main()
{
    int n;
    scanf("%d", &n);
    int k = 0, s = n;
    while (s) { k++; s /= 10; }
    vector<pair<int, int> > res;
    //0 digit
    for (int b = 0; b < 10; b++)
        if ((n - b) % 11 == 0)
        {
            int a = (n - b) / 11;
            res.push_back(make_pair(10 * a + b, a));
        }
    //k-1 digit
    int x = n / p10[k - 1];
    int y = n % p10[k - 1];
    int x10 = n / p10[k - 2];
    int y10 = n % p10[k - 2];
    if (y % 2 == 0)
    {
        res.push_back(make_pair(x*p10[k - 1] + y / 2, y / 2));
    }
    if (x > 1 && (p10[k-1]+y) % 2 == 0)
    {
        res.push_back(make_pair((x - 1)*p10[k - 1] + (p10[k - 1] + y) / 2, (p10[k - 1] + y) / 2));
    }
    if (x10 == 10 && (p10[k-2]+y10) % 2 == 0)
    {
        res.push_back(make_pair(9 * p10[k - 2] + (p10[k - 2] + y10) / 2, (p10[k - 2] + y10) / 2));
    }
    for (int i = 1; i < k-1; i++)
    {
        int x = n / p10[i];
        int y = n % p10[i];
        if (y % 2 == 0)
        {
            for (int b = 0; b < 10; b++)
            {
                if ((x - b) % 11 == 0)
                {
                    int a = (x - b) / 11;
                    int c = y / 2;
                    res.push_back(make_pair((10 * a + b)*p10[i] + c, a*p10[i] + c));
                }
                if (x - 1 - b > 0 && (x - 1 - b) % 11 == 0)
                {
                    int a = (x - 1 - b) / 11;
                    int c = (p10[i] + y) / 2;
                    res.push_back(make_pair((10 * a + b)*p10[i] + c, a*p10[i] + c));
                }
            }
        }
    }
    sort(res.begin(), res.end(), cmp);
    int cnt = 0;

    for (int i = 0; i < res.size(); i++)
        if (i == 0 || (i > 0 && !(res[i].first == res[i - 1].first && res[i].second == res[i - 1].second))) cnt++;
    printf("%d\n", cnt);
    for (int i = 0; i < res.size(); i++)
        if (i == 0 || (i>0 && !(res[i].first == res[i-1].first && res[i].second == res[i-1].second)))
    {
        int s = res[i].first;
        int t = 0;
        while (s) { t++; s /= 10; }
        s = res[i].second;
        if (s == 0) t --;
        while (s) { t--; s /= 10; }
        t--;
        printf("%d + ", res[i].first);
        while (t--) printf("0");
        printf("%d = %d\n", res[i].second, n);
    }
    return 0;
}