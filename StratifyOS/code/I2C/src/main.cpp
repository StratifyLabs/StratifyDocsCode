
#include <cstdio>
//md2code:include
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <sos/dev/i2c.h>

int main(int argc, char * argv[]){
  {
    //md2code:main
    
    int fd;
    i2c_attr_t attr;
    u8 data[8];
    
    fd = open("/dev/i2c0", O_RDWR);
    if ( fd < 0 ){
      printf("Error opening peripheral (%d)\n", errno);
    } else {
      attr.o_flags = I2C_FLAG_SET_MASTER;
      attr.freq = 4000000; //Use a 400KHz I2C clock frequency
      if( ioctl(fd, I_I2C_SETATTR, &attr) < 0 ){
        printf("Failed to set peripheral configuration (%d)\n", errno);
        return -1;
      }
    
      //Now use ioctl to setup a transfer operation
      attr.slave_addr[0].addr8[0] = 0x3F; //This is the right-justified 7-bit or 10-bit slave address
      attr.o_flags = I2C_FLAG_PREPARE_PTR_DATA; //This is a "normal", see i2c_trasfer_mode_t for details
      ioctl(fd, I_I2C_SETATTR, &attr);
    
      //now read the I2C:  This will 1) Start 2) write the 8-bit ptr value 3) Restart 4) Read 8 bytes and 5) Stop
      lseek(fd, 0, SEEK_SET); //this is the ptr value
        if ( read(fd, data, 8) < 0 ){
        printf("Error Reading adc0 (%d)\n", errno);
        return -1;
      }
      close(fd);
    }
    
  }

  return 0;
}
