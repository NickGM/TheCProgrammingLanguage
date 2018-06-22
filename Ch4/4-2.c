#include <stdio.h>
#include <ctype.h>
#include <math.h>

double atof(char s[]);

int main()
{
    printf("%f", atof("123.45e-6"));
}

double atof(char s[])
{
    double val, power, exp;
    int i, sign, negE;

    for(i=0; isspace(s[i]); i++)
        ;
    sign = (s[i]=='-') ? -1:1;
    if(s[i]=='+'||s[i]=='-')
        i++;
    for(val=0.0; isdigit(s[i]); i++)
        val=10.0*val+(s[i]-'0');
    if(s[i]=='.')
        i++;
    for(power=1.0; isdigit(s[i]); i++)
    {
        val=10.0*val+(s[i]-'0');
        power*=10.0;
    }

   if(tolower(s[i])=='e')
        i++;
    negE = (s[i]=='-');
    if(s[i]=='+'||s[i]=='-')
        i++;
    for(exp = 0.0; isdigit(s[i]);i++)
        exp=10.0*exp+(s[i]-'0');
    exp=pow(10, exp);

    if(negE)    power*=exp;
    else        power/=exp;

    return sign*val/power;
}
