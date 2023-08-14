/* Includes ------------------------------------------------------------------*/
#include "nb_cfg.h"
#include "nb_mem.h"
#if NB_MEM_ALGORITHM == NB_MEM_TLST
#include "nb_tlsf.h"

#endif

/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private typedef -----------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
static NB_MEM_UINT nb_mem_poor[NB_MEM_POOL_SIZE / sizeof(NB_MEM_UINT)];
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

void nb_mem_init(void)
{
	tlsf_create_with_pool((void *)nb_mem_poor, NB_MEM_POOL_SIZE);
}

void *nb_malloc(size_t size)
{
	return tlsf_malloc(nb_mem_poor, size);
}

void *nb_realloc(void *ptr, size_t size)
{
	return tlsf_realloc(nb_mem_poor, ptr, size);
}

void *nb_calloc(size_t size)
{
	void *ptr = tlsf_malloc(nb_mem_poor, size);
	if (ptr != NULL) {
		nb_mem_set(ptr, 0, size);
	}
	return ptr;
}

void nb_free(void *ptr)
{
	tlsf_free(nb_mem_poor, ptr);
}

void nb_mem_cpy(void *dst, const void *restrict src, size_t len)
{
	u8_t *d = dst;
	const u8_t *s = src;
	while (len--) {
		*d++ = *s++;
	}
}

void nb_mem_set(void *dst, u8_t v, size_t len)
{
	u8_t *ret = dst;
	while (len--) {
		*ret++ = v;
	}
}
