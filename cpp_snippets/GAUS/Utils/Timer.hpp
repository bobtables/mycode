
#if __cplusplus <= 199711L
  #error This library needs at least a C++11 compliant compiler
#endif

#include <chrono>
#include <ctime>
#include <cassert>



namespace Utils
{
  class Timer
  {
  public:
    Timer(){ id_ = timer_id_++; }
    void Start() { start_ = std::chrono::system_clock::now(); }
    void Stop() { end_ = std::chrono::system_clock::now(); }

    double Elapsed()
    {
      assert(end_ >= start_ );
      elapsed_ = end_ - start_;
      return elapsed_.count();
    }

    double Elapsed_usec()
    {
      Elapsed();
      return std::chrono::duration_cast<std::chrono::microseconds>(elapsed_).count();
    }

    unsigned int id(){ return id_; }

  private:
    static unsigned int timer_id_;
    unsigned int id_;
    std::chrono::system_clock::time_point start_, end_;
    std::chrono::duration<double> elapsed_;

  };

  unsigned int Timer::timer_id_ = 1;

}
