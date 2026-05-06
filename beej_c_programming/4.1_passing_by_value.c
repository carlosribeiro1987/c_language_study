#include <stdio.h>

void increment(int a){
    a++;
}


int main(int argc, char const* argv[]) {
    int i = 10;

    increment(i);
    printf("i = %d\n", i); // prints 10, not 11, because the value of i was passed by value to the increment function

    return 0;
}