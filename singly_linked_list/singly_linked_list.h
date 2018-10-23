// created by nsrazdan

#ifndef SINGLY_LINKED_LIST_H__
#define SINGLY_LINKED_LIST_H__

#include <memory>

namespace Snazzy {
    template <typename T>
    class singly_linked_list {
        struct Node {
            T item;
            std::unique_ptr<Node> next;
        };
     public: 
        singly_linked_list();
        singly_linked_list(T first_item);
     private:
        std::unique_ptr<Node> head;
    };

    template <typename T>
    singly_linked_list<T>::singly_linked_list() {}

    template <typename T>
    singly_linked_list<T>::singly_linked_list(T first_item) {
        head = std::unique_ptr<T>(first_item);
    }
}

#endif // SINGLY_LINKED_LIST_H__