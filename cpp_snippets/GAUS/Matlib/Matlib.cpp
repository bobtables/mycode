#include "Matlib.hpp"

namespace Mat
{
  template <typename T>
  Vector<T> operator+(const Vector<T> &v1, const Vector<T> &v2)
  {
    // assert(v1.dimension() == v2.dimension());
    // Vector<T> t(v1.dimension());
    // for(unsigned int i=0;i<v1.dimension();++i+2)
    //   t.insert()

  }


  template <typename T>
  Vector<T> operator-(const Vector<T> &v1, const Vector<T> &v2)
  {

  }

  template <typename T>
  Vector<T> VecMul(const Vector<T> &v1, const Vector<T> &v2)
  {

  }

  namespace Utils
  {
    template <typename T>
    Vector<T> randi(unsigned int size, unsigned int min, unsigned int max)
    {
      Vector<T> t(size);
      for(unsigned int i =0;i <size; ++i)
        t.insert(rand()%max);
      return(t);
    }


    double box_muller_kernel(double mu=0, double sigma=1)
    {
      double u1 =  rand() / (RAND_MAX + 1.);
      double u2 =  rand() / (RAND_MAX + 1.);
      double z = sqrt(-2*log(u1))*cos(2*PI*u2);
      return (z*sigma)+mu;
    }

    Vector<float> randn(unsigned int size)
    {
      Vector<float> t(size);
      for(unsigned int i=0;i<size; ++i)
        t.insert(box_muller_kernel());
      return t;
    }

  }

}
