#ifndef __SYSTEM__
#define __SYSTEM__

#include "Platform.hpp"

class System
{
  static std::vector<Platform> platforms;

public:
  static void Detect();
  static Platform& GetPlatform(int);
  static Device& GetDevice(int, int);
  static int Size();
};

#endif
