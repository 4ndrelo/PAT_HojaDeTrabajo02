#include "Ejercicio04.h"

class FrontMiddleBackQueue
{
private:
    Node<int>* head;
    Node<int>* middle;
    int size;

public:
    FrontMiddleBackQueue()
    {
        head = nullptr;
        middle = nullptr;
        size = 0;
    }

    void pushFront(int value)
    {
        Node<int>* newNode = new Node<int>{ value, head };
        head = newNode;

        if (size == 0) {
            middle = head;
        }
        else if (size % 2 == 0) {
            middle = middle->next;
        }

        size++;
    }

    void pushMiddle(int value)
    {
        if (size == 0) {
            head = new Node<int>{ value, nullptr };
            middle = head;
        }
        else if (size % 2 == 0) {
            Node<int>* newNode = new Node<int>{ value, middle->next };
            middle->next = newNode;
            middle = newNode;
        }
        else {
            Node<int>* newNode = new Node<int>{ value, middle };
            middle = newNode;
        }

        size++;
    }

    void pushBack(int value)
    {
        if (size == 0) {
            head = new Node<int>{ value, nullptr };
            middle = head;
        }
        else {
            Node<int>* newNode = new Node<int>{ value, nullptr };
            Node<int>* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }

        size++;
    }

    int popFront()
    {
        if (size == 0) {
            return -1;
        }

        int value = head->value;
        Node<int>* temp = head;
        head = head->next;
        delete temp;

        if (size % 2 == 0) {
            middle = middle->next;
        }

        size--;

        return value;
    }

    int popMiddle()
    {
        if (size == 0) {
            return -1;
        }

        int value = middle->value;
        if (size == 1) {
            delete head;
            head = nullptr;
            middle = nullptr;
        }
        else {
            Node<int>* current = head;
            while (current->next != middle) {
                current = current->next;
            }
            current->next = middle->next;
            delete middle;
            middle = current;
        }

        size--;

        return value;
    }

    int popBack()
    {
        if (size == 0) {
            return -1;
        }

        int value;
        if (size == 1) {
            value = head->value;
            delete head;
            head = nullptr;
            middle = nullptr;
        }
        else {
            Node<int>* current = head;
            while (current->next->next != nullptr) {
                current = current->next;
            }
            value = current->next->value;
            delete current->next;
            current->next = nullptr;
        }

        size--;

        return value;
    }
};