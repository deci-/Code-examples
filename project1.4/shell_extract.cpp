#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>

using namespace std;

int main(int argc, char *argv[])
{
  if (argc != 2){
    cerr << "Error! Wrong number of command line arguments" << endl;
    exit(-1); 
  }
  string target = argv[1],str;
  int value;
  
  ifstream f_in ("inst.txt");;
  while (!f_in.eof()){
    f_in >> str;
    if (str.string::compare(target)==0){
      f_in >> value;
      return value;
    }
  }
  
  f_in.close();
  return 0;
}
