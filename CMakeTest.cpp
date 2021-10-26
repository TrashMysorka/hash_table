#include <iostream>
#include "hash_table.h"
#include <gtest/gtest.h>


class HashTableTest : public testing::Test{
protected:
    void SetUp() override{
        t1.insert("Mark Johnson", {.age = 20, .weight = 60});
        t1.insert("John Markson", {.age = 22, .weight = 75});
        t1.insert("Clark Kent", {.age = 24, .weight = 88});
        t1.insert("Bruce Wayne", {.age = 19, .weight = 130});

        t2.insert("Bob Marley", {.age = 28, .weight = 70});
        t2.insert("Barry Allen", {.age = 28, .weight = 70});
        t2.insert("Sergey Bobr", {.age = 19, .weight = 75});
    }
    HashTable t0;
    HashTable t1;
    HashTable t2;

};
TEST_F(HashTableTest, SwapWorks){
    t1.swap(t2);
    EXPECT_EQ(t1.size(), 3);
    EXPECT_EQ(t2.size(), 4);
    EXPECT_EQ(t2["Mark Johnson"].weight, 60);
}
TEST_F(HashTableTest, EraseWorks){
    bool r = t1.erase("Clark Kent");
    EXPECT_EQ(r, true);
    EXPECT_EQ(t1["Clark Kent"].weight, 70);
}
TEST_F(HashTableTest, EmptyWorks){
    bool r = t1.empty();
    EXPECT_EQ(r, false);
    r = t0.empty();
    EXPECT_EQ(r, true);
}
TEST_F(HashTableTest, ContainsWorks){
    bool r = t1.contains("Petr Ivanov");
    EXPECT_EQ(r, false);
    r = t1.contains("Clark Kent");
    EXPECT_EQ(r, true);
}
TEST_F(HashTableTest, AtWorks){
    Value& s = t1.at("Clark Kent");
    EXPECT_EQ(s.weight, 88);
    ASSERT_ANY_THROW(t1.at("sdrw"));
}
TEST_F(HashTableTest, OperatorsWork){
    bool r1 = t1 == t2;
    EXPECT_EQ(r1, false);
    bool r2 = t1 != t2;
    EXPECT_EQ(r2, true);
    unsigned int r3 = t1["Bruce Wayne"].weight;
    EXPECT_EQ(r3, 130);
    t1 = t2;
    r1 = t1 == t2;
    EXPECT_EQ(r1, true);
}
TEST_F(HashTableTest, CopyConstructWorks){
    HashTable t3 = t1;
    EXPECT_EQ(t3.size(), 4);
    bool r0 = t3.contains("Mark Johnson");
    EXPECT_EQ(r0, true);
    bool r1 = t3.contains("John Markson");
    EXPECT_EQ(r1, true);
    bool r2 = t3.contains("someone");
    EXPECT_EQ(r2, false);

}
TEST_F(HashTableTest, MoveConstructWorks){
    HashTable t4 = std::move(t2);

    bool r0 = t4.contains("Bob Marley");
    bool r1 = t4.contains("Barry Allen");
    bool r2 = t4.contains("Sergey Bobr");
    bool r3 = t2.empty();
    EXPECT_EQ(r0, true);
    EXPECT_EQ(r1, true);
    EXPECT_EQ(r2, true);
    EXPECT_EQ(r3, true);
}