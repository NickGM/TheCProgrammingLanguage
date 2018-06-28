#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAXOP 100
#define NUMBER '0'

int getop(char []);
void push(double);
double pop(void);
void clearStack(void);
void printTop(void);
void duplicateTop(void);
void swapTopTwo(void);

main()
{
    int type;
    double op2;
    char s[MAXOP];

    while((type = getop(s))!=EOF)
    {
        switch (type)
        {
            case NUMBER:
                push(atof(s));
                break;
            case '+':
                push(pop()+pop());
                break;
            case '*':
                push(pop()*pop());
                break;
            case '-':
                op2=pop();
                push(pop()-op2);
                break;
            case '/':
                op2=pop();
                if(op2!=0.0)
                    push(pop()/op2);
                else
                    printf("error: zero divisor\n");
                break;
            /*provision for modulus*/
            case '%':
                if(op2!=0.0)
                    push(fmod(pop(),op2));
                else
                    printf("error: zero divisor\n");
                break;
            case '?':
                printTop();
                break;
            case '#':
                duplicateTop();
                break;
            case '~':
                swapTopTwo();
                break;
            case '!':
                clearStack();
                break;
            case '\n':
                printf("\t%.8g\n", pop());
                break;
            default:
                printf("error: unknown command %s\n", s);
                break;
        }
    }
    return 0;
}

#define MAXVAL 100
int sp=0; /*NB: NEXT free stack position */
double val[MAXVAL];

void push(double f)
{
    if (sp<MAXVAL)
        val[sp++]=f;
    else
        printf("error: stack full, can't push %g\n", f);
}

double pop(void)
{
    if(sp>0)
        return val[--sp];
    else {
        printf("error: stack empty\n");
        return 0.0;
    }
}

void printTop(void)
{
    if(sp>0)
        printf("\t%.8g\n", val[sp-1]);
    else
        printf("stack is empty\n");
}

void duplicateTop(void)
{
    double temp = pop();
    push(temp);
    push(temp);
}

void swapTopTwo(void)
{
    double temp1 = pop();
    double temp2 = pop();
    push(temp1);
    push(temp2);
}

void clearStack(void)
{
    sp=0;
}


#include <ctype.h>
int getch(void);
void ungetch(int);

int getop(char s[])
{
    int i,c;
    while((s[0]=c=getch())==' '|| c=='\t')
        ;
    s[1]='\0';
    i=0;
    if(!isdigit(c) && c!='.' && c!='-')
        return c;
    if(c =='-')
        if(isdigit(c=getch())||c=='.')
           s[++i]=c;
        else
        {
            if(c!=EOF)
                ungetch(c);
            return '-';
        }
    if(isdigit(c))
        while(isdigit(s[++i]=c=getch()))
            ;
    if(c=='.')
        while(isdigit(s[++i]=c=getch()))
    s[i]='\0';
    if(c!=EOF)
        ungetch(c);
    return NUMBER;
}

#define BUFSIZE 100

char buf[BUFSIZE];
int bufp=0;

int getch(void)
{
    return (bufp>0)? buf[--bufp]:getchar();
}

void ungetch(int c)
{
    if(bufp>=BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++]=c;
}
