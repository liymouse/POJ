#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

char s[10001];
char out[300][301];
int w[10001];
int h[10001];
int cur;

void getsize(int p)
{
    cur++;
    if ('A' <= s[p] && s[p] <= 'Z')
    {
        w[p] = h[p] = 2;
        return;
    }
    int L = cur;
    getsize(L);
    int R = cur;
    getsize(R);
    if (s[p] == '-')
    {
        w[p] = max(w[L], w[R]);
        h[p] = h[L] + h[R];
    }
    else
    {
        w[p] = w[L] + w[R];
        h[p] = max(h[L], h[R]);
    }
}

void print_window(int p, int cur_x, int cur_y, int realw, int realh)
{
    cur++;
    if ('A' <= s[p] && s[p] <= 'Z')
    {
        //label
        out[cur_y][cur_x] = s[p];
        //star
        if (out[cur_y + realh][cur_x] == ' ') out[cur_y + realh][cur_x] = '*';
        if (out[cur_y][cur_x + realw] == ' ') out[cur_y][cur_x + realw] = '*';
        if (out[cur_y + realh][cur_x + realw] == ' ') out[cur_y + realh][cur_x + realw] = '*';
        //edge
        for (int y = cur_y + 1; y < cur_y + realh; y++)
        {
            if (out[y][cur_x] == ' ') out[y][cur_x] = '|';
            if (out[y][cur_x + realw] == ' ') out[y][cur_x + realw] = '|';
        }
        for (int x = cur_x + 1; x < cur_x + realw; x++)
        {
            if (out[cur_y][x] == ' ') out[cur_y][x] = '-';
            if (out[cur_y + realh][x] == ' ') out[cur_y + realh][x] = '-';
        }
    }
    else
    {
        int L = cur;
        if (s[p] == '-')
        {
            int scale = (h[L] * realh + h[p] - 1) / h[p];
            print_window(L, cur_x, cur_y, realw, scale); //left
            int R = cur;
            print_window(R, cur_x, cur_y + scale, realw, realh - scale); //right
        }
        else
        {
            int scale = (w[L] * realw + w[p] - 1) / w[p];
            print_window(L, cur_x, cur_y, scale, realh); //left
            int R = cur;
            print_window(R, cur_x + scale, cur_y, realw - scale, realh); //right
        }
    }
}

int main()
{
    int num;
    scanf("%d", &num);
    for (int i = 1; i <= num; i++)
    {
        scanf("%s", s);
        cur = 0;
        getsize(0);
        for (int y = 0; y < h[0] + 1; y++)
        {
            for (int x = 0; x < w[0] + 1; x++)
                out[y][x] = ' ';
            out[y][w[0] + 1] = 0;
        }
        cur = 0;
        print_window(0, 0, 0, w[0], h[0]);
        printf("%d\n", i);
        for (int y = 0; y < h[0] + 1; y++)
            printf("%s\n", out[y]);
    }
    return 0;
}