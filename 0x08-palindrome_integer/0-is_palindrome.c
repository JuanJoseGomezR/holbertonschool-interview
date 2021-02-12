#include "palindrome.h"

/**
  * is_palindrome - check if number is palindrome
  * @n: given number
  * Return: 1 || 0
  */

int is_palindrome(unsigned long n)
{
	unsigned long int q = n;
	unsigned long int result = 0;
	unsigned long int rem;

	while (q != 0)
	{
		rem = q % 10;
		result = result * 10 + rem;
		q = q / 10;
	}

	if (result == n)
		return (1);
	else
		return (0);
}
