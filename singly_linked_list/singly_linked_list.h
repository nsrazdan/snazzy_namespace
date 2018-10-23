// created by nsrazdan

#ifndef SINGLY_LINKED_LIST_H__
#define SINGLY_LINKED_LIST_H__

#include <memory>

namespace Snazzy {
    template <typename T>
    Class singly_linked_list<T> {
        Struct Node {
            T item;
            std::unique_ptr<Node> next;
        }
     public: 
        singly_linked_list();
        singly_linked_list(T first_item);
     private:
        std::unique_ptr<Node> head;
    };

    singly_linked_list<T>::singly_linked_list() {}

    singly_linked_list<T>::singly_linked_list(T first_item) {
        head = std::unique_ptr<T>(first_item);
    }
}

#ENDIF // SINGLY_LINKED_LIST_H__