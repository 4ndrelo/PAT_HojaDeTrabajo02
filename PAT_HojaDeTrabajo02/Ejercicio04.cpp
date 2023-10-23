#include "Ejercicio04.h"

FrontMiddleBackQueue::FrontMiddleBackQueue() : head(nullptr), size(0)
{


}




void FrontMiddleBackQueue::pushFront(int value) 
{
    Node* newNode = new Node(value);
    newNode->next = head;
    head = newNode;
    size++;

}

void FrontMiddleBackQueue::pushMiddle(int value) 
{
    if (size == 0) {
        pushFront(value);
    }
    else {
        int middleIndex = (size - 1) / 2;
        Node* curr = head;
        for (int i = 0; i < middleIndex; i++) {
            curr = curr->next;
        }
        Node* newNode = new Node(value);
        newNode->next = curr->next;
        curr->next = newNode;
        size++;
    }
    

}

void FrontMiddleBackQueue::pushBack(int value) 
{
    Node* newNode = new Node(value);
    if (size == 0) {
        head = newNode;
    }
    else {
        Node* curr = head;
        while (curr->next) {
            curr = curr->next;
        }
        curr->next = newNode;
    }
    size++;
}

int FrontMiddleBackQueue::popFront() 
{
    if (size == 0) {
        return -1; 
    }
    int value = head->data;
    Node* temp = head;
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
    if (size == 1) {
        int value = head->data;
        delete head;
        head = nullptr;
        size = 0;
        return value;
    }

    int middleIndex = (size - 1) / 2;
    Node* curr = head;
    for (int i = 0; i < middleIndex; i++) {
        curr = curr->next;
    }
    int value = curr->next->data;
    Node* temp = curr->next;
    curr->next = curr->next->next;
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
        int value = head->data;
        delete head;
        head = nullptr;
        size = 0;
        return value;
    }

    Node* curr = head;
    while (curr->next->next) {
        curr = curr->next;
    }
    int value = curr->next->data;
    delete curr->next;
    curr->next = nullptr;
    size--;
    return value;
}