#include "Ejercicio01.h"

Node<char>* Ejercicio01::rotateRight(Node<char>* head, int k)
{
    if (!head || k == 0) {
        return head;
    }

    int length = 0;
    Node<char>* current = head;
    while (current->next) {
        length++;
        current = current->next;
    }
    length++;


    k = k % length;
    if (k == 0) {
        return head;
    }

    int newHeadPos = length - k;
    current->next = head;
    current = head;
    for (int i = 0; i < newHeadPos - 1; i++) {
        current = current->next;
    }


    Node<char>* newHead = current->next;
    current->next = nullptr;
    return newHead;
}
