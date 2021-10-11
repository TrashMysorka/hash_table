#include <iostream>
#include "hash_table.h"

int main() {
    const HashTable t;
    HashTable s(t);
    const Key str = "abvgd";


    std::cout << int(str[1]) << std::endl;
    return 0;
}
