#ifndef __UTILS__
#define __UTILS__

#define CL_TARGET_OPENCL_VERSION 120
#include <CL/cl.hpp>

namespace Utils
{
  extern void checkErr(cl_int, const char*);
  extern cl_int err;
  extern cl_int count;
}
#endif
