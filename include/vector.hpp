#include "../include/header.hpp"

template <class T>
class my_vector {
    private:
        T *vector;

    public:
        int Size;       // current Size
        int capacity;   // max_size

    // Member functions

        my_vector() {
            capacity = Size = 1;
            vector = new T[Size];
        }

        my_vector(int n, T value) {
            capacity = Size = n;
            vector = new T[Size];

            for (int i = 0; i < Size; i++)
                vector[i] = value;
        }

        ~my_vector() {
            delete[] vector;
        }

        // T operator=() {

        // }

    // Iterators

        T begin() {

        }

        T end() {

        }

    // Capacity

        int size() {
            return this->Size;
        }

        int max_size() {
            return this->capacity;
        }

        void resize(int n, int value) {
            T *tmp = new T[n];

            for (int i = 0; i < n; i++)
                tmp[i] = vector[i];

            delete[] vector;

            vector = tmp;

            if(n > Size) {
                for (int i = 0; i < Size; i++)
                    vector[i] = value;
            }

            capacity = Size = n;
        }

        bool empty() {
            if(!this->Size)
                return true;
            else
                return false;
        }

    // Element access

        // T operator[]() {

        // }

        T at() {

        }

        T front() {

        }

        T back() {

        }

    // Modifiers

        void push_back() {

        }

        void pop_back() {

        }

        void insert() {

        }

        void erase() {

        }

        void swap() {

        }

        void clear() {

        }
};