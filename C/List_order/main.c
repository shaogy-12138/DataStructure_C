//
// Created by RB on 1/9/2022.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "list_order.h"

#define MAX_N 6

void list_order();
int main(){

    list_order();

    return 0;
}

void list_order(){
    ListOr *l1 = create(MAX_N);
    if(l1 == NULL) {
        printf("l1 List create failed:\n");
        exit(-1);
    }


    srand(time(0));
    int i = 0;
    int opt, val1, ind;

    for(; i < MAX_N * 2; i++){
        opt = rand() % 4;
        val1 = rand() % 100;
        ind = rand() % (MAX_N+1);
        switch (opt) {
            case 0:
            case 1:
            case 2:
            case 3:
            case 4: {
                printf("Insert %d to List %d location.result = %d\n", val1, i, insert(l1, i, val1));

            }break;
            case 5:
            case 6:{
                printf("Append %d to List tail.resoult  = %d\n", val1, append(l1, val1));
            }
                break;

            case 7:
            case 8:{
                l1 = erase_val(l1, val1);
                printf("Erase %d from List.\n", val1);
            }
                break;
            default:
            {
                l1 = erase_ind(l1, ind);
                printf("erase %d location num from  list\n", ind);
            }
        }

        output_list_order(l1), printf("\n");

    }

    printf("123.........................\n");
    free_list_order(l1);

#undef MAX_N
    return;
}