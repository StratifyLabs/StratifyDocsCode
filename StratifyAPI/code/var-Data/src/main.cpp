
#include <cstdio>
//md2code:include
#include <sapi/var.hpp>
//md2code:include
#include <sos/dev/pio.h>

int main(int argc, char * argv[]){
  {
    //md2code:main
    
    //allocation 64 bytes
    Data block = Data( arg::Size(64) );
    
    //use DataReference inherited methods
    block.fill<u32>(0xaabbccdd);
    printf("First Byte: 0x%x\n",
      block.at_const_char(
        arg::Position(0)
        )
      );
    
    printf("Second Word: 0x%lx\n",
      block.at_u32(
        arg::Position(1)
        )
      );
    
    //once ~Data() is called the memory is freed
    
  }
  {
    //md2code:main
    pio_attr_t pio_attributes;
    
    Data data;
    data.refer_to(pio_attributes);
    
    if( data.is_reference() == true ){
      printf("this will print\n");
    }
    
    data.allocate( arg::Size(64) );
    
    if( data.is_reference() == true ){
      printf("this won't print\n");
    }
    
  }
  {
    //md2code:main
    Data a;
    if( a.size() == 0 ){
      printf("yep!\n");
    }
    
    if( a.is_valid() ){
      printf("nope!\n");
    }
    
  }
  {
    //md2code:main
    Data a = Data( arg::Size(128) );
    a.fill(0);
    Data b(a); //b has has a copy of a
    
  }
  {
    //md2code:main
    //data is moved from unnamed object to moved_to_object
    Data moved_to_object = Data( arg::Size(64) );
    
  }
  {
    //md2code:main
    Data source_data(arg::Size(64));
    Data destination_data(arg::Size(64));
    source_data.fill<u8>(0x0a);
    destination_data.fill<u8>(0x0b);
    destination_data.append(
      arg::SourceData(source_data)
      );
    
  }
  {
    //md2code:main
    pio_attr_t pio_attributes;
    Data destination_data(arg::Size(64));
    destination_data.fill<u8>(0x0b);
    destination_data.append(pio_attributes);
    
  }
  {
    //md2code:main
    Data small_block(arg::Size(1));
    printf(
      "Size is %ld, Capacity is %ld\n",
      small_block.size(),
      small_block.capacity()
      );
    
    //size will be one, capacity will be minimum_capacity()
    
    //this will just reassign size without using malloc/free
    small_block.allocate(arg::Size(2));
    
  }
  {
    //md2code:main
    
    Data data(arg::Size(64));
    
    if( data.is_reference() ){
      printf("this won't print\n");
    }
    
    u32 some_value = 64;
    data.refer_to(some_value); //64 bytes freed
    
    if( data.is_reference() ){
      printf("this will print: %ld\n",
        data.at_u32(0)
      );
    }
    
  }

  return 0;
}
