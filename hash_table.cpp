#include "hash_table.h"
#include <iostream>
#include <list>
class aaaaaaaaa: public exception
        {
    virtual const char* what() const throw()
    {
        return "aaaaaaaaa";
    }
        } aaaaaaaaa;
int hash_func(const Key& s, int table_size)
{
    int hash_result = 0;
    for (char i : s)
        hash_result = (hash_result + i);
    hash_result = (hash_result * 2) % table_size;
    return hash_result;
}

void HashTable::resize(){
    vector<list<pair<Key, Value>>> new_arr = arr;
    arr.clear();
    buffer_size *= 2;
    list<pair<Key, Value>> k;
    arr.resize(buffer_size, k);
    for (int i = 0; i < buffer_size / 2; i++){
        if (!new_arr[i].empty()){
            for (auto & it : new_arr[i]){
            insert(it.first, it.second);
        }

        }
    }
    }


HashTable::HashTable(){
    buffer_size = default_size;
    list<pair<Key, Value>> k;
    arr.resize(buffer_size, k);
}

HashTable::~HashTable() {


}
HashTable::HashTable(const HashTable& b): HashTable(){
    arr.clear();
    arr.resize(b.arr.size());
    for (const auto & it : b.arr){
        arr.push_back(it);
    }
}
size_t HashTable::size() const{
    return buffer_size;
}
bool HashTable::contains(const Key& k) const{
    int hash = hash_func(k, buffer_size);
    for (const auto & it : arr[hash]) {
        if (it.first == k){
            return true;
        }
    }
    return false;
}
bool HashTable::erase(const Key& k) {
    int hash = hash_func(k, buffer_size);
    for (auto it = arr[hash].begin(); it!=arr[hash].end(); it++) {

        if (it->first == k) {
            arr[hash].erase(it);
            return true;
        }

        return false;
    }
}
bool HashTable::insert(const Key& k, const Value& v){
    int hash = hash_func(k, buffer_size);
    //cout << hash << endl;
    arr[hash].push_front(make_pair(k, v));
    for (auto it = arr[hash].begin(); it != arr[hash].end(); it++){
        //cout << it->second.weight << endl;
    }

    if(arr[hash].size() > rehash_size){
        resize();
    }
    return true;
}
bool HashTable::empty() const{
    for (int i = 0; i < buffer_size / 2; i++){
        if (!arr[i].empty()){
            return false;
        }
    }
    return true;
}
Value& HashTable::operator[](const Key &k) {
    if (contains(k)){
        int hash = hash_func(k, buffer_size);
        for (auto & it : arr[hash]){
            if (it.first == k){
                return it.second;
            }
        }
    }
    else{
        insert(k, default_student);
        return default_student;
    }
}
Value& HashTable::at(const Key &k) {
    if (contains(k)){
        int hash = hash_func(k, buffer_size);
        for (auto & it : arr[hash]){
            if (it.first == k){
                return it.second;
            }
        }
    }
    else{
        throw aaaaaaaaa;
    }
}
void HashTable::clear(){}