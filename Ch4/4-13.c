#include <stdio.h>
#include <string.h>

void reverse(int i, char s[]);

int main()
{
    char s[] = "Hello";
    printf("%s\n", s);
    reverse(0,s);
    printf("%s\n", s);

    return 0;
}

void reverse(int i, char s[])
{
    int c, j;

    if(i < (strlen(s))/2)
    {
        j=strlen(s)-i-1;
        c=s[i];
        s[i]=s[j];
        s[j]=c;
        reverse(++i, s);
    }
}
