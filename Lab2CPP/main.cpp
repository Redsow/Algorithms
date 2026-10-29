#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "stack.h"

using namespace std;

int get_number(Stack *stack)
{
    if (stack_empty(stack))
    {
        return 0;
    }

    int number = stack_get(stack);
    stack_pop(stack);

    return number;
}

void reverse_stack(Stack *&stack)
{
    Stack *temp = stack_create();

    while (!stack_empty(stack))
    {
        stack_push(temp, get_number(stack));
    }

    stack_delete(stack);
    stack = temp;
}

void print_stack(Stack *stack)
{
    bool first = true;

    while (!stack_empty(stack))
    {
        if (!first)
        {
            cout << " ";
        }

        cout << get_number(stack);

        first = false;
    }

    cout << endl;
}

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        return 1;
    }

    ifstream file(argv[1]);
    ifstream input(argv[2]);

    if (!file.is_open() || !input.is_open())
    {
        return 1;
    }

    string program = "";
    char c;

    while (file.get(c))
    {
        program += c;
    }

    Stack *stack1 = stack_create();
    Stack *stack2 = stack_create();

    Stack *current = stack1;

    int k = 0;

    vector<int> marks;

    for (int i = 0; i < (int)program.size(); i++)
    {
        if (program[i] == '*' || program[i] == 'f')
        {
            marks.push_back(i);
        }
    }

    for (int i = 0; i < (int)program.size(); i++)
    {
        char command = program[i];

        // Добавление единицы
        if (command == '1' || command == 'l')
        {
            stack_push(current, 1);
        }

        // Переключение между стеками
        else if (command == ';' || command == 'S')
        {
            if (current == stack1)
            {
                current = stack2;
            }
            else
            {
                current = stack1;
            }
        }

        // Сохранение числа в k
        else if (command == '^' || command == 'u')
        {
            k = get_number(current);
        }

        // Добавление k в стек
        else if (command == 'v' || command == 'd')
        {
            stack_push(current, k);
        }

        // Перестановка двух верхних элементов
        else if (command == '/' || command == 's')
        {
            int a = get_number(current);
            int b = get_number(current);

            stack_push(current, a);
            stack_push(current, b);
        }

        // Вычитание
        else if (command == '-' || command == 'm')
        {
            int a = get_number(current);
            int b = get_number(current);

            stack_push(current, b - a);
        }

        // Переворот стека
        else if (command == '%' || command == 'r')
        {
            if (current == stack1)
            {
                reverse_stack(stack1);
                current = stack1;
            }
            else
            {
                reverse_stack(stack2);
                current = stack2;
            }
        }

        // Чтение числа
        else if (command == '[' || command == 'i')
        {
            int number;

            if (input >> number)
            {
                stack_push(current, number);
            }
        }

        // Вывод числа
        else if (command == ']' || command == 'o')
        {
            cout << get_number(current);
        }

        // Чтение символа
        else if (command == '{' || command == 'I')
        {
            char symbol;

            if (input.get(symbol))
            {
                stack_push(current, (unsigned char)symbol);
            }
        }

        // Вывод символа
        else if (command == '}' || command == 'O')
        {
            int number = get_number(current);

            cout << (char)number;
        }

        // Переход по меткам
        else if (command == '>' || command == 'g')
        {
            int n = get_number(current);

            if (n > 0)
            {
                int count = 0;

                for (int j = 0; j < (int)marks.size(); j++)
                {
                    if (marks[j] > i)
                    {
                        count++;

                        if (count == n)
                        {
                            i = marks[j];
                            break;
                        }
                    }
                }
            }
            else if (n < 0)
            {
                int count = 0;

                for (int j = (int)marks.size() - 1; j >= 0; j--)
                {
                    if (marks[j] < i)
                    {
                        count++;

                        if (count == -n)
                        {
                            i = marks[j];
                            break;
                        }
                    }
                }
            }
        }
    }

    print_stack(stack1);
    print_stack(stack2);

    stack_delete(stack1);
    stack_delete(stack2);

    return 0;
}
