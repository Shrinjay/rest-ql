//
// Created by shrin on 3/6/2021.
//

#ifndef C_DB_STATEMENT_H
#define C_DB_STATEMENT_H
#include "string"
#include "Row.h"

class Statement {
public:
    std::string type;
    Row row_to_insert;
};

#endif //C_DB_STATEMENT_H
