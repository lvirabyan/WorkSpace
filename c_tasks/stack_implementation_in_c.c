#include <stdio.h>
#include "stdlib.h"
int* create(int);
void operation(int*, int*);
void push_back(int*,int*, int);
void pop_back(int*, int*);
void top(int*, int*);
void delete(int*);
int main() {
    int size = 1;
    int* arr = create(size);
    operation(arr, &size);
    return 0;
}
int* create(int len){
    int* arr = (int*)calloc(len, sizeof(int));
    return arr;
}
void push_back(int* arr, int* len, int data) {
    int* arr1 = realloc(arr, *len + 1) ;
    arr = arr1;
    arr[*len] = data;
    ++*(len);
}
void pop_back(int* arr, int* len) {
    if(*len == 1) {
        printf("There is no element to pop.");
        return;
    }
    printf("The last element will be deleted.");
    int* arr1 = realloc(arr, *len - 1);
    arr = arr1;
    --*(len);
}
void top(int* arr, int* len) {
    printf("%d\n", *(arr + *len - 1));
}
void operation(int* arr, int* len){
    printf("Choose an options:\n");
    printf(" 1. Push back.\n 2. Pop back.\n 3. Top \n 4. Exit.\n");
    int op = 0;
    do {
        scanf("%d", &op);
    } while (op < 1 || op > 4);
    if(op == 1) {
        int num = 0;
        printf("Pleas enter a number:");
        scanf("%d", &num);
        push_back(arr, len, num);
    } else if(op == 2) {
        pop_back(arr, len);
    } else if(op == 3) {
        top(arr,len);
        printf("\n");
    } else {
        delete(arr);
        return;
    }
    operation(arr,len);
}
void delete(int* arr) {
    free(arr);
    arr = NULL;
}