#include "monty.h"

/**
 * _strcmp - Function that compares two strings.
 * @s1: str to be compared
 * @s2: str to be compared
 * Return: 0 if s1 and s2 are equals.
 *         otherwise, any value
 */
 
int _strcmp(char *s1, char *s2)
{
	int j;

	for (j = 0; s1[j] == s2[j] && s1[j]; j++)
		;
	if (s1[j] > s2[j])
		return (1);
	if (s1[j] < s2[j])
		return (-1);
	return (0);
}

/**
 * _sch - search if a char is inside a string
 * @s: string to review
 * @c: char to find
 * Return: 1 if success 0 if not
 */
 
int _sch(char *s, char c)
{
	int cont = 0;

	while (s[cont] != '\0')
	{
		if (s[cont] == c)
		{
			break;
		}
		cont++;
	}
	if (s[cont] == c)
		return (1);
	else
		return (0);
}

/**
 * _strtoky - function that cut a string into tokens depending of the delimit
 * @s: string to cut in parts
 * @d: delimiters
 * Return: first partition
 */
 
char *_strtoky(char *s, char *d)
{
	static char *ultimo;
	int m = 0, n = 0;

	if (!s)
		s = ultimo;
	while (s[m] != '\0')
	{
		if (_sch(d, s[m]) == 0 && s[m + 1] == '\0')
		{
			ultimo = s + m + 1;
			*ultimo = '\0';
			s = s + n;
			return (s);
		}
		else if (_sch(d, s[m]) == 0 && _sch(d, s[m + 1]) == 0)
			m++;
		else if (_sch(d, s[m]) == 0 && _sch(d, s[m + 1]) == 1)
		{
			ultimo = s + m + 1;
			*ultimo = '\0';
			ultimo++;
			s = s + n;
			return (s);
		}
		else if (_sch(d, s[m]) == 1)
		{
			n++;
			m++;
		}
	}
	return (NULL);
}
