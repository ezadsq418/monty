#include "monty.h"

/**
  * pint - prints the number at the top of the stack
  * @stack: the double pointer to the head (NULL)
  * @line_number: the line we're on (always passed 0)
  * Return: nothing, void
  */
void pint(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;

	if (vars->head == NULL)
		exit_function(5);
	printf("%d\n", vars->head->n);
}

/**
  * pop - deletes the struct on the top of the stack
  * @stack: the double pointer to the head (NULL)
  * @line_number: the line we're on (always passed 0)
  * Return: nothing, void
  */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *traverse;

	(void) stack;
	(void) line_number;

	if (vars->head == NULL)
		exit_function(6);
	traverse = vars->head->next;
	if (traverse != NULL)
		traverse->prev = NULL;
	free(vars->head);
	vars->head = traverse;
}

/**
 * swap - swaps the top two numbers of the stack
 * @stack: not used
 * @line_number: not used
 * Return: void
 */
void swap(stack_t **stack, unsigned int line_number)
{
	int temp = 0;

	(void) stack;
	(void) line_number;
	if (vars->head != NULL && vars->head->next != NULL)
	{
		temp = vars->head->n;
		vars->head->n = vars->head->next->n;
		vars->head->next->n = temp;
	}
	else
	{
		exit_function(7);
	}
}

/**
  * nop - does nothing
  * @stack: not used
  * @line_number: not used
  * Return: void
  */
void nop(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;
}
