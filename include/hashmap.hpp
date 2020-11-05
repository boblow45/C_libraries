#ifndef __HASHMAP__
#define __HASHMAP__

#include <cstdint>

template <typename K, typename V>

class HashNode {
public:
	V value;
	K key;

	HashNode(K key, V value) {
		this->value = value;
		this->key = key;
	}
};

template <typename K, typename V>

class HashMap {
public:
	HashMap();
	void insertNode(K key, V value);
	V deleteNode(K key);
	V get(K key);
	uint32_t getSize(void);
	bool isEmpty(void);

private:
	uint32_t capacity;
	uint32_t size;
	HashNode<K, V>* dummy;
	HashNode<K, V>** table;

	uint32_t hashCode(K key);
};

#include "../source/hashmap.cpp"
#endif // __HASHMAP__