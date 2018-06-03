#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define N 500000

int binsearch_new(int x, int v[], int n)
{
    int low, high, mid;
    low = 0;
    high = n-1;
    mid = (low+high)/2;

    while(low<=high && x!=v[mid])
    {
        if(x>v[mid]) low=mid+1;
        else high = mid-1;
        mid = (low+high)/2;
    }

    if(x==v[mid])return mid;
    else return -1;
}

int binsearch(int x, int v[], int n)
{
    int low, high, mid;
    low = 0;
    high = n-1;

    while(low<=high)
    {
        mid = (low+high)/2;
        if(x<v[mid])
            high = mid-1;
        else if(x>v[mid])
            low = mid+1;
        else
            return mid;
    }
    return -1;
}

int main()
{
    int a[N];
    int i;
    int index;
    clock_t begin;
    clock_t time_taken;
    for(i=0;i<N;i++)
        a[i]=i;

    for ( i = 0, begin = clock(); i < N; i++ ) {
        index = binsearch(687, a, N);
    }
    time_taken = clock() - begin;

    printf("binsearch() took %lu clocks (%lu seconds)\n",
           (unsigned long) time_taken,
           (unsigned long) time_taken / CLOCKS_PER_SEC);

    for ( i = 0, begin = clock(); i < N; ++i ) {
        index = binsearch_new(687, a, N);
    }
    time_taken = clock() - begin;

    printf("binsearch_new() took %lu clocks (%lu seconds)\n",
           (unsigned long) time_taken,
           (unsigned long) time_taken / CLOCKS_PER_SEC);

}
