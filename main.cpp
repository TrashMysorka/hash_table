#include <iostream>
#include "hash_table.h"
using namespace std;
int main() {
     HashTable t;
     const Value s{.age = 18 , .weight=123 };
        list<pair<Key, Value>> *pList = nullptr;
        pList = new list<pair<Key, Value>>;
        pList->size(); // ->push_front(make_pair("chemo", s));
     //cout << t.empty() << endl;
     bool tick = t.insert("loh", s);
     HashTable blyat;
     bool rtyh = blyat.insert("fuck", s);
     Value sukar = t["loh"];
//cout << sukar.weight;
     t.erase("loh");
     //const HashTable po = t;
     //const HashTable op = blyat;
     bool k = t != blyat;
     cout << k << endl;
     //cout << tvar;
    return 0;
}
