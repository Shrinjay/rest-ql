//
// Created by shrin on 3/6/2021.
//

#ifndef C_DB_TABLE_H
#define C_DB_TABLE_H

std::size_t const PAGE_SIZE = 600;
std::size_t const ROW_SIZE = 291;

class Table {
public:
    int num_rows;
    char* pages[100];
    Table();
    ~Table();
    char* row_slot(int row_num);
};

char* Table::row_slot(int row_num) {
    int page_num = row_num / 2;
    char* page = this->pages[page_num];
    if (page == nullptr) {
        page = this->pages[page_num] = new char[PAGE_SIZE];
    }
    int byte_offset = row_num % 2 * ROW_SIZE;
    return page + byte_offset;
}

Table::Table() {
    num_rows = 0;
    for (int i=0; i<100; i++) {
        pages[i] = nullptr;
    }
}

Table::~Table() {
    for (int i=0; i<100; i++) {
        delete pages[i];
        pages[i] = nullptr;
    }
}


#endif //C_DB_TABLE_H
