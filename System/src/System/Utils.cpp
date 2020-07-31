#ifndef __UTILS__
#include "Utils.hpp"
#include <iostream>

namespace Utils
{
  void checkErr(cl_int error, const char * name)
  {
    count++;
    
    if (error != CL_SUCCESS) {
      std::cerr << "ERROR: " << name
      << " (" << error << ")" << std::endl;
      exit(EXIT_FAILURE);
    }
  }

  cl_int err=CL_SUCCESS;
  cl_int count=0;
}

#endif
