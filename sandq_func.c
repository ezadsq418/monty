#include "monty.h"

/**
  * stack - changes the addition to the stack to LIFO
  * @stack: NULL
  * @line_number: 0
  * Return: nothing, void
  */
void stack(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;

	vars->IFO = 0;
}

/**
  * queue - changes the addition to the stack to FIFO
  * @stack: NULL
  * @line_number: 0
  * Return: nothing, void
  */
void queue(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;

	vars->IFO = 1;
}
