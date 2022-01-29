#include "../include/header.hpp"
#include "../include/list.hpp"
#include "../include/forward_list.hpp"
#include "../include/stack.hpp"
#include "../include/queue.hpp"
#include "../include/vector.hpp"
#include "../include/forward_list.hpp"

int main() {
    #if DEBUG
		fdw = fopen("log.log", "w");
	#endif

    my_fwd_list<int> li;

    for (int i = 0; i < 6; i++)
        li.push_back(i);
    
    li.print_list();

    #if DEBUG
		fclose(fdw);
	#endif

    return 0;
}