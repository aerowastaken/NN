#ifndef __CLMAT__
#define __CLMAT__

#include <System/System.hpp>

template<Device *D, class T>
class CLMat
{
  cl::Buffer v;

  int m;
  int n;

  Device *d;

public:
  CLMat<D, T>();
  CLMat<D, T>(int, int);
  ~CLMat<D, T>();

  void Set(T*);
  void Get(T*);

  void Print();

  template<Device *E, class U>
  friend void Multiply(const CLMat<E, U> &, const CLMat<E, U> &, CLMat<E, U> &);
};

#include "CLMat.cpp"
#endif
