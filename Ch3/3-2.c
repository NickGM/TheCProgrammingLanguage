#include <stdio.h>

void escape(char s[], char t[])
{
    int i;
    int j;
    i=j=0;
    char c;
    while((c=t[i])!='\0')
    {
        switch (c)
        {
            case '\n':
                s[j++]='\\';
                s[j]='n';
                break;

            case '\t':
                s[j++] = '\\';
                s[j] = 't';
                break;

            case '\\':
                s[j++] = '\\';
                s[j] = '\\';
                break;

            default:
                s[j]=t[i];
                break;
    }
    ++i;
    ++j;
    }
    s[j] = t[i];
}

int main()
{
    char test[] = "This is the size of a tab: \t and this is a newline \n from here on.";
    char test2[100];
    printf("%s", test);
    escape(test2, test);
    printf("%s", test2);
}
