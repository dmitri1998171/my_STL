#include "../include/header.hpp"

#define OFFSET 5

class my_string {
    private:
        char* str;
        int size;
        int capacity;

    public:
// Member functions

        my_string() {
            str = nullptr;
            capacity = OFFSET;
            size = 0;
        }

        ~my_string() {
            str = nullptr;
        }

        // char operator= () {}
        // char operator+ () {}
        // char operator== () {}
        // char operator<< () {}
        // char operator>> () {}

// Element access

        char* front() {
            return str;
        }

        char* back() {
            return str + (size * sizeof(char));
        }

        char* data() {

        }

        void find() {

        }

// Capacity

        int size() {
            return this->size;
        }

        int max_size() {
            return this->capacity;
        }

        bool empty() {
            if(!this->size)
                return true;
            else
                return false;
        }

        void reserve() {

        }

        void shrink_to_fit() {

        }
// Operations

        void push_front(char* value) {
            
        }

        void push_back(char* value) {
            
        }

        void print_list() {
            
        }

        void pop_back() {
            
        }

        void append() {

        }

        void compare() {

        }

        void replace() {

        }

        void substr() {

        }

        void copy() {

        }

        void resize() {

        }

        void insert(int index, char* value) {
            
        }

        void erase(char* value) {
            
        }

        void resize(int size, char* value) {
        
        }

        void clear() {
            
        }
};

