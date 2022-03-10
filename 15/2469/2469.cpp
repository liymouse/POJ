#include<stdio.h>

int track[101][53];

void print(int *card)
{
int i , t;

	for(i = 1; i <= 52; i ++)
    {
		t = card[i] % 13;
		switch(t)
		{
			case 0 : printf("Ace "); break;
			case 10 : printf("Jack "); break;
			case 11 : printf("Queen "); break;
			case 12 : printf("King "); break;
			default : printf("%d ",t+1); break;
		}
		printf("of ");
		t = card[i] / 13;
		if (card[i] == 13) printf("Clubs\n");
		else if (card[i] == 26) printf("Diamonds\n");
			else if (card[i] == 39) printf("Hearts\n");
				else if (card[i] == 52) printf("Spades\n");
					else
						switch(t)
						{
							case 0 : printf("Clubs\n"); break;
							case 1 : printf("Diamonds\n"); break;
							case 2 : printf("Hearts\n"); break;
							case 3 : printf("Spades\n"); break;
						}
	}
	printf("\n");      
}

int main()
{
int i , j , k , n , t;
int card[53] , temp[53];

	scanf("%d" , &n);
	for(i = 1; i <= 52; i ++) card[i] = i;
	for(i = 1; i <= n; i ++)
		for(j = 1; j <= 52; j ++)
			scanf("%d" , &track[i][j]);
	while(scanf("%d" , &t) == 1)
    {
		for(i = 1; i <= 52; i ++) temp[i] = card[track[t][i]];
		for(i = 1; i <= 52; i ++) card[i] = temp[i];
		print(card);
    }
	return(0);
}