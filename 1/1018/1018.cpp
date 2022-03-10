#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
	int B, P;
} Dev;

int m[101];
Dev d[101][101];
int n;
int width[10010];
int max;
int minMax;
int width_S;
double maxValue, tmp;

int cp(const void *a, const void *b)
{
	Dev *aa = (Dev *)a;
	Dev *bb = (Dev *)b;

	if (aa->P != bb->P)
	{
		return aa->P - bb->P;
	}
	else
	{
		return bb->B - aa->B;
	}
}

int cp2(const void *a, const void *b)
{
	return *(int *)a - *(int *)b;
}

int main()
{
	int T, i, j, k, ii, P_sum;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &n);
		for (i = 0, k = 0, minMax = 1000000; i < n; i++)
		{
			scanf("%d", &m[i]);
			max = 0;
			for (j = 0; j < m[i]; j++)
			{
				scanf("%d %d", &d[i][j].B, &d[i][j].P);
				width[k++] = d[i][j].B;
				if (d[i][j].B > max)
				{
					max = d[i][j].B;
				}
			}
			if (max < minMax)
			{
				minMax = max;
			}
			qsort(d[i], m[i], sizeof(d[0][0]), cp);
		}
		qsort(width, k, sizeof(width[0]), cp2);
		width_S = k;

		for (i = 0, maxValue = 0.0; width[i] <= minMax && i < width_S; i++)
		{
			if (i > 0 && width[i] == width[i - 1])
			{
				continue;
			}
			P_sum = 0;
			for (j = 0; j < n; j++)
			{
				k = 0;
				while (d[j][k].B < width[i])
				{
					k++;
				}
				P_sum += d[j][k].P;
			}
			tmp = width[i] * 1.0 / P_sum;
			if (tmp > maxValue)
			{
				maxValue = tmp;
			}
		}
		printf("%.3lf\n", maxValue);
	}
	return 0;
}