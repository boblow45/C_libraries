#include <cstdint>
#include <iostream>

template <typename K, typename V>
HashMap<K, V>::HashMap() {
	this->capacity = 20;
	this->size = 0;

	this->table = new HashNode<K, V>*[this->capacity];

	//Initialise all elements of array as NULL
	for(int i = 0; i < this->capacity; i++) {
		this->table[i] = NULL;
	}

	this->dummy = new HashNode<K, V>(-1, -1);
}

template <typename K, typename V>
uint32_t HashMap<K, V>::hashCode(K key) {
	return key % this->capacity;
}

template <typename K, typename V>
void HashMap<K, V>::insertNode(K key, V value) {
	HashNode<K, V>* temp = new HashNode<K, V>(key, value);

	uint32_t hashed_key = this->hashCode(key);

	// Todo: this needs to be changed to a for loop which terminates if it itterates over the whole of the table
	while(this->table[hashed_key] != NULL && this->table[hashed_key]->key != key &&
		  this->table[hashed_key] != this->dummy) {
		hashed_key += 1;
		hashed_key %= this->capacity;
	}

	// // Todo: check for size before adding to table, this might be done in the step before this
	if(this->table[hashed_key] == NULL || this->table[hashed_key] == this->dummy) {
		this->size++;
		this->table[hashed_key] = temp;
	}
}

template <typename K, typename V>
V HashMap<K, V>::deleteNode(K key) {
	uint32_t hashed_key = this->hashCode(key);
	while(this->table[hashed_key] != NULL) {
		if(this->table[hashed_key]->key == key) {
			V val = this->table[hashed_key]->value;
			delete this->table[hashed_key];
			this->table[hashed_key] = this->dummy;

			this->size--;
			return val;
		}
		hashed_key++;
		hashed_key %= this->capacity;
	}

	return NULL;
}

template <typename K, typename V>
V HashMap<K, V>::get(K key) {
	uint32_t hashed_key = this->hashCode(key);

	uint32_t counter = 0;
	while(this->table[hashed_key] != NULL) {
		if(this->table[hashed_key]->key == key) {
			return this->table[hashed_key]->value;
		}

		hashed_key++;
		hashed_key %= this->capacity;

		if(counter++ >= this->capacity) {
			return NULL;
		}
	}

	return NULL;
}

template <typename K, typename V>
uint32_t HashMap<K, V>::getSize() {
	return this->size;
}

template <typename K, typename V>
bool HashMap<K, V>::isEmpty() {
	return this->size == 0;
}
