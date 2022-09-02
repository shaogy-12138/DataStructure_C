//
// Created by RB on 26/8/2022.
//
#include <stdio.h>
#include <stdarg.h>
#include <assert.h>
#include "argcs.h"
double average(int num,...)
{

    va_list valist;
    double sum = 0.0;
    int i;

    /* 为 num 个参数初始化 valist */
    va_start(valist, num);

    /* 访问所有赋给 valist 的参数 */
    for (i = 0; i < num; i++)
    {
        sum += va_arg(valist, int);
    }
    /* 清理为 valist 保留的内存 */
    va_end(valist);

    return sum/num;
}

int kbargc(int num, ...){

    // 1. 创建变量存储参数
    va_list  valist;

    va_start(valist, num);

    int i = 0;
    for(; i < num; i++){
        printf("%s\n", va_arg(valist, int));
    }
    return 0;
}

