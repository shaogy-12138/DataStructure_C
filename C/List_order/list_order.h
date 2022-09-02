//
// Created by RB on 1/9/2022.
//


/*
 *  此 code 是针对顺序表的实现
 *
 *  顺序表可以理解称为更高级的数组，其拥有和数组一样的性质， 可以进行下标访问， 插入， 删除，等等
 *  与数组的区别就是可以进行扩容。
 *
 *  数组就不使用code展示。
 *
 *  数据结构 = 结构定义 + 结构操作
 *
 *  结构定义： 定义列表
 *
 *  结构操作：
 *      1. 创建列表
 *      2. 插入元素
 *      3. 删除元素
 *      4. 列表扩容
 *      5. 查找元素
 *      6. 销毁列表
 *      7. 追加元素
 *      8. 遍历列表
 */
#ifndef LIST_ORDER_H
#define LIST_ORDER_H

typedef struct LIST_ORDER{
    int* data;
    int len, size;
}ListOr;

ListOr *create(int l);
int insert(ListOr *l, int ind, int val);
ListOr *erase_ind(ListOr *l, int ind);
ListOr *erase_val(ListOr *l, int ind);
int get_ind(ListOr *l, int val);
int append(ListOr *l, int val);
int is_full(ListOr *l);
int is_empty(ListOr *l);
int extend(ListOr *old_l, int len);
int find(ListOr *l, int val);
void output_list_order(ListOr *l);
void free_list_order(ListOr *l);

#endif //LIST_ORDER_H
