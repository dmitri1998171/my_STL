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

        int push_front(int value) {
            if(!list){
                LOG_CHAR(LOG_ERROR, "push_front() return 1")
                return 1;
            }

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
            return 0;
        }

        int push_back(int value) {
            if(!list) {
                LOG_CHAR(LOG_ERROR, "push_back() return 1")
                return 1;
            }

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
            return 0;
        }

        int print_list() {
            if(!list) {
                LOG_CHAR(LOG_ERROR, "print_list() return 1")
                return 1;
            }

            lst *tmp = list->head;

            while (tmp) {
                cout << tmp->value << " ";
                tmp = tmp->next;
            }

            cout << endl;
            return 0;
        }

        int pop_back() {
            if(!list || list->tail == NULL) {
                LOG_CHAR(LOG_ERROR, "pop_back() return 1")
                return 1;
            }

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
            return 0;
        }

        int pop_front() {
            if(!list || list->head == NULL) {
                LOG_CHAR(LOG_ERROR, "pop_front() return 1")
                return 1;
            }

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
            return 0;
        }

        int insert() {

        }

        int erase() {

        }

        int swap() {

        }

        int resize() {

        }

        int clear() {
            
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

    li.pop_front();
    li.print_list();

    #if DEBUG
		fclose(fdw);
	#endif

    return 0;
}