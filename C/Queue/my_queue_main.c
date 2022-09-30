//
// Created by RB on 30/9/2022.
//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "my_queue.h"

#define MAX_N 10

int main(){
    Queue *q = init_queue(MAX_N);
    srand(time(0));
    int i;
    for(i = 0; i < MAX_N+10; i++){
        int opt = rand() % 6;
        int val = rand() % 100;
        switch (opt) {
            case 0:
            case 1:
            case 2:
            case 3:
            case 4:{
                printf("Push %d to Queue, Result = %d\n", val, push(q, val));
            }
                break;
            case 5:{
                printf("Pop %d from Queue\n", pop(q));
            }
                break;
        }
        output_queue(q), printf("\n");
    }
    destory_queue(q);
#undef MAX_N
    return 0;
}