#include <stdio.h>

int main()
{
    int c, p;
    while((c = getchar()) != '\n')
    {
        if(!((c==' ')&&(p==' ')))
            putchar(c);
        p=c;
    }
}
