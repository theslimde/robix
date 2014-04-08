#pragma once

#include <stdint.h>

namespace robix
{

class Kernel
{
public:

    Kernel();

    void boot();

    int run();

private:

    const char* kernelName_ = "Robix";
    const uint8_t kernelMajorVersion_ = 1;
    const uint8_t kernelMinorVersion_ = 0;
};

}
