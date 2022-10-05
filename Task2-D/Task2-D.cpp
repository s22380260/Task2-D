#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void reverse_string(char* str)
{
    size_t len = strlen(str);
    for (size_t i = 0; i < len / 2; i++)
    {
        size_t j = len - i - 1;
        char t = str[i];
        str[i] = str[j];
        str[j] = t;
    }
}

char* reverse_string_copy(char* str)
{
    // char* newstr = (char*) malloc(strlen(str) + 1);
    // strcpy(newstr, str);
    char* newstr = _strdup(str);
    reverse_string(newstr);
    return newstr;
}

void test_string(char* str)
{
    printf("\n");
    printf("'%s'\n", str);

    char* reversed = reverse_string_copy(str);
    printf("  reverse_string_copy: '%s'\n", reversed);
    printf("   printf(str): '%s'\n", str);

    reverse_string(str);
    printf("  reverse_string: '%s'\n", str);
    printf("   printf(str): '%s'\n", str);
}

int main()
{
    char str[] = "Hello World";
    test_string(str);

    char cs[256];
    printf("\n===\nEnter custom string to test: ");
    scanf_s("%[^\n]", &cs, sizeof(cs));
    printf("===\n");
    test_string(cs);
}