#include "../include/header.hpp"

#define OFFSET 5

template <class T>
class my_list {
    private:
        typedef struct my_list_t {
            T data;
            struct my_list_t *prev;
            struct my_list_t *next;
        }lst;
        
        typedef struct _header {
            size_t size;
            lst *head;
            lst *tail;
        } header;

        header *list;
        int capacity;

    public:
        my_list() {
            list = (header*) malloc(sizeof(header));
            capacity = OFFSET;
            list->size = 0;
            list->head = list->tail = NULL;
        }

        lst* get_elem(int index) {
            lst *tmp = NULL;
            int i;
            index--;    // Отсчет от 1, а не от 0
            
            if (index < list->size / 2) {
                i = 0;
                tmp = list->head;
                while (tmp && i < index) {
                    tmp = tmp->next;
                    i++;
                }
            } 
            else {
                i = list->size - 1;
                tmp = list->tail;
                while (tmp && i > index) {
                    tmp = tmp->prev;
                    i--;
                }
            }
        
            return tmp;
        }

        int searchByValue(T value){
            if(!list) {
                LOG_CHAR(LOG_ERROR, "searchByValue() return -1")
                return -1;
            }

            int pos = 1;
            lst *tmp = list->head;

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
            if(!list) {
                LOG_CHAR(LOG_ERROR, "searchByPos() return -1")
                return -1;
            }

            lst *tmp = list->head;

            for(int i = 1; i < pos; i++) 
                tmp = tmp->next;

            return tmp->data;
        }

        T front() {
            return list->head;
        }

        T back() {
            return list->tail;
        }

        int size() {
            return list->size;
        }

        int max_size() {
            return this->capacity;
        }

        bool empty() {
            if(!list->size)
                return true;
            else
                return false;
        }

        void push_front(T value) {
            if(!list->size)
                capacity += OFFSET;

            list->size++;

            if(list->size > capacity) {
                cout << "the list is full!" << endl;
            }
            else {
                lst *tmp = (lst*) malloc(sizeof(lst));

                tmp->data = value;
                tmp->prev = NULL;
                tmp->next = list->head;

                if (list->head) 
                    list->head->prev = tmp;

                list->head = tmp;
            
                if (list->tail == NULL) 
                    list->tail = tmp;
            }
        }

        void push_back(T value) {
            if(list->size == 0)
                capacity += OFFSET;

            list->size++;

            if(list->size > capacity) {
                cout << "the list is full!" << endl;
            }
            else {
                lst *tmp = (lst*) malloc(sizeof(lst));

                tmp->data = value;
                tmp->prev = list->tail;
                tmp->next = NULL;

                if (list->tail) 
                    list->tail->next = tmp;
                
                list->tail = tmp;
            
                if (list->head == NULL) 
                    list->head = tmp;
            }
        }

        void print_list() {
            if(list) {
                lst *tmp = list->head;

                while (tmp) {
                    cout << tmp->data << " ";
                    tmp = tmp->next;
                }

                cout << endl;
            }
            else
                cout << "the list is empty" << endl;
        }

        void pop_back() {
            lst *next = NULL;
        
            next = list->tail;
            list->tail = list->tail->prev;

            if (list->tail) 
                list->tail->next = NULL;

            if (next == list->head) 
                list->head = NULL;
            
            free(next);
            list->size--;
        }

        void pop_front() {
            lst *prev = NULL;
        
            prev = list->head;
            list->head = list->head->next;
            if (list->head) 
                list->head->prev = NULL;
            
            if (prev == list->tail) 
                list->tail = NULL;
            
            free(prev);
            list->size--;
        }

        void insert(int index, T value) {
            lst *ins = (lst*) malloc(sizeof(lst));
            lst *elm = get_elem(index);

            if (elm) {
                ins->data = value;
                ins->prev = elm;
                ins->next = elm->next;
                
                if (elm->next) 
                    elm->next->prev = ins;
                
                elm->next = ins;
            
                if (!elm->prev) 
                    list->head = elm;
                
                if (!elm->next) 
                    list->tail = elm;
            
                list->size++;
            }
            else {
                LOG_CHAR(LOG_ERROR, "can't insert element")
            }
        }

        void erase(T value) {
            lst *current_item = list->head;

            while (current_item) {
                lst *tmp = current_item;
                current_item = current_item->next;

                if(value == tmp->data) {
                    if (tmp->prev) 
                        tmp->prev->next = tmp->next;
                    
                    if (tmp->next) 
                        tmp->next->prev = tmp->prev;
                    
                    if (!tmp->prev) 
                        list->head = tmp->next;
                    
                    if (!tmp->next) 
                        list->tail = tmp->prev;
                    
                    free(tmp);
                    list->size--;
                }
            }
        }

        void swap(lst *lst1, lst *lst2) {
            // Возвращает новый корень списка
            lst *prev1, *prev2, *next1, *next2;
            lst *head = list->head;

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
        }

        void resize(int size, T value) {
            if(size > list->size) {
                for (int i = list->size + 1; i < size; i++) 
                    this->push_back(value);
            }

            if(size < list->size) {
                for (int i = size; i < list->size; i++) 
                    this->pop_back();
            }
        }

        void clear() {
            lst *tmp = list->head;
            lst *next = NULL;

            while (tmp) {
                next = tmp->next;
                free(tmp);
                tmp = next;
            }

            free(list);
            list = NULL;
        }

        ~my_list() {
            delete list;
        }
};

