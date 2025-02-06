#include<stdio.h>
#include<ctype.h>

int main()
{
    char ch;
    printf("input a character: ");
    scanf("%c", &ch);
    if(isupper(ch)) {
        ch = tolower(ch);
    }
    else
    {
        ch = toupper(ch);
    }
    printf("after conversion: %c\n", ch);

return 0;

}