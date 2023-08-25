#include "monty.h"

/**
 * _calloc - adds two strings
 * @enumb: amount of elements
 * @s: type of elements
 * Return: empty
 */
 
void *_calloc(unsigned int enumb, unsigned int s)
{
	void *p = NULL;
	unsigned int a;

	if (enumb == 0 || s == 0)
	{
		return (NULL);
	}
	p = malloc(enumb * s);
	if (p == NULL)
	{
		return (NULL);
	}
	for (a = 0; a < (enumb * s); a++)
	{
		*((char *)(p) + a) = 0;
	}
	return (p);
}

/**
 * _realloc - modify then copy size and content
 * @ptr: pointer
 * @osize: old size of bytes
 * @nsize: new size of bytes
 * Return: empty
 */
 
void *_realloc(void *ptr, unsigned int osize, unsigned int nsize)
{
	char *p = NULL;
	unsigned int a;

	if (nsize == osize)
		return (ptr);
	if (ptr == NULL)
	{
		p = malloc(nsize);
		if (!p)
			return (NULL);
		return (p);
	}
	if (nsize == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}
	if (nsize > osize)
	{
		p = malloc(nsize);
		if (!p)
			return (NULL);
		for (a = 0; a < osize; a++)
			p[a] = *((char *)ptr + a);
		free(ptr);
	}
	else
	{
		p = malloc(nsize);
		if (!p)
			return (NULL);
		for (a = 0; a < nsize; a++)
			p[a] = *((char *)ptr + a);
		free(ptr);
	}
	return (p);
}
