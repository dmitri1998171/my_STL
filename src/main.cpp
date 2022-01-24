#include "../include/header.hpp"
#include "../include/list.hpp"
#include "../include/stack.hpp"
#include "../include/queue.hpp"
#include "../include/vector.hpp"

int main() {
    #if DEBUG
		fdw = fopen("log.log", "w");
	#endif

    my_vector<int> vt;
    
    for (int i = 98; i <= 97 + 7; i++)
        vt.push_back(i);

    vt.print_vector();
    cout << endl;

    LOG_NUM(LOG_DEBUG, vt.size())
    LOG_NUM(LOG_DEBUG, vt.max_size())

    vt.erase(3);

    LOG_NUM(LOG_DEBUG, vt.size())
    LOG_NUM(LOG_DEBUG, vt.max_size())

    vt.print_vector();
    

    #if DEBUG
		fclose(fdw);
	#endif

    return 0;
}