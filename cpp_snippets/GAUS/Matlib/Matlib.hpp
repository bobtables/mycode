#include <cmath>
#include <ctime>
#include <iostream>
#include <vector>
#include <cassert>

namespace Mat
{

  #define PI 3.141592653589793238

  template <typename T>
  class Vector
  {

  public:
    Vector(unsigned int size){
      dim_ = size;
    }

    void insert(T val)
    {
      vec_.push_back(val);
    }

    void remove()
    {
      vec_.pop_back();
    }

    unsigned int dimension()
    {
      return dim_;
    }

    template <typename T1>
    friend Vector<T1> operator+( Vector<T1> const &v1,  Vector<T1> const &v2);

    template <typename T1>
    friend Vector<T1> operator-( Vector<T1> const &v1,  Vector<T1> const &v2);

    std::vector<T> vec_;

  private:
    unsigned int dim_;


  };



  namespace Utils
  {
    template <typename T>
    Vector<T> randi(unsigned int size, unsigned int min=0, unsigned int max=RAND_MAX);

    // Return single normal random
    double box_muller_kernel();

      Vector<float> randn(unsigned int size);

  }

}
