#ifndef NB_CFG_H
#define NB_CFG_H

/**
 * @brief 内存分配算法选择
 */
#define NB_MEM_TLST 1
#define NB_MEM_ALGORITHM NB_MEM_TLST

#if NB_MEM_ALGORITHM == NB_MEM_TLST

#define NB_MEM_UINT u8_t
#define NB_MEM_POOL_SIZE 256*256 // 总内存大小

#endif /* NB_MEM_ALGORITHM == NB_MEM_TLST */

#endif // NB_CFG_H
