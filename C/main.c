//
// Created by RB on 27/8/2022.
//

#include <stdio.h>


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
    test1();
    return 0;
}