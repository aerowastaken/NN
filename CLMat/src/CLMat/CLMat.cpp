#ifdef __CLMAT__

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>

#include <System/Utils.hpp>
#include <clblast.h>


template<Device *D, class T>
CLMat<D, T>::CLMat(): m(0), n(0), d(D)
{
}

template<Device *D, class T>
CLMat<D, T>::CLMat(int _m, int _n): m(_m), n(_n), d(D)
{
  v=cl::Buffer(d->Context(), CL_MEM_READ_WRITE, sizeof(T)*m*n, NULL, &Utils::err);
  Utils::checkErr(Utils::err, "Creating Buffer");
}

template<Device *D, class T>
CLMat<D, T>::~CLMat()
{

}

template<Device *D, class T>
void CLMat<D, T>::Set(T *h)
{
  Utils::err=d->Queue().enqueueWriteBuffer(v, CL_TRUE, 0, m*n*sizeof(T), h, NULL, NULL);
  Utils::checkErr(Utils::err, "Copying to Buffer");
}

template<Device *D, class T>
void CLMat<D, T>::Get(T *h)
{
  Utils::err=d->Queue().enqueueReadBuffer(v, CL_TRUE, 0, m*n*sizeof(T), h, NULL, NULL);
  Utils::checkErr(Utils::err, "Reading from Buffer");
}

template<Device *D, class T>
void CLMat<D, T>::Print()
{
  T *temp;

  temp=new T[m*n];

  Get(temp);

  for(int i=0; i<m; i++)
  {
    for(int j=0; j<n; j++)
    std::cout << temp[j+i*n] << " ";

    std::cout << std::endl;
  }

  delete[] temp;
}

template<Device *D, class T>
void Multiply(const CLMat<D, T> &a, const CLMat<D, T> &b, CLMat<D, T> &c)
{
  auto status = clblast::Gemm(clblast::Layout::kRowMajor,
    clblast::Transpose::kNo, clblast::Transpose::kNo,
    a.m, b.n, a.n,
    T(1.),
    a.v(), 0, a.n,
    b.v(), 0, b.n,
    T(0.),
    c.v(), 0, c.n,
    &a.d->Queue()());
}




















#endif
