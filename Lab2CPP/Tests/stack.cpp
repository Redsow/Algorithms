#include <cassert>
#include "../../LibraryCPP/stack.h"

int main()
{
    Stack *stack = stack_create();
    assert(stack_empty(stack));

    stack_push(stack, 10);
    stack_push(stack, 20);
    stack_push(stack, 30);

    assert(!stack_empty(stack));

    assert(stack_get(stack) == 30);
    stack_pop(stack);

    assert(stack_get(stack) == 20);

    stack_pop(stack);

    assert(stack_get(stack) == 10);
    stack_pop(stack);

    assert(stack_empty(stack));

    stack_push(stack, 50);

    assert(stack_get(stack) == 50);

    stack_delete(stack);

    return 0;
}
