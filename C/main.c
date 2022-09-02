//
// Created by RB on 27/8/2022.
//

#include <stdio.h>
#include "argcs.h"


void test1(){
    /*
     * 可变参数
     */
    int n;
    scanf("%d", &n);
    kbargc(5, "nihao", "shaogy", "wo", "laizi", "kuailexingqiu");
    printf("Average of 2, 3, 4, 5 = %f\n", average(4, 2,3,4,5));
    printf("Average of 5, 10, 15 = %f\n", average(3, 5,10,15));
}
int main()
{
    test1();
    return 0;
}