#include <stdio.h>
#include <string.h>

int main()
{
    char str1[] = "Sakib", str2[] = "Shahriyar", str3[] = "Sakib";

    int result;

    result=strlen(str1);
    printf("strlen(str1) = %d\n",result);
    result=strlen(str2);
    printf("strlen(str2) = %d\n",result);
    result=strlen(str3);
    printf("strlen(str3) = %d\n",result);

    result = strcmp(str1, str2);
    printf("strcmp(str1, str2) = %d\n", result);

    result = strcmp(str1, str3);
    printf("strcmp(str1, str3) = %d\n", result);

    result = strcmp(str2, str3);
    printf("strcmp(str2, str3) = %d\n", result);


    return 0;
}
