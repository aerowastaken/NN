#ifndef __DEVICE__

#include "Utils.hpp"
#include "Device.hpp"

Device::Device()
{

}

Device::Device(cl::Device &d, cl::Context &c)
{
  device=d;
  // CL_QUEUE_OUT_OF_ORDER_EXEC_MODE_ENABLE |
  queue=cl::CommandQueue(c, device, CL_QUEUE_PROFILING_ENABLE, &Utils::err);
  Utils::checkErr(Utils::err, "Creating Queue");
}

Device::~Device()
{

}

cl::Device Device::GetDevice()
{
  return device;
}

cl::Context Device::Context()
{
  return queue.getInfo<CL_QUEUE_CONTEXT>();
}

cl::CommandQueue Device::Queue()
{
  return queue;
}
#endif
