//Header ==> Function Declarations
#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

const int N = 10;

#ifndef MATRIX_H
#define MATRIX_H

class Matrix {
public:
  //Defaut constructor
  Matrix();

  //Overloaded constructor
  Matrix(float[N][N],int);

  //Defaut destrucor
  ~Matrix(); 
  
  //Print functions
  void printMatrix();
  void printMatrix(float[N][N],int);
  void printSize();
  
  //Return functions
  int getSize();

  //Matrix determinant functions
  float determinant();
  float dummyDeterminant(float[N][N],int);
       //required for a call inside determinant(),cofactor() and inverse() function

  //Matrix cofactor function
  void cofactor(float[N][N]);
  //Inverse function
  void inverse(float[N][N]);
  //Multiplication function
  void product(float[N][N]);
  
private:
  //Member Variables
 int newSize;
 float newMatrix[N][N];
};

#endif
