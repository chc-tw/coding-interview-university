# ifndef HASHNODE_H_
# define HASHNODE_H_

template <typename K, typename V>
struct HashNode{
    K key;
    V value;
    HashNode(K key, V value) : key(key), value(value){}
};
# endif 