#include <stdio.h>
#include <string.h>
#include <limits.h>

void reverse(char s[])
{
    int i,j,t;
    for(i=0, j=strlen(s)-1;i<j;i++,j--)
    {
        t=s[i];
        s[i]=s[j];
        s[j]=t;
    }
}

void itoa(int n, char s[],int p)
{
    int i, sign=n;
    i=0;

    do
    {
        s[i++]=abs(n%10)+'0';
    } while(n/=10);

    while(i<p)
        s[i++]=' ';

    if(sign<0)
        s[i++]='-';
    s[i]='\0';
    reverse(s);
}

main()
{
    char s[128];
    int i;
    for(i=2; i<=1000; i*=2)
    {
        itoa(i, s, 4);
        printf("%d is converted to %s\n", i, s);
    }

}
