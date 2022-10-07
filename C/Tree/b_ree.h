//
// Created by Administrator on 2022/10/7 0007.
//

#ifndef _B_REE_H
#define _B_REE_H

// 树：除了根节点外， 每个节点都只有一个前驱
// 这里主要以二叉树顺序存储结构为例： 任何一颗树， 左子树的元素小于节点元素， 右子树元素大于节点元素 （左小右大）
// 数据结构 = 结构定义 + 结构操作
// 二叉树结构定义： |  值域  |  左孩子  |  右孩子  |
// 二叉树结构操作：
// 1. 创建二叉树
// 2. 创建节点
// 3. 节点插入
// 4. 节点删除
// 5. 节点查找
// 6. 二叉树遍历
// 7. 二叉树回收


typedef struct NODE{
    int val;
    struct NODE *l_child, *r_child;
}Node;

typedef struct BTREE{
    //int len;
    Node *root; // 指向二叉树根节点
}BTree;

BTree *init_b_tree();
Node *create_node(int data);
Node *insert_node(Node *n, int val);
Node *delete_node(Node *n, int val);
int find_node(Node *n, int val);
void pre_in_order(Node *n);
void mid_in_order(Node *n);
void post_in_order(Node *n);
void free_node(Node *n);
void free_tree(BTree *n);
#endif //_B_REE_H
