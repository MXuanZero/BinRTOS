/* Includes ------------------------------------------------------------------*/
#include <string.h>
#include "nb_list.h"

/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private typedef -----------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

void nb_list_init(nb_list_t *list, size_t size)
{
	if (list == NULL) {
		return;
	}
	list->head = NULL;
	list->tail = NULL;
	// size       = (size + 3) & (~0x3);
	list->size = size;
}

void nb_list_inc_head(nb_list_t *list, nb_node_t *new_node)
{
	if (list == NULL || new_node == NULL) {
		return;
	}
	nb_node_t *head = list->head;
	new_node->prev = NULL;
	new_node->next = head;

	if (head != NULL) {
		head->prev = new_node;
	}
	list->head = new_node;
	if (list->tail == NULL) {
		list->tail = new_node;
	}
}

void nb_list_inc_tail(nb_list_t *list, nb_node_t *new_node)
{
	if (list == NULL || new_node == NULL) {
		return;
	}

	nb_node_t *tail = list->tail;

	new_node->prev = tail;
	new_node->next = NULL;

	if (tail != NULL) {
		tail->next = new_node;
	}
	list->tail = new_node;

	if (list->head == NULL) {
		list->head = new_node;
	}
}

void nb_list_inc_next(nb_list_t *list, nb_node_t *node, nb_node_t *new_node)
{
	if (list == NULL || node == NULL || new_node == NULL) {
		return;
	}

	nb_node_t *buf = NULL;
	buf = node->next;
	node->next = new_node;
	new_node->next = buf;
	if (buf != NULL) {
		buf->prev = new_node;
	} else {
		list->tail = new_node;
	}
	new_node->prev = node;
}

void nb_list_inc_prev(nb_list_t *list, nb_node_t *node, nb_node_t *new_node)
{
	if (list == NULL || node == NULL || new_node == NULL) {
		return;
	}
	nb_node_t *buf = node->prev;
	node->prev = new_node;
	new_node->prev = buf;
	if (buf != NULL) {
		buf->next = new_node;
	} else {
		list->head = new_node;
	}
	new_node->next = node;
}

void nb_list_delete(nb_list_t *list, nb_node_t *node)
{
	if (list == NULL || node == NULL) {
		return;
	}
	if (node->next == NULL && node->prev == NULL) {
		list->head = NULL;
		list->tail = NULL;
	} else if (node->next == NULL) {
		node->prev->next = NULL;
		list->tail = node->prev;
		node->prev = NULL;
	} else if (node->prev == NULL) {
		node->next->prev = NULL;
		list->head = node->next;
		node->next = NULL;
	} else {
		node->next->prev = node->prev;
		node->prev->next = node->next;
		node->next = NULL;
		node->prev = NULL;
	}
}

void nb_list_change_node(nb_list_t *olist, nb_list_t *nlist, nb_node_t *node,
			 bool head)
{
	if (olist == NULL || nlist == NULL || node == NULL) {
		return;
	}
	nb_list_delete(olist, node); // �Ͽ��ڵ�����
	if (head) {
		nb_node_t *head_node = nlist->head;
		node->prev = NULL;
		node->next = head_node;
		if (head_node != NULL) {
			head_node->prev = node;
		}
		nlist->head = node;
		if (nlist->tail == NULL) {
			nlist->tail = node;
		}
	} else {
		nb_node_t *tail_node = nlist->tail;
		node->prev = tail_node;
		node->next = NULL;
		if (tail_node != NULL) {
			tail_node->next = node;
		}
		nlist->tail = node;
		if (nlist->head == NULL) {
			nlist->head = node;
		}
	}
}

void nb_list_move_node(nb_list_t *list, nb_node_t *act, nb_node_t *node,
		       bool before)
{
	if (list == NULL || act == NULL || node == NULL) {
		return;
	}
	nb_list_delete(list, act); // �Ͽ��ڵ�����

	/* �����µĽڵ� */
	if (node->next == NULL && node->prev == NULL) {
		return; // �������������Ϊ����
	}
	if (before) {
		if (node->prev == NULL) {
			act->next = node;
			node->prev = act;
			list->head = act;
		} else {
			node->prev->next = act;
			act->prev = node->prev;
			node->prev = act;
			act->next = node;
		}
	} else {
		if (node->next == NULL) {
			act->prev = node;
			node->next = act;
			list->head = act;
		} else {
			node->next->prev = act;
			act->next = node->next;
			node->next = act;
			act->prev = node;
		}
	}
}

size_t nb_list_get_len(const nb_list_t *list)
{
	if (list == NULL)
		return 0;

	nb_node_t *node = list->head;
	size_t len = 0;
	while (node != NULL) {
		node = node->next;
		++len;
	}
	return len;
}

inline bool lib_list_is_empty(nb_list_t *list)
{
	if (list == NULL) {
		return false;
	}
	if (list->head == NULL && list->tail == NULL) {
		return true;
	}
	return false;
}
