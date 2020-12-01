#ifndef __BIT_MAN__
#define __BIT_MAN__

#include <stdint.h>

uint32_t git_bits(uint32_t data, uint32_t str, uint32_t num_bits);
uint32_t set_bits(uint32_t x, uint32_t str, uint32_t num_bits, uint32_t y);

#endif // __BIT_MAN__