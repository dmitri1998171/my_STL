#ifndef HEADER_HPP
#define HEADER_HPP
#include <iostream>

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
#endif