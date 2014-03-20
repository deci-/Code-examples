#include "project_header.h"

using namespace std;

int N = 10;

int main ( int argc, char *argv[] )
{
  int * N_ptr = &N;
  string instruction;
  float ground=0.0;

  cin >> instruction;
  if (instruction == "Mesh" || instruction == "mesh")
    cin >> *N_ptr;
  else{
    cerr << "Error! Mesh instruction not found!" << endl;
    exit(1);
  }
  cin >> instruction;
  if (instruction == "Ground" || instruction == "ground")
    cin >> ground;
  else{
    cerr << "Error! Ground instruction not found!" << endl;
    exit(1);
  }

    // we will use dynamic memory, because it is easier to pass around
    // that's how you create a 2D array on the heap:
   float **mesh = new float*[N];
   char **bmesh = new char*[N];
    //void * memset ( void * ptr, int value, size_t num )
    //Sets the first num bytes of the block of memory pointed by ptr to the specified value (interpreted as an unsigned char)
   for (int i = 0; i < N; i++){ 
     mesh[i] = new float[N];
     bmesh[i] = new char[N];
   }
  
  int f;
  char ch;

  ifstream f_in ("shell_floatmesh.dat"); //potentials at boundaries
  ifstream f_in2 ("shell_charmesh.dat");//boundaries 
  for (int i=0; i<N; i++)
    for (int j=0; j<N; j++){
      f_in >> f;
      f_in2 >> ch;
      mesh[i][j]=f;
      bmesh[i][j]=ch;
    }

  f_in.close();
  f_in2.close();

  generateMesh(mesh,bmesh); 
  algorithm(mesh,bmesh,ground);

  for (int i = 0; i < N; i++){
    delete bmesh[i];
    delete mesh[i];
  }
  delete mesh;
  delete bmesh;
  
  return 0;
}    





