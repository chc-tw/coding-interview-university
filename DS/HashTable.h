#ifndef HASHTABLE_H_
#define HASHTABLE_H_
// It's the chaining version of HASHTABLE 

#include <vector>
#include <list>
#include <functional>
#include "HashNode.h"

template<typename K, typename V>
class HashTable {
private:

    std::vector<std::list<HashNode<K,V>>> buckets;
    size_t size;
    static const size_t INI_CAP = 4;
    static constexpr float load_factor = 0.75f;

public:
    HashTable() : buckets(INI_CAP), size(0) {}
    ~HashTable() {}

    size_t hash(const K& key) const {
        return std::hash<K>()(key) % buckets.size();
    }

    void resize(size_t new_size) {
        std::vector<std::list<HashNode<K,V>>> new_buckets(new_size);
        for (auto &bucket : buckets) {
            for (auto &slut : bucket) {
                std::size_t new_ind = std::hash<K>()(slut.key) % new_size;
                new_buckets[new_ind].push_back(slut);
            }
        }
        buckets = std::move(new_buckets);
    }

    void set(K key, V value) {
        std::list<HashNode<K,V>>& bucket = buckets[hash(key)];
        for (auto &node : bucket) {
            if (node.key == key) {
                node.value = value;
                return;
            }
        }
        bucket.emplace_back(HashNode<K,V>{key, value});
        ++size;

        if (size >= buckets.size() * load_factor) {
            resize(buckets.size() * 2);
        }
    }

    void remove(K key) {
        std::list<HashNode<K,V>>& bucket = buckets[hash(key)];
        size_t initial_size = bucket.size();
        bucket.remove_if([key](const HashNode<K,V>& node) { return node.key == key; });
        size_t removed = initial_size - bucket.size();

        size -= removed;
        if (size <= buckets.size() / 8) {
            resize(buckets.size() / 2);
        }
    }

    V get(K key) {
        std::list<HashNode<K,V>>& bucket = buckets[hash(key)];
        for (auto &node : bucket) {
            if (node.key == key) {
                return node.value;
            }
        }
        throw std::runtime_error("Key not found");
    }

    std::list<K> keys() const {
        std::list<K> key_list;
        for (auto &bucket : buckets) {
            for (auto &node : bucket) {
                key_list.push_back(node.key);
            }
        }
        return key_list;
    }
};

#endif