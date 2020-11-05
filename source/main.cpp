#include <iostream>
#include <iterator> // for iterators
#include <math.h>
#include <vector>

#include "hashmap.hpp"

#define MAX 1000

// Since array is global, it is initialized as 0.
bool has[MAX + 1][2];

bool search(int32_t x) {
	if(x >= 0) {
		if(has[x][0] == 1) {
			return true;
		}
		else {
			return false;
		}
	}
	else {
		x = abs(x);
		if(has[x][1] == 1) {
			return true;
		}
		else {
			return false;
		}
	}
}

void insert(int32_t x) {
	if(x >= 0) {
		has[x][0] = 1;
	}
	else {
		has[abs(x)][1] = 1;
	}
}

int main() {

	std::cout << "Hello World" << std::endl;

	int a[] = {-1, 9, -5, -8, -5, -2};
	uint8_t n = sizeof(a) / sizeof(a[0]);
	for(uint8_t i = 0; i < n; i++) {
		insert(a[i]);
	}

	int X = -5;
	if(search(X) == true)
		std::cout << "Present" << std::endl;
	else
		std::cout << "Not Present" << std::endl;
	return 0;
}