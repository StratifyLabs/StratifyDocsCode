
#include <cstdio>
//md2code:include
#include <sapi/chrono.hpp>

int main(int argc, char * argv[]){
  {
    //md2code:main
    wait(Seconds(1)); //wait for one second -- Timer inherits WorkObject so it can use the wait methods statically
    wait(Milliseconds(1000));
    wait(Microseconds(1000000));
    
    ClockTime clock_time;
    wait(clock_time); //wait based on a clock time value
    
    Microseconds microseconds;
    microseconds = Milliseconds(100);
    wait(microseconds); //wait based on a microsecond value
    
  }

  return 0;
}
