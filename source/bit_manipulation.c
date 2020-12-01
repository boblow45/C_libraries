#include <stdint.h>
#include "bit_manipulation.h"

uint32_t git_bits(uint32_t data, uint32_t str, uint32_t num_bits){
    return (data >> str) & ((1<<num_bits)-1);
}

uint32_t set_bits(uint32_t x, uint32_t str, uint32_t num_bits, uint32_t y){    
    return (x & ~(((1 << num_bits) - 1) << str)) | (y << str); 
}

