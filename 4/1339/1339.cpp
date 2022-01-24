#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
using namespace std;

typedef struct {
    int v, id;
}Node;
Node heap[100005];
int heapn;
int f[200001];
int a[100005];
int cmp(Node &x, Node &y)
{
    return x.v < y.v;
}
void heapPop()
{
    heap[0] = heap[heapn - 1];
    heapn--;
    int k = 0;
    while (k * 2 + 1 < heapn)
    {
        int j = k * 2 + 1;
        if (j + 1 < heapn && heap[j+1].v < heap[j].v) j++;
        if (heap[k].v < heap[j].v) break;
        Node tmp = heap[k]; heap[k] = heap[j]; heap[j] = tmp;
        k = j;
    }
}
void heapShiftUp(int x)
{
    while (x > 0 && heap[x].v < heap[(x - 1) / 2].v)
    {
        Node tmp = heap[x]; heap[x] = heap[(x - 1) / 2]; heap[(x - 1) / 2] = tmp;
        x = (x - 1) / 2;
    }
}
int main()
{
    int ca;
    scanf("%d", &ca);
    while (ca--)
    {
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &heap[i].v);
            heap[i].id = i;
            a[i] = heap[i].v;
        }
        sort(heap, heap + n, cmp);
        heapn = n;
        int id = n;
        for (int i = 0; i < n - 1; i++)
        {
            Node x = heap[0];
            heapPop();
            Node y = heap[0];
            heapPop();
            f[x.id] = f[y.id] = id;
            heap[heapn].v = x.v + y.v;
            heap[heapn].id = id++;
            heapn++;
            heapShiftUp(heapn - 1);
        }
        int res = 0;
        for (int i = 0; i < n; i++)
        {
            int t = 0;
            int k = i;
            while (k != id - 1) { t++; k = f[k]; }
            res += t * a[i];
        }
        printf("%d\n", res);
    }
    return 0;
}