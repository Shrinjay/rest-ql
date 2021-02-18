#include <iostream>
#include <string.h>
#include "./modules/relp_logic.h"
# include "./modules/InputBuffer.h"

int main(int argc, char* argv[]) {

    InputBuffer* inputBuffer = new InputBuffer;

    while (true) {
        print_prompt();
        read_input(inputBuffer);

        if (strcmp(inputBuffer->buffer, ".exit") == 0) {
            break;
        }
        else {
            std::cout << "Unrecognized command " + std::string(inputBuffer->buffer) + "\n";
        }
    }

    return 0;
}
