#include <stdio.h>
#include "monty.h"

#define MAX_LINE_SIZE 1024

globales_t globalvar = {NULL, NULL, NULL};

/**
 * main - entry point for the CLI program
 * @argc: count of arguments passed to the program
 * @argv: pointer to an array of char pointers to arguments
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int main(int argc, char **argv)
{
    char *token = NULL;
    size_t line_buf_size = MAX_LINE_SIZE;
    int line_number = 0, flag = 0, flag2 = 0;
    stack_t *stack = NULL;

    if (argc != 2)
        stderr_usage();
    globalvar.fd = fopen(argv[1], "r");
    if (globalvar.fd == NULL)
        stderr_fopen(argv[1]);
    
    globalvar.line_buf = malloc(line_buf_size);
    if (globalvar.line_buf == NULL)
        stderr_malloc();
    
    while (fgets(globalvar.line_buf, MAX_LINE_SIZE, globalvar.fd) != NULL)
    {
        line_number++;
        flag = 0;
        flag2 = 0;

        if (globalvar.line_buf[0] == '#')
            continue;
        
        token = strtok(globalvar.line_buf, DELIM);
        globalvar.token2 = strtok(NULL, DELIM);

        if (token == NULL)
        {
            flag2 = 1;
            nop(&stack, line_number);
        }

        if (flag2 == 0)
        {
            if (token[0] == '#')
                continue;
        }

        if (flag == 0)
            get_builtin(token, &stack, line_number);
    }

    free_dlistint(stack);
    free(globalvar.line_buf);
    globalvar.line_buf = NULL;
    fclose(globalvar.fd);
    return EXIT_SUCCESS;
}
