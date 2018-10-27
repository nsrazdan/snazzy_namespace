// created by nsrazdan

#include <memory>

namespace Snazzy {
    template <typename T>
    class dynamic_array_vector {
     public:
        // default constructor
        dynamic_array_vector();
        // insert element at given pos
        void insert(const T& insert, const unsigned int& pos);
        // remove element at given pos
        void remove(const unsigned int& pos);
        // get element at given pos
        T& get(const unsigned int& pos);
        // return cur_size
        unsigned int cur_size();
        // return if list is empty
        bool isEmpty();
        // return if list is full
        bool isFull();
        // swaps elements at two positions
        void swap(const unsigned int& pos_1, const unsigned int& pos_2);
        // find element that matches given value
        unsigned int find(const T& search);
     private:
        unsigned int capacity;
        unsigned int cur_size;
        std::unique_ptr<T*> arr;
    };
    
    
    // default constructor
    template <typename T>
    static_array_vector<T>::static_array_vector() : arr(new T[10]),
                                                    capacity(10),
                                                    cur_size(0) {}
    
    // insert element at given pos
    template <typename T>
    void static_array_vector<T>::insert
        (const T& insert, const unsigned int& pos) {
        if (!isValid(pos)) {
            throw std::underflow_error("Position is invalid!");
        } else if (isFull()) {
            throw std::overflow_error("Array is full!");
        }
        for (unsigned int i = cur_size - 1; i >= pos; i--) {
            arr[i + 1] = arr[i];
        }
        arr[i] = insert;
        cur_size++;
    }
    
    // remove element at given pos
    template <typename T>
    void static_array_vector<T>::remove(const unsigned int& pos) {
        if (!isValid(pos)) {
            throw std::underflow_error("Position is invalid!");
        }
        arr[pos] = arr[size - 1];
        arr[size - 1] = NULL;
        cur_size--;
    }
    
    // get element at given pos
    template <typename T>
    T& static_array_vector<T>::get(const unsigned int& pos) {
        if (!isValid(pos)) {
            throw std::underflow_error("Position is invalid!");
        }
        return arr[pos];
    }
    
    // return cur_size
    template <typename T>
    unsigned int static_array_vector<T>::size() {
        return cur_size;
    }
    
    // return if list is empty
    template <typename T>
    bool static_array_vector<T>::isEmpty() {
        return (cur_size == 0);
    }
    
    // return if the vector is full
    template <typename T>
    bool static_array_vector<T>::isFull() {
        return (cur_size == cur_size);
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
        for (unsigned int i = 0; i < cur_size; i++) {
            if (arr[i] == search) {
                return i;
            }
        }
        
        std::cerr << "No match found" << std::end;
    }
    
    // return if the given pos is valid
    template <typename T>
    void static_array_vector<T>::isValid(unsigned int pos) {
        return (capacity > pos);
    }
}