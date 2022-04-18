#include "dataStructure.h"
#include "linkedList.h"
#include <stdlib.h>

int main()
{
    Data *list = NULL;
    list = insert(4, "one", 1.1, list);
    list = insert(1, "one", 1.1, list);
    list = insert(8, "two", 2.2, list);
    list = insert(12, "two", 2.2, list);
    list = insert(5, "two", 2.2, list);
    list = remove(list, 13);
    // list = remove(list, 4);
    // list = remove(list, 8);
    // list = remove(list, 12);
    // list = remove(list, 5);
    return 0;
}