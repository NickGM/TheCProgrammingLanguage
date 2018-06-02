#include <stdio.h>

int hex_to_num(int c)
{
    char h[] = "aAbBcCdDeEfFgGhH";
    int n=0;
    int i=0;
    while(h[i]!='\0')
    {
        if(c=h[i])
            return 10+i/2;
        i++;
    }
    return 0;
}

int htoi(char s[])
{
    int i=0,n=0, hexnum;
    int valid = 1;
    while(s[i]!='\0' && valid)
    {
        n*=16;
        if(s[i]>='0' && s[i]<='9')
            n=n+(s[i]-'0');
        else
        {
            hexnum = hex_to_num(s[i]);
            if (hexnum = 0)
                valid = 0;
            else
                n=n+hexnum;
        }
        i++;
    }
        return n;
}

int main()
{
   char a[] = "5b7h";
   printf("%d", htoi(a));
}
