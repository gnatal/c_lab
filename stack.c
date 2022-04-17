#include "dataStructure.h"
#include <stdlib.h>
#include <stdio.h>

Data *push(Data *stack)
{
    Data *top = malloc(sizeof(Data));
    top->numeric = 0;
    top->integer = 0;
    top->text = "";
    top->pointer = NULL;

    if (stack == NULL)
    {
        stack = top;
        return stack;
    }
    top->pointer = stack;
    return top;
}

Data *pop(Data **stack)
{
    Data *top = *stack;
    *stack = (*stack)->pointer;
    return top;
}

Data *init()
{
    Data *stack = NULL;
    return stack;
}

void show(Data *stack)
{
    Data *current = stack;
    while (current != NULL)
    {
        printf("%d integer %.2f numeric %s char\n", current->integer, current->numeric, current->text);
        current = current->pointer;
    }
}

Data *empty(Data *stack)
{
    Data *current = stack;
    while (current != NULL)
    {
        Data *temp = current;
        current = current->pointer;
        free(temp);
        temp = NULL;
    }
    return NULL;
}

int main()
{
    Data *stack = init();
    stack = push(stack);
    stack = push(stack);
    stack = push(stack);
    show(stack);
    stack = empty(stack);
    show(stack);
    return 0;
}