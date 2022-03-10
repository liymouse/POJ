
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define MAXB  512
#define MAXS  512
      /* must be higher than the maximal numbers */


#define DEBUG 0
#if DEBUG
#define WARN 1
#else
#define WARN 1
#endif


/*
   in the `i'-th step, we are dividing books among `i' scribers
   `prevm[b]' - the best solution for first `b' books and `i-1' scribers
   `nowm[b]' - the best solution for `i' scribers
*/
int nowm[MAXB];
int prevm[MAXB];

int pag[MAXB], sum[MAXB];   /* input numbers and partial sums */
int res[MAXB];   /* where tu put a divider */


int main (void)
{
   int prob, probn;
   scanf ("%d", &probn);
   
   for ( prob = 0;  prob < probn;  ++prob )
   {
      int n, k, s, i;
      scanf ("%d%d", &n, &k);
      
      /***** read the input *****/
      sum[0] = s = 0;
      for ( i = 0;  i < n;  ++i )
      {
         scanf ("%d", pag+i);
         sum[i+1] = s += pag[i];
      }
      for ( i = 1;  i <= n;  ++i )  prevm[i] = sum[n] + 1;
      prevm[0] = 0;
      
      /***** from a single scriber to `k' scribers *****/
      for ( s = 0;  s++ < k; )
      {
         int i, j;
         for ( i = s;  i <= n;  ++i )
         {
            /***** find the optimal solution for the first `i' books *****/
            int min = sum[n] << 1, jmin = -1;
            
            for ( j = s-1;  j < i;  ++j )
            {
               int val1 = prevm[j];
               int val2 = sum[i] - sum[j];
               int max = ( val1 > val2 ) ? val1 : val2;
               if ( max < min )
               {
                  min = max;
                  jmin = j;
               }
            }
            
            /***** remember the optimal solution *****/
            if ( jmin >= 0 )
               nowm[i] = min;
#if WARN
            else printf ("Warning! Minimum was not found!\n");
#endif
         }
         
         /***** proceed to the next step *****/
         memcpy (&prevm, &nowm, sizeof (prevm));

#if DEBUG
         printf ("s=%d: ", s);
         for ( i = 1;  i <= n;  ++i )
            printf ("%d ", nowm[i]);
         printf ("\n");
#endif
      }

      /***** output the result *****/
      memset (&res, 0, sizeof (res));
      s = 0;
      for ( i = n;  --i >= 0;  )
         if (( s += pag[i] ) > nowm[n] )
         {
            res[i+1] = 1;
            s = pag[i];
            --k;
         }
      
      printf ( "%d", pag[0]);
      for ( i = 1;  i < n;  ++i )
      {
         int sep = res[i];
         if ( !sep )  if ( --k > 0 )  sep = 1;
         printf ("%s %d", sep ? " /" : "", pag[i]);
      }
      printf ( "\n");
   }
   
   return 0;
}
