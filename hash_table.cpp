#include "hash_table.h"
#include <iostream>
#include <list>
int HashFunctionHorner(const std::string& s, int table_size, const int key)
{
    int hash_result = 0;
    for (int i = 0; s[i] != s.size(); ++i)
        hash_result = (key * hash_result + s[i]) % table_size;
    hash_result = (hash_result * 2 + 1) % table_size;
    return hash_result;
}
HashTable::HashTable(){
    buffer_size = default_size;
    arr = new Node*[buffer_size];
    table_size = 0;
    for (int i = 0; i < buffer_size; i++){
        arr[i] = nullptr;
    }
}
HashTable::~HashTable() {
    for (int i = 0; i < buffer_size; i++)
        if(arr[i])
            delete arr[i];
    delete[] arr;
}
HashTable::HashTable(const HashTable& b): HashTable(){}
size_t HashTable::size() const{
    return buffer_size;
}
void HashTable::clear(){}