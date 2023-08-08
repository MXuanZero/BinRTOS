#ifndef NB_CLOCK_H
#define NB_CLOCK_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

/* Define --------------------------------------------------------------------*/
/* Exported macro ------------------------------------------------------------*/
/**
 * @brief ���ر�ͷ
 */
#define nb_list_get_head(l) ((l) != NULL ? (l)->head : NULL)

/**
 * @brief ���ر�β
 */
#define nb_list_get_tail(l) ((l) != NULL ? (l)->tail : NULL)

/**
 * @brief ˳���������
 * @param l ����
 * @param n �ڵ�
 */
#define nb_list_for_each(l, n) \
	for ((n) = nb_list_get_head(l); (n) != NULL; (n) = (n)->next)

/**
 * @brief ˳��ȫ�����������������������Ҫɾ�������ʹ�øú�
 * @param l ����
 * @param n �ڵ�
 * @param b ����ڵ�
 */
#define nb_list_for_each_safe(l, n, b)              \
	for ((n) = nb_list_get_head((l)),           \
	    (b) = ((n) != NULL ? (n)->next : NULL); \
	     (n) != NULL; (n) = (b), (b) = ((n) != NULL ? (n)->next : NULL))

/**
 * @brief �����������
 * @param l ����
 * @param n �ڵ�
 */
#define nb_list_for_each_prev(l, n) \
	for ((n) = nb_list_get_tail(l); (n) != NULL; (n) = (n)->prev)

/**
 * @brief ����ȫ�����������������������Ҫɾ�������ʹ�øú�
 * @param l ����
 * @param n �ڵ�
 * @param b ����ڵ�
 */
#define nb_list_for_each_prev_safe(l, n, b)         \
	for ((n) = nb_list_get_tail((l)),           \
	    (b) = ((n) != NULL ? (n)->next : NULL); \
	     (n) != NULL; (n) = (b), (b) = ((n) != NULL ? (n)->next : NULL))

/* Exported types ------------------------------------------------------------*/
typedef struct nb_note_t nb_node_t;

typedef struct nb_note_t {
	struct nb_note_t *next;
	struct nb_note_t *prev;
} nb_node_t;

typedef struct nb_list_t {
	nb_node_t *head;
	nb_node_t *tail;
	size_t size;
} nb_list_t;

/* Exported constants --------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */

/**
 * ��ʼ������
 */
void nb_list_init(nb_list_t *list, size_t size);

/**
 * ����±�ͷ�������±�ͷ�ĵ�ַ
 */
void nb_list_inc_head(nb_list_t *list, nb_node_t *new_node);

/**
 * ����±�β�����ر�β��ַ
 */
void nb_list_inc_tail(nb_list_t *list, nb_node_t *new_node);

/**
 * @brief ��ָ��������ָ���ڵ�������½ڵ�
 */
void nb_list_inc_next(nb_list_t *list, nb_node_t *node, nb_node_t *new_node);

/**
 * @brief ��ָ��������ָ���ڵ�ǰ�����½ڵ�
 */
void nb_list_inc_prev(nb_list_t *list, nb_node_t *node, nb_node_t *new_node);

/**
 * ɾ���ýڵ�
 */
void nb_list_delete(nb_list_t *list, nb_node_t *node);

/**
 * ��һ���ڵ��ƶ���������
 * @param olist �ڵ����ڵ�����
 * @param nlist �µ�����
 * @param node  �ڵ�
 * @param head true: be the head in the nlist list
 *             false be the tail in the nlist list
 */
void nb_list_change_node(nb_list_t *olist, nb_list_t *nlist, nb_node_t *node,
			 bool head);

/**
 * ��һ���ڵ��ƶ���ͬһ�������е���һ���ڵ�֮ǰ
 * @param n_act Ҫ�ƶ��Ľڵ�
 * @param node_addr Ŀ��λ��
 * @param before �ƶ����ýڵ�ǰ
 */
void nb_list_move_node(nb_list_t *list, nb_node_t *act, nb_node_t *node,
		       bool before);

/**
 * ������������ĳ���
 */
size_t nb_list_get_len(const nb_list_t *list);

/**
 * ��������Ƿ�Ϊ��
 */
bool lib_list_is_empty(nb_list_t *list);

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif // NB_CLOCK_H
