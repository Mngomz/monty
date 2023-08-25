#include "monty.h"

/**
 * _div - division of the second by the top element
 * @doubly: header pointer
 * @cline: line number;
 * Return: empty
 */
 
void _div(stack_t **doubly, unsigned int cline)
{
	int c = 0;
	stack_t *auxi = NULL;

	auxi = *doubly;

	for (; auxi != NULL; auxi = auxi->next, c++)
		;

	if (c < 2)
	{
		dbprintf(2, "L%u: can't div, stack too short\n", cline);
		free_vglo();
		exit(EXIT_FAILURE);
	}

	if ((*doubly)->n == 0)
	{
		dbprintf(2, "L%u: division by zero\n", cline);
		free_vglo();
		exit(EXIT_FAILURE);
	}

	auxi = (*doubly)->next;
	auxi->n /= (*doubly)->n;
	_pop(doubly, cline);
}

/**
 * _mult - multiplies top to the second top element
 * @doubly: head of the linked list
 * @cline: line number;
 * Return: no return
 */
 
void _mult(stack_t **doubly, unsigned int cline)
{
	int c = 0;
	stack_t *auxi = NULL;

	auxi = *doubly;

	for (; auxi != NULL; auxi = auxi->next, c++)
		;

	if (c < 2)
	{
		dbprintf(2, "L%u: can't mul, stack too short\n", cline);
		free_vglo();
		exit(EXIT_FAILURE);
	}

	auxi = (*doubly)->next;
	auxi->n *= (*doubly)->n;
	_pop(doubly, cline);
}

/**
 * _mod - continues devision of top to the second element
 * @doubly: header pointer
 * @cline: line number;
 * Return: empty
 */
 
void _mod(stack_t **doubly, unsigned int cline)
{
	int c = 0;
	stack_t *auxi = NULL;

	auxi = *doubly;

	for (; auxi != NULL; auxi = auxi->next, c++)
		;

	if (c < 2)
	{
		dbprintf(2, "L%u: can't mod, stack too short\n", cline);
		free_vglo();
		exit(EXIT_FAILURE);
	}

	if ((*doubly)->n == 0)
	{
		dbprintf(2, "L%u: division by zero\n", cline);
		free_vglo();
		exit(EXIT_FAILURE);
	}

	auxi = (*doubly)->next;
	auxi->n %= (*doubly)->n;
	_pop(doubly, cline);
}
/**
 * _pchar - prints char value of the first element
 * @doubly: header pointer
 * @cline: line number;
 * Return: empty
 */
 
void _pchar(stack_t **doubly, unsigned int cline)
{
	if (doubly == NULL || *doubly == NULL)
	{
		dbprintf(2, "L%u: can't pchar, stack empty\n", cline);
		free_vglo();
		exit(EXIT_FAILURE);
	}
	if ((*doubly)->n < 0 || (*doubly)->n >= 128)
	{
		dbprintf(2, "L%u: can't pchar, value out of range\n", cline);
		free_vglo();
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (*doubly)->n);
}

/**
 * _pstr - prints the string of the stack
 *
 * @doubly: head of the linked list
 * @cline: line number;
 * Return: no return
 */
 
void _pstr(stack_t **doubly, unsigned int cline)
{
	stack_t *auxi;
	(void)cline;

	auxi = *doubly;

	while (auxi && auxi->n > 0 && auxi->n < 128)
	{
		printf("%c", auxi->n);
		auxi = auxi->next;
	}

	printf("\n");
}
