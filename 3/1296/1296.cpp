#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define max(a,b) ((a)>(b)?(a):(b))
typedef unsigned char uint8;

int L, L2;
uint8 org[400 * 400], src0[400 * 400], src1[400 * 400];
int calConfidence(uint8 *s0, uint8 *s1)
{
    int sum = 0;
    for (int i = 0; i < L2; i++)
        if (abs(s0[i] - s1[i]) <= 100) sum++;
    return sum;
}
#define A(x, y) img[(y)*L+(x)]
void rotate90(uint8 *img)
{
    for (int y = 0; y < L/2; y ++)
        for (int x = y; x < L - 1- y; x++)
        {
            uint8 tmp = A(x, y);
            A(x, y) = A(y, L - 1 - x);
            A(y, L - 1 - x) = A(L - 1 - x, L - 1 - y);
            A(L - 1 - x, L - 1 - y) = A(L - 1 - y, x);
            A(L - 1 - y, x) = tmp;
        }
}
void flipHori(uint8 *dst, uint8 *src)
{
    for (int y = 0; y < L; y++)
    {
        uint8 *ps = src + y * L;
        uint8 *pd = dst + y * L;
        for (int x = 0; x < L; x++)
        {
            pd[x] = ps[L - 1 - x];
        }
    }
}
int main()
{
    while (scanf("%d", &L) == 1)
    {
        if (L == 0) break;
        L2 = L * L;
        for (int i = 0; i < L2; i ++) scanf("%d", &org[i]);
        for (int i = 0; i < L2; i++) scanf("%d", &src0[i]);
        int res = 0, k;
        flipHori(src1, src0);
        k = calConfidence(org, src0); res = max(res, k);
        k = calConfidence(org, src1); res = max(res, k);
        for (int i = 0; i < 3; i++)
        {
            rotate90(src0); rotate90(src1);
            k = calConfidence(org, src0); res = max(res, k);
            k = calConfidence(org, src1); res = max(res, k);
        }
        printf("%.2lf\n", res * 100.0 / L2);
    }
    return 0;
}
