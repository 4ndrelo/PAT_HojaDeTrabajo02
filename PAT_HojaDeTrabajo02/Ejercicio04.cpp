#include "Ejercicio04.h"
FrontMiddleBackQueue::FrontMiddleBackQueue()
{
    head = nullptr;
    size = 0;
}

void FrontMiddleBackQueue::pushFront(int value)
{
    Node<int>* newNode = new Node<int>{ value, head };
    head = newNode;
    size++;
}

void FrontMiddleBackQueue::pushMiddle(int value)
{
    if (size == 0) {
        pushFront(value);
    }
    else {
        int mid = (size - 1) / 2;
        Node<int>* current = head;
        for (int i = 0; i < mid; i++) {
            current = current->next;
        }
        Node<int>* newNode = new Node<int>{ value, current->next };
        current->next = newNode;
        size++;
    }
}

void FrontMiddleBackQueue::pushBack(int value)
{
    Node<int>* newNode = new Node<int>{ value, nullptr };
    if (size == 0) {
        head = newNode;
    }
    else {
        Node<int>* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }
    size++;
}

int FrontMiddleBackQueue::popFront()
{
    if (size == 0) {
        return -1;
    }
    int value = head->value;
    Node<int>* temp = head;
    head = head->next;
    delete temp;
    size--;
    return value;
}

int FrontMiddleBackQueue::popMiddle()
{
    if (size == 0) {
        return -1;
    }
    int mid = (size - 1) / 2;
    Node<int>* current = head;
    for (int i = 0; i < mid; i++) {
        current = current->next;
    }
    int value = current->next->value;
    Node<int>* temp = current->next;
    current->next = current->next->next;
    delete temp;
    size--;
    return value;
}

int FrontMiddleBackQueue::popBack()
{
    if (size == 0) {
        return -1;
    }
    if (size == 1) {
        int value = head->value;
        delete head;
        head = nullptr;
        size--;
        return value;
    }
    Node<int>* current = head;
    while (current->next->next != nullptr) {
        current = current->next;
    }
    int value = current->next->value;
    delete current->next;
    current->next = nullptr;
    size--;
    return value;
}
    