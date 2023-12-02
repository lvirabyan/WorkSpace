#include <stdio.h>
int showOperations();
int calcNumbers(int,int,int);
int numInputType();
int numOutputType();
int binToDec(int);
int main() {
    int inputType = numInputType();
    int outputType = numOutputType();
    int op = showOperations();
    long long num1 = 0;
    long long num2 = 0;
    int res = 0;
    if (op == 7) {
        main();
    } else if(op == 8) {
        return 0;
    } else {
        if(inputType == 2) {
            printf("Please enter first binary number.");
            scanf("%lld", &num1);
            int Num1 = binToDec(num1);
            printf("Please enter second binary number.");
            scanf("%lld", &num2);
            int Num2 = binToDec(num2);
            res = calcNumbers(op, Num1, Num2);
        } else if(inputType == 10) {
            printf("Please enter first decimal number.");
            scanf("%d", &num1);
            printf("Please enter second decimal number.");
            scanf("%d", &num2);
            res = calcNumbers(op, num1, num2);
        }  else {
            printf("Please enter first hexadecimal number.");
            scanf("%x", &num1);
            printf("Please enter second hexadecimal number.");
            scanf("%x", &num2);
            res = calcNumbers(op, num1, num2);
        }
    }
    if(outputType == 2) {
        for(int i = sizeof(res) * 8-1; i >= 0; --i ){
            printf("%d", (res >> i) & 1);
        }
        printf("\n");
        main();
    } else if(outputType == 10) {
        printf("%d\n", res);
        main();
    } else {
        printf("0x%x\n", res);
        main();
    }
}

int showOperations(){
    int operation;
    printf("1. AND \n");
    printf("2. OR \n");
    printf("3. XOR \n");
    printf("4. NOR\n");
    printf("5. Left Shift \n");
    printf("6. Right Shift \n");
    printf("7. Replay\n");
    printf("8. Exit\n");
    printf("Choose an operation \n");
    do {
        scanf("%d" , &operation);
    } while(operation > 8 || operation < 1);
    return operation;
}
int calcNumbers(int op, int num1,int num2){
    switch (op) {
        case 1: return num1 & num2; break;
        case 2: return num1 | num2; break;
        case 3: return num1 ^ num2; break;
        case 4: return ~(num1 | num2); break;
        case 5: return num1 << num2; break;
        case 6: return num1 >> num2; break;
    }
}
int numInputType(){
    printf("Choose the type of numbers for input. \n");
    int type = 0;
    do{
        printf("insert 2 for binary. \n");
        printf("insert 10 for decimal. \n");
        printf("insert 16 for hexadecimal. \n");
        scanf("%d", &type);
    } while (type != 2 && type != 10 && type != 16);
    return type;
}
int numOutputType(){
    printf("Choose the type of for output. \n");
    int type = 0;
    do{
        printf("insert 2 for binary. \n");
        printf("insert 10 for decimal. \n");
        printf("insert 16 for hexadecimal. \n");
        scanf("%d", &type);
    } while (type != 2 && type != 10 && type != 16);
    return type;
}
int binToDec(int n){
    int num = 0;
    int i = 0;
    int rem = 0;
    while(n) {
        rem = n % 10;
        n /= 10;
        num += rem * (1 << i);
        ++i;
    }
    return num;
}
