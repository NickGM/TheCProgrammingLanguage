#include <stdio.h>

int lower (int c)
{
    return ((c>='A')&&(c<='Z') ? (c+'a'-'A'):c);
}

int main()
{
    char c = 'N';
    printf("%c",lower(c));
}
