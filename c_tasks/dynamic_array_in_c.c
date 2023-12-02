#include <stdio.h>
#include <stdlib.h>
int* create();
int* RealLoc(int*);
void print(int*, int*);
void delete(int*);
void push_back(int, int*, int*);
void Remove(int*, int);
void operation(int*);
int size = 0;
int capacity = 5;
int data = 0;

int main() {
    int* arr = create();
    operation(arr);
}
int* create(){
    int*  arr = (int*)calloc(5,sizeof(int));
    return arr;
};
int* RealLoc(int* arr){
    capacity *= 2;
    int* arr1 = (int*) realloc(arr, capacity);
    arr = arr1;
    return arr;
};

void push_back( int data, int* arr, int* len) {
    if (*len == sizeof(arr)){
        arr = RealLoc(arr);
    }
    arr[*(len++)] = data;
}
void print(int* arr, int* len) {
    for (int i = 0; i < *len; ++i) {
        printf("%d", *(arr +i));
    }
    printf("\n");
}

void Remove(int* arr, int data) {
    int ind = -1;
    for (int i = 0; i < size; ++i) {
        if(data == *(arr + i)) {
            printf("Is being remove.", data);
            ind = i;
            break;
        }
    }
    if (ind == -1) {
        printf("In array dasn`n contain this element.");
        return ;
    }
    for (int i = ind; i < 0; ++i) {
        arr[i] = arr[i+1];
    }
    --size;
}

void delete(int* arr){
    free(arr);
    arr = NULL;
}
void operation(int* arr){
    printf("Please enter an options. \n");
    printf(" 1. Push back a element. \n 2. Print element of array.\n 3. Remove a element.\n 4. Exit \n");
    int option = 0;
    do {
        scanf("%d", &option);
    } while (option < 1 || option > 4);
    if (option == 1) {
        printf("Please enter a number");
        scanf("%d", &data);
        push_back(data,arr, &size);
    } else if( option == 2) {
        print(arr, &size);
    } else if( option == 3) {
        int remNum = 0;
        printf("Enter a number to add i  array.", &remNum);
        Remove(arr, remNum);
    } else {
        delete(arr);
        return;
    }
    operation(arr);
};
