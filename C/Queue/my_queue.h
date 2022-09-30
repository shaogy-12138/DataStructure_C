//
// Created by RB on 2/9/2022.
//

#ifndef DATASTRUCTURE_C_MY_QUEUE_H
#define DATASTRUCTURE_C_MY_QUEUE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// 数据结构 = 结构定义 + 结构操作
// 队列属于线性结构 && 队列的特性： FIFO 或 LILO即先进先出/后进后出
//

// 结构定义： 定长数组 & Head(记录头) & Tail(记录尾) & Size(记录队列长度) & Len(记录当前队列元素个数)
// 结构操作：
// 1. 初始化队列
// 2. 销毁队列
// 3. 入队Push
// 4. 出队Pop
// 5. 判空
// 6. 判满
// 7. 清空队列
// 8. 遍历队列

typedef int DataType;
typedef struct _QUEUE{
    DataType *data; // 队列长度由用户决定
    int head, tail, q_len, q_size;
}Queue;

Queue *init_queue(int length);
void destory_queue(Queue *q);
int push(Queue *q, DataType val);
int pop(Queue *q);
int is_empty(Queue *q);
int is_full(Queue *q);
void clear_queue(Queue *q);
void output_queue(Queue *q);

#endif //DATASTRUCTURE_C_MY_QUEUE_H
