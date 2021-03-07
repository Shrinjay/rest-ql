//
// Created by shrin on 3/6/2021.
//

#ifndef C_DB_ROW_H
#define C_DB_ROW_H

std::size_t ID_OFFSET = 0;
int USER_OFFSET = 4;
int USER_DATA_OFFSET = 36;
std::size_t ID_SIZE = 4;
int USER_SIZE = 32;
int USER_DATA_SIZE = 255;

class Row {
public:
    int id;
    char user[32];
    char user_data[255];
    void print_row();
};

void Row::print_row() {
    std::cout << this->id << ", " << this->user << ", " << this->user_data << "\n";
}

void serialize_row(Row* source, char* destination) {
    memcpy(destination + ID_OFFSET, &(source->id), ID_SIZE);
    memcpy(destination + USER_OFFSET, &(source->user), USER_SIZE);
    memcpy(destination + USER_DATA_OFFSET, &(source->user_data), USER_DATA_OFFSET);
}

void deserialize_row(char* source, Row* destination) {
    memcpy(&(destination->id), source + ID_OFFSET, ID_SIZE);
    memcpy(&(destination->user), source + USER_OFFSET, USER_SIZE);
    memcpy(&(destination->user_data), source + USER_DATA_OFFSET, USER_DATA_SIZE);
}
#endif //C_DB_ROW_H
