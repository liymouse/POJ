#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define max(a,b) ((a)>(b)?(a):(b))
#define M 11
int main()
{
    int n;
    char line[M][260];
    char has5[M] = { 0 };
    char con[256] = { 0 };
    con['A'] = con['E'] = con['I'] = con['O'] = con['U'] = con['Y'] = 1;
    con['a'] = con['e'] = con['i'] = con['o'] = con['u'] = con['y'] = 1;
    for (int i = 'a'; i <= 'z'; i++) con[i] = 1 - con[i];
    for (int i = 'A'; i <= 'Z'; i++) con[i] = 1 - con[i];
    scanf("%d", &n);
    gets_s(line[0]);
    for (int i = 0; i < n; i++)
    {
        int cur_id = i % M;
        gets_s(line[cur_id]);
        int has6 = 0;
        int L = 0;
        has5[cur_id] = 0;
        for (int j = 0; line[cur_id][j] != 0; j ++)
            if (con[line[cur_id][j]])
            {
                L++;
                if (L > 4) has5[cur_id] = 1;
                if (L > 5) has6 = 1;
            }
            else L = 0;
        if (has6) { printf("n\n"); continue; }
        int has5_num = 0;
        int same_num = 0;
        for (int j = max(i - 10, 0); j < i; j++)
        {
            if (!strcmp(line[j%M], line[cur_id])) same_num++;
            if (has5[j%M]) has5_num++;
        }
        if (same_num > 1) printf("n\n");
        else if (has5[cur_id] == 1 && has5_num > 2) printf("n\n");
        else printf("y\n");
    }
    return 0;
}
