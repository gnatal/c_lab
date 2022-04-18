#include "dataStructure.h"
#include <stdlib.h>

/*Insert sorted*/
Data *insert(int integer, char *text, double numeric, Data *list)
{
    Data *data = (Data *)malloc(sizeof(Data));
    data->integer = integer;
    data->text = text;
    data->numeric = numeric;
    data->pointer = NULL;
    int found = 0;
    if (list == NULL)
    {
        list = data;
        return list;
    }
    Data *temp = list;
    Data *last = NULL;
    while (found == 0 && temp != NULL)
    {
        if (temp->integer > integer)
        {
            found = 1;
            data->pointer = temp;
            if (last != NULL)
            {
                last->pointer = data;
            }
            else
            {
                list = data;
            }
        }
        else
        {
            if (temp->pointer == NULL)
            {
                temp->pointer = data;
                found = 1;
            }
            last = temp;
            temp = temp->pointer;
        }
    }
    return list;
}

Data *remove(Data *list, int integer)
{
    Data *temp = list;
    Data *last = NULL;
    while (temp != NULL)
    {
        if (temp->integer == integer)
        {
            if (last != NULL)
            {
                last->pointer = temp->pointer;
                free(temp);
                temp = NULL;
                return list;
            }
            else
            {
                Data *removed = list;
                list = temp->pointer;
                free(removed);
                removed = NULL;
                return list;
            }
        }
        last = temp;
        temp = temp->pointer;
    }
    return list;
}