// created by nsrazdan

#include <iostream>
#include <string>

namespace Snazzy {
    template <typename T>
    class static_array_vector {
     public:
        // default constructor
        static_array_vector();
        // insert element at given pos
        void insert(const T& insert, const unsigned int& pos);
        // remove element at given pos
        void remove(const unsigned int& pos);
        // get element at given pos
        T& get(const unsigned int& pos);
        // return size
        unsigned int size();
        // return if list is empty
        bool isEmpty();
        // return if list is full
        bool isFull();
        // swaps elements at two positions
        void swap(const unsigned int& pos_1, const unsigned int& pos_2);
        // find element that matches given value
        unsigned int find(const T& search);
     private:
        bool checkInvalid(unsigned int pos);
        unsigned int size;
        T[1000] arr;
    };

    // default constructor
    template <typename T>
    static_array_vector<T>::static_array_vector() : size(0) {}
    
    // insert element at given pos
    template <typename T>
    void static_array_vector<T>::insert
        (const T& insert, const unsigned int& pos) {
        if (!isValid(pos)) {
            throw std::underflow_error("Position is invalid!");
        } else if (isFull()) {
            throw std::overflow_error("Array is full!");
        }
        for (unsigned int i = size - 1; i >= pos; i--) {
            arr[i + 1] = arr[i];
        }
        arr[i] = insert;
        size++;
    }
    
    // remove element at given pos
    template <typename T>
    void static_array_vector<T>::remove(const unsigned int& pos) {
        if (!isValid(pos)) {
            throw std::underflow_error("Position is invalid!");
        }
        arr[pos] = arr[size - 1];
        arr[size - 1] = NULL;
        size--;
    }
    
    // get element at given pos
    template <typename T>
    T& static_array_vector<T>::get(const unsigned int& pos) {
        if (!isValid(pos)) {
            throw std::underflow_error("Position is invalid!");
        }
        return arr[pos];
    }
    
    // return size
    template <typename T>
    unsigned int static_array_vector<T>::size() {
        return size;
    }
    
    // return if list is empty
    template <typename T>
    bool static_array_vector<T>::isEmpty() {
        return (size == 0);
    }
    
    // return if the vector is full
    template <typename T>
    bool static_array_vector<T>::isFull() {
        return (size == 1000);
    }
    
    // swap elements at two given positions
    template <typename T>
    void static_array_vector<T>::swap
        (const unsigned int& pos_1, const unsigned int& pos_2) {
        // FIXME: print relevant error for both different position accesses
        if (!isValid(pos_1)) {
            std::string err_string = "Position" + pos_1 + "is invalid.";
            throw std::underflow_error(err_string);
        } else if (!isValid(pos_2)) {
            std::string err_string = "Position" + pos_2 + "is invalid.";
            throw std::underflow_error(err_string);
        }
        
        T temp = arr[pos_1];
        arr[pos_1] = arr[pos_2];
        arr[pos_2] = temp;
    }
    
    // find element that matches given value
    template <typename T>
    unsigned int static_array_vector<T>::find(const T& search) {
        for (unsigned int i = 0; i < size; i++) {
            if (arr[i] == search) {
                return i;
            }
        }
        
        std::cerr << "No match found" << std::end;
    }
    
    // return if the given pos is valid
    template <typename T>
    void static_array_vector<T>::isValid(unsigned int pos) {
        return (size > pos);
    }
}

int main() {
    
    Snazzy::static_array_vector<int> test;
    return 0;
}