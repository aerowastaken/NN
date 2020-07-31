
#ifndef __PLATFORM__
#define __PLATFORM__

#include "Device.hpp"

class Platform
{
  cl::Platform platform;
  cl::Context context;

  std::vector<Device> devices;

public:
  Platform();
  ~Platform();
  Platform(cl::Platform &);
  Device& GetDevice(int);

  int Size();
};
#endif
