#include <cstddef>
#include "list.h"

struct ListItem
{
	Data data;
	ListItem *next;
	ListItem *prev;
};

struct List
{
	ListItem *first;
	ListItem *last;
};

List *list_create()
{	
	List *list = new List;
	list -> first = NULL;
	list ->last = NULL;
	return list;
    
}

void list_delete(List *list)
{
    if (list == NULL)
        return;
    ListItem *current = list->first;

    while (current != NULL)
    {
        ListItem *next = current->next;
        delete current;
        current = next;
    }

    delete list;
}

ListItem *list_first(List *list)
{
    return list ->first;
}

ListItem *list_last(List *list)
{
    return list ->last;
}

Data list_item_data(const ListItem *item)
{
    return item -> data;
}

ListItem *list_item_next(ListItem *item)
{
    return item->next;
}

ListItem *list_item_prev(ListItem *item)
{
    return item->prev;
}

ListItem *list_insert(List *list, Data data)
{
    ListItem *item = new ListItem;
    item->data = data;
    item->prev = NULL;
    item->next = list->first;

    if (list->first != NULL)
    {
        list->first->prev = item;
    }
    else
    {
        list->last = item;
    }

    list->first = item;

    return item;
}

ListItem *list_insert_after(List *list, ListItem *item, Data data)
{
    if (item == NULL)
    {
        return list_insert(list, data);
    }
    ListItem *newItem = new ListItem;
    newItem->data = data;
    newItem->prev = item;
    newItem->next = item->next;

    if (item->next != NULL)
    {
        item->next->prev = newItem;
    }
    else
    {
        list->last = newItem;
    }
    item->next = newItem;
    return newItem;
}

ListItem *list_erase_first(List *list)
{
    if (list->first == NULL)
    {
        return NULL;
    }
    ListItem *item = list->first;
    list->first = item->next;
    if (list->first != NULL)
    {
        list->first->prev = NULL;
    }
    else
    {
        list->last = NULL;
    }
    delete item;
    return list->first;
}

ListItem *list_erase_next(List *list, ListItem *item)
{
    if (item == NULL)
    {
        return list_erase_first(list);
    }

    if (item->next == NULL)
    {
        return NULL;
    }
    ListItem *deleted = item->next;
    item->next = deleted->next;
    if (deleted->next != NULL)
    {
        deleted->next->prev = item;
    }
    else
    {
        list->last = item;
    }
    ListItem *next = deleted->next;
    delete deleted;
    return next;
}
