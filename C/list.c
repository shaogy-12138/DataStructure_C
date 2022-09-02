//
// Created by RB on 26/8/2022.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next, *par;
}Node;
typedef struct list{
    int len, sum;
    Node head;
}List;
List *creat_list(){
    List *l = (List *)malloc(sizeof (List));
    l->len = 0;
    l->sum = 0;
    l->head.next = NULL;
    l->head.par = NULL;
    return l;
}
Node *get_new_node(int val){
    Node *p = (Node *)malloc(sizeof(Node));
    p->data = val;
    p->next = NULL;
    p->par = NULL;
    return p;
}

void clear_node(Node *n){
    if(n == NULL) return;
    free(n);
    return;
}

void clear_list(List *p){
    if(p == NULL) return;
    Node *tmp = p->head.next;
    while(tmp){
        Node *q = tmp->next;
        clear_node(tmp);
        tmp = q;
    }
    free(p);
    return;
}

int insert(List *l, int ind, int val){
    if(l == NULL) return 0;
    if(ind < 0 || ind > l->len) return 0;


    Node *p = &(l->head), *tmp;
    while(ind--){
        tmp = p->next;
        p = tmp;
    }

    Node *in = get_new_node(val);

    in->next = p->next;
    in->par = p;
    p->next = in;
    if(in->next != NULL) in->next->par = in;



    l->len += 1;
    l->sum += val;
    return 1;
}

void output(List *l){
    if(l == NULL) return ;
    Node *p = l->head.next;
    int i = 0;
    for(; p; i++){
        i && printf(" ");
        printf("%d", p->data);
        p = p->next;
    }
    printf("\n");
    return;
}

void sum(List *l){
    if(l == NULL) return ;
    Node *p = l->head.next;
    int i = 0, sum = 0;
    for(; p; i++){
        sum += p->data;
        p = p->next;
    }
    printf("%d\n",sum);
    return;
}
void swap_func(List *l){
    if(l == NULL || l->len <= 1) return;
    Node *first = l->head.next;
    int data1 = first->data;
    int data2 = first->next->data;

    // 交换前两个
    first->data = data2;
    first->next->data = data1;

    // 交换最后两个
    Node *tmp = &(l->head), *q = tmp->next;
    int i = l->len;
    while(q->next){
        tmp = q;
        q = tmp->next;
    }
    data1 = tmp->data;
    data2 = q->data;
    tmp->data = data2;
    q->data = data1;
    return;
}
void erase(List *l, int val){
    if(l == NULL) return;
    Node *head = l->head.next, *q;
    while(head){
        //printf("head = %d ", head->data);
        if(head->data == val){
            if(head->next == NULL){
                head->par->next = NULL;
                free(head);
            }else{
                head->par->next = head->next;
                head->next->par = head->par;
            }
            l->len -= 1;
        }
        head = head->next;
        //output(l);
    }
    return;
}
int main(){
    int n, m;
    int i = 0;
    List *la = creat_list();
    //List *lb = creat_list();
    scanf("%d %d", &n, &m);
    int *arr = (int *) malloc(n * sizeof (int));

    for(; i < n; i++){
        scanf("%d", &arr[i]);
    }
    for(i = n-1; i>=0; i--){
        insert(la, 0, arr[i]);
    }
    insert(la, m, m);

    output(la);

    //printf("%d\n", l->sum);
    clear_list(la);

    return 0;
}