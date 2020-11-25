#ifndef __SORTING_ALG__
#define __SORTING_ALG__

#include <stdint.h>

void quick_sort(int32_t base[], uint32_t low, uint32_t high);
void merge_sort(int32_t base[], uint32_t low, uint32_t high);
void quickSort(
	void* data, uint32_t n_ele, uint32_t size, int32_t (*compr)(const void*, const void*));

#endif // __SORTING_ALG__