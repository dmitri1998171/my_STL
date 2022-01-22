#include <iostream>
#include "/Users/dmitry/Programming/C/Lists/list_header.h"

// ##############################
#define DEBUG 1

#if DEBUG
    FILE* fdw;

    enum log_level_t {LOG_ERROR, LOG_WARNING, LOG_INFO, LOG_DEBUG};

	#define LOG_NUM(log_level, x)           \
        ( (log_level == LOG_DEBUG) ?        \
            (fprintf(fdw, "%s, %s: %d\n", #log_level, #x, x)) :\
            (fprintf(fdw, "%s, %d\n", #log_level, x)) ); 

	#define LOG_CHAR(log_level, x)   	    \
        ( (log_level == LOG_DEBUG) ? 		\
            (fprintf(fdw, "%s, %s: %s\n", #log_level, #x, x)) :\
            (fprintf(fdw, "%s\n", x)) );		
#else
	#define LOG(x) 
#endif
// ##############################


using namespace std;

class my_list {
    private:
        typedef struct my_list_t {
            int data;
            struct my_list_t *prev;
            struct my_list_t *next;
        }my_list_s;
        
        typedef struct _header {
            size_t size;
            lst *head;
            lst *tail;
        } header;

        header *list;

    public:
        my_list() {
            list = (header*) malloc(sizeof(header));
            list->size = 0;
            list->head = list->tail = NULL;
        }

        int search(header *list, int value){
            if(!list){
                LOG_CHAR(LOG_ERROR, "search() return -1")
                return -1;
            }

            int pos = 0;
            lst *tmp = list->head;

            while(tmp) {
                if(value == tmp->value)
                    return pos;
                
                tmp = tmp->next;
                pos++;
            }

            LOG_CHAR(LOG_ERROR, "search() return -2")
            return -2;
        }

        void push_front(int value) {
            lst *tmp = (lst*) malloc(sizeof(lst));

            tmp->value = value;
            tmp->prev = NULL;
            tmp->next = list->head;

            if (list->head) 
                list->head->prev = tmp;

            list->head = tmp;
        
            if (list->tail == NULL) 
                list->tail = tmp;
            
            list->size++;
        }

        void push_back(int value) {
            lst *tmp = (lst*) malloc(sizeof(lst));

            tmp->value = value;
            tmp->prev = list->tail;
            tmp->next = NULL;

            if (list->tail) 
                list->tail->next = tmp;
            
            list->tail = tmp;
        
            if (list->head == NULL) 
                list->head = tmp;
            
            list->size++;
        }

        void print_list() {
            if(list) {
                lst *tmp = list->head;

                while (tmp) {
                    cout << tmp->value << " ";
                    tmp = tmp->next;
                }

                cout << endl;
            }
            else
                cout << "the list is empty" << endl;
        }

        void pop_back() {
            lst *next = NULL;
            int tmp = 0;
        
            next = list->tail;
            list->tail = list->tail->prev;

            if (list->tail) 
                list->tail->next = NULL;

            if (next == list->head) 
                list->head = NULL;
            
            tmp = next->value;
            free(next);
        
            list->size--;
        }

        void pop_front() {
            lst *prev = NULL;
            int tmp = 0;
        
            prev = list->head;
            list->head = list->head->next;
            if (list->head) 
                list->head->prev = NULL;
            
            if (prev == list->tail) 
                list->tail = NULL;
            
            tmp = prev->value;
            free(prev);
        
            list->size--;
        }

        void insert() {

        }

        void erase(int value) {
            lst *current_list_item = list->head;

            while (current_list_item) {
                lst *tmp = current_list_item;
                current_list_item = current_list_item->next;

                if(value == tmp->value) {
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

        void swap() {

        }

        void resize() {

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
};

int main() {
    #if DEBUG
		fdw = fopen("log.log", "w");
	#endif

    my_list li;
    header *tmp = create_header();

    for (int i = 0; i < 5; i++) 
        li.push_front(i);
    
    li.print_list();

    li.erase(2);
    li.print_list();

    #if DEBUG
		fclose(fdw);
	#endif

    return 0;
}