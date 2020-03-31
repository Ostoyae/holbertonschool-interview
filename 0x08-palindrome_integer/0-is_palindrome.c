#include <stdio.h>
#include "palindrome.h"
#include <math.h>

/**
 * is_palindrome - check if a unsigned long number is a palindrome
 * @n: unsigned long number to test.
 * Return: 1 if palindrome else 0
 */
int is_palindrome(unsigned long n)
{
		unsigned long lfh, rth;

		lfh = (unsigned long) log10l(n);
		rth = 10;

		if (lfh == 0)
		return (1);
		else if (lfh == 1 && n / 10 == n % 10)
		return (1);

		lfh = (unsigned long) powl(10, lfh);

		while (lfh >= rth)
		{
		if (n / lfh % 10 != (n % rth) / (rth / 10))
		return (0);
		lfh /= 10;
		rth *= 10;
		}

		return (1);
}
