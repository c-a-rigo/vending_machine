

int main()
{
    int i;
    for (i = 0; i < 100000000000; i++)
        ;

    return 0;
}

#include "Interface.cpp"

#ifdef PC
#include "InterfacePC.cpp"
#endif

#ifdef ATL
#include "InterfaceAtl.cpp"
#endif