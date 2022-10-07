//
// Created by RB on 27/8/2022.
//

#include <stdio.h>
#include "b_ree.h"
#include <time.h>
#include "stdlib.h"
#define MAX_N 20
void copy_str(char *from, char *to){
    for(; *from != '\0'; from++, to++){
        *to = *from;
    }
    *to = '\0';
}

void test1(){
    char a[] = "I am a boy";
    char *b;
    printf("%x, %x\n", &a, &b);
    copy_str(a, b);
    printf("a is : %s\n", a);
    printf("b is : %s\n", b);
    return;

}
int main()
{
    //test1();
    BTree *tree= init_b_tree();
    if(tree == NULL){
        printf("create tree failed\n");
        return 1;
    }
    srand(time(0));
    int i;
    for(i = 0; i < MAX_N; i++){
        int val = rand() % 100;
        int opt = rand() % 5;

        switch (opt) {
            case 0:
            case 1:
            case 2:
            case 3:{
                tree->root = insert_node(tree->root, val);
                printf("insert a val %d in b_tree\n", val);
            }
                break;
            case 10:{
                printf("delete a val in b_tree\n");
                tree->root = delete_node(tree->root, val);
            }
                break;
        }
        pre_in_order(tree->root), printf("\n");
        mid_in_order(tree->root), printf("\n");
        pre_in_order(tree->root), printf("\n");
    }
    free_tree(tree);
    return 0;
}