//
// Created by RB on 31/8/2022.
//

#include "my_stack.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>


#define MAX_N 256
const int max_len = 256;

void test_stack();
void num_conv(Stack *, int , int);
void kf_compare(Stack *, const char *);

int main(){

    srand(time(0));
    Stack *s = create(MAX_N);
    char str[] = {"{{([])([])([])([])}}[][][](()))"};

    kf_compare(s, (const char *)str);
    free_stack(s);
#undef MAX_N
    return 0;
    int num, x;
    scanf("%d %d", &num, &x);
    num_conv(s, num, x);
    return 0;
}

void num_conv(Stack *s, int num, int x){
    int tmp = num;
    while(tmp){
        int val = tmp % x;
        push(s, val);
        tmp /= x;
    }

    output_stack(s);
    clear_stack(s);
}


void kf_compare(Stack *s, const char *str){
    int i = 0, tmp = 0;
    while(str[i]){
        switch (str[i]) {
            case '{':
            case '[':
            case '(':{
                push(s, str[i]);
            }
                break;
            case '}':{
                tmp = get_top(s);
                if(tmp == '{') pop(s);
                else {
                    printf("invalid str 1!\n");
                    return;
                }
            }
                break;
            case ']':{
                tmp = get_top(s);
                if(tmp == '[') pop(s);
                else {
                    printf("invalid str 2!\n");
                    return;
                }
            }
                break;
            case ')': {
            tmp = get_top(s);
            if(tmp == '(') pop(s);
            else {
                printf("invalid str 3!\n");
                return;
            }
            }
                break;
        }
        str++;
    }

    if(!is_empty(s)){
        printf("compare success!\n");
    }else{
        printf("invalid str 4!\n");
    }
    return;
}

void test_stack(){
    Stack *s = create(max_len);
    int i = 0;
    for(; i < max_len; i++){
        int opt = rand()%4;
        int val = rand()%100;

        if(opt > 3){
            if(s->size == 0) {
                printf("Stack is empty.\n");
            }else{
                printf("top value is %d, will pop a value from stack, result = %d\n", get_top(s), pop(s));
            }
        }else{
            printf("Push %d to stack, result = %d\n", val, push(s, val));
        }

        output_stack(s);
    }

    clear_stack(s);
    printf("stack clear, current size = %d\n", s->size);
    output_stack(s);
    free_stack(s);
    return;
}