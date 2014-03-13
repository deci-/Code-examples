#include <iostream>
#include "Matrix.h"
#include <string.h>
#include <stdio.h>

int getdim();
void getsqmatrix(float[N][N],int);

using namespace std;

int main()
{
  float matrix[N][N]={{0}},co[N][N],inverse[N][N]={{0}},pr[N][N],det,k;
  int size=0;
  char answ;
  //loops until user enters exit command (5)
  while (answ != '5'){
    sleep(1);
    cout << "What would you like to do?" << endl <<
      "Inverse(1)/Cofactor(2)/Multiplication(3)/Determinant(4)" <<
      endl << "Enter (5) to exit:";
    //requests user to enter his choice
    cin >> answ;
    cout << answ << endl;
    //cals getdim and getsqmatrix functions only if user asks for
    //determinant, inverse of cofactor(otherwise it is not necessary)
    if (answ=='1' || answ=='2' || answ=='4'){
      size=getdim();
      getsqmatrix(matrix,size);
    }
    //creates object matrix_1 using class Matrix
    //args: 2d array - square matrix, int - size of the matrix
    Matrix matrix_1(matrix,size);
    switch (answ){
    case '1'://inverse case
      matrix_1.inverse(inverse);
      cout << "Inverse:"<< endl;
      matrix_1.printMatrix(inverse,size);
      break;
    case '2'://cofactor case
      matrix_1.cofactor(co);
      cout << "Cofactor:" << endl;
      matrix_1.printMatrix(co,size);
      break;
    case '3'://product case
      matrix_1.product(pr);
      cout << "Enter the inner dimension: ";
      cin >> k;//issue of not knowing dimensions here
      cout << endl;
      cout << "Product:" << endl;
      matrix_1.printMatrix(pr,k);
      break;
    case '4'://determinant case
      det = matrix_1.determinant();
      cout << "Determinant: " << det << endl;
      break;
    case '5'://exit case
      break;
    default://invalid input case
      cerr << "Invalid command! Try again!" << endl;
    }
  }
  return 0;
}

void getsqmatrix(float matrix[N][N],int size)
//asks user to enter a square matrix
//args: dummy 2d array - matrix, int size of the matrix
//return: doesn't return, just fills in the matrix array
{
  cout << "Enter your a square matrix row by row:" << endl;
  for(int j=0; j<size; j++)
    for(int i=0; i<size; i++)//loops through columns
      cin >> matrix[j][i];//loops through rows
}

int getdim()
//asks user to enter dimension of the square matrix
//args: N/A
//return: int, dimension of the square matrix
{
  int size;
  cout << "Enter the dimension of your square matrix: ";
  cin >> size;
  return size;
}
