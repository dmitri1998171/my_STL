#include "../include/header.hpp"

#define OFFSET 5

template <class T>
class my_fwd_list {
    private:
        typedef struct my_fwd_list_t {
            T data;
            struct my_fwd_list_t *next;
        }lst;
        
        typedef struct _header {
            size_t size;
            lst *head;
            lst *tail;
        } header;

        header *fwd_list;
        int capacity;

    public:
        my_fwd_list() {
            fwd_list = (header*) malloc(sizeof(header));
            capacity = OFFSET;
            fwd_list->size = 0;
            fwd_list->head = fwd_list->tail = NULL;
        }

        lst* get_elem(int index) {
            lst *tmp = fwd_list->head;
            int i = 0;
            index--;    // Отсчет от 1, а не от 0
            
            while (tmp && i < index) {
                tmp = tmp->next;
                i++;
            }
    
            return tmp;
        }

        int searchByValue(T value){
            if(!fwd_list) {
                LOG_CHAR(LOG_ERROR, "searchByValue() return -1")
                return -1;
            }

            int pos = 1;
            lst *tmp = fwd_list->head;

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
            if(!fwd_list) {
                LOG_CHAR(LOG_ERROR, "searchByPos() return -1")
                return -1;
            }

            lst *tmp = fwd_list->head;

            for(int i = 1; i < pos; i++) 
                tmp = tmp->next;

            return tmp->data;
        }

        T front() {
            return fwd_list->head;
        }

        T back() {
            return fwd_list->tail;
        }

        int size() {
            return fwd_list->size;
        }

        int max_size() {
            return this->capacity;
        }

        bool empty() {
            if(!fwd_list->size)
                return true;
            else
                return false;
        }

        void push_front(T value) {
            if(!fwd_list->size)
                capacity += OFFSET;

            fwd_list->size++;

            if(fwd_list->size > capacity) {
                cout << "the fwd_list is full!" << endl;
            }
            else {
                lst *tmp = (lst*) malloc(sizeof(lst));

                tmp->data = value;
                tmp->next = fwd_list->head;

                if (fwd_list->head) 
                    fwd_list->head = tmp;

                fwd_list->head = tmp;
            
                if (fwd_list->tail == NULL) 
                    fwd_list->tail = tmp;
            }
        }

        void push_back(T value) {
            if(fwd_list->size == 0)
                capacity += OFFSET;

            fwd_list->size++;

            if(fwd_list->size > capacity) {
                cout << "the fwd_list is full!" << endl;
            }
            else {
                lst *tmp = (lst*) malloc(sizeof(lst));

                tmp->data = value;
                tmp->next = NULL;

                if (fwd_list->tail) 
                    fwd_list->tail->next = tmp;
                
                fwd_list->tail = tmp;
            
                if (fwd_list->head == NULL) 
                    fwd_list->head = tmp;
            }
        }

        void print_list() {
            if(fwd_list) {
                lst *tmp = fwd_list->head;

                while (tmp) {
                    cout << tmp->data << " ";
                    tmp = tmp->next;
                }

                cout << endl;
            }
            else
                cout << "the fwd_list is empty" << endl;
        }

        void pop_back() {
            lst *next = NULL;
            lst *tmp = fwd_list;
        
            next = fwd_list->tail;

            while (tmp->next->next != NULL)
                tmp = tmp->next;

            fwd_list->tail = tmp;

            if (fwd_list->tail) 
                fwd_list->tail->next = NULL;

            if (next == fwd_list->head) 
                fwd_list->head = NULL;
            
            free(next);
        
            fwd_list->size--;
        }

        void pop_front() {
            lst *p = NULL;
        
            p = fwd_list->head;
            fwd_list->head = fwd_list->head->next;
            
            if (p == fwd_list->tail) 
                fwd_list->tail = NULL;
            
            free(p);
        
            fwd_list->size--;
        }

        void insert(int index, T value) {
            lst *ins = (lst*) malloc(sizeof(lst));
            lst *elm = get_elem(index);
            lst *tmp = fwd_list;

            while (tmp->next->next != NULL)
                tmp = tmp->next;

            if (elm) {
                ins->data = value;
                tmp = elm;
                ins->next = elm->next;
                
                elm->next = ins;
            
                if (!tmp) 
                    fwd_list->head = elm;
                
                if (!elm->next) 
                    fwd_list->tail = elm;
            
                fwd_list->size++;
            }
            else {
                LOG_CHAR(LOG_ERROR, "can't insert element")
            }
        }

        void erase(T value) {
            lst *temp = fwd_list->head;
            lst *ptr = get_elem(searchByValue(value));

            while (temp->next->data != value) 
                temp = temp->next;

            if(ptr == fwd_list->tail)
                fwd_list->tail = temp;

            temp->next = ptr->next;
            
            free(ptr);
        }

        void swap(lst *lst1, lst *lst2) {
            // Возвращает новый корень списка
            lst *prev1, *prev2, *next1, *next2;
            lst *head = fwd_list->head; 
            prev1 = head;
            prev2 = head;

            if (prev1 == lst1)
                prev1 = NULL;

            else {
                while (prev1->next != lst1) // поиск узла предшествующего lst1
                    prev1 = prev1->next;
            }

            if (prev2 == lst2)
                prev2 = NULL;

            else {
                while (prev2->next != lst2) // поиск узла предшествующего lst2
                    prev2 = prev2->next;
            }

            next1 = lst1->next;  // узел следующий за lst1
            next2 = lst2->next;  // узел следующий за lst2

            if (lst2 == next1) { // обмениваются соседние узлы
                lst2->next = lst1;
                lst1->next = next2;

                if (lst1 != head)
                    prev1->next = lst2;
            }

            else if (lst1 == next2) {
                // обмениваются соседние узлы
                lst1->next = lst2;
                lst2->next = next1;
                
                if (lst2 != head)
                    prev2->next = lst2;
            }

            else {
                // обмениваются отстоящие узлы
                if (lst1 != head)
                    prev1->next = lst2;

                lst2->next = next1;

                if (lst2 != head)
                    prev2->next = lst1;
                
                lst1->next = next2;
            }
        }

        void resize(int size, T value) {
            if(size > fwd_list->size) {
                for (int i = fwd_list->size + 1; i < size; i++) 
                    this->push_back(value);
            }

            if(size < fwd_list->size) {
                for (int i = size; i < fwd_list->size; i++) 
                    this->pop_back();
            }
        }

        void clear() {
            lst *tmp = fwd_list->head;
            lst *next = NULL;

            while (tmp) {
                next = tmp->next;
                free(tmp);
                tmp = next;
            }

            free(fwd_list);
            fwd_list = NULL;
        }

        ~my_fwd_list() {
            delete fwd_list;
        }
};

