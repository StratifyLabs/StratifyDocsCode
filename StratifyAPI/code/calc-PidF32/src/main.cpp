
#include <cstdio>
//md2code:include
#include <sapi/calc.hpp>
#include <sapi/hal.hpp>

int main(int argc, char * argv[]){
{
//md2code:main
PidF32 pid_loop;
Pwm control(0);
Adc present_value(0);
u16 adc_value;

volatile bool is_active = true;

pid_loop.set_kp(1.0f);
pid_loop.set_ki(0.1f);
pid_loop.set_kd(0.001f);
pid_loop.set_maximum(1000.0f); //max duty cycle
pid_loop.set_minimum(0.0f); //min duty cycle

 //Init the PWM output and ADC input

while( is_active ){
 present_value.read(
  arg::Location(0),
  arg::DestinationBuffer(&adc_value),
  arg::Size(2)
  );
 control.set_channel(
   0,
   pid_loop.calculate_control_variable(
     3.3f * adc_value / 4096.0f
     )
   );
}
}

	return 0;
}
