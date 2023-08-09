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
 * @brief 返回表头
 */
#define nb_list_get_head(l) ((l) != NULL ? (l)->head : NULL)

/**
 * @brief 返回表尾
 */
#define nb_list_get_tail(l) ((l) != NULL ? (l)->tail : NULL)

/**
 * @brief 顺序遍历链表
 * @param l 链表
 * @param n 节点
 */
#define nb_list_for_each(l, n) \
	for ((n) = nb_list_get_head(l); (n) != NULL; (n) = (n)->next)

/**
 * @brief 顺序安全遍历链表，如果遍历过程中需要删除链表可使用该宏
 * @param l 链表
 * @param n 节点
 * @param b 缓存节点
 */
#define nb_list_for_each_safe(l, n, b)              \
	for ((n) = nb_list_get_head((l)),           \
	    (b) = ((n) != NULL ? (n)->next : NULL); \
	     (n) != NULL; (n) = (b), (b) = ((n) != NULL ? (n)->next : NULL))

/**
 * @brief 逆序遍历链表
 * @param l 链表
 * @param n 节点
 */
#define nb_list_for_each_prev(l, n) \
	for ((n) = nb_list_get_tail(l); (n) != NULL; (n) = (n)->prev)

/**
 * @brief 逆序安全遍历链表，如果遍历过程中需要删除链表可使用该宏
 * @param l 链表
 * @param n 节点
 * @param b 缓存节点
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
 * 初始化链表
 */
void nb_list_init(nb_list_t *list, size_t size);

/**
 * 添加新表头，返回新表头的地址
 */
void nb_list_inc_head(nb_list_t *list, nb_node_t *new_node);

/**
 * 添加新表尾，返回表尾地址
 */
void nb_list_inc_tail(nb_list_t *list, nb_node_t *new_node);

/**
 * @brief 在指定链表中指定节点后增加新节点
 */
void nb_list_inc_next(nb_list_t *list, nb_node_t *node, nb_node_t *new_node);

/**
 * @brief 在指定链表中指定节点前增加新节点
 */
void nb_list_inc_prev(nb_list_t *list, nb_node_t *node, nb_node_t *new_node);

/**
 * 删除该节点
 */
void nb_list_delete(nb_list_t *list, nb_node_t *node);

/**
 * 将一个节点移动到新链表
 * @param olist 节点所在的链表
 * @param nlist 新的链表
 * @param node  节点
 * @param head true: be the head in the nlist list
 *             false be the tail in the nlist list
 */
void nb_list_change_node(nb_list_t *olist, nb_list_t *nlist, nb_node_t *node,
			 bool head);

/**
 * 将一个节点移动到同一个链表中的另一个节点之前
 * @param n_act 要移动的节点
 * @param node_addr 目标位置
 * @param before 移动到该节点前
 */
void nb_list_move_node(nb_list_t *list, nb_node_t *act, nb_node_t *node,
		       bool before);

/**
 * 返回整个链表的长度
 */
size_t nb_list_get_len(const nb_list_t *list);

/**
 * 检查链表是否为空
 */
bool lib_list_is_empty(nb_list_t *list);

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif // NB_CLOCK_H
