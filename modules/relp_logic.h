//
// Created by shrin on 2/18/2021.
//

#ifndef C_DB_RELP_LOGIC_H
#define C_DB_RELP_LOGIC_H

#include <iostream>
#include <string>
#include "InputBuffer.h"

void print_prompt() {
    std::cout << "db > ";
}

void read_input(InputBuffer* input_buffer) {
    std::cin.getline(input_buffer->buffer, 256);
    size_t bytes_read = std::cin.gcount();

    if (bytes_read <= 0) {
        std::cout << "Error reading input \n";
    }
    input_buffer -> buffer_length = bytes_read - 1;
}

#endif //C_DB_RELP_LOGIC_H
