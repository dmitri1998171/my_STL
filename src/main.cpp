#include "../include/header.hpp"
#include "../include/list.hpp"
#include "../include/stack.hpp"
#include "../include/queue.hpp"
#include "../include/deque.hpp"

int main() {
    #if DEBUG
		fdw = fopen("log.log", "w");
	#endif

    my_deque<int> qe;

    for (int i = 0; i < 5; i++)
        qe.push_back(i);

    qe.print_deque();

    cout << qe.at(3) << endl;
    // qe.print_deque();

    #if DEBUG
		fclose(fdw);
	#endif

    return 0;
}