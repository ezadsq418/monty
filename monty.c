#include "monty.h"

vars_t *vars;

/**
  * main - Entry Point
  * @argc: Number of arguments
  * @argv: Arguments names
  * Return: 0 on success, exit on failures
  */
int main(int argc, char **argv)
{
	size_t n = 0;
	vars_t temp = {0, NULL, NULL, NULL, NULL, NULL, 1};

	vars = &temp;
	vars->fname = argv[1];
	if (argc != 2)
		exit_function(16);

	vars->fp = fopen(argv[1], "r");
	if (vars->fp == NULL)
		exit_function(1);

	for (; getline(&(vars->buf), &n, vars->fp) != EOF; vars->line_number++)
	{
		vars->tokened = malloc(sizeof(char *) * 2);
		if (vars->tokened == NULL)
			exit_function(3);
		tokenize(vars->buf);
		find_op();
		free_buf();
		free_token();
	}
	free_buf();
	free_list(vars->head);
	free_token();
	fclose(vars->fp);
	return (0);
}
