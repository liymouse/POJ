#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
typedef struct
{
    int num;
    int a[30];
    int pay;
}Custom;
int main()
{
    int cas;
    scanf("%d", &cas);
    for (int ca = 1; ca <= cas; ca++)
    {
        int minv, maxv, m, n;
        scanf("%d %d %d %d", &minv, &maxv, &m, &n);
        int cost[30];
        for (int i = 0; i < m; i++) scanf("%d", &cost[i]);
        Custom cus[30];
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &cus[i].num);
            for (int j = 0; j < cus[i].num; j++) {
                scanf("%d", &cus[i].a[j]); cus[i].a[j]--;
            }
            scanf("%d", &cus[i].pay);
        }
        int ress = 0;
        int rescus_st = 0;
        int respro = 0;
        int respay = 0;
        int rescost = 0;
        int rescus = 0;
        int resfeature = 0;
        for (int s = 1; s < (1 << m); s++)
        {
            int totcost = 0;
            int totfeature = 0;
            for (int i = 0; i < m; i++)
                if (s & (1 << i))
                {
                    totcost += cost[i]; totfeature++;
                }
            if (totcost < minv || totcost > maxv) continue;
            int totcus = 0;
            int totpay = 0;
            int cusst = 0;
            for (int i = 0; i < n; i++)
            {
                int sati = 1;
                for (int j = 0; j < cus[i].num; j ++)
                    if ((s & (1 << cus[i].a[j])) == 0) { sati = 0; break; }
                if (sati) { totcus++; totpay += cus[i].pay; cusst |= 1 << i; }
            }

            int pro = (totpay * 1000 + totcost / 2) / totcost;
            if (pro > respro ||
                (pro == respro && totpay - totcost > respay - rescost) ||
                (pro == respro && totpay - totcost == respay - rescost && totfeature < resfeature) ||
                (pro == respro && totpay - totcost == respay - rescost && totfeature == resfeature && totcus > rescus))
            {
                respro = pro;
                respay = totpay;
                rescost = totcost;
                resfeature = totfeature;
                rescus = totcus;
                ress = s;
                rescus_st = cusst;
            }
        }
        printf("Feature Set %d\n", ca);
        printf("%.3lf\n", respro / 1000.0);
        printf("%d\n", respay);
        printf("%d\n", rescost);
        int first = 1;
        for (int i = 0; i < m; i ++)
            if (ress & (1 << i))
            {
                if (first) { printf("%d", i + 1); first = 0; }
                else printf(" %d", i + 1);
            }
        printf("\n");
        first = 1;
        for (int i = 0; i < n; i ++)
            if (rescus_st & (1 << i))
            {
                if (first) { printf("%d", i + 1); first = 0; }
                else printf(" %d", i + 1);
            }
        printf("\n");
    }
    return 0;
}