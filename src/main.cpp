#include "../include/header.hpp"
#include "../include/list.hpp"
#include "../include/stack.hpp"
#include "../include/queue.hpp"

int main() {
    #if DEBUG
		fdw = fopen("log.log", "w");
	#endif

    my_queue<int> qe;

    for (int i = 0; i < 5; i++)
        qe.push(52 - i);

    qe.print_queue();

    qe.swap(qe.get_elem(2), qe.get_elem(3));
    qe.print_queue();

    #if DEBUG
		fclose(fdw);
	#endif

    return 0;
}