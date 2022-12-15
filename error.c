#include "monty.h"
/**
 * exit_function - handles errors and frees memory before exiting
 * @err_num: number corresponding to an error message
 * Return: void
 */
void exit_function(unsigned int err_num)
{
	char *s[] = {"swap", "add", "sub", "div", "mul", "mod"};
	int ln = vars->line_number;

	if (err_num == 1)
		printf("Error: Can't open file %s\n", vars->fname);
	if (err_num == 2)
		printf("L%d: unknown instruction %s\n", ln, vars->tokened[0]);
	if (err_num == 3)
		printf("Error: malloc failed\n");
	if (err_num == 4)
		printf("L%d: usage: push integer\n", ln);
	if (err_num == 5)
		printf("L%d: can't pint, stack empty\n", ln);
	if (err_num == 6)
		printf("L%d: can't pop an empty stack\n", ln);
	if (err_num >= 7 && err_num <= 12)
		printf("L%d: can't %s, stack too short\n", ln, s[err_num - 7]);
	if (err_num == 13)
		printf("L%d: division by zero\n", ln);
	if (err_num == 14)
		printf("L%d: can't pchar, value out of range\n", ln);
	if (err_num == 15)
		printf("L%d: can't pchar, stack empty\n", ln);
	if (err_num == 16)
		printf("USAGE: monty file\n");

	free_buf();
	free_list(vars->head);
	free_token();
	if (vars->fp != NULL)
		fclose(vars->fp);
	exit(EXIT_FAILURE);
}
/**
 * free_list - free a stack_t list
 * @head: head of list to free
 * Return: void
 */
void free_list(stack_t *head)
{
	if (head != NULL)
	{
		if (head->next != NULL)
			free_list(head->next);
		free(head);
	}
}
/**
 * free_buf - free getline buffer
 * Return: void
 */
void free_buf(void)
{
	if (vars->buf != NULL)
	{
		free(vars->buf);
		vars->buf = NULL;
	}
}

/**
  * free_token - Frees malloc'd tokens
  * Return: Nothing, void
  */
void free_token(void)
{
	if (vars->tokened != NULL)
	{
		if (vars->tokened[0] != NULL)
			free(vars->tokened[0]);
		if (vars->tokened[1] != NULL)
			free(vars->tokened[1]);
		free(vars->tokened);
	}
	vars->tokened = NULL;
}
