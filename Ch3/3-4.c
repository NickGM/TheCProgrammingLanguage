#include <stdio.h>
#include <string.h>
#include <limits.h>
/*answer: two's compliment is assymetrical about zero. Absolute of -n != n, it's 1 bigger*/

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

void itoa(int n, char s[])
{
    int i, sign=n;
    i=0;

    do
    {
        s[i++]=abs(n%10)+'0';
    } while(n/=10);

    if(sign<0)
        s[i++]='-';
    s[i]='\0';
    reverse(s);
}

main()
{
    char s[128];
    itoa(INT_MIN, s);
    printf("%d is converted to %s.\n", INT_MIN, s);
}
