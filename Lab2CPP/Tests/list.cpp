#include <cassert>
#include "../../LibraryCPP/list.h"

int main()
{
    List *list = list_create();
    assert(list_first(list) == nullptr);
    assert(list_last(list) == nullptr);

    list_insert(list, 10);
    list_insert(list, 20);
    list_insert(list, 30);
    assert(list_item_data(list_first(list)) == 30);
    assert(list_item_data(list_last(list)) == 10);

    ListItem *first = list_first(list);
    ListItem *second = list_item_next(first);

    assert(list_item_data(second) == 20);

    assert(list_item_prev(second) == first);

    list_insert_after(list, second, 15);

    assert(list_item_data(list_item_next(second)) == 15);

    list_erase_first(list);

    assert(list_item_data(list_first(list)) == 20);

    list_erase_next(list, list_first(list));

    assert(list_item_data(list_last(list)) == 10);

    list_delete(list);

    return 0;
}
