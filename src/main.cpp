#include "../include/header.hpp"
#include "../include/list.hpp"
#include "../include/forward_list.hpp"
#include "../include/stack.hpp"
#include "../include/queue.hpp"
#include "../include/vector.hpp"
// #include "../include/forward_list.hpp"
#include "../include/array.hpp"

#include <string.h>

int main() {
    #if DEBUG
		fdw = fopen("log.log", "w");
	#endif

    my_array<char, 6> arr;

    arr.fill('*');
    arr.print_arr();


    #if DEBUG
		fclose(fdw);
	#endif

    return 0;
}