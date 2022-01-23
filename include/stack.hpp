#include "../include/header.hpp"

template <class T>
class my_stack {
    private:
        typedef struct stack_struct_t {
            T data;
            struct stack_struct_t *prev;
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
            tmp->prev = stack->tail;
            tmp->next = NULL;

            if (stack->tail) 
                stack->tail->next = tmp;

            stack->tail = tmp;

            if (stack->head == NULL) 
                stack->head = tmp;

            stack->size++;
        }

        void pop() {
            stack_t *next = NULL;
            T tmp = 0;
        
            next = stack->tail;
            stack->tail = stack->tail->prev;

            if (stack->tail) 
                stack->tail->next = NULL;

            if (next == stack->head) 
                stack->head = NULL;
            
            tmp = next->data;
            free(next);
        
            stack->size--;
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

        int size() {
            return stack->size;
        }

        stack_t* get_elem(int index) {
            stack_t *tmp = NULL;
            int i;
            index--;    // Отсчет от 1, а не от 0
            
            if (index < stack->size / 2) {
                i = 0;
                tmp = stack->head;
                while (tmp && i < index) {
                    tmp = tmp->next;
                    i++;
                }
            } 
            else {
                i = stack->size - 1;
                tmp = stack->tail;
                while (tmp && i > index) {
                    tmp = tmp->prev;
                    i--;
                }
            }
        
            return tmp;
        }

        stack_t* swap(stack_t *lst1, stack_t *lst2) {
            stack_t *head = stack->head;  // Возвращает новый корень списка

            stack_t *prev1 = lst1->prev;  // узел предшествующий lst1
            stack_t *prev2 = lst2->prev;  // узел предшествующий lst2
            stack_t *next1 = lst1->next;  // узел следующий за lst1
            stack_t *next2 = lst2->next;  // узел следующий за lst2

            if (lst2 == next1) {  // обмениваются соседние узлы
                lst2->next = lst1;
                lst2->prev = prev1;
                lst1->next = next2;
                lst1->prev = lst2;

                if(next2 != NULL)
                    next2->prev = lst1;
                
                if (lst1 != head)
                    prev1->next = lst2;
            }

            else if (lst1 == next2) { // обмениваются соседние узлы
                lst1->next = lst2;
                lst1->prev = prev2;
                lst2->next = next1;
                lst2->prev = lst1;
                if(next1 != NULL)
                next1->prev = lst2;
                if (lst2 != head)
                prev2->next = lst1;
            }

            else { // обмениваются отстоящие узлы
                if (lst1 != head)  // указатель prev можно установить только для элемента,
                    prev1->next = lst2; // не являющегося корневым
                
                lst2->next = next1;
                
                if (lst2 != head)
                    prev2->next = lst1;
                
                lst1->next = next2;
                lst2->prev = prev1;
                
                if (next2 != NULL) // указатель next можно установить только для элемента,
                    next2->prev = lst1; // не являющегося последним
                
                lst1->prev = prev2;
                
                if (next1 != NULL)
                    next1->prev = lst2;
            }

            if (lst1 == head)
                return(lst2);

            if (lst2 == head)
                return(lst1);

            return(head);
        }

        bool empty() {
            if(!stack->size)
                return true;
            else
                return false;
        }

        T top() {
            return stack->tail->data;
        }

        ~my_stack() {
            delete stack;
        }
};