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
        qe.push(i);

    qe.print_queue();

    qe.pop();
    qe.print_queue();

    #if DEBUG
		fclose(fdw);
	#endif

    return 0;
}