
#include <iostream>
#include <string>
#include <unordered_map>
#include "allocator.h"
#include "hash_table.h"
#include "string_hash_table.h"

int main()
{
    std::unordered_map<float, int> hash_table;
    // std::unordered_map<int, int>::key_type;
    using HashSet = HashTable<HashTableCell<int>, DefaultAllocator, HTAssistant<>>;
    HashSet my_hash_table;
    HashSet::result_type cell = {};
    bool inserted = my_hash_table.Emplace(1, cell);
    if (inserted)
    {
        std::cout << cell->GetKey() << "\n";
    }
    my_hash_table.Emplace(2, cell);
    my_hash_table.Emplace(3, cell);
    my_hash_table.Emplace(4, cell);

    cell = my_hash_table.Lookup(3);
    std::cout << "3 = 3 ? : " << (cell->GetKey() == 3) << "\n";

    bool erased = my_hash_table.Erase(3);
    std::cout << "erase ? : " << erased << "\n";

    cell = my_hash_table.Lookup(3);
    std::cout << "cell is null? ? : " << (cell == nullptr) << "\n";

    using StringHashSet = StringHashTable;
    StringHashSet my_hash_set;
    std::string name = "hello world";
    StringHashSet::result_type result;
    inserted = my_hash_set.Emplace(duckdb::string_t(name.c_str(), name.size()), result);
    if (inserted)
    {
        std::cout << "inserted ? : " << inserted << "\n";
    }
    std::string apple = "Apple";
    inserted = my_hash_set.Emplace(duckdb::string_t(apple.c_str(), apple.size()), result);
    if (inserted)
    {
        std::cout << "inserted ? : " << inserted << "\n";
    }

    std::cout << "size = 2 ? : " << (my_hash_set.Size() == 2) << "\n";
    std::cout << "print size : " << my_hash_set.PrintSize() << "\n";

    result = my_hash_set.Lookup(duckdb::string_t(name.c_str(), name.size()));
    if (result)
    {
        std::cout << "result key = " << result->GetKey().GetString() << "\n";
    }
    return 0;
}