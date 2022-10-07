//
// Created by Administrator on 2022/10/7 0007.
//
#include "b_ree.h"
#include <stdio.h>
#include <stdlib.h>
BTree *init_b_tree(){
    BTree *bt = (BTree *) malloc(sizeof(BTree));
    //bt->len = 0;
    bt->root = NULL;
    return bt;
}

Node *create_node(int data){
    Node *n = (Node *) malloc(sizeof(Node));
    n->val = data;
    n->l_child = NULL;
    n->r_child = NULL;
    return n;
}

Node *insert_node(Node *n, int val){
    if(n == NULL){
        return create_node(val);
    }
    if(n->val == val) {
        printf("Node had excited!\n");
        return n;
    }
    if(n->val < val){
        // 插入到节点右子树部分
        n->r_child = insert_node(n->r_child, val);
    }else{
        // 插入到节点左子树部分
        n->l_child = insert_node(n->l_child, val);
    }
    return n;
}
Node *delete_node(Node *n, int val){
    return n;
}

int find_node(Node *n, int val){
    if(n == NULL) return 0;
    if(n->val == val) return 1;
    if(n->val > val) {
        return find_node(n->l_child, val);
    }
    return find_node(n->r_child, val);
}
void pre_get_node(Node *n){
    if(n == NULL){
        printf("NULL ");
        return;
    }
    printf("%d ", n->val);
    pre_get_node(n->l_child);
    pre_get_node(n->r_child);
    return;
}

void mid_get_node(Node *n){
    if(n == NULL){
        printf("NULL ");
        return;
    }
    pre_get_node(n->l_child);
    printf("%d ", n->val);
    pre_get_node(n->r_child);
    return;
}

void post_get_node(Node *n){
    if(n == NULL){
        printf("NULL ");
        return;
    }

    pre_get_node(n->l_child);
    pre_get_node(n->r_child);
    printf("%d ", n->val);
    return;
}

void pre_in_order(Node *n){
    if(n == NULL) return;
    printf("Pre_in_order: ");
    pre_get_node(n);
    return;
}
void mid_in_order(Node *n){
    if(n == NULL) return;
    printf("mid_in_order: ");
    mid_get_node(n);
    return;
}
void post_in_order(Node *n){
    if(n == NULL) return;
    printf("Post_in_order: ");
    post_get_node(n);
    return;
}
void free_node(Node *n){
    if(n == NULL) return;
    free_node(n->l_child);
    free_node(n->r_child);
    free(n);
    return;
}
void free_tree(BTree *n){
    if(n == NULL) return;
    free_node(n->root);
    free(n);
    return;
}