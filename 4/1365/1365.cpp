#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <sstream>
using namespace std;

int c[182] = { 0 };
vector<int> prime;

int main()
{
    for (int i = 2; i * i < 182; i ++)
        if (c[i] == 0)
        {
            for (int k = i + i; k < 182; k += i) c[k] = 1;
        }
    for (int i = 2; i < 182; i++) if (c[i] == 0) prime.push_back(i);
    char s[1024];
    while (gets_s(s))
    {
        stringstream ss(s);
        int a = 0;
        int x, y;
        while (ss >> x >> y)
        {
            if (a == 0) a = 1;
            for (int i = 0; i < y; i++) a *= x;
        }
        if (a == 0) break;
        a--;
        vector<int> res;
        vector<int> resn;
        for (int i = prime.size() - 1; i >= 0; i --)
            if (a % prime[i] == 0)
            {
                int num = 0;
                while (a % prime[i] == 0) { num++; a /= prime[i]; }
                res.push_back(prime[i]);
                resn.push_back(num);
                if (a == 1) break;
            }
        int k = 0;
        if (a != 1) printf("%d 1", a);
        else {
            printf("%d %d", res[0], resn[0]); k = 1;
        }
        for (int i = k; i < res.size(); i++) printf(" %d %d", res[i], resn[i]);
        printf("\n");
    }
    return 0;
}