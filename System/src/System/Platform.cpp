#ifndef __PLATFORM__

#include "Platform.hpp"
#include "Utils.hpp"

Platform::Platform()
{

}

Platform::~Platform()
{

}

Platform::Platform(cl::Platform &_platform)
{
  platform=_platform;

  std::vector<cl::Device> temp;
  platform.getDevices(CL_DEVICE_TYPE_ALL, &temp);

  cl_context_properties cprops[3] = {CL_CONTEXT_PLATFORM, (cl_context_properties)(platform)(), 0};

  context=cl::Context(CL_DEVICE_TYPE_ALL, cprops, NULL, NULL, &Utils::err);
  Utils::checkErr(Utils::err, "Creating Context");

  for(auto &i: temp)
  devices.push_back(Device(i, context));
}

Device& Platform::GetDevice(int d)
{
  return devices[d];
}

int Platform::Size()
{
  return devices.size();
}
#endif
