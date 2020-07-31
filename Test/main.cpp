#include <iostream>
#include <CLMat/CLMat.hpp>
#include <chrono>
#include <random>

int main()
{
  System::Detect();

  static Device AMD_GPU;

  AMD_GPU=System::GetDevice(0, 0);

  int m=2048;
  int n=3000;
  int k=5000;

  cl_float *h;
  cl_float *t;

  h=new cl_float[m*k];
  t=new cl_float[k*n];

	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_real_distribution<> dist(0, 1);

	for(int i=0; i<m*k; i++)
	h[i]=float(i);

  for(int i=0; i<n*k; i++)
  t[i]=float(2*i);

  CLMat<&AMD_GPU, float> a(m, k);
  CLMat<&AMD_GPU, float> b(k, n);
  CLMat<&AMD_GPU, float> c(m, n);

  a.Set(h);
  b.Set(t);

  Multiply(a, b, c);

  auto start = std::chrono::steady_clock::now();
  Multiply(a, b, c);
  auto end = std::chrono::steady_clock::now();

  auto time=std::chrono::duration_cast<std::chrono::nanoseconds>(end-start).count();

  std::cout << "Time Elapsed: " << time*1e-6 << " ms" << std::endl;

  c.Print();

  delete[] h;
  delete[] t;

  return 0;
}
