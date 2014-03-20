#include <iostream>
#include <stdlib.h>//srand
#include <sys/time.h>//gettimeofday
#include <fstream>//fopen,etc.
#include <math.h>//pow()

//function prototypes
void rand_point(float[],float[],int);
using namespace std;

//boundaries x^2+y^2=a^2 and (x-c)^2+y^2=b^2
//equation of a circle (x-x0)^2 + (y-y0)^2 = r^2 where centre of a circle is at (x0,y0)
//x^2+y^2=a^2 - centre at (0,0), radius a; (x-c)^2+y^2=b^2 - centre at (c,0), radius b;
//allowed x coordinates must be in range -a<x<c-b => 0<x+a<a-b+c 
//moment of inertia can be approximated as the sum of N elements of r^2*dm where dm=m/N
//r is the distance of a data point from the axis of rotation, in this case point (0,0) 
//./inertia n will simulate n data points
//./inertia n datafile.dat will simulate n data points and write them in datafile.dat


//start of the code

int main(int argc, char* argv[])
{
  float data_x[5000]={0},data_y[5000]={0},mass,d_mass,mom_of_inertia=0.0; //infinitesimal mass element
  int N = atoi(argv[1]);//number of data points used
  cout << "Enter the total mass of the crescent: ";
  cin >> mass;
  d_mass=mass/((float) N);
  rand_point(data_x,data_y,N);//generates N x and y coordinates
  //sums up N r^2*dm elements to get the approximation for the moment of inertia
  for (int j = 0; j < N; j++){
    mom_of_inertia+=d_mass*(pow(data_x[j],2)+pow(data_y[j],2));
  }
  cout << "Moment of inertia of the crescent of mass " << mass << " approximated with " << N << " data points is " <<
    mom_of_inertia << endl;
  if (argc == 3){//if datafile is provided, program writes the datapoints into that file
    cout << "Writing data points into a file " << argv[2] << "..." << endl;
    ofstream f_out (argv[2]);//opens out_file for writing
    for (int i = 0; i < N; i++){//writes x and y coordinates into a file out_file
      f_out << data_x[i] << " " << data_y[i] << endl;
    }
    cout << "Closing " << argv[2] << "..." << endl;
    f_out.close();//closes file
  }
  cout << "Exiting C++ program..." << endl;
  return 0;
}

void rand_point(float data_x[5000], float data_y[5000],int N)
{
  int i=0;
  float temp_x, temp_y,a=7,b=6,c=3; // b<a, a-b<c<a+b;
  struct timeval time; 
  gettimeofday(&time,NULL);
  srand((time.tv_sec * 1000) + (time.tv_usec / 1000));//seed for rand()
  cout << "Starting Simulation..." << endl;
  while (i < N){//picks N data points in total
    //change the interval for more efficient algorithm 
    temp_x = (float) 2*a*rand()/(RAND_MAX)-a;//generates x values in the interval -a<y<a
    temp_y = (float) 2*a*rand()/(RAND_MAX)-a;//generates y values in the interval -a<y<a
    //picks out points that are within the circle of radius a but not within the circle of radius b
    if(pow(temp_x,2)+pow(temp_y,2)<pow(a,2) && pow(c-temp_x,2)+pow(temp_y,2)>pow(b,2)){
      data_x[i]=temp_x;
      data_y[i]=temp_y;
      i++;
    } 
  }
}
