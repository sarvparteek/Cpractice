// Code to reverse integers

#include <stdio.h>
#include <stdint.h>

int32_t reverseDigits(int32_t num);

int main()
{
    int32_t input = -1024;
    printf("Input: %" PRId32 "\nOutput: %" PRId32 "\n", input, reverseDigits(input));
    return 0;
}

int32_t reverseDigits(int32_t num)
{
    int32_t newNum = 0, rem = 0;
    do
    {
        rem = num % 10;
        num /= 10;
        newNum = newNum * 10 + rem;
    }
    while (num);

    return newNum;
}