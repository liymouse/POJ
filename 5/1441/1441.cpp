#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <vector>
#include <string>
using namespace std;
typedef unsigned char uint8;
#define max(a,b) ((a)>(b)?(a):(b))

//#define TEST
#ifdef TEST
uint8 m[12] = "|*\\[tT$-+]/";
uint8 mo[12] = { 179, 180, 191, 192, 193, 194, 195, 196, 197, 217, 218 };
#else //TEST
uint8 m[12] = { 179, 180, 191, 192, 193, 194, 195, 196, 197, 217, 218 };
#endif

vector<vector<uint8> > table[100][255];

int main()
{
#ifdef TEST
    freopen("1441a.in", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    uint8 s[260];
    int col[255] = { 0 }, row[100] = { 0 };
    int c = 0, r = 0;
    while (gets_s((char*)s, 260))
    {
        int j = 0;
        if (s[j] == m[6] || s[j] == m[3]) r++; // |-
        else if (s[j] == m[0]) // |
        {
            row[r] ++;
            c = 0;
            int x = j, y = j;
            j++;
            while (s[j] != 0)
            {
                //find end
                while (s[j] != m[0]) j++;
                y = j;

                x++; y--;
                while (s[x] == ' ') x++;
                while (s[y] == ' ') y--;
                int cL = y - x + 1;
                vector<uint8> a;
                for (int k = x; k <= y; k++) a.push_back(s[k]);
                table[r][c].push_back(a);
                col[c] = max(col[c], cL);
                x = j; j++; c++;
            }
        }
    }
    //1st line
    printf("%c", m[10]);
    for (int i = 0; i < c; i++)
    {
        for (int j = 0; j < col[i] + 2; j++) printf("%c", m[7]);
        if (i != c - 1) printf("%c", m[5]); else printf("%c", m[2]);
    }
    printf("\n");
    for (int i = 0; i < r; i++)
    {
        for (int ii = 0; ii < row[i]; ii++)
        {
            printf("%c", m[0]);
            for (int j = 0; j < c; j++)
            {
                printf(" ");
                if (ii < table[i][j].size())
                {
                    for (int k = 0; k < table[i][j][ii].size(); k++) printf("%c", table[i][j][ii][k]);
                    for (int k = 0; k < col[j] - table[i][j][ii].size(); k++) printf(" ");
                    
                }
                else
                {
                    for (int k = 0; k < col[j]; k++) printf(" ");
                }
                printf(" %c", m[0]);
            }
            printf("\n");
        }
        if (i == r - 1) printf("%c", m[3]);
        else printf("%c", m[6]);
        for (int j = 0; j < c; j++)
        {
            for (int k = 0; k < col[j] + 2; k++) printf("%c", m[7]);
            if (j != c - 1)
            {
                if (i == r - 1) printf("%c", m[4]); else printf("%c", m[8]);
            }
            else
            {
                if (i == r - 1) printf("%c", m[9]); else printf("%c", m[1]);
            }
        }
        printf("\n");
    }
    return 0;
}
