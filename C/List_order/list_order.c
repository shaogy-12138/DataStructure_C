//
// Created by RB on 1/9/2022.
//
#include "list_order.h"
#include <stdlib.h>
#include <stdio.h>

ListOr *create(int len){
    ListOr *l = (ListOr *) malloc(sizeof(ListOr)); // 1. 开辟一段内存空间存放列表
    l->data = (int *) malloc(sizeof(int) * len); //2. 开辟一段内存空间存放数据， 表头存放在列表中
    l->len = len;
    l->size = 0;
    return l;
}


int insert(ListOr *l, int ind, int val){
    if(l == NULL) return 0;
    if(ind < 0 || ind > l->size){
        printf("index is invaild, insert failed!\n");
        return 0;
    }
    if(is_full(l)){

        printf("ListOrder current is full, will auto extend!\n");
        extend(l, l->len);
        printf("current size = %d\n", l->len);
    }
    int i = l->size;
    printf("i = %d, val = %d\n", i, val);
    for(; i > ind; i--){
        printf("DEBUG[%d]\t", i);
        l->data[i] = l->data[i-1];
    }
    printf("\n");
    l->data[ind] = val;
    l->size += 1;
    return 1;
}


ListOr *erase_ind(ListOr *l, int ind){
    if(l == NULL || is_empty(l)) return l;
    if(ind < 0 || ind > l->size) return l;
    int i = ind;
    for(; i < l->size - 1;i++){
        l->data[i] = l->data[i+1];
    }
    l->size -= 1;
    return l;
}


ListOr *erase_val(ListOr *l, int val){
    if(l == NULL || is_empty(l)) return l;
    int ind = get_ind(l, val);
    if(ind < 0){
        printf("val not in List, erase failed!\n");
        return l;
    }
    return erase_ind(l, ind);
}


int get_ind(ListOr *l, int val){
    if(l == NULL || l->size == 0) return -1;
    int i = 0;
    for(; i < l->size; i++){
        if(l->data[i] == val) return i;
    }
    return -1;
}

int append(ListOr *l, int val){
    if(l == NULL) return 0;
    if(is_full(l))  return 0;

    l->data[l->size ++] = val;
    return 1;
}


int is_full(ListOr *l){
    return l->len == l->size;
}


int is_empty(ListOr *l){
    return l->size == 0;
}


int extend(ListOr *old_l, int len){
    int new_len = len;
    int *tmp;
    while (new_len){
        len += new_len;
        tmp = (int *) realloc(old_l->data, sizeof(int) * len); // 需要注意
        if(tmp){
            printf("Extend successfully! Current size = %d\n", len);
            old_l->data = tmp;
            old_l->len = len;
            return 1;
        }
        new_len >>= 1;
    }

    if(new_len == 0){
        printf("Extend Failed!\n");
    }

    return 0;
}


int find(ListOr *l, int val){
    if(l == NULL) return -1;
    if(is_empty(l)) return -1;

    int i = 0;
    for(; i < l->size; i++){
        if(l->data[i] == val) return i;
    }
    return -1;
}


void output_list_order(ListOr *l){
    if(l == NULL) return;
    printf("ListOrder(%d): ", l->size);

    int i = 0;
    for(; i < l->size; i++){
        i && printf(" ,");
        printf("%d", l->data[i]);
    }
    printf("\n");
    return;
}


void free_list_order(ListOr *l){
    if(l == NULL) return;
    printf("l->len = %d, l->size = %d, l->data = %p\n", l->len, l->size, l->data);
    free(l->data);
    free(l);
    return;
}