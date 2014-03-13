#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

int main(int argc, char *argv[])
{
  if (argc!=2)
    cerr << "Error! Command line argument missing!" << endl; 
  int N=atoi(argv[1]);//mesh size

  ofstream f_out ("shell_mesh.dat");
  for (int i=0; i<N; i++){
    for (int j=0; j<N; j++){
      f_out << '#';
    }
    f_out << endl;
  }

  f_out.close();

  return 0;
}
