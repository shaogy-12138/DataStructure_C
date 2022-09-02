//
// Created by RB on 30/8/2022.
//
/*
 *  数据结构 = 结构定义 + 结构操作
 *
 *  本文件主要定义的是单链表定义和实现
 *  结构定义：
 *      1. 链表结构定义
 *      2. 链表结点结构定义
 *
 *  结构操作：
 *      1. 创建链表
 *      2. 创建结点
 *      3. 结点插入
 *      4. 结点查询寻
 *      5. 结点删除
 *      6. 链表遍历
 *      7. 结点回收
 *      8. 链表回收
 *      9. 链表合并
 *      10. 链表反转
 *
 *
 * 有两点需要注意：
 *      1. 当插入/删除结点时， 初始结点在此code中： Node *p = &(l->head)， 这样可以从结点的前一个结点开始
 *      2. 遍历/合并/翻转时， 初始结点在此code中: Node *p = l->head.next, 这样可以从第一个结点开始
 */

#ifndef LIST_SIG_H
#define LIST_SIG_H

typedef  struct NODE{
    int val;
    struct NODE *next;
}Node;
typedef struct LIST{
    int len;
    Node head;
}List;

List *create_list();
Node *get_node(int val);
int insert(List *l, int ind, int val);
int search(List *l, int val);
int del_node_ind(List *l, int ind);
int del_node_val(List *l, int val);
void output(List *l);
void merge_list(List *l1, List *l2, List*l);
void re_list(List *l1, List *l);
void free_node(Node *n);
void free_list(List *l);

#endif //铁电_LIST_SIG_H
