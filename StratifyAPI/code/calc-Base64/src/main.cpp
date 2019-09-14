
#include <cstdio>
//md2code:include
#include <sapi/calc.hpp>
#include <sapi/var.hpp>
#include <sapi/fs.hpp>

int main(int argc, char * argv[]){
  {
    //md2code:main
    Data data_to_encode(arg::Size(128));
    data_to_encode.fill<u8>(32);
    
    String encoded_string = Base64::encode(
      arg::SourceData(data_to_encode)
    );
    
    //You can then decode the data using this code snippet:
    
    Data original_data = Base64::decode(
      arg::Base64EncodedString(encoded_string)
    );
    
    if( original_data == data_to_encode ){
      printf("It works!\n");
    }
    
  }
  {
    //md2code:main
    String encoded_string;
    //assign base64 encoded string
    Data raw_data;
    
    raw_data = Base64::decode(encoded_string);
    
  }
  {
    //md2code:main
    Data raw_data(arg::Size(64)); //raw binary data that needs to be encoded
    raw_data.fill<u8>(0xaa);
    String result = Base64::encode(arg::SourceData(raw_data));
    printf("Encoded string is '%s'\n", result.cstring());
    
  }
  {
    //md2code:main
    File source;
    File destination;
    
    source.open(
      arg::FilePath("/home/raw_data.dat"),
      OpenFlags::read_only()
      );
    
    destination.create(
      arg::DestinationFilePath("/home/base64_encoded.txt"),
      arg::IsOverwrite(true)
      );
    
    Base64::encode(
      arg::SourceFile(source),
      arg::DestinationFile(destination)
      );
    
  }

  return 0;
}
