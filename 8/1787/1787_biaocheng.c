/*
 *	Solution to Charlie's change task
 */
#include <stdio.h>

const int p[4] = {1,5,10,25};

#define MIN(a,b) ((a) < (b) ? (a) : (b))

int compute(int *c, int *use, int start, int price)
{
	int i, val;

	val = 0;
	for (i = 0; i <= start; i++)
		val += c[i]*p[i];
	for (i = start; i >= 0; i--) {
		val -= p[i]*c[i];
		if (val > price)
		    	use[i] = 0;
		else
		    	use[i] = (price-val+p[i]-1)/p[i];
		if (use[i] > c[i] || use[i]*p[i] > price)
		    	return -1;
		price -= use[i]*p[i];
	}
	val = 0;
	for (i = 0; i < 4; i++)
	   	val += use[i];
	return val;
}

int main(void)
{
	int price, c[4], val, use[2][4], i, coins[2];

	while (1) {
	    	scanf("%d %d %d %d %d", &price, &c[0], &c[1], &c[2], &c[3]);
		if (!price && !c[0] && !c[1] && !c[2] && !c[3])
			break;

		val = 0;
		for (i = 0; i < 3; i++)
		    	val += c[i]*p[i];
		if (val > price)
		    	use[0][3] = 0;
		else
		    	use[0][3] = MIN((price-val+p[3]-1)/p[3], c[3]);
		coins[0] = compute(c, use[0], 2, price - use[0][3]*p[3]);
		if (use[0][3] < c[3]) {
			use[1][3] = use[0][3]+1;
			coins[1] = compute(c, use[1], 2, price - use[1][3]*p[3]);
		}
		else
		    	coins[1] = -1;
		if (coins[0] == -1 && coins[1] == -1)
		    	puts("Charlie cannot buy coffee.");
		else {
		    	i = 0;
		    	if (coins[1] > coins[0])
			    	i = 1;
			printf("Throw in %d cents, %d nickels, %d dimes, and %d quarters.\n", use[i][0], use[i][1], use[i][2], use[i][3]);
		}
	}
	return 0;
}
