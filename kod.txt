#include <stdio.h>
#include <stdlib.h>
int main()
{
    int count=10,i,n=10;
    int arr[n];
    i=1;
    do{
        arr[i]=i*count;
        printf("%d * %d = %d\n",i,count,i*count);
        i++;
    }while(i<=n);
    return 0;
}