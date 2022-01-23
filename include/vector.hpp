#include "../include/header.hpp"

template <class T>
class my_vector {
    private:
        T *vector;
        int size;

    public:
    // Member functions

        my_vector() {
            size = 2;
            vector = new vector[size];
        }

        my_vector(int n, T value) {
            size = n;
            vector = new vector[size];

            for (int i = 0; i < size; i++)
                vector[i] = value;
        }

        ~my_vector() {
            delete[] vector;
        }

        T operator=() {

        }

    // Iterators

        T begin() {

        }

        T end() {

        }

    // Capacity

        int size() {

        }

        int max_size() {

        }

        void resize() {

        }

        bool empty() {

        }

    // Element access

        T operator[]() {

        }

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