#include <iostream>
#include <Signal.h>
using namespace std;

int main()
{
    debugger::Signal l_signal;
    std::cout << l_signal.test() << std::endl;
    return 0;
}
