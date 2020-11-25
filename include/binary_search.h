#ifndef __BIN_SEARCH__
#define __BIN_SEARCH__

#include <stdint.h>

/**
 * @brief   Returns the index of the value of interest. Will return -1 if the value is not in the input array
 *          Note, the data passed to this function needs to be sorted before it is called        
 *  
 * 
 * @param data  Sorted data to search for value of interest <x>
 * @param l     Index to start looking at. Should zero to start a the beginning of the data set
 * @param r     N-1 to search the whole data set
 * @param x     Value to look for in the data set
 * 
 * @return int32_t 
 */
int32_t binary_search(uint32_t* data, uint32_t l, uint32_t r, uint32_t x);

#endif // __BIN_SEARCH__