#include <stdio.h>

int main()
{
double s1[200],s2[200];
    int i,round;
	double a_win,b_win,tie;
	for(i=0;i<200;i++)
		s1[i]=s2[i]=0;
    printf("Round   A wins    B wins    Tie\n");
	s1[103]=1*100/(double)(16);
	s1[102]=2*100/(double)(16);
    s1[101]=4*100/(double)(16);
	s1[100]=6*100/(double)(16);
	s1[99]=2*100/(double)(16);
	s1[97]=1*100/(double)(16);
	a_win=7*100/(double)(16);
	b_win=3*100/(double)(16);
	tie=6*100/(double)(16);
	printf("    1   %7.4lf%%  %7.4lf%%  %7.4lf%%\n",a_win,b_win,tie);
	for(round=2;round<=20;round++)
	{   for(i=100-3*round;i<=100+3*round;i++)
		{s1[i]=s1[i]/16;
		 s2[i]=0;
		}
		for(i=100-3*(round-1);i<=100+3*(round-1);i++)
		{   s2[i+3]=s2[i+3]+s1[i];
		    s2[i+2]=s2[i+2]+2*s1[i];
			s2[i+1]=s2[i+1]+4*s1[i];
			s2[i]=s2[i]+6*s1[i];
			s2[i-1]=s2[i-1]+2*s1[i];
			s2[i-3]=s2[i-3]+s1[i];
		}
        for(i=100-3*round,b_win=0;i<100;i++)
			b_win=b_win+s2[i];
        for(i=101,a_win=0;i<=100+3*round;i++)
			a_win=a_win+s2[i];
		tie=s2[100];
	    printf("%5d   %7.4lf%%  %7.4lf%%  %7.4lf%%\n",round,a_win,b_win,tie);
		for(i=100-3*round;i<=100+3*round;i++)
			s1[i]=s2[i];
	}

	//printf("Round   A wins    B wins    Tie\n");
	//printf("    1   43.7500%  18.7500%  37.5000%\n");
	//printf("    2   56.6406%  22.2656%  21.0938%\n");
	//printf("    3   62.3535%  22.7051%  14.9414%\n");
	//printf("    4   65.9134%  22.0657%  12.0209%\n");
	//printf("    5   68.6609%  21.0665%  10.2726%\n");
	//printf("    6   70.9815%  19.9854%   9.0332%\n");
	//printf("    7   73.0088%  18.9226%   8.0686%\n");
	//printf("    8   74.8079%  17.9104%   7.2816%\n");
	//printf("    9   76.4212%  16.9569%   6.6219%\n");
	//printf("   10   77.8796%  16.0617%   6.0587%\n");
	//printf("   11   79.2070%  15.2222%   5.5709%\n");
	//printf("   12   80.4219%  14.4346%   5.1434%\n");
	//printf("   13   81.5393%  13.6954%   4.7653%\n");
	//printf("   14   82.5709%  13.0010%   4.4280%\n");
	//printf("   15   83.5266%  12.3482%   4.1251%\n");
	//printf("   16   84.4146%  11.7339%   3.8515%\n");
	//printf("   17   85.2417%  11.1553%   3.6030%\n");
	//printf("   18   86.0137%  10.6098%   3.3764%\n");
	//printf("   19   86.7359%  10.0952%   3.1690%\n");
	//printf("   20   87.4124%   9.6092%   2.9784%\n");

	return 0;
}