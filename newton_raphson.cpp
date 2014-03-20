#include <iostream>
#include <cmath>
#include <cstdlib>
//evaluates roots of an equation at "f" using Newton-Raphson method
//call "./newton_raphson guess conv"
//change function that is evaluated by changing the return value in "function"
//WARNING! You must manually differenciate that function and put the //expression for derivative in the return of df


//function prototypes
void newton_raphson(double,double &,double);

using namespace std;

//start of code

double f(double x)
{
  return x*x-3*x-4;
}

double df(double x)
{
  return 2*x-3;
}

int main(int argv, char **argc)
{
  if (argv!=3){
    cerr << "Error! Incorrect number of command line arguments!" << endl
	 << "Correct call ./newton_raphson r_guess err \nr_guess is a value which you think might be close to a root and conv is convergence factor\n"
	 << "(expecting 2, provided " << argv-1 << ")" << endl;
    exit(1);
  }

  double r_guess=atof(*(argc+1)),
    conv=atof(*(argc+2)),
    r;

  newton_raphson(r_guess,r,conv);//passing reference to r to n-r function
  cout << "Success! " << " r ~= " << r << endl;

  return 0;
}

void newton_raphson(double r_old, double & r, double conv)
{
  double r_test;
  int counter=0,max_itter=1000;
  while (1){
    counter ++;
    r_test = r_old - f(r_old)/df(r_old);
    if (abs(r_old-r_test)<conv)
      break;
    cout << "Iteration number " << counter << endl;
    cout << "old root= " << r_old << ";\tnew root = " << r_test<<";"<< endl;
    r_old=r_test;
    if (counter>=max_itter){
      cerr << "Error! Calculation exhausted after " << counter << " iterations\nPosibble reasons:\ndf is not a correct derivative expression of f\nGuess is too far from the root\nFunction has no roots\nGuess is in a flat region (df=0)\nCyclic iterations"<<endl;
      exit(1);
    } 
    cout << "---------------------------------------" << endl;
  }
  r=r_test;
}


