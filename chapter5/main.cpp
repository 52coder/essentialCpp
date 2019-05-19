#include "fibonacci.h"
#include <iostream>
using namespace std;

int main(void)
{
    Fibonacci fib;
    cout << fib << endl;

    Fibonacci fib2(4);
    cout << fib2 << endl;

    Fibonacci fib3(8, 12);
    cout << fib3 << endl;

    return 0;
}
