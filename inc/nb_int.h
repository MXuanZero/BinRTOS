#ifndef NB_INT_H
#define NB_INT_H

typedef signed char s8_t;
typedef unsigned char u8_t;
typedef short s16_t;
typedef unsigned short u16_t;
typedef int s32_t;
typedef unsigned u32_t;
typedef long long s64_t;
typedef unsigned long long u64_t;

typedef s32_t ssize_t;
typedef u32_t size_t;


#define NB_S8_MIN (-128)
#define NB_S16_MIN (-32768)
#define NB_S32_MIN (-2147483647 - 1)
#define NB_S64_MIN (-9223372036854775807LL - 1)

#define NB_S8_MAX 127
#define NB_S16_MAX 32767
#define NB_S32_MAX 2147483647
#define NB_S64_MAX 9223372036854775807LL

#define NB_U8_MAX 0xffU /* 255U */
#define NB_U16_MAX 0xffffU /* 65535U */
#define NB_U32_MAX 0xffffffffUL /* 4294967295U */
#define NB_U64_MAX 0xffffffffffffffffULL /* 18446744073709551615ULL */

#endif // NB_INT_H
