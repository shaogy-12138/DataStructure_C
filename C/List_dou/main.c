//
// Created by RB on 31/8/2022.
//
#include "list_dou.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_N  20

void list_dou();
int main(){
    list_dou();
//#undef MAX_N

    return 0;
}

void list_dou(){
    List *l1 = create_list();
    if(l1 == NULL) {
        printf("l1 List create failed:\n");
        exit(-1);
    }
    List *l2 = create_list();
    if(l2 == NULL) {
        printf("l2 List create failed:\n");
        exit(-1);
    }


    srand(time(0));
    int i = 0;
    int opt, val1, val2;

    for(; i < MAX_N; i++){
        opt = rand() % 4;
        val1 = rand() % 100;
        val2 = rand() % 200;
        switch (opt) {
            case 0:
            case 1:
            case 2: {
                printf("Insert %d to List1,result = %d\n", val1, insert(l1, l1->len, val1));
                printf("Insert %d to List2,result = %d\n", val2, insert(l2, l2->len, val2));
            }break;
            default:
            {
                printf("erase a item in list1, result = %d\n", del_node_val(l1, val1));
                printf("erase a item in list2, result = %d\n", del_node_val(l2, val2));
            }
        }

        output(l1), printf("\n");
        output(l2), printf("\n");
    }



    free_list(l1);
    free_list(l2);
    return ;
}