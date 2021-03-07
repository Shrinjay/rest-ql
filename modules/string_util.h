//
// Created by shrin on 3/6/2021.
//

#ifndef C_DB_STRING_UTIL_H
#define C_DB_STRING_UTIL_H

#include "string.h"

char* read_to_end(int start, char* str, std::size_t buffer_length) {
    char* result = new char[buffer_length-start];
    for (int i=start; i<buffer_length; i++) {
        result[i-start] = str[i];
    }
    return result;
};

#endif //C_DB_STRING_UTIL_H
