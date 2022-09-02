//
// Created by RB on 30/8/2022.
//
#include "list_sig.h"
#include <stdio.h>
#include <stdlib.h>

List *create_list(){
    List *l = (List *)malloc(sizeof (List));
    l->len = 0;
    l->head.next = NULL;
    return l;
}


Node *get_node(int val) {
    Node *n = (Node *) malloc(sizeof (Node));
    n->val = val;
    n->next = NULL;
    return n;
}


int insert(List *l, int ind, int val){
    if(l == NULL) return 0;
    if(ind < 0 || ind > l->len) return 0;

    // 遍历链表, list指向待插入位置的前一个元素
    // 例： 插入第0个位置， 则p 指向head， p->next为第0个元素
    Node *p = &(l->head);
    while(ind--){
        p = p->next;
    }

    // 创建结点 && 插入 && 链表长度加一
    Node *q = get_node(val);
    q->next = p->next;
    p->next = q;
    l->len += 1;
    return 1;
}


int search(List *l, int val){
    if(l == NULL) return -1;

    Node *p = l->head.next;
    int ind = 0;
    while(p && p->val != val){
        p = p->next;
        ind ++;
    }

    if(p==NULL) return -1;
    return ind;
}


int del_node_ind(List *l, int ind){
    if(l == NULL || l->len == 0) return 0;
    if(ind < 0 || ind > l->len) return 0;

    Node *p = &(l->head);
    while(ind--){
        p = p->next;
    }

    p->next = p->next->next;
    l->len -= 1;
    return 1;
}


int del_node_val(List *l, int val){
    if(l == NULL) return 0;
    int ind = search(l, val);
    if(ind < 0) return 0;
    return del_node_ind(l, ind);
}


void output(List *l){
    if(l == NULL) return;
    Node *p = l->head.next; //从第一个结点开始即可
    printf("List(%d): ", l->len);
    while(p){
        printf("%d->", p->val);
        p = p->next;
    }
    printf("NULL\n");
    return;
}


void merge_list(List *l1, List *l2, List*l){
    if(l1 == NULL && l2 == NULL || l == NULL) return;
    Node *p1 = (l1->head.next), *p2 = (l2->head.next);
    while(p1 && p2){
        if(p1->val < p2->val){
            insert(l, l->len, p1->val);
            p1 = p1->next;
        } else{
            insert(l, l->len, p2->val);
            p2 = p2->next;
        }
    }
    while (p1){
        insert(l, l->len, p1->val);
        p1 = p1->next;
    }
    while (p2){
        insert(l, l->len, p2->val);
        p2 = p2->next;
    }
    return;
}


void re_list(List *l1, List *l){
    if(l1 == NULL || l == NULL) return;
    Node *p = l->head.next;
    while (p){
        insert(l, 0, p->val);
        p = p->next;
    }
    return;
}


void free_node(Node *n){
    if(n == NULL) return;
    free(n);
    return;
}


void free_list(List *l){
    if(l == NULL) return;

    Node *p = (l->head.next), *tmp;
    while (p){
        tmp = p->next;
        free_node(p);
        p = tmp;
    }

    free(l);
    return;
}