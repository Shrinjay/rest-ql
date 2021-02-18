//
// Created by shrin on 2/17/2021.
//

#ifndef C_DB_INPUTBUFFER_H
#define C_DB_INPUTBUFFER_H

#include <iostream>

class InputBuffer {
    public:
        char* buffer{};
        std::size_t buffer_length{};
        std::size_t input_length{};

        InputBuffer();
        ~InputBuffer();
};


#endif //C_DB_INPUTBUFFER_H
