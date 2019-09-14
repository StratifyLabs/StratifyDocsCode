
#include <cstdio>
//md2code:include
#include <sapi/fs.hpp>
#include <sapi/var.hpp>

int main(int argc, char * argv[]){
{
//md2code:main
File f;
String str;

//create a new file and write a string to it
f.create(
   arg::DestinationFilePath("/home/myfile.txt"),
   arg::IsOverwrite(true)
   );
str = "Hello New File!\n";
f.write(str);
f.close();

 //Now open the file we just closed
f.open(
  arg::FilePath("/home/myfile.txt"),
  OpenFlags::read_only()
  );
str = "";
str = f.gets(); //reads a line from the file
f.close();

//This is what was read from the file
printf("The String is %s\n", str.cstring());

File::remove(
  arg::SourceFilePath("/home/myfile.txt")
 ); //delete the file

int fd;
if(1){
  File file;
  file.open(
    arg::FilePath("/home/file.txt"),
    OpenFlags::read_only()
  );
  fd = file.fileno();
  file.set_keep_open(); //will keep the file open after ~File()
  //~File() is called here
 }

char buffer[16];
read(fd, buffer, 16); //OK because file.set_keep_open() was used
 return 0;
}

	return 0;
}
