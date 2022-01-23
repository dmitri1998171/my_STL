#include "../include/header.hpp"
#include "../include/list.hpp"
#include "../include/stack.hpp"

int main() {
    #if DEBUG
		fdw = fopen("log.log", "w");
	#endif

    my_stack<int> st;

    for (int i = 0; i < 5; i++)
        st.push(52 - i);

    st.print_stack();

    st.swap(st.get_elem(2), st.get_elem(3));
    st.print_stack();

    #if DEBUG
		fclose(fdw);
	#endif

    return 0;
}