#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <iomanip>
#include <signal.h> //  our new library
using namespace std;

volatile sig_atomic_t flag = 0;

void my_function(int sig)
{ // can be called asynchronously
    string a;
    printf("\n Signal caught!\n");
    printf("\n default action it not termination!\n"); // set flag
    cin >> a;
}

int main()
{

    int k = 0;
    // Register signals
    signal(SIGINT, my_function);
    //      ^          ^
    //  Which-Signal   |-- which user defined function registered

    for (int i = 0; i < 10; i++)
    {
        raise(SIGINT);
    }

    return 0;
}