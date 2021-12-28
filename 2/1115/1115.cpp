#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <vector>
#include <map>
using namespace std;

typedef struct
{
    char key[5];
    //vector<pair<char, int> > ans;
    map<char, int> ans;
    char org[12][100];
    int line_num;
}Ques;
char ans[10001][101];

int main()
{
    char survey[110];
    Ques qu[100];
    int qnum = 0;
    int anum = 0;
    char s[200];
    gets_s(survey);
    gets_s(s);
    while (1)
    {
        //get key
        qu[qnum].key[0] = s[0]; qu[qnum].key[1] = s[1]; qu[qnum].key[2] = s[2]; qu[qnum].key[3] = 0;
        qu[qnum].line_num = 0;
        strcpy(qu[qnum].org[qu[qnum].line_num++], s);
        int id = 0;
        while (gets_s(s))
        {
            if (s[0] != ' ') break;
            strcpy(qu[qnum].org[qu[qnum].line_num++], s);
            qu[qnum].ans[s[1]] = id ++;
        }
        qnum++;
        if (s[0] == '#') break;
    }
    //get ans
    while (gets_s(ans[anum]))
    {
        if (ans[anum][0] == '#') break;
        anum++;
    }
    while (gets_s(s))
    {
        if (s[0] == '#') break;
        char q1[4] = { s[0],s[1],s[2],0 };
        char q2[4] = { s[4],s[5],s[6],0 };
        char table[200] = { 0 };
        strcpy(table, s + 8);

        int x = -1, y = -1;
        for (int i = 0; i < qnum; i ++)
            if (strcmp(q1, qu[i].key) == 0) { x = i; break; }
        for (int i = 0; i < qnum; i ++)
            if (strcmp(q2, qu[i].key) == 0) { y = i; break; }
        int L1[11][11] = { 0 }; //num
        int L2[11][11] = { 0 }; //percent in row
        int L3[11][11] = { 0 }; //percent in col
        for (int i = 0; i < anum; i++)
        {
            int idx = qu[x].ans[ans[i][x]];
            int idy = qu[y].ans[ans[i][y]];
            L1[idx][idy] ++;
        }
        int nx = qu[x].ans.size();
        int ny = qu[y].ans.size();
        for (int i = 0; i < nx; i++)
        {
            for (int j = 0; j < ny; j++)
            {
                L1[i][ny] += L1[i][j];
                L1[nx][j] += L1[i][j];
                L1[nx][ny] += L1[i][j];
            }
        }
        for (int i = 0; i <= nx; i++)
        {
            for (int j = 0; j < ny; j++)
            {
                if (L1[i][ny] == 0) L2[i][j] = -1;
                else L2[i][j] = L1[i][j] * 100 / L1[i][ny];
                L2[i][ny] += L2[i][j];
            }
            if (L2[i][ny] > 0)
            {
                int last = 100 - L2[i][ny];
                L2[i][ny] = 100;
                for (int j = 0; j < ny; j ++)
                    if (last > 0 && L1[i][j] * 100 % L1[i][ny] != 0)
                    {
                        L2[i][j] ++;
                        last--;
                    }
            }
        }
        for (int j = 0; j <= ny; j++)
        {
            for (int i = 0; i < nx; i++)
            {
                if (L1[nx][j] == 0) L3[i][j] = -1;
                else L3[i][j] = L1[i][j] * 100 / L1[nx][j];
                L3[nx][j] += L3[i][j];
            }
            if (L3[nx][j] > 0)
            {
                int last = 100 - L3[nx][j];
                L3[nx][j] = 100;
                for (int i = 0; i < nx; i++)
                    if (last > 0 && L1[i][j] * 100 % L1[nx][j] != 0)
                    {
                        L3[i][j] ++;
                        last--;
                    }
            }
        }
        printf("%s - %s\n", survey, table);
        for (int i = 0; i < qu[x].line_num; i++) printf("%s\n", qu[x].org[i]);
        for (int i = 0; i < qu[y].line_num; i++) printf("%s\n", qu[y].org[i]);
        printf("\n");
        //1st line
        printf("      ");
        for (int j = 0; j < ny; j++) printf(" %s:%c", qu[y].key, qu[y].org[j + 1][1]);
        printf(" TOTAL\n");
        for (int i = 0; i <= nx; i++)
        {
            //3 lines
            if (i < nx) printf(" %s:%c", qu[x].key, qu[x].org[i + 1][1]);
            else printf(" TOTAL");
            for (int j = 0; j <= ny; j++) printf("%6d", L1[i][j]);
            printf("\n");
            printf("      ");
            for (int j = 0; j <= ny; j++)
                if (L2[i][j] < 0) printf("     -");
                else printf("%5d%%", L2[i][j]);
            printf("\n");
            printf("      ");
            for (int j = 0; j <= ny; j++)
                if (L3[i][j] < 0) printf("     -");
                else printf("%5d%%", L3[i][j]);
            printf("\n");
        }
        printf("\n");
    }
    return 0;
}