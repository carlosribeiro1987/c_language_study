#include <stdio.h>

int main(void){
    int i; // i's type is "int"

    int *p; // p's type is "pointer to an int, or int-pointer". p is a pointerr, but ios unitialized and points to garbage

    p = &i; // p is addigned to the adresss of i--p now points to i
}