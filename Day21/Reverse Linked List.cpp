#include <bits/stdc++.h>

/****************************************************************

    Following is the class structure of the LinkedListNode class:

    template <typename T>
    class LinkedListNode
    {
    public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*****************************************************************/

template <typename T>
LinkedListNode<T> *reverseLinkedList(LinkedListNode<T> *head) {
    LinkedListNode<T> *prev = nullptr;
    LinkedListNode<T> *current = head;
    LinkedListNode<T> *next = nullptr;

    while (current != nullptr) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    return prev; // new head of the reversed list
}
