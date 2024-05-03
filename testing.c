#include<stdio.h>
#include<stdlib.h>
int main(){
    int *ptr=(int*)malloc(sizeof(int));
    int *ptr1=(int *)calloc(1,sizeof(int));
    printf("%p\n",ptr);
    printf("%p+",ptr1);
}