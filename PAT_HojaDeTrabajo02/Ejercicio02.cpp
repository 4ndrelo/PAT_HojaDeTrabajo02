#include "Ejercicio02.h"

Node<int>* Ejercicio02::addTwoNumbers(Node<int>* l1, Node<int>* l2)
{
    Node<int>* dummy = new Node<int>();
    Node<int>* current = dummy;
    int carry = 0;

    while (l1 || l2 || carry) {
        int x = (l1) ? l1->value : 0;
        int y = (l2) ? l2->value : 0;

        int sum = x + y + carry;
        carry = sum / 10;
        int digit = sum % 10;

        current->next = new Node<int>();
        current = current->next;
        current->value = digit;

        if (l1) l1 = l1->next;
        if (l2) l2 = l2->next;
    }


    return dummy->next;
}
