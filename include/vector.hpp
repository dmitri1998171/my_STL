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
            this->capacity = this->Size = 0;
            vector = new T[this->capacity];
        }

        my_vector(int n, T value) {
            this->capacity = this->Size = n;
            vector = new T[this->capacity];

            for (int i = 0; i < this->Size; i++)
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
            return vector[this->Size - 1];
        }

    // Modifiers

        void push_back(T value) {
            vector[this->Size] = value;
            this->Size++;

            if(this->Size > this->capacity) {
                this->capacity = this->Size + OFFSET;
                resize(this->capacity);
            }
        }

        void pop_back() {
            vector[this->Size] = 0;
            this->Size--;
        }

        void insert(int pos, T value) {
            this->Size++;
            T *tmp = new T[this->Size];

            // Copy vector
            for (int j = 0; j < this->Size; j++)
                tmp[j] = vector[j];

            delete[] vector;
            vector = new T[this->capacity];

            //  Resize vector
            if(this->Size > this->capacity) {
                this->capacity = this->Size + OFFSET;
                resize(this->capacity);
            }

            // Fill vector from copy
            for (int j = 0; j < pos; j++) 
                vector[j] = tmp[j];

            vector[pos] = value;

            for (int j = pos + 1; j < this->Size; j++) 
                vector[j] = tmp[j - 1];
        }

        // void insert(iterator pos, T value) {
        //     T *tmp = new T[n];

        // }

        void erase(int pos) {
            T *tmp = new T[this->Size];

            // Copy vector
            for (int j = 0; j < pos; j++) 
                tmp[j] = vector[j];

            for (int j = pos + 1; j < this->Size; j++) 
                tmp[j - 1] = vector[j];

            delete[] vector;
            vector = new T[this->capacity];

            this->Size--;

            // Fill vector from copy
            for (int j = 0; j < this->Size; j++) {
                vector[j] = tmp[j];
            }
        }

        void print_vector() {
            for (int i = 0; i < this->Size; i++)
                cout << vector[i] << " ";
        }

        void clear() {
            delete[] vector;
            vector = new T[0];
            this->capacity = this->Size = 0;
        }
};