#include <stdio.h>

/*print fahrenheit-celcius conversion table */

int main()
{
    float fahr, celsius;
    int upper, lower, step;

    lower = 0;
    upper = 300;
    step = 20;

    fahr = lower;
    printf("%s", "Fahrenheit to celcius conversion table:\n");

    while(fahr<=upper)
    {
        celsius=(5.0/9.0)*(fahr-32.0);
        printf("%3.0f %6.1f\n", fahr, celsius);
        fahr+=step;
    }
}
