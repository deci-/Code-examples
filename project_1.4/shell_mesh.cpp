#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

int main(int argc, char *argv[])
{ 
  int N=atoi(argv[1]);//mesh size
  float ground = atoi(argv[2]);
  float potential;
  if (argc==4)//if potential is given assign it 
    potential = atoi(argv[3]);
  else if (argc==3)//if not set it to zero
    potential=0;
  else
    cerr << "Error! Command line argument is missing!" << endl;
  
  char **bmesh = new char*[N];
  float **mesh = new float *[N];
  for (int i=0; i<N; i++){
    bmesh[i]=new char[N];
    mesh[i]=new float[N];
  };

  //read in shell_mesh.dat
  char ch;
  ifstream f_in ("shell_mesh.dat");
  for (int i=0; i<N; i++){
    for (int j=0; j<N; j++){
      f_in >> ch;
      if (ch == '#')
	bmesh[i][j]='.';
      else 
	bmesh[i][j]='#';
    }
  }
  
  ofstream f_out ("shell_floatmesh.dat");
  ofstream f_out2 ("shell_charmesh.dat");
  for (int i=0; i<N; i++){
    for (int j=0; j<N; j++){
      f_out2 << bmesh[i][j];
      if (bmesh[i][j]=='.'){
	mesh[i][j] = ground;
	f_out << ground << " ";
      }
      else{ 
	mesh[i][j]=potential;
	f_out << potential << " ";
      } 
    }
    f_out << endl;
    f_out2 << endl;
  }
  

  for (int i=0; i<N; i++){
    delete bmesh[i];
    delete mesh[i];
  }
  delete bmesh;
  delete mesh;

  f_in.close();
  f_out.close();
  f_out2.close();

  return 0;
}
