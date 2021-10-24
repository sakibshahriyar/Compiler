#include <stdio.h>
#include <ctype.h>
#include <string.h>
main()
{
int i=0;
char s [20];
puts(" Input String ");
gets(s);
while (i<strlen(s))
    if (isdigit(s[i]) || s[i]=='.')
    i++ ;
    else
    {
        puts("Not Numeric");
        getch();
        exit(0);
    }
    puts("Numeric Constant");
    getch();
}

