
#include <cstdio>
//md2code:include
#include <sapi/chrono.hpp>

int main(int argc, char * argv[]){
  {
    //md2code:main
    wait(Seconds(1)); //wait for one second
    wait(Milliseconds(1000)); //wait for one second
    wait(Microseconds(1000000)); //wait for one second
    
    ClockTime clock_time;
    wait(clock_time); //wait based on a clock time value
    
    Microseconds microseconds;
    microseconds = Milliseconds(100);
    wait(microseconds); //wait based on a microsecond value
    
  }
  {
    //md2code:main
    
    wait(Microseconds(100));
    
    //Milliseconds, Seconds, and Nanoseconds will convert to Microseconds automatically
    wait(Seconds(3));
    wait(Milliseconds(3000));
    wait(Nanoseconds(60000));
    wait(Nanoseconds(999)); //this won't wait because it converts to 0 microseconds
    
  }

  return 0;
}
