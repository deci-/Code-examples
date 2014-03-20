#include <iostream>
#include <cmath>
#include <iomanip>
#include <stdlib.h>
#include <stdio.h>
#include <ctime>

//function prototypes
float f(float);
float trapezoid(float,float,int);
float simpson(float,float,int);
float monte_carlo(float,float,int);

using namespace std;
#define pi = 3.1415;

//start of code

int main()
{
  setprecision(5);
  int sep=0;
  float bound_min,bound_max,step;
  while (sep<=1){//ensures that separation value is positive and greater than one
    cout << "Enter how many separations would you like to make: ";
    cin >> sep;
    if (sep<=1)//prints error message if invalid number of separations is requested
      cerr << "Invalid number of separations (expecting int greater than 1)" << endl;
  }
  cout << "Enter minimum and maximum boundaries of integraton: ";
  cin >> bound_min >> bound_max;
  cout << "Integral of f(x) evaluated using Trapezoidal rule at ["<<bound_min<<":"<<bound_max<<"] is: " << trapezoid(bound_min,bound_max,sep)<< endl;
  cout << "Integral of f(x) evaluated using Simpson's rule at ["<<bound_min<<":"<<bound_max<<"] is: " << simpson(bound_min,bound_max,sep)<< endl;
  cout << "Monte Carlo method: " << monte_carlo(bound_min,bound_max,sep)<<endl;
  return 0;  
}

float f(float x)
//function that is being integrated
{
  return 2+cos(2*sqrt(x));
}

float trapezoid(float bound_min, float bound_max, int sep)
//integrates function f(float x) using trapezoidal rule
//args: floats - minimum and maximum boundaries of integration, int - number of separations in x domain
//return: integral value of f(float x)
{
  int sign=1;
  float sum=0,temp;
  if (bound_min>bound_max){//swaps the boundaries and changes sign before the integral if lower boundary is larger than high boundary 
    sign=-1;
    temp=bound_min;
    bound_min=bound_max;
    bound_max=temp;
  }
  float step=(abs(bound_max-bound_min))/((float) sep);
  float weight=(abs(bound_max-bound_min))/((float) sep-1.0);//calculates correction factor for the integral
  for(float i=(bound_min+step); i<=(bound_max-step); i+=step)//loops through all the cases exept from the boundary ones
    sum+=f(i);
  sum+=0.5*(f(bound_min)+f(bound_max));//adds the boundary cases
  return sign*weight*sum;
}

float simpson(float bound_min, float bound_max, int sep)
//integrates function f(float x) using simpson's rule
//args: floats - minimum and maximum boundaries of integration, int - number of separations in x domain
//return: integral value of f(float x)
{
  int sign=1,n=2;
  float sum=0.0,temp;
  if (bound_min>bound_max){//swaps the boundaries and changes sign before the integral if low boundary is larger than high boundary 
    sign=-1;
    temp=bound_min;
    bound_min=bound_max;
    bound_max=temp;
  }
  float step=(bound_max-bound_min)/((float) sep);
  float weight=(bound_max-bound_min)/((float) sep-1.0);//calculates correction factor for the integral
  for(float i=(bound_min+step); i<=(bound_max-step); i+=step){//loops through all the cases exept from the boundary ones
    if (n%2==0)//adjusts weight factors depending on weather it is an even or odd number of summation
      sum+=(4.0/3.0)*f(i);
    else
      sum+=(2.0/3.0)*f(i);
    n++;
  }
  sum+=(1.0/3.0)*(f(bound_min)+f(bound_max));//adds the boundary cases
  return sign*weight*sum;
}

float monte_carlo(float bound_min, float bound_max, int num)
//integrates function f(float x) using Monte Carlo method
//args: floats - minimum and maximum boundaries of integration, int - number of random evaluations done
//return: integral value of f(float x)
{
  int sign=1;
  float x,sum=0.0,weight,temp;
  if (bound_min>bound_max){//swaps the boundaries and changes sign before the integral if lower boundary is larger than high boundary 
    sign=-1;
    temp=bound_min;
    bound_min=bound_max;
    bound_max=temp;
  }
  srand ((unsigned) (time(0)));//initializing seed for rand()
  weight=(bound_max-bound_min)/((float) num);
  for (int i=1; i<=num; i++){
    //generates a pseudo-random number between min and max boundaries
    x = bound_min + (float) (rand()) /( (float) (RAND_MAX/(bound_max-bound_min)));
    sum+=f(x);
  }
  return sign*weight*sum;
}
