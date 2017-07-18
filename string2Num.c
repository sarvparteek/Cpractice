/*
 * Author: Sarv Parteek Singh
 * Date: 07/18/2017
 * Brief: File to convert a string into int
 */

#include <stdio.h>
#include <string.h> // for strlen()
#include <math.h> // for pow()
#include <inttypes.h> // for fixed-width data types

#define MAX_STRING_LENGTH 11U // max number of digits that can be stored in 32 bit signed int = 9 (1 for sign, 1 for \0)

int32_t str2Num(char *str, uint8_t len);

int main()
{
    char str[MAX_STRING_LENGTH] = {'\0'};
    printf("Enter the integer (add a negative sign at the front for negative integers)\n");
    scanf("%s", str);
    int32_t num = str2Num(str, strlen(str));
    printf("The number is %" PRId32 "\n",num);
}

int32_t str2Num(char *str, uint8_t len)
{
    int32_t digits = (str[0] == '-'? len-1: len);
    int32_t num = 0;
    int32_t i;
    for (i = len-1; i >= len-digits; i--)
    {
        num += (int32_t)((uint8_t)str[i]- 48) * (int32_t)round(pow(10,len-1-i)); // char-48 = int (refer ASCII Table)
        // round is required because pow gives double results (eg. 9.99 for 10, which if directly converted to int is 9)
    }
    return (digits == len-1? -1*num: num);
}