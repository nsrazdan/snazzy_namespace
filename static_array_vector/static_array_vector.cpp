// created by nsrazdan

template <typename T>
namespace Snazzy {
    class static_array_vector {
     public:
        static_array_vector() {}
     private:
        T[1000] vec;
    };
}

int main() {
    
    Snazzy::static_array_vector<int> test;
    return 0;
}