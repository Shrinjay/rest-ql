//
// Created by shrin on 2/17/2021.
//

# include "InputBuffer.h"
# include <iostream>

InputBuffer::InputBuffer() {
    buffer = new char[256];
    buffer_length = 0;
    input_length = 0;
}

InputBuffer::~InputBuffer() {
    delete[] buffer;
    buffer = nullptr;
}