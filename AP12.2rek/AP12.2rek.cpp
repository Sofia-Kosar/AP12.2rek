#include <iostream>
#include <windows.h>

using namespace std;

typedef int Info;
struct Elem
{
    Elem* link;
    Info  info;
};

void Input(Elem*& first, Elem*& last, Info value)
{
    if (first == NULL)
    {
        first = new Elem;
        first->info = value;
        first->link = NULL;
        last = first;
    }
    else
    {
        Input(first->link, last, value);
    }
}

void DeleteAfter(Elem*& first, Info value)
{
    if (first == NULL || first->link == NULL) return;

    if (first->info == value)
    {
        Elem* tmp = first->link;
        first->link = tmp->link;
        delete tmp;
        DeleteAfter(first, value); 
    }
    else
    {
        DeleteAfter(first->link, value);
    }
}


void InputValues(Elem*& first, Elem*& last, int i, int n)
{
    if (i > n) return;
    int value;
    cout << "¬вед≥ть значенн€ " << i << "-го елемента: ";
    cin >> value;
    Input(first, last, value);
    InputValues(first, last, i + 1, n);
}
void PrintList(Elem*& first)
{
    if (first == NULL) return;
    cout << first->info << " ";
    PrintList(first->link);
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Elem* first = NULL,
        * last = NULL;
    int n;
    cout << "¬вед≥ть к≥льк≥сть елемент≥в: ";
    cin >> n;
    InputValues(first, last, 1, n);

    int value;
    cout << "¬вед≥ть значенн€, п≥сл€ €кого будуть видален≥ елементи: ";
    cin >> value;

    DeleteAfter(first, value);

    PrintList(first);

    return 0;
}
