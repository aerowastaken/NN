#ifndef __SYSTEM__
#include "System.hpp"

int size=0;
std::vector<Platform> System::platforms;

void System::Detect()
{
  std::vector<cl::Platform> temp;
  cl::Platform::get(&temp);

  for(auto &i: temp)
  platforms.push_back(Platform(i));
}

Platform& System::GetPlatform(int p)
{
  return platforms[p];
}

Device& System::GetDevice(int p, int d)
{
  return platforms[p].GetDevice(d);
}

int System::Size()
{
  return platforms.size();
}
#endif
