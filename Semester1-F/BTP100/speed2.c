#include <time.h>
 #include <stdio.h>
 #define NITER 400

 int main(void)
 {
         double x;
         int i, j, k;
         time_t t0, t1;
         clock_t c0, c1;

         x = 1;
         t0 = time(NULL);
         c0 = clock();
         for (i = 0; i < NITER; i++)
             for (j = 0; j < NITER; j++)
                 for (k = 0; k < NITER; k++)
                     x = x * 1.0000000001;
         t1 = time(NULL);
         c1 = clock();
         printf("Elapsed time is %.1lf secs\n",
                difftime(t1, t0)); 
         printf("Process time is %.3lf secs\n",
                (double)(c1-c0)/CLOCKS_PER_SEC); 
         printf("Value of x is %.10lf\n", x);

         return 0;
 }