// created by nsrazdan

#ifndef SINGLY_LINKED_LIST_H__
#define SINGLY_LINKED_LIST_H__

#include <memory>
#include <iostream>

namespace Snazzy {
    
    template <typename U>
    class Node {
     public:
        Node();
        Node(const U& item);
     private:
        U item;
        std::unique_ptr<Node<U>> next;
    };

    template <typename T>
    class singly_linked_list {
     public: 
        singly_linked_list();
        template <typename U>
        singly_linked_list(const U& first_item);
     private:
        template <typename U>
        std::unique_ptr<Node<U>> head = nullptr;
        unsigned int size = 0;
    };

    template <typename U>
    Node<U>::Node() {}
    
    template <typename U>
    Node<U>::Node(const U& item) : item(item) {}
    
    template <typename T>
    singly_linked_list<T>::singly_linked_list() {}

    template <typename T>
    template <typename U>
    singly_linked_list<T>::singly_linked_list(const U& first_item) {
        std::unique_ptr<Node<U>> n(new Node<U>(first_item));
        head = std::make_unique<Node<U>>(std::move(n));
        size++;
    }
    
}

#endif // SINGLY_LINKED_LIST_H__