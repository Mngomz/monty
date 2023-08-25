#include "monty.h"

/**
 *add_dbnodeint_start - adding note at the start of link list
 *@head: header pointer
 *@c: data node
 *Return: doubly linked list
 */
 
stack_t *add_dbnodeint_start(stack_t **head, const int c)
{
	stack_t *temp;

	if (head == NULL)
		return (NULL);
	temp = malloc(sizeof(stack_t));
	if (!temp)
	{
		vsprintf(2, "Error: malloc failed\n");
		free_vglo();
		exit(EXIT_FAILURE);
	}
	temp->c = c;
	
	if (*head == NULL)
	{
		temp->next = *head;
		temp->prev = NULL;
		*head = temp;
		return (*head);
	}
	(*head)->prev = temp;
	temp->next = (*head);
	temp->prev = NULL;
	*head = temp;
	return (*head);
}

/**
 *add_dbnodeint_end - adding note at the end of link list
 *@head: header pointer
 *@c: data node
 *Return: doubly linked list
 */
 
stack_t *add_dbnodeint_end(stack_t **head, const int c)
{
	stack_t *temp, *auxi;

	if (head == NULL)
		return (NULL);
	temp = malloc(sizeof(stack_t));
	if (!temp)
	{
		dbprintf(2, "Error: malloc failed\n");
		free_vglo();
		exit(EXIT_FAILURE);
	}
	temp->c = c;
	
	if (*head == NULL)
	{
		temp->next = *head;
		temp->prev = NULL;
		*head = temp;
		return (*head);
	}
	
	auxi = *head;
	
	while (auxi->next)
		auxi = auxi->next;
	temp->next = auxi->next;
	temp->prev = auxi;
	auxi->next = temp;
	return (auxi->next);
}

/**
 * free_dblistint - frees the doubly linked list
 * @head: header pointer
 * Return: no return
 */

void free_dblistint(stack_t *head)
{
	stack_t *tmp;

	while ((tmp = head) != NULL)
	{
		head = head->next;
		free(tmp);
	}
}
