//
//  LXLinkedList.h
//  LXLinearList
//
//  Created by wenglx on 2017/3/3.
//  单向链表

#include <stdlib.h>

#pragma mark - 数据结构定义
// 严格顺序 - 01
#define LXLinkedListDefined
// 严格顺序 - 02
typedef void *LXLinkedListValue;

typedef struct _LXLinkedListNode LXLinkedListNode;
struct _LXLinkedListNode {
    LXLinkedListValue value; // 节点里面存储的值
    LXLinkedListNode *next; // 下一个节点
};

typedef struct {
    int length; // 元素的数量
    LXLinkedListNode *header; // 头结点
} LXLinkedList;
// 严格顺序 - 03
#include "LXLinkedList.h"

#pragma mark - 常量
int const LXLinkedListNotFound = -1;

/** 创建链表 */
LXLinkedList *lx_linkedList_create(void)
{
    LXLinkedList *list = malloc(sizeof(LXLinkedList));
    if (list) {
        list->length = 0;
        list->header = malloc(sizeof(LXLinkedListNode));
    }
    return list;
}

/** 清空链表 */
void lx_linkedList_clear(LXLinkedList *list)
{
    if (list == NULL) return;
    for (int i = 0; i < list->length; i++) {
        LXLinkedListNode *nextNode = list->header->next;
        // 让头结点指向nextNode的下一个节点
        list->header->next = nextNode->next;
        // 销毁nextNode
        free(nextNode);
    }
    list->length = 0;
}

/** 销毁链表 */
void lx_linkedList_destroy(LXLinkedList *list)
{
    if (list == NULL) return;
    // 清空节点
    lx_linkedList_clear(list);
    // 销毁头结点
    if (list->header) free(list->header);
    // 销毁链表
    free(list);
}

/** 链表长度 */
int lx_linkedList_length(LXLinkedList *list)
{
    if (list == NULL) return 0;
    return list->length;
}

/** 添加元素 */
void lx_linkedList_add(LXLinkedList *list, LXLinkedListValue value)
{
    lx_linkedList_insert(list, value, list->length);
}

void lx_linkedList_insert(LXLinkedList *list, LXLinkedListValue value, int index)
{
    if (list == NULL || index < 0 || index > list->length) return;
    // 找到index - 1位置的node
    LXLinkedListNode *node = list->header;
    for (int i = 0; i < index; i++) {
        node = node->next;
    }
    // 分配内存给新节点
    LXLinkedListNode *newNode = malloc(sizeof(LXLinkedListNode));
    newNode->value = value;
    newNode->next = node->next;
    node->next = newNode;
    // 增加数量
    list->length++;
}

void lx_linkedList_set(LXLinkedList *list, LXLinkedListValue value, int index)
{
    if (list == NULL || index < 0 || index >= list->length) return;
    // 找到index位置的node
    LXLinkedListNode *node = list->header;
    for (int i = 0; i < index + 1; i++) {
        node = node->next;
    }
    node->value = value;
}

/** 移除元素 */
void lx_linkedList_remove(LXLinkedList *list, int index)
{
    if (list == NULL || index < 0 || index >= list->length) return;
    // 找到index - 1位置的node
    LXLinkedListNode *node = list->header;
    for (int i = 0; i < index; i++) {
        node = node->next;
    }
    // 需要删除的节点
    LXLinkedListNode *removeNode = node->next;
    // 设置next
    node->next = removeNode->next;
    // 销毁节点
    free(removeNode);
    // 数量减少
    list->length--;
}

void lx_linkedList_remove_value(LXLinkedList *list, LXLinkedListValue value)
{
    if (list == NULL) return;
    LXLinkedListNode *node = list->header;
    while (node) {
        // 拿到下一个节点
        LXLinkedListNode *nextNode = node->next;
        if (nextNode == NULL) return;
        // 判断值
        if (nextNode->value == value) { // 删除nextNode
            node->next = nextNode->next;
            free(nextNode);
            list->length--;
        } else { // 不用删除nextNode
            node = nextNode;
        }
    }
}

/** 检索元素 */
int lx_linkedList_index(LXLinkedList *list, LXLinkedListValue value)
{
    if (list == NULL) return LXLinkedListNotFound;
    // 找到符合要求的节点位置
    LXLinkedListNode *node = list->header;
    for (int i = 0; i < list->length; i++) {
        node = node->next;
        if (node->value == value) return i;
    }
    return LXLinkedListNotFound;
}

LXLinkedListValue lx_linkedList_get(LXLinkedList *list, int index)
{
    if (list == NULL || index < 0 || index >= list->length) return NULL;
    // 找到index位置的node
    LXLinkedListNode *node = list->header;
    for (int i = 0; i < index + 1; i++) {
        node = node->next;
    }
    return node->value;
}
