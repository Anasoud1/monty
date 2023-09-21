#ifndef MONTY_H
#define MONTY_H

#define  _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <string.h>
#include <ctype.h>

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

int parse_execute_line(char *line, stack_t **top, unsigned int ln, FILE *fp);
void push_item(stack_t **top, int data, char *line);
void print_all(stack_t **top, unsigned int ln);
void error_msg(int number_err, unsigned int line_number, stack_t *stack);
int is_number(char *s);
int remove_leading(char *str);
void free_list(stack_t *head);
void print_top(stack_t **top, unsigned int ln);
void pop_top(stack_t **stack, unsigned int line_number);
void swap(stack_t  **stack, unsigned int line_number);
void add(stack_t  **stack, unsigned int line_number);
void nop(stack_t  **stack, unsigned int line_number);
void sub_top_items(stack_t  **stack, unsigned int line_number);
int parse_execute_push(char *opcode, unsigned int ln, stack_t **top,
		char *line);
int parse_execute_instructions(instruction_t *instructions, char *opcode,
		stack_t **top, unsigned int ln);
void error_msg2(int number_err, unsigned int line_number, stack_t *stack);
void div_top_items(stack_t  **stack, unsigned int line_number);
void mul_top_items(stack_t  **stack, unsigned int line_number);
void mod_top_items(stack_t  **stack, unsigned int line_number);
void pchar_top_item(stack_t  **stack, unsigned int line_number);
void pstr_items(stack_t  **stack, unsigned int line_number);
void rotl(stack_t  **stack, unsigned int line_number);

#endif
