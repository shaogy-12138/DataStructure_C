//
// Created by RB on 26/8/2022.
//
#include <stdio.h>

typedef struct DATE{
    int year = 0;
    int month = 0;
    int day = 0;
}Date;

void ouput(Date date){
    printf("%d/%d/%d\n", date.day, date.month, date.year);
    return;
}
int main(){

    Date date;
    int year, month, day;
    scanf("%d %d %d", &year, &month. &day);
    date.year = year;
    date.month = month;
    date.day = day;
    ouput(date);
    return 0;
}