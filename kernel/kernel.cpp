#include "kernel.hpp"

#include "driver/vga/basicvga.hpp"

robix::Kernel::Kernel() {
}

void robix::Kernel::boot() {
    basicVga console;

    console << "Welcome to " << kernelName_;
    console << " ver " << kernelMajorVersion_ << '.' << kernelMinorVersion_;

    console << basicVga::control::endl;

    console << "Booting kernel ..." << basicVga::control::endl;
}

int robix::Kernel::run() {

    while(1);

    return 0;
}
