#include "../include/header.hpp"
#include "../include/list.hpp"
#include "../include/stack.hpp"
#include "../include/queue.hpp"
#include "../include/vector.hpp"

int main() {
    #if DEBUG
		fdw = fopen("log.log", "w");
	#endif

    my_list<int> li;
    cout << endl << li.max_size() << " " << li.size() << endl;

    for (int i = 0; i < 6; i++)
        li.push_back(i);
    
    li.print_list();

    cout << endl << li.max_size() << " " << li.size() << endl;

    #if DEBUG
		fclose(fdw);
	#endif

    return 0;
}