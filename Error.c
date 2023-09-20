#include "monty.h"

void error_msg(int number_err, unsigned int line_number, stack_t *stack)
{
	(void)stack;
        switch (number_err)
        {
                case 1:
                        fprintf(stderr, "L%d: usage: push integer\n", line_number);
                        /*free_list(stack);*/
                        exit(EXIT_FAILURE);
                case 2:
                        fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
                        /*free_list(stack);*/
                        exit(EXIT_FAILURE);
                case 3:
                        fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
                        /*free_list(stack);*/
                        exit(EXIT_FAILURE);
                case 4:
                        fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
                        /*free_list(stack);*/
                        exit(EXIT_FAILURE);
                case 5:
                        fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
                        /*free_list(stack);*/
                        exit(EXIT_FAILURE);
        }
}
