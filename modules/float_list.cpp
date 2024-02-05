#include "float_list.h"
using namespace std;

unsigned int float_list::size()
{
    return this->length;
}

bool float_list::push(float data)
{
    Node *newNode = new Node();
    if (newNode == NULL)
        return false;
    newNode->data = data;
    newNode->next = NULL;

    if (length == 0)
    {
        newNode->prev = NULL;
        root = newNode;
        last = newNode;
    }
    else
    {
        newNode->prev = last;
        last->next = newNode;
        last = newNode;
    }

    length++;
    return true;
}

void float_list::clear()
{
    Node *current = root;
    Node *nextNode = nullptr;

    while (current != nullptr)
    {
        nextNode = current->next;
        delete current;
        current = nextNode;
    }

    root = nullptr;
    last = nullptr;
    length = 0;
}

float &float_list::operator[](int index)
{
    if (index < 0 || index >= this->length)
    {
        // Lanzamos excepcion de indice fuera de rango.
        throw std::out_of_range("Index out of bounds");
    }

    Node *current = root;
    for (int i = 0; i < index; ++i)
    {
        current = current->next;
    }

    return current->data;
}