#include "../include/header.hpp"

template <class T>
class my_deque {
    private:
        typedef struct deque_struct_t {
            T data;
            struct deque_struct_t *prev;
            struct deque_struct_t *next;
        }deque_t;
        
        typedef struct _header {
            size_t size;
            deque_t *head;
            deque_t *tail;
        } header;

        header *deque;

    public:
        my_deque() {
            deque = (header*) malloc(sizeof(header));
            deque->size = 0;
            deque->head = deque->tail = NULL;
        }

        deque_t* get_elem(int index) {
            deque_t *tmp = NULL;
            int i;
            index--;    // Отсчет от 1, а не от 0
            
            if (index < deque->size / 2) {
                i = 0;
                tmp = deque->head;
                while (tmp && i < index) {
                    tmp = tmp->next;
                    i++;
                }
            } 
            else {
                i = deque->size - 1;
                tmp = deque->tail;
                while (tmp && i > index) {
                    tmp = tmp->prev;
                    i--;
                }
            }
        
            return tmp;
        }

        int searchByValue(T value){
            if(!deque) {
                LOG_CHAR(LOG_ERROR, "searchByValue() return -1")
                return -1;
            }

            int pos = 1;
            deque_t *tmp = deque->head;

            while(tmp) {
                if(value == tmp->data)
                    return pos;
                
                tmp = tmp->next;
                pos++;
            }

            LOG_CHAR(LOG_ERROR, "searchByValue() return -2")
            return -2;
        }

        T searchByPos(int pos){
            if(!deque) {
                LOG_CHAR(LOG_ERROR, "searchByPos() return -1")
                return -1;
            }

            deque_t *tmp = deque->head;

            for(int i = 1; i < pos; i++) 
                tmp = tmp->next;

            return tmp->data;
        }

        void push_front(T value) {
            deque_t *tmp = (deque_t*) malloc(sizeof(deque_t));

            tmp->data = value;
            tmp->prev = NULL;
            tmp->next = deque->head;

            if (deque->head) 
                deque->head->prev = tmp;

            deque->head = tmp;
        
            if (deque->tail == NULL) 
                deque->tail = tmp;
            
            deque->size++;
        }

        void push_back(T value) {
            deque_t *tmp = (deque_t*) malloc(sizeof(deque_t));

            tmp->data = value;
            tmp->prev = deque->tail;
            tmp->next = NULL;

            if (deque->tail) 
                deque->tail->next = tmp;
            
            deque->tail = tmp;
        
            if (deque->head == NULL) 
                deque->head = tmp;
            
            deque->size++;
        }

        void print_deque() {
            if(deque) {
                deque_t *tmp = deque->head;

                while (tmp) {
                    cout << tmp->data << " ";
                    tmp = tmp->next;
                }

                cout << endl;
            }
            else
                cout << "the deque is empty" << endl;
        }

        void pop_back() {
            deque_t *next = NULL;
            T tmp = 0;
        
            next = deque->tail;
            deque->tail = deque->tail->prev;

            if (deque->tail) 
                deque->tail->next = NULL;

            if (next == deque->head) 
                deque->head = NULL;
            
            tmp = next->data;
            free(next);
        
            deque->size--;
        }

        void pop_front() {
            deque_t *prev = NULL;
            T tmp = 0;
        
            prev = deque->head;
            deque->head = deque->head->next;
            if (deque->head) 
                deque->head->prev = NULL;
            
            if (prev == deque->tail) 
                deque->tail = NULL;
            
            tmp = prev->data;
            free(prev);
        
            deque->size--;
        }

        void insert(int index, T value) {
            deque_t *ins = (deque_t*) malloc(sizeof(deque_t));
            deque_t *elm = get_elem(index);

            if (elm) {
                ins->data = value;
                ins->prev = elm;
                ins->next = elm->next;
                
                if (elm->next) 
                    elm->next->prev = ins;
                
                elm->next = ins;
            
                if (!elm->prev) 
                    deque->head = elm;
                
                if (!elm->next) 
                    deque->tail = elm;
            
                deque->size++;
            }
            else {
                LOG_CHAR(LOG_ERROR, "can't insert element")
            }
        }

        void erase(T value) {
            deque_t *current_item = deque->head;

            while (current_item) {
                deque_t *tmp = current_item;
                current_item = current_item->next;

                if(value == tmp->data) {
                    if (tmp->prev) 
                        tmp->prev->next = tmp->next;
                    
                    if (tmp->next) 
                        tmp->next->prev = tmp->prev;
                    
                    if (!tmp->prev) 
                        deque->head = tmp->next;
                    
                    if (!tmp->next) 
                        deque->tail = tmp->prev;
                    
                    free(tmp);
                    deque->size--;
                }
            }
        }

        deque_t* swap(deque_t *lst1, deque_t *lst2) {
            // Возвращает новый корень списка
            deque_t *prev1, *prev2, *next1, *next2;
            deque_t *head = deque->head;

            prev1 = lst1->prev;  // узел предшествующий lst1
            prev2 = lst2->prev;  // узел предшествующий lst2
            next1 = lst1->next;  // узел следующий за lst1
            next2 = lst2->next;  // узел следующий за lst2

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

        int size() {
            return deque->size;
        }

        void resize(int size, T value) {
            if(size > deque->size) {
                int deltaSize = size - deque->size;

                for (int i = 0; i < deltaSize; i++) 
                    this->push_back(value);
            }

            if(size < deque->size) {
                int deltaSize = deque->size - size;

                for (int i = 0; i < deltaSize; i++) 
                    this->pop_back();
            }
        }

        bool empty() {
            if(!deque->size)
                return true;
            else
                return false;
        }

        T front() {
            return deque->head->data;
        }

        T back() {
            return deque->tail->data;
        }

        T at(int index) {
            if(index > 0 && index < deque->size)
                return this->get_elem(index)->data;
            else
                return -1;
        }

        void clear() {
            deque_t *tmp = deque->head;
            deque_t *next = NULL;

            while (tmp) {
                next = tmp->next;
                free(tmp);
                tmp = next;
            }

            free(deque);
            deque = NULL;
        }

        ~my_deque() {
            delete deque;
        }
};

