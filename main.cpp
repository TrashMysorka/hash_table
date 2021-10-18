#include <iostream>
#include "hash_table.h"

int main() {
     HashTable t;
     const Value s{.age = 18 , .weight=123 };
     cout << t.empty() << endl;
     bool tick = t.insert("loh", s);
     bool suka = t.insert("gandonishe", s);
     bool tvar = t.insert("2", s);
     Value sukar = t["loh"];
     cout << sukar.weight;
     t.erase("loh");
     cout << t.at("loh").weight << endl;
     cout << tvar;
    return 0;
}
