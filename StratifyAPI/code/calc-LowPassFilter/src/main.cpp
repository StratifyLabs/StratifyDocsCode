
#include <cstdio>
//md2code:include
#include <sapi/hal.hpp>
#include <sapi/calc.hpp>

int main(int argc, char * argv[]){
  {
    //md2code:main
    //first initialize a filter with a value of 0 and with an averaging constant of 0.1
    LowPassFilterS32 filter(0, LOW_PASS_FILTER_S32_ALPHA(0.1));
    //Or do:  LowPassFilter<u16, s32, s64> filter(0, LOW_PASS_FILTER_S32_ALPHA(0.1));
    
    //now use the ADC to get some data
    Adc adc(0);
    u16 sample;
    adc.initialize();
    
    for(u32 i=0; i < 100; i++){  //take 100 samples and filter as we go
       adc.read(
          arg::Location(0),
          arg::DestinationBuffer(&sample),
          arg::Size(sizeof(sample))
       );
       filter << sample;
       printf("%ld %d %ld;\n", i, sample, filter.present_value());
    }
    
  }

  return 0;
}
