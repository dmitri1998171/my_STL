#include "../include/header.hpp"

template<class T, int value>
class my_array {
    private:
        T arr[value];

    public:
        T& operator[] (const int index) {
            return arr[index];
        }

        T at(int index) {
            return arr[index];
        }

        T front() {
            return arr[0];
        }

        T back() {
            return arr[value - 1];
        }

        T data() {
            return *arr;
        }

        void fill(T val) {
            for (int i = 0; i < value; i++)
                arr[i] = val;
        }

        int size() {
            return value;
        }
        
        int max_size() {
            return value;
        }

        bool empty() {
            if(!value)
                return true;
            else    
                return false;
        }

        void print_arr() {
            for (int i = 0; i < value; i++)
                cout << arr[i] << " ";
        }
};