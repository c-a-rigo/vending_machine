#include <iostream>
#include <string>
#include <stdlib.h>
#include <unistd.h>
using namespace std;

int main()
{
    int num;
    int rem;

    num = 1838;

    rem = num % 100;
    cout << "hora " << rem << endl;

    num = num / 100;

    rem = num % 100;
    cout << "min " << rem << endl;
}
/* 
#include <iostream> // required to perform C++ stream I/O

using namespace std; // for accessing C++ Standard Library members

// function main begins program execution

int main()
{

    int num;
    int rem;

    cout << " Input a five-digit number : ";
    cin >> num;
    ;

    for (int i = 0; i < 5; i++)
    {
        rem = num % 10;
        num = num / 10;
        cout << rem << endl;
    }

    return 0; // indicate that program ended successfully

} // end function main */