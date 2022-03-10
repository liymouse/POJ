#include <string.h>
#include <stdio.h>
#include <math.h>

int main()
{ 
float mw , mi , tw , ti;
  
	while (scanf("%f %f %f %f", &mw , &mi , &tw , &ti) == 4)
	{
	    if ((mw == 0) && (mi == 0) && (tw == 0) && (ti == 0)) return 0;
		if(mw * 4.19 * tw > -mi * 2.09 * ti + 335 * mi)
			printf("0.0 g of ice and %.1lf g of water at %.1lf C\n" , mw + mi , (mw * 4.19 * tw + mi * 2.09 * ti - 335 * mi) / (mw * 4.19 + mi * 4.19));
		else if(-mi * 2.09 * ti < mw * 4.19 * tw + mw * 335)
		{
			if(mw * 4.19 * tw > -mi * 2.09 * ti)  
                printf("%.1f g of ice and %.1f g of water at 0.0 C\n" , mi - (mw * 4.19 * tw + mi * 2.09 * ti) / 335 , mw + (mw * 4.19 * tw + mi * 2.09 * ti) / 335);
			else printf("%.1f g of ice and %.1f g of water at 0.0 C\n" , mi + (-mw * 4.19 * tw - mi * 2.09 * ti) / 335 , mw - (-mw * 4.19 * tw - mi * 2.09 * ti) / 335);
		}  
		else printf("%.1f g of ice and 0.0 g of water at %.1f C\n" , mw + mi , (mw * 4.19 * tw + mw * 335 + mi * 2.09 * ti) / (mi * 2.09 + mw * 2.09));
 	}
	return 0;
}

