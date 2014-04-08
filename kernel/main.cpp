#include "kernel.hpp"

int main()
{
    robix::Kernel kernel;
    kernel.boot();

    return kernel.run();
}
