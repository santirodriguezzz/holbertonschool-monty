#include "monty.h"

/**
*add_dnodeint - function that adds a new node at the beginning
*@head: pointer of pointer to first node
*@n: value
*Return: New Node
*/

void _push(stack_t **stack, unsigned int line_number)
{
	stack_t *new;
	char *new_list_number;

	new_list_number = strtok(NULL, " \n\t$");
	if (!new_list_number || !is_digit(new_list_number))
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		free_list(*stack);
		fclose(file);
		exit(EXIT_FAILURE);
	}
	new = malloc(sizeof(stack_t));
	if (!new)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_list(*stack);
		fclose(file);
		exit(EXIT_FAILURE);
	}

	new->n = atoi(new_list_number);
	new->next = *stack;
	new->prev = NULL;
	if ((*stack) != NULL)
	{
		(*stack)->prev = new;
	}
	(*stack) = new;
}

/**
* _add - sum data
* @head: pointer to head node
* Return: sum of all the data
*/
 int _add(stack_t **stack, unsigned int __attribute__((unused))line_number)
 {
 	int count = 0;
	stack_t *head = *stack;

	while (count < 2)
	{
		count += head->n;
		head = head->next;
	}
	return (count);
}
/** print_list - function that print a node
* @h: pointer
* Return:  the number of nodes
*/

size_t print_list(const list_t *h)
{
	int count = 0;

	while (h != NULL)
	{
		if (h->str == NULL)
			printf("[0] (nil)\n");
		else
			printf("[%i] %s\n", h->len, h->str);
		count++;
		h = h->next;
	}
	return (count);
}
/**
* print_list - function that print a node
* @h: pointer
* Return:  the number of nodes
*/

size_t _pall(stack_t **stack, unsigned int __atribute__((unused))line_number)
{
	size_t count = 0;
	stack_t *h = *stack;

	while (h != NULL)
	{
		printf("%d\n" h->n);
		count++;
		h = h->next;
	}
	return (count);
}
