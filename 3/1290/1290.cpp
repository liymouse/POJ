#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
char c[7][3][3];
void rotate(int r)
{
    int face[2][4][2] = { { {0,0},{0,2},{2,2},{2,0} }, { {0,1},{1,2},{2,1},{1,0}} };
    int bian[6][3][4][3] = {
        { { {5,0,0},{2,0,0},{6,0,0},{4,2,2} }, { {5,1,0},{2,1,0},{6,1,0},{4,1,2} }, { {5,2,0},{2,2,0},{6,2,0},{4,0,2} } },
        { { {5,2,0},{3,0,0},{6,0,2},{1,2,2} }, { {5,2,1},{3,1,0},{6,0,1},{1,1,2} }, { {5,2,2},{3,2,0},{6,0,0},{1,0,2} } },
        { { {5,2,2},{4,0,0},{6,2,2},{2,2,2} }, { {5,1,2},{4,1,0},{6,1,2},{2,1,2} }, { {5,0,2},{4,2,0},{6,0,2},{2,0,2} } },
        { { {5,0,0},{1,2,0},{6,2,2},{3,0,2} }, { {5,0,1},{1,1,0},{6,2,1},{3,1,2} }, { {5,0,2},{1,0,0},{6,2,0},{3,2,2} } },
        { { {2,0,0},{1,0,0},{4,0,0},{3,0,0} }, { {2,0,1},{1,0,1},{4,0,1},{3,0,1} }, { {2,0,2},{1,0,2},{4,0,2},{3,0,2} } },
        { { {2,2,0},{3,2,0},{4,2,0},{1,2,0} }, { {2,2,1},{3,2,1},{4,2,1},{1,2,1} }, { {2,2,2},{3,2,2},{4,2,2},{1,2,2} } }
    };
    int f = abs(r);
    //face rotate
    int sk = r > 0 ? 3 : 0;
    int ek = r > 0 ? 0 : 3;
    int d  = r > 0 ? -1 : 1;
    for (int i = 0; i < 2; i++)
    {
        char tmp = c[f][face[i][sk][0]][face[i][sk][1]];
        for (int k = sk; k != ek; k+= d)
            c[f][face[i][k][0]][face[i][k][1]] = c[f][face[i][(k+d+4) % 4][0]][face[i][(k+d+4) % 4][1]];
        c[f][face[i][ek][0]][face[i][ek][1]] = tmp;
    }
    for (int i = 0; i < 3; i++)
    {
        char tmp = c[bian[f - 1][i][sk][0]][bian[f - 1][i][sk][1]][bian[f - 1][i][sk][2]];
        for (int k = sk; k != ek; k += d)
            c[bian[f-1][i][k][0]][bian[f - 1][i][k][1]][bian[f - 1][i][k][2]] = c[bian[f - 1][i][(k+d+4)%4][0]][bian[f - 1][i][(k + d + 4) % 4][1]][bian[f - 1][i][(k + d + 4) % 4][2]];
        c[bian[f - 1][i][ek][0]][bian[f - 1][i][ek][1]][bian[f - 1][i][ek][2]] = tmp;
    }
}

int check()
{
    for (int f = 1; f <= 6; f++)
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                if (c[f][i][j] != c[f][0][0]) return 0;
    return 1;
}
int main()
{
    int ca;
    scanf("%d", &ca);
    while (ca--)
    {
        char s[10];
#define Read(face,row,col) do {scanf("%s",s); c[face][row][col] = s[0]; }while(0)
        for (int i = 0; i < 3; i ++)
            for (int j = 0; j < 3; j++)
            {
                Read(5, i, j);
            }
        for (int i = 0; i < 3; i ++)
            for (int f = 1; f <= 4; f ++)
                for (int j = 0; j < 3; j++)
                {
                    Read(f, i, j);
                }
        for (int i = 0; i < 3; i ++)
            for (int j = 0; j < 3; j++)
            {
                Read(6, i, j);
            }
#undef Read
        int r;
        while (scanf("%d", &r) == 1)
        {
            if (r == 0) break;
            rotate(r);
        }
        if (check()) printf("Yes, grandpa!\n");
        else printf("No, you are wrong!\n");
    }
    return 0;
}