#include <iostream>

#include "./modules/relp_logic.h"
#include "./modules/InputBuffer.h"
#include "./modules/Table.h"


int main(int argc, char* argv[]) {

    InputBuffer *inputBuffer;
    inputBuffer = new InputBuffer;
    Table* table;
    table = new Table;
    std::cout << table->num_rows;

    while (true) {
        print_prompt();
        read_input(inputBuffer);

        if (inputBuffer->buffer[0] == '.') {
            if (run_meta_command(inputBuffer)) {
                std::cout << "Executed command: " + std::string(inputBuffer->buffer) + "\n";
            } else {
                std::cout << "Invalid command: " + std::string(inputBuffer->buffer) + "\n";
            }
        }
        else {
            bool result = run_sql_command(inputBuffer, table);
            if (result) std::cout << "\n" <<  "Executed command: " + std::string(inputBuffer->buffer) + "\n";
            else std::cout << "\n" << "Invalid Command: " + std::string(inputBuffer->buffer) + "\n";
        }
    }

    return 0;
}
