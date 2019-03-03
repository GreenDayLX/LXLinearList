//
//  LXArrayList.c
//  LXLinearList
//
//  Created by wenglx on 2017/3/3.
//  数组

#include <stdio.h>
#include <stdlib.h>

#pragma mark - 数据结构定义
// 严格顺序 - 01
#define LXArrayListDefined
// 严格顺序 - 02
typedef void * LXArrayListValue;
typedef struct {
    int capacity; // 最大容量
    int length; // 元素的数量(数组的长度)
    LXArrayListValue *values; // 元素
} LXArrayList;
// 严格顺序 - 03
#include "LXArrayList.h"

#pragma mark - 常量
int const LXArrayListNotFound = -1;
int const LXArrayListDefaultCapacity = 2;

#pragma mark - 私有函数
void lx_arrayList_ensure_capacity(LXArrayList *list)
{
    if (list == NULL) return;
    // 设置新容量
    if (list->length == list->capacity) { // 容量不够用了, 增加容量
        list->capacity *= 2;
    } else if (list->length < list->capacity / 4) { // 元素数量减少到一定程度, 缩减容量
        list->capacity /= 2;
    } else {
        return;
    }
    // 开辟一块新空间
    LXArrayListValue *newValues = malloc(sizeof(LXArrayListValue) * list->capacity);
    // 拷贝元素到新空间(list->values 拷贝到 newValues)
    for (int i = 0; i < list->length; i++) {
        newValues[i] = list->values[i];
    }
    // 释放旧空间
    free(list->values);
    // 赋值新空间
    list->values = newValues;
}

#pragma mark - 数组
/** 创建数组 */
LXArrayList *lx_arrayList_create(int capacity)
{
    LXArrayList *list = malloc(sizeof(LXArrayList));
    if (list) {
        list->capacity = (capacity > LXArrayListDefaultCapacity) ? capacity : LXArrayListDefaultCapacity;
        list->length = 0;
        list->values = malloc(sizeof(LXArrayListValue) * list->capacity);
    }
    return list;
}

/** 清空数组 */
void lx_arrayList_clear(LXArrayList *list)
{
    if (list == NULL) return;
    list->length = 0;
}

/** 销毁数组 */
void lx_arrayList_destroy(LXArrayList *list)
{
    if (list == NULL) return;
    // 释放元素
    if (list->values) {
        free(list->values);
    }
    // 释放数组
    free(list);
}

/** 数组长度 */
int lx_arrayList_length(LXArrayList *list)
{
    if (list == NULL) return 0;
    return list->length;
}

/** 数组容量 */
int lx_arrayList_capacity(LXArrayList *list)
{
    if (list == NULL) return 0;
    return list->capacity;
}

#pragma mark - 元素
/** 添加元素 */
void lx_arrayList_add(LXArrayList *list, LXArrayListValue value)
{
    lx_arrayList_insert(list, value, list->length);
}

void lx_arrayList_insert(LXArrayList *list, LXArrayListValue value, int index)
{
    // 时间复杂度:O(n)
    // 这里的index可以等于list->length
    if (list == NULL || index < 0 || index > list->length) return;
    // 保证容量
    lx_arrayList_ensure_capacity(list);
    // 将index位置以及后面的所有元素, 往后移动
    for (int i = list->length - 1; i >= index; i--) {
        list->values[i + 1] = list->values[i];
    }
    // 覆盖index位置的数据
    list->values[index] = value;
    // 数量增加
    list->length++;
}

void lx_arrayList_set(LXArrayList *list, LXArrayListValue value, int index)
{
    // 时间复杂度:O(1)
    if (list == NULL || index < 0 || index >= list->length) return;
    list->values[index] = value;
}

/** 移除元素 */
void lx_arrayList_remove(LXArrayList *list, int index)
{
    // 时间复杂度:O(n)
    if (list == NULL || index < 0 || index >= list->length) return;
    // 将index后面的数据往前移动
    for (int i = index + 1; i < list->length; i++) {
        list->values[i - 1] = list->values[i];
    }
    // 数量减少
    list->length--;
    // 容量检测
    lx_arrayList_ensure_capacity(list);
}

void lx_arrayList_remove_value(LXArrayList *list, LXArrayListValue value)
{
    // 时间复杂度:O(n)
    if (list == NULL) return;
    // 元素操作
    int valueCount = 0;
    for (int i = 0; i < list->length; i++) {
        if (list->values[i] == value) { // 找到value
            valueCount++;
        } else { // 如果不是value, 往前移动valueCount个位置
            list->values[i - valueCount] = list->values[i];
        }
    }
    // 数量减少
    list->length -= valueCount;
    // 容量检测
    lx_arrayList_ensure_capacity(list);
}

/** 检索元素 */
int lx_arrayList_index(LXArrayList *list, LXArrayListValue value)
{
    // 时间复杂度:O(n)
    if (list == NULL) return LXArrayListNotFound;
    for (int i = 0; i < list->length; i++) {
        if (list->values[i] == value) return i;
    }
    return LXArrayListNotFound;
}

LXArrayListValue lx_arrayList_get(LXArrayList *list, int index)
{
    // 时间复杂度:O(1)
    if (list == NULL || index < 0 || index >= list->length) return 0;
    // list->values[index]等价于*(list->values + index);
    return list->values[index];
}
