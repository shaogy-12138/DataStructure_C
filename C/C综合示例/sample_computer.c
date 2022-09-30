//
// Created by RB on 8/9/2022.
//


#include "stdio.h"
#include "stdlib.h"

/*
 *   本示例为简单的计算器的实现：
 *   输入一串操作：
 *   1. 判断数值
 *   2. 判断下一个操作为x/？
 *   3. 判断下一个操作为+-？
 *   4. 判断非法字符？
 */
float get_num(char **);
int main(){

    char a[80];
    int sign = 1;
    float result = 0;
    char *p;
    gets(a);
    p = a;
    printf("%s\n", p);
    if(*p == '-'){
        sign = -1;
        p++;
//        printf("*p = %c\n\n", *p);
    }

    while(*p != 0){
//        printf("*p = %c\n", *p);
        float m;
        m = sign * get_num(&p);
        while(*p == '*' || *p == '/'){
            if(*p == '*'){
                p++;
                m *= get_num(&p);
            }else{
                int div;
                p++;
                div = get_num(&p);
                if(div){
                    m /= div;
                }else{
                    printf("Div is invaild number!\n");
                    exit(1);
                }
            }

        }
        printf("m = %d\n", m);
        if(*p != '+' && *p != '-' && *p != 0){
            printf("Invalid char!\n");
            exit(1);
        }

        result += m;
//        printf("Result = %d\n", result);
        if(*p == '+'){
            sign = 1;
            p++;
        }else {
            if(*p == '-'){
                sign = -1;
                p++;
            }
            else
                break;
        }


    }

    printf("The result is %f\n", result);


    return 0;
}

float get_num(char **pp){
    float x = 0, m = 10;
    if(**pp != '.' &&(**pp < '0' || **pp > '9' )){
        printf("invalid char after operator！\n");
        exit(1);
    }
    while (**pp >= '0' && **pp <= '9'){
        x = x * 10 + **pp - 48;
        (*pp) ++;
    }

    if(**pp == '.') {
        (*pp)++;
        while(**pp >= '0' && **pp <= '9') {
            x += (**pp - 48)/m;
            (*pp)++;
            m *= 10;
        }
    }
    return x;
}