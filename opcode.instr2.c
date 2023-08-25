#include "monty.h"

/**
 * _queue - sets format of data to the queue (FIFO)
 * @doubly: header pointer
 * @cline: line number;
 * Return: empty
 */
 
void _queue(stack_t **doubly, unsigned int cline)
{
	(void)doubly;
	(void)cline;

	vglo.lifo = 0;
}

/**
 * _stack - sets format for data (LIFO)
 * @doubly: header pointer
 * @cline: line number;
 * Return: empty
 */
 
void _stack(stack_t **doubly, unsigned int cline)
{
	(void)doubly;
	(void)cline;

	vglo.lifo = 1;
}

/**
 * _add - adds top two elements of the stack
 * @doubly: header pointer
 * @cline: line number;
 * Return: empty
 */
 
void _add(stack_t **doubly, unsigned int cline)
{
	int c = 0;
	stack_t *auxi = NULL;

	auxi = *doubly;

	for (; auxi != NULL; auxi = auxi->next, c++)
		;

	if (c < 2)
	{
		dbprintf(2, "L%u: can't add, stack too short\n", cline);
		free_vglo();
		exit(EXIT_FAILURE);
	}

	auxi = (*doubly)->next;
	auxi->n += (*doubly)->n;
	_pop(doubly, cline);
}

/**
 * _nop - print results of the stack
 * @doubly: header pointer
 * @cline: line number;
 * Return: emmpty
 */
 
void _nop(stack_t **doubly, unsigned int cline)
{
	(void)doubly;
	(void)cline;
}

/**
 * _sub - subtracts from the top element of the stack
 * @doubly: header pointer
 * @cline: line number;
 * Return: empty
 */
 
void _sub(stack_t **doubly, unsigned int cline)
{
	int f = 0;
	stack_t *auxi = NULL;

	auxi = *doubly;

	for (; auxi != NULL; auxi = auxi->next, f++)
		;

	if (f < 2)
	{
		dbprintf(2, "L%u: can't sub, stack too short\n", cline);
		free_vglo();
		exit(EXIT_FAILURE);
	}

	auxi = (*doubly)->next;
	auxi->n -= (*doubly)->n;
	_pop(doubly, cline);
}
