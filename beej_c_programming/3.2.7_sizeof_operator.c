#include <stdio.h>

int main(int argc, char const* argv[]) {
    int a = 999;

    //%zu is the format specifier for size_t, 
    //If your compiler balks at the "z" part, leave it of
    
    printf("%zu\n", sizeof(a)); // prints the size of the variable a in bytes
    printf("%zu\n", sizeof(2 + 7)); // prints the size of the result of the expression 2 + 7 in bytes
    printf("%zu\n", sizeof(3.14)); // prints the size of the floating-point literal 3.14 in bytes)

    //If you need to print oput negative size_t values, use %zd

    printf("%zu\n", sizeof(int)); //Prints 4
    printf("%zu\n", sizeof(char)); //Prints 1, the size of a char is always 1 byte

    return 0;
}
