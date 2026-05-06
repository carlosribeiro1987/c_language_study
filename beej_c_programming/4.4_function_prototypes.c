#include <stdio.h>

int foo(void); // This is the prototype

int main(void){
    int i;

    // We can call foo here before its definition because the
    // prototype has already been declared, above!
    i = foo();
    printf("%d\n", i); 

}

int foo(void){
    return 3490;
}