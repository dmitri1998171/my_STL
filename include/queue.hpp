#include "../include/header.hpp"

template <class T>
class my_queue {
    private:
        typedef struct queue_struct_t {
            T data;
            struct queue_struct_t *prev;
            struct queue_struct_t *next;
        }queue_t;

        typedef struct _header {
            size_t size;
            queue_t *head;
            queue_t *tail;
        } header;

        header *queue;

    public:
        my_queue() {
            queue = (header*) malloc(sizeof(header));
            queue->head = queue->tail = NULL;
            queue->size = 0;
        }

        void push(T value) {
            queue_t *tmp = (queue_t*) malloc(sizeof(queue_t));

            tmp->data = value;
            tmp->prev = queue->tail;
            tmp->next = NULL;

            if (queue->tail) 
                queue->tail->next = tmp;

            queue->tail = tmp;

            if (queue->head == NULL) 
                queue->head = tmp;

            queue->size++;
        }

        void pop() {
            queue_t *prev = NULL;
            T tmp = 0;
        
            prev = queue->head;
            queue->head = queue->head->next;

            if (queue->head) 
                queue->head->prev = NULL;

            if (prev == queue->tail) 
                queue->tail = NULL;
            
            tmp = prev->data;
            free(prev);
        
            queue->size--;
        }

        void print_queue() {
            if(queue) {
                queue_t *tmp = queue->head;

                while(tmp) {
                    LOG_NUM(LOG_INFO, tmp->data)

                    cout << tmp->data << " ";
                    tmp = tmp->next;
                }

                cout << endl;
            }
            else
                cout << "the queue is empty" << endl;
        }

        int size() {
            return queue->size;
        }

        queue_t* get_elem(int index) {
            queue_t *tmp = NULL;
            int i;
            index--;    // Отсчет от 1, а не от 0
            
            if (index < queue->size / 2) {
                i = 0;
                tmp = queue->head;
                while (tmp && i < index) {
                    tmp = tmp->next;
                    i++;
                }
            } 
            else {
                i = queue->size - 1;
                tmp = queue->tail;
                while (tmp && i > index) {
                    tmp = tmp->prev;
                    i--;
                }
            }
        
            return tmp;
        }

        queue_t* swap(queue_t *lst1, queue_t *lst2) {
            queue_t *head = queue->head;  // Возвращает новый корень списка

            queue_t *prev1 = lst1->prev;  // узел предшествующий lst1
            queue_t *prev2 = lst2->prev;  // узел предшествующий lst2
            queue_t *next1 = lst1->next;  // узел следующий за lst1
            queue_t *next2 = lst2->next;  // узел следующий за lst2

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
            if(!queue->size)
                return true;
            else
                return false;
        }

        T front() {
            return queue->head->data;
        }

        T back() {
            return queue->tail->data;
        }

        ~my_queue() {
            delete queue;
        }
};