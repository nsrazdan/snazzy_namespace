// created by nsrazdan

#include <iostream>
#include "singly_linked_list.h"

int main() {
    Snazzy::singly_linked_list<int> list(8);
    std::cout << "Hello World!" << std::endl;
    list.print_list();
    return 0;
}