//
// Created by RB on 25/8/2022.
//
#include <stdio.h>
#include <stdlib.h>
#include "sort.h"
void _swap(int *a, int *b){
    *a ^= *b;
    *b ^= *a;
    *a ^= *b;
    return;
}
void bubble_sort(int *array, int n){
    for(int i = 1; i < n; i++){
        int flag = 0;
        for(int j = 0; j < n - i; j++){
            if(array[j] > array[j+1]){
                flag = 1;
                _swap(&array[j+1], &array[j]);
            }
        }
        if(flag == 0) break;
    }
    return ;
}

void select_sort(int *array, int n){
    for(int i = 0; i < n - 1; i++){
        int min = i;
        for(int j = i + 1; j < n; j++){
            if(array[j] < array[min]){
                min = j;
            }
        }
        if(min != i){
            _swap(&array[min], &array[i]);
        }
    }
    return;
}

void insert_sort(int *array, int n){
    for(int i = 1; i < n; i++){
        int j = i -1;
        int tmp = array[i];
        while(j >=0 && array[j] < tmp){
            array[j+1] = array[j];
            j--;
        }
        array[j] = tmp;
    }
    return;
}

void ouput(int *array, int n){
    for(int i = 0; i < n; i++){
        i && printf(" ");
        printf("%d", array[i]);
    }
    printf("\n");
    return;
}


void test_sort(){
    int n;
    scanf("%d", &n);
    int *array = (int *)malloc(sizeof(int) * n);
    for(int i = 0; i < n; i++){
        scanf("%d", &array[i]);
    }
    select_sort(array, n);

    ouput(array, n);
    return ;
}
