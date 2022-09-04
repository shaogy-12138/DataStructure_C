//
// Created by Administrator on 2022/8/21 0021.
//

#include <stdio.h>
#include <string.h>

#define MAX_LEN 255

int next[MAX_LEN + 5];

int str_compare_1(const char*s, const char* t, int s_len, int t_len);
void get_next(const char* t, int t_len);
int kmp_compare(const char*s, const char* t, int s_len, int t_len);
int test();

int main2(int argc, char *argv[]){

    char *s = "abaabcac";
    char *t = " ";
    get_next((const char *)s, strlen(s));
    int cmp_flag = kmp_compare((const char *)s, (const char *)t, strlen(s), strlen(t));
    if(cmp_flag < 0){
        printf("匹配失败，未匹配到字符\n");
    }else{
        printf("匹配成功， index = %d \n", cmp_flag);
    }

    return 0;

}

int str_compare_1(const char*s, const char* t, int s_len, int t_len){
    if(t_len < 0 || t_len > s_len) return -1;

    int i = 0, j = 0;
    while(i < s_len && j < t_len){
        if(s[i] == t[j]){
            i++, j++;
        }else{
            // s：1 2 3 4 5 6 7 8 9  i = 3
            // t: 1 2 3 5 j = 3
            // i应该从2开始比， 即从 i - j + 1处开始
            i = i - j + 1; //s的第i个字符串前移j个字符。
            j = 0;
        }
    }

    if(j >= t_len){
        //printf("匹配成功！\n");
        return i - t_len;
    }
    //printf("匹配失败!\n");
    return -1;
}

void get_next(const char* t, int t_len){
    /*
     * 获取next函数, next存放的是当匹配失败时， 将t[next[i]]移动到当前位置
     * 根据前一个元素的next[i-1]获取当前元素的next[i]
     * 1. next[0] = 0, j = i - 1
     * 2. 如果 t[i] == t[j] : next[i] = next[j] + 1
     * 3. 如果 t[i] != t[j] : 令 j = next[j] - 1, 重复 2 3 , 直到满足2 或者 next[j] == 0
     */
    next[0] = 0;

    for(int i = 1; i < t_len; i++){
        int j = i - 1;
        while(1){
            if(next[j] == 0 || t[i - 1] == t[next[j]-1]){
                next[i] = next[j] + 1;
                break;
            }
            j = next[j] - 1;
        }
    }

    for(int i= 0; i < t_len; i ++){
        i && printf(" ");
        printf("%d", next[i]);
    }
    printf("\n");
}

int kmp_compare(const char*s, const char* t, int s_len, int t_len){
    if(t_len < 0 || t_len > s_len) return -1;

    int i = 0, j = 0;
    while(i < s_len && j < t_len){
        if(s[i] == t[j]){
            i++, j++;
        }else{
            if(j == 0){
                ++i;
            }else{
                j = next[j] - 1;
            }
        }
    }

    if(j >= t_len) return i - t_len;
    return -1;
}

int test() {
    char str1[] = "abababcabb";
    char str2[] = "abaabcac";

    int len1 = strlen(str1), len2 = strlen(str2);
    int next1[len2];
    next1[0] = 0;

    //next 数组初始化
    for(int i = 1; i < len2; i++){
        int j = i - 1;
        while(1){
            if(next1[j] == 0 || str2[i - 1] == str2[next1[j] - 1]){
                next1[i] = next1[j] + 1;
                break;
            }
            j = next1[j] - 1;
        }
    }

    for(int i = 0; i < len2; i++){
        printf("%d\n", next1[i]);
    }

    int i = 0, j = 0;
    while(i < len1){
        if(str1[i] == str2[j]){
            i++;
            j++;
        }else{
            if(j == 0){
                i++;
            }else{
                j = next1[j] - 1; //将第next[j] 个元素移动到不同处
            }
        }

        if(j == len2){
            break;
        }
    }
    printf( j == len2 ? "ol\n" : "fail\n");
    return 0;
}