#include <stdio.h>

int main()
{
int p[6][3] = {{1 , 0 , 0} , {0 , 1 , 0} , {0 , 0 , 1} , {-1 , 0 , 0} , {0 , -1 , 0} , {0 , 0 , -1}};
int turn[3][4] = {{0 , 4 , 3 , 1} , {1 , 5 , 4 , 2} , {0 , 2 , 3 , 5}};
int upfoot[6][4] = {{0 , 3 , 1 , 2} , {0 , 2 , 1 , 3} , {0 , 5 , 1 , 4} , {0 , 4 , 1 , 5} , {2 , 5 , 3 , 4} , {2 , 4 , 3 , 5}};
int upface[6][4] = {{0 , 2 , 3 , 5} , {3 , 2 , 0 , 5} , {1 , 2 , 4 , 5} , {4 , 2 , 1 , 5} , {1 , 0 , 4 , 3} , {4 , 0 , 1 , 3}};
int t;
int n , i , j , k , bo;
int x , y , z , face , L , foot;
char word[10];

	scanf("%d" , &t);
	while (t --)
	{
		scanf("%d" , &n);
		x = 0; y = 0; z = 0; face = 0; foot = 0;
		for (i = 0; i < n; i ++)
		{
			scanf("%s %d" , word , &L);
			switch(word[0])
			{
			case 'b' :
				face = (face + 3) % 6;
				break;
			case 'l' :
				if ((foot == 0) || (foot == 2) || (foot == 4))
				{
					for (j = 0; j < 4; j ++) if (face == turn[foot/2][j]) break;
					face = turn[foot/2][(j+1)%4];
				}
				else
				{
					for (j = 0; j < 4; j ++) if (face == turn[foot/2][j]) break;
					face = turn[foot/2][(j+3)%4];
				}
				break;
			case 'r' :
				if ((foot == 1) || (foot == 3) || (foot == 5))
				{
					for (j = 0; j < 4; j ++) if (face == turn[foot/2][j]) break;
					face = turn[foot/2][(j+1)%4];
				}
				else
				{
					for (j = 0; j < 4; j ++) if (face == turn[foot/2][j]) break;
					face = turn[foot/2][(j+3)%4];
				}
				break;
			case 'u' :
				bo = 0;
				for (k = 0; k < 6; k ++)
				{
					for (j = 0; j < 4; j ++)
						if ((foot == upfoot[k][j]) && (face == upface[k][j])) {bo = 1; break;}
					if (bo) break;
				}
				face = upface[k][(j+1)%4];
				foot = upfoot[k][(j+1)%4];
				break;
			case 'd' :
				bo = 0;
				for (k = 0; k < 6; k ++)
				{
					for (j = 0; j < 4; j ++)
						if ((foot == upfoot[k][j]) && (face == upface[k][j])) {bo = 1; break;}
					if (bo) break;
				}
				face = upface[k][(j+3)%4];
				foot = upfoot[k][(j+3)%4];
				break;
			}
			x += L * p[face][0]; y += L * p[face][1]; z += L * p[face][2];
		}
		printf("%d %d %d %d\n" , x , y , z , face);
	}
	return 0;
}