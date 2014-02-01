#include <iostream>
#include <cmath>//cos,pow,atan
#include <sys/time.h>//gettimeofday
#include <stdlib.h>//srand
//integrates two functions (one original and other is flat version of that funciton)
//using Monte Carlo and compares the errors if requested

//function prototypes
float original_funct(float);
float flat_funct(float);
float rand_generator(float,float);
float error(int,float[],float,float(float));

using namespace std;

//start of code

int main()
{
  int points;
  float min_bound=-10.0, max_bound=10.0,x,y,mean=0.0,flat_mean=0.0,weight;
  float flat_min_bound=-atan(10),flat_max_bound=atan(10),flat_weight;
  char answ;
  cout << "How many points would you like to simulate? ";
  cin >> points;
  float x_array[points],y_array[points];//required for error analysis
  cout << "Would you like to see the error analysis?(y/n) ";
  while (answ!='y' && answ!='n'){
    cin >> answ;
    switch (answ){
    case 'y':
      break;
    case 'n':
      break;
    default:
      cerr << "Invalid answer! (expecting 'y' or 'n')" << endl << "Try again: ";
    }
  }
  weight=(max_bound-min_bound)/((float) points);
  flat_weight=(flat_max_bound-flat_min_bound)/((float) points);
  for (int j = 0; j < points; j++){
    x=rand_generator(min_bound,max_bound);
    y=rand_generator(flat_min_bound,flat_max_bound);
    if (answ=='y'){//executes if error analysis is requested
      x_array[j]=x;
      y_array[j]=y;
    }
    mean+=weight*original_funct(x);
    flat_mean+=flat_weight*flat_funct(y);
  }
  cout << "I have simulated "<<points<<" points" << endl << "Integral of the original function is " <<
    mean << endl << "Integral of the flat functon is " << flat_mean << endl;
  if (answ=='y'){
    cout <<"---------------------------" << endl;
    cout << "Error analysis:" << endl << "Error using original function: " << error(points, x_array,mean,original_funct) <<
      endl<< "Error using flat function: " << error(points, y_array,flat_mean,flat_funct) << endl;
  }
  return 0;
}

float original_funct(float var)
{
  return (1.0+0.25*cos(var))/(1+pow(var,2));
}

float flat_funct(float var)
{
  return 1.0+0.25*cos(tan(var));
}

float rand_generator(float min, float max)
//returns a random number between min and max
{
  struct timeval time; 
  gettimeofday(&time,NULL);
  srand((time.tv_sec * 1000) + (time.tv_usec / 1000));//seed for rand()
  return (float) rand()/(RAND_MAX)*(max-min)+min;
}

float error(int points, float x[], float mean,float f(float x))
//args: int points - number of data points, float x[] - array of random datapoints, float mean - mean value of data points, f(x) - evaluated function
//return: monte carlo error of f(x) evaluated 
{
  float sum=0.0, sum_mean=0.0;
  for (int i = 0; i < points; i++){
    sum+=pow(f(x[i]),2);//sum of squares of f @ x[i] 0<=i<points
    sum_mean+=f(x[i]);
  }
  sum=sum/(float) points;
  sum_mean=pow(sum_mean/(float) points,2);//square of sum of f @ x[i] 0<=i<points
  return sqrt(abs(sum-sum_mean)/(float) points);
}
