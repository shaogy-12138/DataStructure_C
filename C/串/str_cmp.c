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
        printf("ƥ��ʧ�ܣ�δƥ�䵽�ַ�\n");
    }else{
        printf("ƥ��ɹ��� index = %d \n", cmp_flag);
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
            // s��1 2 3 4 5 6 7 8 9  i = 3
            // t: 1 2 3 5 j = 3
            // iӦ�ô�2��ʼ�ȣ� ���� i - j + 1����ʼ
            i = i - j + 1; //s�ĵ�i���ַ���ǰ��j���ַ���
            j = 0;
        }
    }

    if(j >= t_len){
        //printf("ƥ��ɹ���\n");
        return i - t_len;
    }
    //printf("ƥ��ʧ��!\n");
    return -1;
}

void get_next(const char* t, int t_len){
    /*
     * ��ȡnext����, next��ŵ��ǵ�ƥ��ʧ��ʱ�� ��t[next[i]]�ƶ�����ǰλ��
     * ����ǰһ��Ԫ�ص�next[i-1]��ȡ��ǰԪ�ص�next[i]
     * 1. next[0] = 0, j = i - 1
     * 2. ��� t[i] == t[j] : next[i] = next[j] + 1
     * 3. ��� t[i] != t[j] : �� j = next[j] - 1, �ظ� 2 3 , ֱ������2 ���� next[j] == 0
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

    //next �����ʼ��
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
                j = next1[j] - 1; //����next[j] ��Ԫ���ƶ�����ͬ��
            }
        }

        if(j == len2){
            break;
        }
    }
    printf( j == len2 ? "ol\n" : "fail\n");
    return 0;
}