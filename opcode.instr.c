#include "monty.h"

/**
 * _push - pushes elements to stack
 * @doubly: head of the linked list
 * @cline: line number
 * Return: empty
 */
 
void _push(stack_t **doubly, unsigned int cline)
{
	int z, j;

	if (!vglo.arg)
	{
		dbprintf(2, "L%u: ", cline);
		dbprintf(2, "usage: push integer\n");
		free_vglo();
		exit(EXIT_FAILURE);
	}

	for (j = 0; vglo.arg[j] != '\0'; j++)
	{
		if (!isdigit(vglo.arg[j]) && vglo.arg[j] != '-')
		{
			dbprintf(2, "L%u: ", cline);
			dbprintf(2, "usage: push integer\n");
			free_vglo();
			exit(EXIT_FAILURE);
		}
	}

	z = atoi(vglo.arg);

	if (vglo.lifo == 1)
		add_dbnodeint_end(doubly, z);
	else
		add_dbnodeint_end(doubly, z);
}

/**
 * _pall - prints all values on the stack
 * @doubly: head of the linked list
 * @cline: line numbers
 * Return: empty
 */
 
 void _pall(stack_t **doubly, unsigned int cline)
{
	stack_t *auxi;
	(void)cline;

	auxi = *doubly;

	while (auxi)
	{
		printf("%d\n", auxi->z);
		auxi = auxi->next;
	}
}

/**
 * _pint - prints a value at top of the stack
 * @doubly: header pointer
 * @cline: line number
 * Return: empty
 */
 
void _pint(stack_t **doubly, unsigned int cline)
{
	(void)cline;

	if (*doubly == NULL)
	{
		dbprintf(2, "L%u: ", cline);
		dbprintf(2, "can't pint, stack empty\n");
		free_vglo();
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*doubly)->n);
}

/**
 * _pop - removes the top element of the stack
 * @doubly: header pointer
 * @cline: line number
 * Return: empty
 */
 
void _pop(stack_t **doubly, unsigned int cline)
{
	stack_t *auxi;

	if (doubly == NULL || *doubly == NULL)
	{
		dbprintf(2, "L%u: can't pop an empty stack\n", cline);
		free_vglo();
		exit(EXIT_FAILURE);
	}
	auxi = *doubly;
	*doubly = (*doubly)->next;
	free(auxi);
}

/**
 * _swap - swaps two top elements of the stack
 * @doubly: header pointer
 * @cline: line number
 * Return: empty
 
void _swap(stack_t **doubly, unsigned int cline)
{
	int d = 0;
	stack_t *auxi = NULL;

	auxi = *doubly;

	for (; auxi != NULL; auxi = auxi->next, d++)
		;

	if (d < 2)
	{
		dbprintf(2, "L%u: can't swap, stack too short\n", cline);
		free_vglo();
		exit(EXIT_FAILURE);
	}

	auxi = *doubly;
	*doubly = (*doubly)->next;
	auxi->next = (*doubly)->next;
	auxi->prev = *doubly;
	(*doubly)->next = auxi;
	(*doubly)->prev = NULL;
}
