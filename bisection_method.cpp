#include <iostream>
#include <cmath>
#include <cstdlib>
//evaluates roots of an equation using bisection method
//call "./bisection a b err" where [a,b] is the range in which you expect to find root(s)
//and err is the error threshold
//change function that is evalueted by changing the return value in "function" 

//function prototypes
void bisection(double,double,double &,double);
bool sign_test(double,double);
bool sign_test(double,double,double);

using namespace std;


//start of code
double function(double x)
{
  return x*x-3*x-4;  
}

int main(int argv, char **argc)
{
  if (argv!=4){
    cerr << "Error! Incorrect number of command line arguments!" << endl
	 << "Correct call ./bisection a b err where [a,b] is the range in which you expect to find root(s) and err is the error threshold\n"
	 << "(expecting 3, provided " << argv-1 << ")" << endl;
    exit(1);
  }
  double a=atof(*(argc+1)),
    b=atof(*(argc+2)),
    err=atof(*(argc+3)),
    r;

  bisection(a,b,r,err);//passing reference to r to bisection function
  cout << "Success! " << " r ~= " << r << endl;

  return 0;
}

void bisection(double a, double b, double & r, double err)
//args:[a,b] - range for location of root(s), reference to radius r, error threshold
//evaluates one root of function between a and b within the error threshold and writes that value into r
//exhausts after "max_itter" iterations and exits if no root has been found
//exits and prints a message if function has no roots in specified range 
{
  double r_test = 0.5*(a+b);//midpoint 
  int counter = 0, max_itter=1000;
  while(1){
    counter ++;
    cout << "Iteration number "<< counter << endl;
    cout << "a = " << a << "; b = "<< b << "; r = " << r_test << endl;
    cout  << "f(a) = " << function(a)
	  << ";  f(b) = " << function(b)
	  << ";  f(r) = " << function(r_test) << endl;
    if (abs(function(r_test)) < err){//while loop break successfully only here
      r=r_test;
      break;
    }
    else if (sign_test(function(a),function(r_test)) && !sign_test(function(b),function(r_test))){ // f(a) and f(r_test) have the same sign
      cout << "f(a) and f(r) have the same sign, a=r" << endl;
      a=r_test;
      r_test = 0.5*(a+b);
    }
    else if (sign_test(function(b),function(r_test)) && !sign_test(function(a),function(r_test))){ // f(b) and f(r_test) have the same sign
      cout << "f(b) and f(r) have the same sign, b=r" << endl;
      b=r_test;
      r_test = 0.5*(a+b);
    }
    else if (sign_test(function(a),function(b),function(r_test))){
      cerr << "Function has no roots in " << "[" << a <<","<< b << "]"<< "!" << endl;
      exit(1);
    }
    else{
      cerr << "Function has more then one root here! Try changing the boundaries" << endl;
      exit(1);
    }
    if (counter>=max_itter){
      cerr << "Error! Calculation exhausted after " << counter << " itterations" << endl;
      exit(1);
    } 
    cout << "---------------------" << endl;
  }
  
}


bool sign_test(double x, double y)
{
  bool answ = x*y>0;
  return answ;
}


bool sign_test(double x, double y, double z)
{
  bool answ = (x*y>0 && x*z>0);
  return answ;
}
