//
// Created by shrin on 2/18/2021.
//

#ifndef C_DB_RELP_LOGIC_H
#define C_DB_RELP_LOGIC_H

#include <iostream>
#include <string>
#include "InputBuffer.h"
#include <string.h>
#include "string_util.h"
#include "Statement.h"
#include "Table.h"

int INSERT_AND_STATEMENT_LENGTH = 6;

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

bool run_meta_command(InputBuffer* input_buffer) {
    if (strcmp(input_buffer->buffer, ".exit") == 0) {
        exit(0);
    } else {
        return false;
    }
}

bool run_sql_command(InputBuffer* input_buffer, Table* table) {
    Statement statement;
    if (strncmp(input_buffer->buffer, "insert", INSERT_AND_STATEMENT_LENGTH) == 0) {
        statement.type = "INSERT";
        sscanf(input_buffer->buffer, "insert %d %s %s",
                                   &(statement.row_to_insert.id), statement.row_to_insert.user,
                                   statement.row_to_insert.user_data);
        serialize_row(&(statement.row_to_insert), table->row_slot(table->num_rows));
        table->num_rows += 1;
        return true;
    }
    else if (strncmp(input_buffer->buffer, "select", INSERT_AND_STATEMENT_LENGTH) == 0) {
        Row row = {};
        for (int i=0; i< table->num_rows; i++) {
            deserialize_row(table->row_slot(i), &row);
            row.print_row();
        }
        return true;
    }
    else {
        return false;
    }
}

#endif //C_DB_RELP_LOGIC_H
