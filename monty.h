#ifndef MONTY_H
#define MONTY_H

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#define _GNU_SOURCE

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

void _add(stack_t **head);
void _sub(stack_t **head);
void _div(stack_t **head);
void _mul(stack_t **head);
void _mod(stack_t **head);
void _swap(stack_t **head);
void _pop(stack_t **head);
void _pint(stack_t **head);
void _pchar(stack_t **head);
void _pstr(stack_t **head);
void _rotl(stack_t **head);
void _rotr(stack_t **head);
void push(stack_t **stack, unsigned int line_number);
size_t _pall(const stack_t *h);
size_t dlistint_len(const stack_t *h);
size_t print_dlistint(const stack_t *h);
int delete_dnodeint_at_index(stack_t **head, unsigned int index);
stack_t *add_dnodeint(stack_t **head, const int n);
int main(int argc, char **argv);
void switch_s(stack_t **st, char *s, int lnum)(stack_t **, unsigned int);
void free_all(stack_t **stack);
void _close(void);
void push_error(stack_t **stack, unsigned int line_number);
void add_node(stack_t **stack, int argument);
void add_node_end(stack_t **stack, int argument);

/**
 * struct global_s - file pointer and argument
 * @fp: file pointers
 * @queue: 0 if stack (LIFO), 1 if queue (FIFO)
 */
typedef struct global_s
{
        FILE *fp;
        int queue;
} global_t;
extern global_t global;

#endif
