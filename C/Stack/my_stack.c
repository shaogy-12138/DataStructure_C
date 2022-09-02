//
// Created by RB on 31/8/2022.
//
#include "my_stack.h"
#include <stdlib.h>
#include <stdio.h>


Stack *create(int l){
    Stack *s = (Stack *) malloc(sizeof(Stack));
    s->data = (int *) malloc(sizeof(int) * l);
    s->len = l;
    s->size = 0;
    s->s_top = 0; // 栈空， 执向-1
    return s;
}


int push(Stack *s, int val){
    if(s == NULL) return 0;
    if(is_full(s)) return 0;
    s->data[s->s_top ++] = val;
    ++ s->size;
    return 1;
}


int is_empty(Stack *s){
    return s->size;
}


int is_full(Stack *s){
    return s->len == s->size;
}


int pop(Stack *s){
    if(s == NULL) return 0;
    s->s_top -= 1;
    s->size -= 1;
    return 1;
}


int get_top(Stack *s){
    if(!is_empty(s)) return -1;
    return s->data[s->s_top - 1];
}


void clear_stack(Stack *s){
    if(s == NULL) return ;
    s->s_top = 0;
    s->size = 0;
    return;
}


void output_stack(Stack *s){
    if(s == NULL) return;
    if(!is_empty(s)) return;
    int i = s->s_top - 1;
    printf("Stack(%d):[ ", s->size);
    for(; i >= 0; i--){
        printf("%d", s->data[i]);
        i && printf(", ");
    }
    printf("]\n");
    return;
}


void free_stack(Stack *s){
    if(s == NULL) return;
    free(s->data); // 所有malloc的堆区域都需要被free
    free(s);
    return ;
}