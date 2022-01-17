#include <stdio.h>
typedef long long lld;

int f[10005] = { 0 };

int main()
{
    int n;
    int sum_t[10005] = { 0 };
    int sum_f[10005] = { 0 };
    int q[10005] = { 0 };
    int S, T, F;
    scanf("%d %d", &n, &S);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d %d", &T, &F);
        sum_t[i] = sum_t[i - 1] + T;
        sum_f[i] = sum_f[i - 1] + F;
    }
    int left = 1, right = 1;
    for (int i = 1; i <= n; i++)
    {
        while (left < right && f[q[left + 1]] - f[q[left]] <= (S + sum_t[i])*(sum_f[q[left + 1]] - sum_f[q[left]])) left++;
        f[i] = f[q[left]] + sum_t[i] * (sum_f[i] - sum_f[q[left]]) + S * (sum_f[n] - sum_f[q[left]]);
        while (left < right && (f[q[right]] - f[q[right - 1]])*(sum_f[i] - sum_f[q[right]]) >= (f[i] - f[q[right]]) * (sum_f[q[right]] - sum_f[q[right - 1]])) right--;
        right++;
        q[right] = i;
    }

    printf("%d\n", f[n]);
    return 0;
}