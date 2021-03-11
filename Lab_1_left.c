//
// 1. Для целого числа (int) вывести содержимое каждого байта (в десятичной
//системе счисления).
//

#include <stdio.h>
#include <stdlib.h>

int main(){
    // this
    int value = 0;
    scanf("%d", &value);
    for (int i = 0; i < sizeof(int); i++) {
        printf("%hhu ", *(((unsigned char *) &value) + i));
    }
    // or this
    int *number = (int*) malloc(sizeof(int));
    scanf("%d", number);
    for(int i = 0; i < sizeof(*number); i++){
        printf("%hhu ", *(((unsigned char *) number)+i));
    }
}