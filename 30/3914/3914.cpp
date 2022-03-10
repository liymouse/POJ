#include <stdio.h>
#include <math.h>

int main()
{
    int n;
    while (scanf("%d" , &n) == 1)
    {
        if (n == 0) break;
        int p , s;
        int current = 0;
        int maxmem = 0;
        int state = 0;
        scanf("%d %d" , &p , &s);
        int dll[22] , pmem[15] , pneed[15];
        int num[15] = {0};
        for (int i = 0; i < n; i ++) scanf("%d" , &dll[i]);
        for (int i = 1; i <= p; i ++)
        {
            char need[30];
            scanf("%d %s" , &pmem[i] , need);
            pneed[i] = 0;
            for (int j = 0; need[j] != 0; j ++) pneed[i] |= 1 << (need[j]-'A');
        }
        for (int k = 0; k < s; k ++)
        {
            int index;
            scanf("%d" , &index);
            if (index > 0)
            {
                current += pmem[index];
                int need = (pneed[index] ^ state) & pneed[index];
                for (int i = 0; i < n; i ++)
                    if ((1 << i) & need) current += dll[i];
                state |= pneed[index];
                num[index] ++;
                if (current > maxmem) maxmem = current;
            }
            else
            {
                index = -index;
                current -= pmem[index];
                num[index] --;
                int nextstate = 0;
                for (int i = 1; i <= p; i ++)
                    if (num[i]) nextstate |= pneed[i];
                int remove = (pneed[index] ^ nextstate) & pneed[index];
                for (int i = 0; i < n; i ++)
                    if ((1 << i) & remove) current -= dll[i];
                state = nextstate;
            }

        }
        printf("%d\n" , maxmem);
    }
    return 0;
}
