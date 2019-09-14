
#include <cstdio>
//md2code:include
#include <sapi/chrono.hpp>

int main(int argc, char * argv[]){
  {
    //md2code:main
    //must be explicitly constructed
    Microseconds duration = Microseconds(5);
    printf("Duration is %ld microseconds\n", duration.microseconds());
    
  }
  {
    //md2code:main
    Microseconds duration = Seconds(5); //converted to microseconds
    printf("Duration is %ld microseconds\n", duration.microseconds());
    
  }
  {
    //md2code:main
    Microseconds duration = Milliseconds(3000); //converted to microseconds
    printf("Duration is %ld microseconds\n", duration.microseconds());
    
  }
  {
    //md2code:main
    Microseconds duration = Nanoseconds(3000); //converted to microseconds
    Microseconds zero = Nanoseconds(999); //converted using truncation -- goes to zero
    printf("Duration is %ld microseconds\n", duration.microseconds());
    printf("Zero is %ld microseconds\n", zero.microseconds());
    
  }

  return 0;
}
