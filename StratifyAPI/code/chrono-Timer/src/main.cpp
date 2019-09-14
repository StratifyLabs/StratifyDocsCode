
#include <cstdio>
//md2code:include
#include <sapi/chrono.hpp>

int main(int argc, char * argv[]){
  {
    //md2code:main
    Timer t;
    t.start(); //start
    wait(Microseconds(500));
    t.stop();
    printf("value after 500usec is %ld\n", t.microseconds());
    
    t.resume();
    wait(Micrseconds(500));
    t.stop();
    printf("value after another 500usec is %ld\n", t.microseconds());
    
    if( t.is_started() ){
      printf("t has been started (not in reset state)\n");
    }
    
    //comparing to time values
    if( t > Seconds(1) ){
      printf("Greater than a second\n");
    }
    
    if( t > Milliseconds(1) ){
      printf("Greater than a millisecond\n");
    }
    
    if( t < Microseconds(500) ){
      printf("Greater than a microsecond\n");
    }
    
    t.start(); //this will start from zero again
    t.start(); //calling start again has no effect
    if( t.is_running() ){
      printf("t is running\n");
    }
    if( t.is_stopped() ){
      printf("t is not stopped\n");
    }
    t.restart(); //start from zero even if timer is running
    t.reset(); //reset to initial state: not running, stopped and reset
    if( t.is_reset() && t.is_stopped() ){
      printf("t is reset\n");
    }
    if( t.is_started() ){
      printf("this won't print in reset state\n");
    }
    
  }

  return 0;
}
