//
// Created by RB on 2/9/2022.
//

#include "my_queue.h"


Queue *init_queue(int length){
    Queue *q = (Queue *)malloc(sizeof (Queue)); //申请一段堆空间存放队列
    q->data = (DataType *) malloc(sizeof(DataType) * length);
    memset(q->data, 0, sizeof (DataType) * length);
    q->head = 0; //初始head指向代存位置
    q->tail = 0; // 初始tail指向代存位置
    q->q_len = 0; // 当前0个元素
    q->q_size = length; // 队列总长

    return q;
}

void destory_queue(Queue *q){
    if(q == NULL) return;
    free(q->data); // 所有malloc的部分都需要free进行释放
    free(q);
    return;
}

int push(Queue *q, DataType val){
    if(q == NULL) return 0;
    if(is_full(q)) return 0;
    q->data[q->tail ++] = val;
    q->tail %= q->q_size;
    q->q_len += 1;
    return 1;
}
int pop(Queue *q){
    if(q == NULL || is_empty(q)) return 0;
    int tmp = q->data[q->head ++];
    q->head %= q->q_size;
    q->q_len -= 1;
    return tmp;
}

int is_empty(Queue *q){
    return !q->q_len; // 空->1 非空->0
}

int is_full(Queue *q){
    return (q->q_len == q->q_size); // 满->1 不满->0
}


void clear_queue(Queue *q){
    if(q == NULL || is_empty(q)) return;
    q->head = q->tail;
    return;
}

void output_queue(Queue *q){
    if(q == NULL || is_empty(q)) return;
    printf("Queue[%d|start(%d)|tail(%d)]: ", q->q_len, q->head, q->tail);
    int i = 0;
    if(q->head < q->tail){
        i = q->head;
        for(; i < q->tail; i++){
            (i != q->head) && printf(", ");
            printf("%d", q->data[i]);
        }
    }else{
        int cnt = 0;
        for(i = q->head; cnt < q->q_len; cnt++){
            cnt && printf(", ");
            printf("%d", q->data[i++]);
            i %= q->q_size;
        }
    }

    printf("\n");
    printf("Queue[%d]: ", q->q_len);
    for(i = 0; i < q->q_size; i++){
        i && printf(", ");
        printf("%d", q->data[i]);
    }
    printf("\n");
    return;
}
