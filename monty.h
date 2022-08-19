#ifndef MONTY_H
#define MONTY_H
#include <stddef.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;
/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/*prototypes*/

/*int _add(stack_t **stack, unsigned int __attribute__((unused))line_number);
size_t _pall(stack_t **stack, unsigned int __atribute__((unused))line_number);
size_t print_list(const list_t *h);
void _push(stack_t **stack, unsigned int line_number);
*/
int (*get_op_func(char *s))(int, int);
int _strcmp(char *s1, char *s2);
int _strlen(char *s);
/*char *_strdup(char *str);*/
char **generate_arguments(char *s, char *delimeters);
/*void free_listint(dlistint_t *head);*/
char *read_all_file(const char *path);
#endif
