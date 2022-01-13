#include <stdio.h>
#include <string.h>
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))

void init(int a[][64], int p[][2])
{
    for (int i = 0; i < 64; i++)
        for (int j = 0; j < 64; j++)
            a[i][j] = 1 << 10;
    for (int i = 0; i < 64; i++) a[i][i] = 0;
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
        {
            for (int k = 0; k < 8; k++)
            {
                int x = i + p[k][0];
                int y = j + p[k][1];
                if (0 <= x && x < 8 && 0 <= y && y < 8)
                {
                    a[i * 8 + j][x * 8 + y] = 1;
                }
            }
        }
    for (int k = 0; k < 64; k++)
        for (int i = 0; i < 64; i++)
            if (i != k)
                for (int j = 0; j < 64; j++)
                    if (j != k && j != i && a[i][k] + a[k][j] < a[i][j])
                        a[i][j] = a[i][k] + a[k][j];
}
int main()
{
    int a[64][64]; //knight step
    int b[64][64]; //king step
    char s[200];
    scanf("%s", s);
    int king, knight[70];
    int kn = 0;
    king = (s[1] - '1') * 8 + s[0] - 'A';
    int L = strlen(s);
    for (int i = 2; i < L; i += 2)
    {
        knight[kn++] = (s[i+1] - '1') * 8 + s[i] - 'A';
    }
    int knight_move[8][2] = { { -2, -1 },{ -2, 1 },{ -1, 2 },{ 1, 2 },{ 2, 1 },{ 2, -1 },{ 1, -2 },{ -1, -2 } };
    int king_move[8][2] = { { -1, -1 },{ -1, 0 },{ -1, 1 },{ 0, 1 },{ 1, 1 },{ 1, 0 },{ 1, -1 },{ 0, -1 } };

    init(a, knight_move);
    init(b, king_move);
    int res = 1 << 30;
    for (int end = 0; end < 64; end++)
    {
        int step = b[king][end];
        for (int i = 0; i < kn; i++)
            step += a[knight[i]][end];
        res = min(res, step);

        if (kn > 0)
        for (int get = 0; get < 64; get++)
        {
            step = b[king][get]; //king to get point first
            int sum = 0;
            for (int i = 0; i < kn; i++) sum += a[knight[i]][end];
            int minv = 1 << 30;
            for (int i = 0; i < kn; i++)
                if (sum - a[knight[i]][end] + a[knight[i]][get] + a[get][end] < minv)
                    minv = sum - a[knight[i]][end] + a[knight[i]][get] + a[get][end];
            step += minv;
            res = min(res, step);
        }
    }
    printf("%d\n", res);
    return 0;
}