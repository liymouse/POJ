#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <vector>
using namespace std;
#define min(a,b) ((a)<(b)?(a):(b))

int main()
{
    int ca;
    scanf("%d", &ca);
    while (ca--)
    {
        int A, K;
        scanf("%d %d", &A, &K);
        int a[26];
        char str[1000] = { 0 };
        int c[26][26] = { 0 };
        char s[2][1000];
        for (int i = 0; i < A; i++) a[i] = -1;
        int ok = 1;
        int p = 0, q = 1;
        scanf("%s", s[0]);
        for (int i = 1; i < K; i++)
        {
            scanf("%s", s[q]);
            int k = 0;
            int Li = strlen(s[p]);
            int Lj = strlen(s[q]);
            while (s[p][k] == s[q][k] && k < Li && k < Lj) k++;
            if (s[p][k] != 0 && s[q][k] != 0)
                c[s[p][k] - 'a'][s[q][k] - 'a'] = 1;
            p = 1 - p;
            q = 1 - q;
        }
        while (!str[0]) gets_s(str);
        int rank = 0;
        int degree[26] = { 0 };
        for (int i = 0; i < A; i++)
            for (int j = 0; j < A; j++)
                degree[j] += c[i][j];
        int mark[26] = { 0 };
        while (1)
        {
            vector<int> out;
            for (int i = 0; i < A; i++)
                if (mark[i] == 0 && degree[i] == 0) out.push_back(i);
            if (out.size() == 0) break;
            if (out.size() == 1) //fix
            {
                a[out[0]] = rank;
            }
            for (int i = 0; i < out.size(); i++)
            {
                mark[out[i]] = 1;
                for (int j = 0; j < A; j++)
                    if (c[out[i]][j]) degree[j] --;
            }
            rank += out.size();
        }
        int L = strlen(str);
        for (int i = 0; i < L; i ++)
            if ('a' <= str[i] && str[i] < 'a' + A && a[str[i] - 'a'] == -1) { ok = 0; break; }
        if (!ok) printf("Message cannot be decrypted.\n");
        else
        {
            for (int i = 0; i < L; i++)
                if ('a' <= str[i] && str[i] < 'a' + A) printf("%c", a[str[i] - 'a'] + 'a');
                else printf("%c", str[i]);
            printf("\n");
        }
    }
    return 0;
}
