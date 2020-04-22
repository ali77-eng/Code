#include <stdio.h>
#include <cs50.h>

//Asking user for name and saying hello.
int main(void)
{
    string name = get_string("What is your name?\n");
    printf("hello, %s\n", name);
}
