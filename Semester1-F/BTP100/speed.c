#include <time.h>
 #include <stdio.h>
 #define NITER 1000000000

 int main(void)
 {
         double x;
         int i, j, k;
         time_t t0, t1;

         x = 1;
         t0 = time(NULL);
         for (i = 0; i < NITER; i++)
                 x = x * 1.0000000001;
         t1 = time(NULL);
         printf("Elapsed time is %.1lf secs\n", 
          difftime(t1, t0)); 
         printf("Value of x is %.10lf\n", x);

         return 0;
 }