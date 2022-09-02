//
// Created by RB on 31/8/2022.
//
/*
 * 此Code实现栈
 *  数据结构 = 结构定义 + 结构操作
 *
 *  栈属于线性结构  && 栈的特性：FILO 或LIFO 即先进后出或后进先出
 *
 *  1. 结构定义[最基本的栈就是指定长度的栈]
 *  2. 结构操作
 *      1. 创建/初始化一个栈
 *      2. push
 *      3. 判空
 *      4. 判满
 *      5. pop
 *      6. 获取栈顶元素
 *      7. 清空栈
 *      8. 遍历
 *      9. 销毁栈
 *
 *  栈可以使用顺序表、数组、链表等实现， 这里使用的是数组实现的
 */

#ifndef MY_STACK_H
#define MY_STACK_H

typedef struct STACK{
    int *data; // 数据域
    int len, size, s_top; // 栈长度、元素个数、栈顶
}Stack;

Stack *create(int l);
int push(Stack *s, int val);
int is_empty(Stack *s);
int is_full(Stack *s);
int pop(Stack *s);
int get_top(Stack *s);
void clear_stack(Stack *s);
void output_stack(Stack *s);
void free_stack(Stack *s);


typedef struct STACK_LIST_ORDER{

}StackLo;

#endif //MY_STACK_H
