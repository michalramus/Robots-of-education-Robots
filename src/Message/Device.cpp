#include "Message/Device.hpp"

Device::~Device()
{
    delete[] pins;
    delete values;
}
