#include <iostream>
#include <cmath>
#include <cstdlib>
//evaluates roots of an equation at "f" using Secant method
//call "./secant guess1 guess2 conv"
//change function that is evaluated by changing the return value in "function"


//function prototypes
void secant(double,double,double &,double);

using namespace std;

//start of code

double f(double x)
{
  return x*x-3*x-4;
}

int main(int argv, char **argc)
{
  if (argv!=4){
    cerr << "Error! Incorrect number of command line arguments!" << endl
	 << "Correct call ./secant guess1 guess2 conv \nguess1 and guess2 are values which you think might be close to a root and conv is convergence factor\n"
	 << "(expecting 3, provided " << argv-1 << ")" << endl;
    exit(1);
  }

  double r_guess1=atof(*(argc+1)),
    r_guess2=atof(*(argc+2)),
    conv=atof(*(argc+3)),
    r;

  if (abs(r_guess1-r_guess2)<pow(0.1,6)){
    cerr << "Error! The two values that you've guessed are too close to each other!" << endl;
    exit(1);
  }

  secant(r_guess1,r_guess2,r,conv);//passing reference to r to n-r function
  cout << "Success! " << " r ~= " << r << endl;

  return 0;
}

void secant(double r_old, double r_oldest, double & r, double conv)
{
  double r_test;
  int counter=0,max_itter=1000;
  while (1){
    counter ++;
    r_test = r_old - f(r_old)*(r_old-r_oldest)/(f(r_old)-f(r_oldest));
    if (abs(r_old-r_test)<conv)
      break;
    cout << "Iteration number " << counter << endl;
    cout << "old root= " << r_old << ";\tnew root = " << r_test<<";"<< endl;
    r_oldest = r_old;
    r_old=r_test;
    if (counter>=max_itter){
      cerr << "Error! Calculation exhausted after " << counter << " iterations\nPosibble reasons:\ndf is not a correct derivative expression of f\nGuessing too far from the root\nFunction has no roots\nGuess is in a flat region (df=0)\nCyclic iterations"<<endl;
      exit(1);
    } 
    cout << "---------------------------------------" << endl;
  }
  r=r_test;
}


