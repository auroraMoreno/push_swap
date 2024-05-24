
#include <stdio.h>

int main(){
    int a = 16; 
    int* p = &a; 
    // u can also use the * to set the value at that memory address:
    *p = 17; // deref p equals 17. 
    // if we did p = 17, that would set the actual addres that p is pointing to 17
    //printf("%d\n", p); // p here is actually an address, what we would be printing here is the address
    // it's the value of int*, and the value of that pointer is the address of a 
    // how can we tell the language that what we want is not just the address but the value at that address?
    // using the derefence operator: 
    printf("%d\n", *p); // so now, what C is going to do is find p and look at what address is stored in there
    // it will be like: oh, the value stored in there is the address of a
    // okay, so go there in memory and find me an integer and is gonna go there and return the value of a, 
    //IMPORTANT: don't get confused with int* and *p. They are completly different things, one is to indicate the type: pointer and the other is to deref

    return (0);
}