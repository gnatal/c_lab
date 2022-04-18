#include "dataStructure.h"
#include <stdlib.h>

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

int main()
{
    Data *list = NULL;
    list = insert(4, "one", 1.1, list);
    list = insert(1, "one", 1.1, list);
    list = insert(8, "two", 2.2, list);
    list = insert(12, "two", 2.2, list);
    list = insert(5, "two", 2.2, list);
    return 0;
}