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

    LOG_NUM(LOG_DEBUG, vt.size())
    LOG_NUM(LOG_DEBUG, vt.max_size())

    for (int i = 1; i <= 12; i++)
        vt.push_back(i);

    LOG_NUM(LOG_DEBUG, vt.size())
    LOG_NUM(LOG_DEBUG, vt.max_size())
    vt.print_vector();
    

    #if DEBUG
		fclose(fdw);
	#endif

    return 0;
}