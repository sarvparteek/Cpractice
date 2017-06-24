// Code to test structures

#include <stdio.h>
#include <stdbool.h> // for bool
#include <stdint.h> // for fixed-width data types
#include <math.h> // for ceil()
#include <string.h>

bool isPalindrome(char *str);

int main()
{
    printf("%d\n",(uint32_t)isPalindrome("kayak"));
    printf("%d\n",(uint32_t)isPalindrome("baab"));
    printf("%d\n",(uint32_t)isPalindrome("kayaik"));
	return 0;
}

bool isPalindrome(char *str)
{
	uint32_t len = strlen(str);
	for (uint32_t i = 0; i < ceil(len/2.0); i++)
	{
		if (str[i] != str[len-1-i])
			return false;
	}
	return true;
}