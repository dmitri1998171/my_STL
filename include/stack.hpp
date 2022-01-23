#include "../include/header.hpp"

template <class T>
class my_stack {
    private:
        typedef struct stack_struct_t {
            T data;
            struct stack_struct_t *next;
        }stack_t;

        typedef struct _header {
            size_t size;
            stack_t *head;
            stack_t *tail;
        } header;

        header *stack;

    public:
        my_stack() {
            stack = (header*) malloc(sizeof(header));
            stack->head = stack->tail = NULL;
            stack->size = 0;
        }

        void push(T value) {
            stack_t *tmp = (stack_t*) malloc(sizeof(stack_t));

            tmp->data = value;
            tmp->next = NULL;

            if (stack->tail) 
                stack->tail->next = tmp;

            stack->tail = tmp;

            if (stack->head == NULL) 
                stack->head = tmp;

            stack->size++;
        }

        void print_stack() {
            if(stack) {
                stack_t *tmp = stack->head;

                while(tmp) {
                    LOG_NUM(LOG_INFO, tmp->data)

                    cout << tmp->data << " ";
                    tmp = tmp->next;
                }

                cout << endl;
            }
            else
                cout << "the stack is empty" << endl;
        }

        ~my_stack() {
            delete stack;
        }
};