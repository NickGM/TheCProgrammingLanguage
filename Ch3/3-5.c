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

void itob(int n, char s[], int b)
{
    int i, a, sign;
    i=0;
    sign = n;
    do
    {
        a=abs(n%b);
        s[i++]=(a>9)?((a-10) + 'A') : (a+'0');
    } while(n/=b);

    if(sign<0)
        s[i++]='-';
    s[i]='\0';
    reverse(s);
}

int main(void) {
    char arr[16];
    int i;

    for ( i = 2; i <= 20; ++i ) {
        itob(255, arr, i);
        printf("255 in base %.2d : %s\n", i, arr);
    }
    return 0;
}

