
#include <cstdio>
//md2code:include
#include <sapi/sys.hpp>
//md2code:include
#include <sapi/sys.hpp>
#include <sapi/inet.hpp>
#include <sapi/fs.hpp>

int main(int argc, char * argv[]){
  {
    //md2code:main
    Printer p;
    p.open_object("System Information") << SysInfo::get() << p.close();
    
  }
  {
    //md2code:main
    Printer p;
    //whole object only prints with debug verbose level
    p.open_array("keys", Printer::MESSAGE);
    p.info("Hello");
    p.info("Hello");
    p.info("Hello");
    p.warning("Hello");
    p.message("Hello");
    p.message("Hello");
    p.warning("Hello");
    p.close_array(); //close_array() and close_object() are interchangeable
    
  }
  {
    //md2code:main
    Printer p; //printer is now an array
    p.close_array();
    p.open_object(""); //top level type is an object
    
  }
  {
    //md2code:main
    Printer p;
    //whole object only prints with debug verbose level
    p.open_object("keys", Printer::DEBUG);
    p.key("key0", "value0");
    p.key("key1", "value1");
    p.key("key2", "value2");
    p.close_object();
    
  }
  {
    //md2code:main
    Printer p;
    
    p.progress_key() = var::ConstString("downloading");
    Socket socket;
    HttpClient http_client(socket);
    DataFile data_file(OpenFlags::append_read_write());
    
    //download file to data_file and print the progress using #'s
    http_client.get(
      arg::UrlEncodedString("http://some.url/file"),
      arg::DestinationFile(data_file),
      p.progress_callback()
      );
    
  }
  {
    //md2code:main
    Printer p;
    p.open_object("empty object") << p.close();
    p.open_array("messages", Printer::MESSAGE) << "hello" << p.close();
    
  }

  return 0;
}
