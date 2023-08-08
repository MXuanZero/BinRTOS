#ifndef NB_DEF_H
#define NB_DEF_H

/**
 * @brief version
 */
#define NB_VERSION_MAJOR 0
#define NB_VERSION_MINOR 0
#define NB_VERSION_PATCH 1

/**
 * @brief Gets the address offset of the variable in the structure.
 */
#define nb_addr_offset(type, member) ((size_t) & ((type *)0)->member)

/**
 * @brief Gets the starting address of the structure
 * @param i item
 * @param t type
 * @param m member
 */
#define nb_container_addr(i, t, m) ((t *)((char *)(i)-nb_addr_offset(t, m)))

/**
 * @brief Returns the number of arrays
 */
#define NB_ARRAY_SIZE(x) (sizeof(x) / sizeof((x)[0]))





#define nb_bit_read(value, bit) (((value) >> (bit)) & 0x01)
#define nb_bit_set(value, bit) ((value) |= (1UL << (bit)))
#define nb_bit_clear(value, bit) ((value) &= ~(1UL << (bit)))
#define nb_bit_toggle(value, bit) ((value) ^= (1UL << (bit)))
#define nb_bit_write(value, bit, bitvalue) \
	((bitvalue) ? nb_bit_set(value, bit) : nb_bit_clear(value, bit))

#endif //NB_DEF_H
