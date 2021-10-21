#include "hash_table.h"
#include <iostream>
#include <list>


using namespace std;





int hash_func(const Key& s, int table_size)
{
    int hash_result = 0;
    for (char i : s)
        hash_result = (hash_result + i);
    hash_result = (hash_result * 2) % table_size;
    return hash_result;
}


void HashTable::resize(){
    vector<list<pair<Key, Value>>*> new_arr = arr;
    arr.clear();
    buffer_size *= 2;
    list<pair<Key, Value>>* k = nullptr;
    arr.resize(buffer_size, k);
    for (int i = 0; i < buffer_size / 2; i++){
        if (!new_arr[i]->empty()){
            for (auto & it : *new_arr[i]){
            insert(it.first, it.second);
        }

        }
    }
    }


HashTable::HashTable(){
    default_student.weight = 70;
    default_student.age = 18;
    buffer_size = default_size;
    table_size = 0;
    list<pair<Key, Value>>* k = nullptr;
    arr.resize(buffer_size, k);
}


HashTable::~HashTable() {
    /*for (const auto it : arr){
        if(it != nullptr){
            delete it;
        }
    }*/
    vector<list<pair<Key, Value>>*>().swap(arr);

}


HashTable::HashTable(const HashTable& b): HashTable(){
    arr = b.arr;
    buffer_size = b.buffer_size;
    table_size = b.table_size;
    default_student = b.default_student;

}


HashTable::HashTable(HashTable &&b){
    arr = b.arr;
    buffer_size = b.buffer_size;
    table_size = b.table_size;
    default_student = b.default_student;
    for (auto & it : b.arr){
        it = nullptr;
    }

}

HashTable& HashTable::operator=(const HashTable& b) {
    if (this == &b){
        return *this;
    }
    buffer_size = b.buffer_size;
    table_size = b.table_size;
    arr.clear();
    arr = b.arr;

    return *this;
}
HashTable& HashTable::operator=(HashTable &&b){
    if (this == &b){
        return *this;
    }
    buffer_size = b.buffer_size;
    table_size = b.table_size;
    arr.clear();
    arr = b.arr;
    for(auto it : b.arr){
        it = nullptr;
    }
    return *this;
}
/*HashTable& HashTable::operator=(HashTable b) {
    buffer_size = b.buffer_size;
    table_size = b.table_size;
    arr.swap(b.arr);
}*/

void HashTable::swap(HashTable &b) {
    int prom = buffer_size;
    buffer_size = b.buffer_size;
    b.buffer_size = prom;
    prom = table_size;
    table_size = b.table_size;
    b.table_size = prom;
    arr.swap(b.arr);
}


void HashTable::clear(){
    list<pair<Key, Value>>* cl = nullptr;
    arr.clear();
    arr.resize(buffer_size, cl);
}


bool HashTable::erase(const Key& k) {
    int hash = hash_func(k, buffer_size);
    for (auto it = arr[hash]->begin(); it != arr[hash]->end(); it++){

        if (it->first == k) {
            arr[hash]->erase(it);
            table_size--;
            return true;
        }

    }
    return false;
}


bool HashTable::insert(const Key& k, const Value& v){
    int hash = hash_func(k, buffer_size);
    if (arr[hash] == nullptr){
        arr[hash] = new list<pair<Key, Value>>;
    }
    arr[hash]->push_front(make_pair(k, v));
    if(arr[hash]->size() > rehash_size){
        resize();
    }
    table_size++;
    return true;
}


bool HashTable::contains(const Key& k) const{
    int hash = hash_func(k, buffer_size);
    if(arr[hash] == nullptr){
        return false;
    }

    for (const auto & it : *arr[hash]) {


        if (it.first == k){
            return true;
        }
    }
}


Value& HashTable::operator[](const Key &k) {
    if (contains(k)){
        int hash = hash_func(k, buffer_size);
        for (auto & it : *arr[hash]){
            if (it.first == k){
                return it.second;
            }
        }
    }
    insert(k, default_student);
    return default_student;
}


Value& HashTable::at(const Key &k) {
    if (contains(k)){
        int hash = hash_func(k, buffer_size);
        for (auto & it : *arr[hash]){
            if (it.first == k){
                return it.second;
            }
        }
    }
    else{
        throw invalid_argument("Element at this position doesn't exist");
    }
}


size_t HashTable::size() const{
    return table_size;
}


bool HashTable::empty() const{
    for (const auto it : arr){
        if(it!= nullptr){
                return false;
        }
    }
    return true;
}


bool operator==(const HashTable& a, const HashTable& b){
    bool size = a.buffer_size == b.buffer_size;
    bool arrs = a.arr == b.arr;
    return size && arrs;
}


bool operator!=(const HashTable& a, const HashTable& b){

        bool size = a.buffer_size == b.buffer_size;
        bool arrs = a.arr == b.arr;
        bool r = size && arrs;
        return !r;

}