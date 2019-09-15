
#include <cstdio>
//md2code:include
#include <sapi/var.hpp>
#include <sapi/fs.hpp>
//md2code:include
#include <sos/dev/pio.h>
//md2code:include
#include <sapi/var.hpp>
#include <sapi/hal.hpp>

int main(int argc, char * argv[]){
  {
    //md2code:main
    
    File f;
    f.open(
      arg::FilePath("/home/test.txt"),
      OpenFlags::append()
      );
    
    u32 data[4];
    
    f.write(
      arg::SourceData(DataReference(data))
      ); //writes 4 * sizeof(u32) bytes
    //or
    f.write(
      arg::SourceBuffer(data),
      //above cases needn't worry about size
      arg::Size(sizeof(data))
      );
    
  }
  {
    //md2code:main
    const char buffer[16] = {0};
    DataReference read_only_data =
      DataReference(
        arg::ReadOnlyBuffer(buffer),
        arg::Size(16)
      );
    
    if( read_only_data.to_char() == nullptr ){
      printf("this will print (data is read-only)\n");
    }
    
    if( read_only_data.to_const_char() == nullptr ){
      printf("this won't print\n");
    }
    
  }
  {
    //md2code:main
    char buffer[16] = {0};
    DataReference read_write_data =
      DataReference(
        arg::ReadWriteBuffer(buffer),
        arg::Size(16)
      );
    
    if( read_write_data.to_char() == nullptr ){
      printf("this won't print\n");
    }
    
    if( read_write_data.to_const_char() == nullptr ){
      printf("this won't print\n");
    }
    
  }
  {
    //md2code:main
    pio_attr_t pio_attributes;
    
    DataReference data_structure(pio_attributes);
    data_structure.fill<u8>(0);
    
    if( data_structure.to_void() == (void*)&pio_attributes ){
      printf("this will print\n");
    }
    
  }
  {
    //md2code:main
    char buffer[64];
    DataReference a(buffer); //a is 64 bytes
    a.at<char>(arg::Position(0)) = 'a'; //assign 'a' to the first char location
    a.at<u32>(arg::Position(4)) = 0xAAAA5555; //assigns a u32 value assuming a is a u32 array
    u32 value = a.at<u32>(arg::Position(4)); //reads a value as if a is a u32 array
    printf("value is 0x%lx\n", value);
    
  }
  {
    //md2code:main
    char buffer[16];
    
    DataReference data_reference(buffer);
    
    data_reference.fill<u8>(0xaa);
    data_reference.fill<u32>(0xaabbccdd);
    data_reference.fill((u16)0xaa55);
    
  }
  {
    //md2code:main
    pio_attr_t pio_attributes;
    
    DataReference data_structure;
    if( data_structure.is_valid() ){
      printf("this won't print\n");
    }
    
    data_structure.refer_to(pio_attributes);
    
    if( data_structure.is_valid() ){
      printf("this will print\n");
    }
    
  }
  {
    //md2code:main
    pio_attr_t pio_attributes;
    
    DataReference data_structure;
    data_structure.refer_to(pio_attributes);
    data_structure.fill<u8>(0);
    
    if( data_structure.to_void() == (void*)&pio_attributes ){
      printf("this will print\n");
    }
    
  }
  {
    //md2code:main
    char buffer[16];
    
    DataReference data_reference =
      DataReference(
        arg::ReadOnlyBuffer(buffer),
        arg::Size(16)
      );
    
    if( data_reference.to_void() == nullptr ){
      printf("this will print\n");
    }
    
    if( data_reference.to_const_void() == nullptr ){
      printf("this won't print\n");
    }
    
  }
  {
    //md2code:main
    char buffer[16];
    
    DataReference data_reference =
      DataReference(
        arg::ReadWriteBuffer(buffer),
        arg::Size(16)
      );
    
    if( data_reference.to_void() == nullptr ){
      printf("this won't print\n");
    }
    
    if( data_reference.to_const_void() == nullptr ){
      printf("this won't print\n");
    }
    
  }
  {
    //md2code:main
    char buffer[16];
    DataReference data_reference(buffer);
    
    //assume the spi outputs big endian data -- swaps 32-bit words
    data_reference.swap_byte_order();
    data_reference.swap_byte_order(4); //this is the same as calling swap_byte_order()
    
    //or for swapping bytes in 16-bit words
    data_reference.swap_byte_order(2);
    
  }
  {
    //md2code:main
    char buffer[64];
    DataReference a(buffer); //allocate 64 bytes of data
    u32 * value = a.to<u32>(); //casts data as u32*
    const u32 * const_value = a.to<const u32>(); //works with read only data
    if( value == const_value ){
      printf("prints for read-write objects but not read-only\n");
    }
    
  }

  return 0;
}
