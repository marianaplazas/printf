#include "holberton.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
/**
 *convertd - convert a int to a string
 *
 *@num: number to convert
 *@s: string;
 * Return: 0
 */
char *convertd(long int num, char *s)
{
	int i, rem, len = 0;
	long int n;
	char *str;
	int sign = 1;

	if (num == 0)
		len++;
	if (num < 0)
	{
		sign--;
		num = -num;
	}
	n = num;
	while (n != 0)
	{
		len++;
		n /= 10;
	}
	str = malloc(sizeof(char) * (len + 1 + (-sign + 1)));
	if (str == NULL)
	{
		free(str);
		return (NULL);
	}
	for (i = 0; i < len; i++)
	{
		rem = num % 10;
		num = num / 10;
		str[len - (i + sign)] = rem + '0';
	}
	if (sign == 0)
		str[0] = '-';
	str[len + (1 - sign)] = '\0';
	s = str;
	return (s);
}
