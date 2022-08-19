#include "monty.h"

/**
* get_op_func - funcion
* @s: char
* Return: 0
*/
int (*get_op_func(char *s))(int, int)
{
	op_t ops[] = {
	{"+", op_add},
	{"-", op_sub},
	{"*", op_mul},
	{"/", op_div},
	{"%", op_mod},
	{NULL, NULL}
	};
	int i;

	i = 0;
	while (ops[i].op)
	{
		if (ops[i].op[0] == *s)
			return (ops[i].f);
		i++;
	}
	return (NULL);
}

/**
 * _strcmp - Comparate two strings
 * @s1: First string
 * @s2: Second string
 * Return: Result of the comparatin
 */
int _strcmp(char *s1, char *s2)
{
	int i = 0;

	if (!s1 && !s2)
		return (0);
	if (!s1 || !s2)
		return (-1);
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

/**
 * _strlen - length of a string
 * @s: string
 * Return: return length of a s variable
 */
int _strlen(char *s)
{
	int length = 0;

	while (*(s + length))
		length++;
	return (length);
}

/**
 * _strdup - pointer to a newly allocated space in memory
 * @str: string
 * Return: return array
 */
char *_strdup(char *str)
{
	char *temp;
	unsigned int i = 0;
	unsigned int size = 0;

	if (str == NULL)
		return (NULL);

	for (; str[size]; size++)
		;

	temp = malloc(size + 1);

	if (temp == NULL)
		return (NULL);
	while (i < size)
	{
		temp[i] = str[i];
		i++;
	}
	temp[i] = '\0';
	return (temp);
}

/**
* generate_arguments - generates an array with the given arguments
* @s: strings variable to tokenize
* @delimeters: bounding parameters
* Return: full array
*/
char **generate_arguments(char *s, char *delimeters)
{
	char **args;
	int i = 0;
	int length = 0;
	char *s_tmp;
	char *token;

	s_tmp = _strdup(s);
	token = strtok(s_tmp, delimeters);
	for (length = 0; token; length++)
	{
		token = strtok(NULL, delimeters);
	}
	free(s_tmp);
	args = malloc(sizeof(char *) * (length + 1));
	if (args == NULL)
	{
		return (NULL);
	}

	s_tmp = _strdup(s);
	token = strtok(s_tmp, delimeters);
	for (i = 0; token; i++)
	{
		args[i] = _strdup(token);
		token = strtok(NULL, delimeters);
	}
	args[i] = NULL;
	free(s_tmp);
	return (args);
}
/**
* free_dlistint -  function that frees memory
* @head: pointer to head node
*/
void free_listint(dlistint_t *head)
{
	stack_t *tmp;

	while (head)
	{
		tmp = head->next;
		free(head);
		head = tmp;
	}
}
