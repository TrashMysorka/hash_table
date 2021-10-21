// В этой задаче для простоты не требуется делать контейнер шаблонным,
// это допускается по желанию. Для нешаблонного решения,
// введем типы ключей и значений: ключом будет выступать строка (например, имя
// студента, значением - произвольная структура (например, численные
// характеристики студента.
#include <iostream>
#include <list>
#include <vector>
using namespace std;

struct Student {
    unsigned age;
    unsigned weight;
};


typedef std::string Key;
typedef Student Value;

int hash_func(const Key& s, int table_size);

class HashTable {
    static const int default_size = 8;
    static const int rehash_size = 8;
    vector<list<pair<Key, Value>>*> arr;
    int buffer_size;
    int table_size;
    Value default_student{};
    //void rehash();
    void resize();
public:
    HashTable();

    ~HashTable();

    HashTable(const HashTable& b); // copy
    HashTable(HashTable&& b); // nullptr to table

    class aaaaaaaaa: public exception {

    }exc;
    HashTable& operator=(const HashTable& b);
    HashTable& operator=(HashTable&& b);
    //HashTable& operator=(HashTable b);

    // Обменивает значения двух хэш-таблиц.
    void swap(HashTable& b);

     // Очищает контейнер.
    void clear();
    // Удаляет элемент по заданному ключу.
    bool erase(const Key& k);
    // Вставка в контейнер. Возвращаемое значение - успешность вставки.
    bool insert(const Key& k, const Value& v);

    // Проверка наличия значения по заданному ключу.
    bool contains(const Key& k) const;

    // Возвращает значение по ключу. Небезопасный метод.
    // В случае отсутствия ключа в контейнере, следует вставить в контейнер
    // значение, созданное конструктором по умолчанию и вернуть ссылку на него.
    Value& operator[](const Key& k);

    // Возвращает значение по ключу. Бросает исключение при неудаче.
    Value& at(const Key& k);
    //const Value& at(const Key& k) const; ???

    size_t size() const;
    bool empty() const;

    friend bool operator==(const HashTable& a, const HashTable& b);
    friend bool operator!=(const HashTable& a, const HashTable& b);


};

//bool operator==(const HashTable& a, const HashTable& b);
//bool operator!=(const HashTable& a, const HashTable& b);

