#include "project_header.h"

extern int N;

void algorithm(float **Nmesh, char **Nbmesh, float ground)
{
  int time_before,time_after,dN=50,M=N+2*dN;//for accuracy increase
  int counter=0, counter_vals=M*M, counter_zeros=0;
  float zeroish=0.02;
  float dx=1,dy=1,b=dx/dy;

  //reasigning mesh and bmesh with bigger sides
   float **mesh = new float*[M];
   char **bmesh = new char*[M];
   for (int i = 0; i < M; i++){ 
     mesh[i] = new float[M];
     bmesh[i] = new char[M];
   }
  for(int k=0; k<M; k++)
    for(int l=0; l<M; l++){
      mesh[k][l]=ground;
      bmesh[k][l]='.';
    }
  for(int k=0; k<N; k++)
    for(int l=0; l<N; l++){
      mesh[k+dN][l+dN]=Nmesh[k][l];
      bmesh[k+dN][l+dN]=Nbmesh[k][l];
   }
  
  
  float mesh_old[M][M], mesh_new[M][M];
  for(int k=0; k<M; k++)
    for(int l=0; l<M; l++){
      mesh_old[k][l]=mesh[k][l];
      mesh_new[k][l]=mesh[k][l];
    }
  cout << "Starting Algorithm.." << endl;
  time_before = time(NULL);
  while(1){//runs while the entire mesh has finished converging
    for (int i=1; i<M-1; i++)//runs the algorithm for one timestep 
      for (int j=1; j<M-1; j++)//runs the algorithm for one timestep
	if (bmesh[i][j]!='#')//if the point is not on a boundary run the algorithm
	  mesh[i][j]=(mesh[i+1][j]+mesh[i-1][j]+b*b*mesh[i][j+1]+b*b*mesh[i][j-1])/(2*(1+b*b));
   
    if (counter%1000==0){
      if (counter != 0)//to exclude print message from the 1st itteration
	cout << "I have just done "<< counter/1000 << "k iterations!"<< endl;
      for(int k=0; k<M; k++)//compares current mesh with the mesh before 1k itterations
	for(int l=0; l<M; l++){
	  mesh_old[k][l]=mesh_new[k][l];
	  mesh_new[k][l]=mesh[k][l];
	  if (abs(mesh_old[k][l]-mesh_new[k][l])<zeroish)
	    counter_zeros++;//counts how many elements in the two meshes have finished converging
	}
      if (counter_zeros == counter_vals)//if the whole mesh finished converging breaks
	break;
    }
    counter++;
    counter_zeros=0;
  }
  time_after = time(NULL);
  cout<<"Finished Algorithm!" << endl << "It was running for " << time_after-time_before << " seconds."<<endl;

  
  //creates a datafile for gnuplot
  ofstream f_out ("matrix.dat");
  for (int i = dN; i < N+dN; i++){
    for (int j = dN; j < N+dN;j++){
      // f_out << i << " "<< j << " " << mesh[i][j] << endl;
      f_out << mesh[i][j] << " ";
    }
    f_out << endl;
  }
  cout << "Successfully generated the data file 'data.dat'!" << endl;
  ofstream f_out2 ("data.dat");
  for (int i = dN; i < N+dN; i++){
    for (int j = dN; j < N+dN;j++){
      f_out2 << i-dN << " "<< j-dN << " " << mesh[i][j] << endl;
    }
  }
  cout << "Successfully generated the matrix file 'matrix.dat'!" << endl;  

  for (int i = 0; i < M; i++){
    delete bmesh[i];
    delete mesh[i];
  }
  delete mesh;
  delete bmesh;
  
  f_out.close();//closes file
}
