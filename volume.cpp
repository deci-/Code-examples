#include <iostream>
#include <ctime>
#include <sys/time.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

//function prototypes
float rand_point(float[],int);
int test(int);

using namespace std;

const int N = 25;//max number of dimensions
const int PI=3.14159;

//start of code

int main()
{
  int dim,test_num,hit=0;
  cout << "Enter number of dimensions: ";
  cin >> dim;
  cout << "Enter the number of test cases: ";
  cin >> test_num;
  for (int i = 0; i < test_num; i++)
    hit+=test(dim);
  cout << "Volume of " << dim << "-dimensional sphere of diameter 1 is " << (float) hit/test_num << endl;
  return 0;
}

float rand_point(float point[N],int dim)
{
  struct timeval time; 
  gettimeofday(&time,NULL);
  srand((time.tv_sec * 1000) + (time.tv_usec / 1000));//seed for rand()
  for (int i = 0; i < dim; i++)//fils in point array with dim number of elements 
    point[i]=((float) rand() / (RAND_MAX));  //random point between 0 and 1
}

int test(int dim)
{
  float centre[N]={0.5},point[N]={0.0},radius=0.5,sum=0.0;
  rand_point(point,dim);//gets a random point
  for (int i = 0; i < dim; i++){//calculates distance of a point from the centre
    sum+=(0.5-point[i])*(0.5-point[i]);
  }
  if ( sqrt(sum)<=radius )//returns 1 if point is within dimensions of the sphere
    return 1;
  else
    return 0;
}
