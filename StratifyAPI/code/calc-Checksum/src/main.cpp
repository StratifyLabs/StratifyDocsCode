
#include <cstdio>
//md2code:include
#include <sapi/calc.hpp>
#include <sapi/var.hpp>

int main(int argc, char * argv[]){
  {
    //md2code:main
    typedef struct MCU_PACK {
     u8 member_a;
     u32 member_b;
     u16 member_c;
     u8 checksum;
    } data_struct_t;
    
    data_struct_t data;
    //set member variables
    data.checksum = Checksum::calc_zero_sum((u8*)&data, sizeof(data));
    
    if( Checksum::verify_zero_sum((u8*)&data, sizeof(data)) == true ){
     //checksum is good
    }
    
  }

  return 0;
}
