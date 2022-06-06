#include <time.h>
#include <stdio.h>
#include <stdlib.h>
int main()
{
clock_t basla_t, bitir_t;
basla_t = clock();
    int count=10,i,n=10;
    int arr[n];
    i=1;
    do{
        arr[i]=i*count;
        printf("%d * %d = %d\n",i,count,i*count);
        i++;
    }while(i<=n);
bitir_t = clock();
printf("Calismaya baslama suresi: %d \n", basla_t);
printf("Calismanin bitisi suresi: %d \n", bitir_t);
printf("Kod calistiginde gecen sure (saniye): %f \n", (double)(bitir_t - basla_t) / CLOCKS_PER_SEC );
    return 0;
}