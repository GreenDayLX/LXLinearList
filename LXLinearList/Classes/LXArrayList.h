//
//  LXArrayList.h
//  LXLinearList
//
//  Created by wenglx on 2017/3/3.
//  数组

#ifndef LXArrayList_h
#define LXArrayList_h

extern int const LXArrayListNotFound;

#ifndef LXArrayListDefined
typedef void LXArrayList;
typedef void *LXArrayListValue;
#endif

/** 创建数组 */
LXArrayList *lx_arrayList_create(int capacity);

/** 清空数组 */
void lx_arrayList_clear(LXArrayList *list);

/** 销毁数组 */
void lx_arrayList_destroy(LXArrayList *list);

/** 数组长度 */
int lx_arrayList_length(LXArrayList *list);

/** 数组容量 */
int lx_arrayList_capacity(LXArrayList *list);

/** 添加元素 */
void lx_arrayList_add(LXArrayList *list, LXArrayListValue value);
void lx_arrayList_insert(LXArrayList *list, LXArrayListValue value, int index);
void lx_arrayList_set(LXArrayList *list, LXArrayListValue value, int index);

/** 移除元素 */
void lx_arrayList_remove(LXArrayList *list, int index);
void lx_arrayList_remove_value(LXArrayList *list, LXArrayListValue value);

/** 检索元素 */
int lx_arrayList_index(LXArrayList *list, LXArrayListValue value);
LXArrayListValue lx_arrayList_get(LXArrayList *list, int index);

#endif /* LXArrayList_h */
