#ifndef __DEVICE__
#define __DEVICE__

#define CL_TARGET_OPENCL_VERSION 120
#include <CL/cl.hpp>

class Device
{
  cl::Device device;
  cl::CommandQueue queue;

public:
  Device();
  Device(cl::Device &, cl::Context &);
  ~Device();

  cl::Device GetDevice();
  cl::Context Context();
  cl::CommandQueue Queue();
};
#endif
