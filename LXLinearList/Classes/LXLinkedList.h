//
//  LXLinkedList.h
//  LXLinearList
//
//  Created by wenglx on 2017/3/3.
//  单向链表

#ifndef LXLinkedList_h
#define LXLinkedList_h

extern int const LXLinkedListNotFound;

#ifndef LXLinkedListDefined
typedef void LXLinkedList;
typedef void *LXLinkedListValue;
#endif

/** 创建链表 */
LXLinkedList *lx_linkedList_create(void);

/** 清空链表 */
void lx_linkedList_clear(LXLinkedList *list);

/** 销毁链表 */
void lx_linkedList_destroy(LXLinkedList *list);

/** 链表长度 */
int lx_linkedList_length(LXLinkedList *list);

/** 添加元素 */
void lx_linkedList_add(LXLinkedList *list, LXLinkedListValue value);
void lx_linkedList_insert(LXLinkedList *list, LXLinkedListValue value, int index);
void lx_linkedList_set(LXLinkedList *list, LXLinkedListValue value, int index);

/** 移除元素 */
void lx_linkedList_remove(LXLinkedList *list, int index);
void lx_linkedList_remove_value(LXLinkedList *list, LXLinkedListValue value);

/** 检索元素 */
int lx_linkedList_index(LXLinkedList *list, LXLinkedListValue value);
LXLinkedListValue lx_linkedList_get(LXLinkedList *list, int index);

#endif /* LXLinkedList_h */
