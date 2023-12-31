#ifndef NB_MEM_H
#define NB_MEM_H
/* Includes ------------------------------------------------------------------*/
#include "nb_int.h"
/* Define --------------------------------------------------------------------*/
/* Exported macro ------------------------------------------------------------*/
/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/* Exported functions --------------------------------------------------------*/
void nb_mem_init(void);
void *nb_malloc(size_t size);
void *nb_realloc(void *ptr, size_t size);
void nb_free(void *ptr);
// void nb_mem_cpy(void * dst, const void * src, size_t len);
void nb_mem_set(void * dst, u8_t v, size_t len);

#endif // NB_MEM_H
