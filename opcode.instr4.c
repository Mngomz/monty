#include "monty.h"

/**
 * _rotl - rotates elements
 * @doubly: header pointer
 * @cline: line number;
 * Return: empty
 */
 
void _rotl(stack_t **doubly, unsigned int cline)
{
	stack_t *aux1 = NULL;
	stack_t *aux2 = NULL;
	(void)cline;

	if (*doubly == NULL)
		return;

	if ((*doubly)->next == NULL)
		return;

	aux1 = (*doubly)->next;
	aux2 = *doubly;

	for (; aux2->next != NULL; aux2 = aux2->next)
		;

	aux1->prev = NULL;
	aux2->next = *doubly;
	(*doubly)->next = NULL;
	(*doubly)->prev = aux2;
	*doubly = aux1;
}

/**
 * _rotr - reverses the stack
 * @doubly: header pointer
 * @cline: line number
 * Return: empty
 */
 
void _rotr(stack_t **doubly, unsigned int cline)
{
	stack_t *auxi = NULL;
	(void)cline;

	if (*doubly == NULL)
		return;

	if ((*doubly)->next == NULL)
		return;

	auxi = *doubly;

	for (; auxi->next != NULL; auxi = auxi->next)
		;

	auxi->prev->next = NULL;
	auxi->next = *doubly;
	auxi->prev = NULL;
	(*doubly)->prev = auxi;
	*doubly = auxi;
}
