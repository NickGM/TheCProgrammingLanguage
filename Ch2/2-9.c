#include <stdio.h>

int bitcount(unsigned x)
{
   int b;
   for(b=0;x!=0;x&=(x-1))
        b++;
    return b;
}

void displayBits(unsigned x)
{
    unsigned mask = 1<<31;
    char bit;
    while(mask!=0)
    {
        bit = (x&mask ? '1':'0');
        printf("%c",bit);
        mask>>=1;
    }
    printf("\n");

}

int main()
{
    unsigned x;
    printf("%s", "Select an integer: ");
    scanf("%u", &x);
    displayBits(x);
    printf("%d",bitcount(x));

}
