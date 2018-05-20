#include <stdio.h>
#define MAXLINE 1000

int getline(char line[]);
void reverse(char a[], int len);
void swap(char b[], int x, int y);

main()
{
    int len, max;
    char line[MAXLINE];

    max = 0;
    while((len=getline(line))>0)
    {
        reverse(line,len);
        printf("%d\n",len);
        printf("%s",line);
    }

        return 0;

}

int getline(char s[])
{
    int c,i;
    for(i=0;i<MAXLINE-1 && (c=getchar())!=EOF && c!='\n'; i++)
        s[i]=c;
    if(c=='\n')
    {
        s[i]=c;
        i++;
    }
    s[i]='\0';
    return i;
}

void reverse(char line[], int len)
{
    int i, eLen = len-1;
    for(i=0;i<(eLen)/2;i++)
    {
        swap(line, i, eLen-i);
    }
}

void swap (char line[], int a, int b)
{
        char temp = line[a];
        line[a] = line[b];
        line[b]=temp;
}
