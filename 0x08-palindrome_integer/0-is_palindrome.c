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

/*		lfh = (unsigned long) log10l(n);  // the right way*/
		lfh = digit_count(n);
		rth = 10;

		if (lfh == 1)
		return (1);
		else if (lfh == 2 && n / 10 == n % 10)
		return (1);

/*		lfh = (unsigned long) powl(10, lfh); */
		lfh = _pow(10, lfh - 1);


	while (lfh >= rth)
		{
		if (n / lfh % 10 != (n % rth) / (rth / 10))
		return (0);
		lfh /= 10;
		rth *= 10;
		}

		return (1);
}

/**
 * _pow - performs power operation on a number
 * @n: number to multiply
 * @x: factor
 * Return: unsigned long int
 */
unsigned long _pow(unsigned long n, unsigned long x)
{
	while (x > 1)
	{
	n *= n;
	x--;
	}
	return (n);
}

/**
 * digit_count - count the number of digits in a unsigned long int
 * dev note: would the log10 + 1 method but can't not use math.h with
 * Holberton checker
 *
 * @x: number to perform operation on
 * Return: count as unsigned long
 */
unsigned long digit_count(unsigned long x)
{
	unsigned long i;

	if (x == 0)
	return (1);

	i = 0;
	while (x)
	{
	i++;
	x = x / 10;
	}
	return (i);
}

