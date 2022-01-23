#include "../include/header.hpp"

#define OFFSET 5

template <class T>
class my_vector {
    private:
        T *vector;

    public:
        int Size;       // current Size
        int capacity;   // max_size

    // Member functions

        my_vector() {
            capacity = Size = 0;
            vector = new T[capacity];
        }

        my_vector(int n, T value) {
            capacity = Size = n;
            vector = new T[capacity];

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

        void resize(int n) {
            T *tmp = new T[n];

            for (int i = 0; i < n; i++)
                tmp[i] = vector[i];

            delete[] vector;
            vector = tmp;
            Size = n;
            capacity = Size + OFFSET;
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

        T at(int index) {
            return vector[index];
        }

        T front() {
            return vector[0];
        }

        T back() {
            return vector[this->Size];
        }

    // Modifiers

        void push_back(T value) {
            vector[Size] = value;
            this->Size++;

            if(this->Size > this->capacity)
                resize(this->Size);
        }

        void pop_back() {

        }

        void insert() {

        }

        void erase() {

        }

        void swap() {

        }

        void print_vector() {
            for (int i = 0; i < this->Size; i++)
                cout << vector[i] << " ";
        }

        void clear() {

        }
};