#include "dataStructure.h"
#include <stdlib.h>
#include <stdio.h>

Data *push(Data *queue)
{
    Data *newest = malloc(sizeof(Data));
    newest->numeric = 0;
    newest->integer = 0;
    newest->text = "";
    newest->pointer = NULL;
    if (queue == NULL)
    {
        queue = newest;
        return queue;
    }
    Data *init = queue;
    while (queue->pointer != NULL)
    {
        queue = queue->pointer;
    }

    queue->pointer = newest;
    return init;
}

Data *pop(Data **queue)
{
    Data *top = *queue;
    *queue = (*queue)->pointer;
    return top;
}

void show(Data *queue)
{
    Data *current = queue;
    while (current != NULL)
    {
        printf("%d integer %.2f numeric %s char\n", current->integer, current->numeric, current->text);
        current = current->pointer;
    }
}

int main()
{
    Data *queue = NULL;
    queue = push(queue);
    queue = push(queue);
    queue = push(queue);
    show(queue);
    pop(&queue);
    pop(&queue);
    pop(&queue);
    show(queue);
    return 0;
}