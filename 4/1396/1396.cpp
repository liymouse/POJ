#include <stdio.h>
#include <string.h>
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
int c[501][600] = { 0 };
void fix(int *a, int *L)
{
    for (int i = 0; i < (*L); i ++)
        if (a[i] > 9)
        {
            a[i + 1] += a[i] / 10;
            a[i] %= 10;
        }
    while (a[*L] > 0)
    {
        if (a[*L] > 9)
        {
            a[(*L) + 1] += a[*L] / 10;
            a[*L] %= 10;
        }
        (*L) ++;
    }
    while (*L > 1 && a[(*L) - 1] == 0) (*L) --;
}
int main()
{
    int n;
    char s[1200];
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%s", s);
        int a[503] = { 0 }, b[503] = { 0 };
        char type;
        int La = 0, Lb = 0;
        int L = 0;
        while ('0' <= s[L] && s[L] <= '9') L++;
        for (int i = L - 1; i >= 0; i--) a[La++] = s[i]-'0';
        type = s[L++];
        while ('0' <= s[L] && s[L] <= '9') L++;
        for (int i = L-1; i > La; i --) b[Lb++] = s[i]-'0';
        if (type == '+' || type == '-')
        {
            int Ld = 0;
            for (int i = 0; i < Lb; i++)
                if (type == '+') a[i] += b[i];
                else a[i] -= b[i];
            Ld = max(La, Lb);
            for (int i = 0; i < Ld; i++)
                if (a[i] > 9)
                {
                    a[i + 1] ++;
                    a[i] -= 10;
                }
                else if (a[i] < 0)
                {
                    a[i + 1] --;
                    a[i] += 10;
                }
            while (a[Ld] > 0) Ld++;
            while (Ld > 1 && a[Ld - 1] == 0) Ld--;

            int L = max(La, Lb+1);
            L = max(L, Ld);
            for (int i = 0; i < L - La; i++) printf(" ");
            s[La] = 0;
            printf("%s\n", s);
            for (int i = 0; i < L - Lb - 1; i++) printf(" ");
            printf("%c", type);
            for (int i = Lb - 1; i >= 0; i--) printf("%d", b[i]); printf("\n");
            int Ll = max(Lb + 1, Ld);
            for (int i = 0; i < L - Ll; i++) printf(" ");
            for (int i = 0; i < Ll; i++) printf("-"); printf("\n");

            for (int i = 0; i < L - Ld; i++) printf(" ");
            for (int i = Ld - 1; i >= 0; i--) printf("%d", a[i]); printf("\n");
        }
        else
        {
            int d[1020] = { 0 };
            int Lc[501] = { 0 };
            int L = max(La, Lb + 1);
            int Ld = 0;
            for (int i = 0; i < Lb; i++)
            {
                memset(c[i], 0, sizeof(c[i]));
                for (int j = 0; j < La; j++)
                    c[i][j] = a[j] * b[i];
                Lc[i] = La;
                fix(c[i], &Lc[i]);
                L = max(L, Lc[i] + i);
                for (int j = i; j < i + Lc[i]; j++)
                    d[j] += c[i][j - i];
                Ld = max(Ld, i + Lc[i]);
            }
            fix(d, &Ld);
            L = max(L, Ld);
            for (int i = 0; i < L - La; i++) printf(" ");
            for (int i = La - 1; i >= 0; i--) printf("%d", a[i]); printf("\n");
            for (int i = 0; i < L - Lb - 1; i++) printf(" ");
            printf("*");
            for (int i = Lb - 1; i >= 0; i--) printf("%d", b[i]); printf("\n");
            int Ll = L;
            if (Lb > 1)
            {
                Ll = max(Lb + 1, Lc[0]);
                for (int i = 0; i < L - Ll; i++) printf(" ");
                for (int i = 0; i < Ll; i++) printf("-"); printf("\n");
                for (int i = 0; i < Lb; i++)
                {
                    for (int j = 0; j < L - Lc[i] - i; j++) printf(" ");
                    for (int j = Lc[i] - 1; j >= 0; j--) printf("%d", c[i][j]); printf("\n");
                }
                Ll = max(Ld, Lc[Lb - 1] + Lb - 1);
            }
            else Ll = max(Lb + 1, Ld);
            for (int i = 0; i < L - Ll; i++) printf(" ");
            for (int i = 0; i < Ll; i++) printf("-"); printf("\n");
            for (int i = 0; i < L - Ld; i++) printf(" ");
            for (int i = Ld - 1; i >= 0; i--) printf("%d", d[i]); printf("\n");
        }
        printf("\n");
    }
    return 0;
}