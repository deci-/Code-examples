//Function Definitions
#include "Matrix.h"

Matrix::Matrix()
{
  for (int i=0; i<=N; i++)
    for (int j=0; j<=N; j++)
      newMatrix[i][j]=0;
  newSize=0;
}

Matrix::Matrix(float matrix[N][N],int size)
{
  for (int i=0; i<=size; i++)
    for (int j=0; j<=size; j++)
      newMatrix[i][j]=matrix[i][j];
  newSize=size;
}

Matrix::~Matrix(){

}

void Matrix::printMatrix()
{
  for(int i=0; i<newSize; i++){    //This loops on the rows 
    for(int j=0; j<newSize; j++) //This loops on the columns
      cout << newMatrix[i][j]  << "  ";
    cout << endl;
  }
}

void Matrix::printMatrix(float matrix[N][N],int size)
{
  for(int i=0;i<size;i++) {
    for(int j=0;j<size;j++) {
      if (matrix[i][j]==-0.00 || matrix[i][j]==0.000)  // because I use float, i would get some random small number instead of 0 , like -0.00 (because of precision aswell)
	cout << "    0" ;
      else 
	if (matrix[i][j]>0)
	  cout << "  " << fixed << setprecision (3)  << matrix[i][j];
	else
	  cout << "  " << fixed << setprecision (2)  << matrix[i][j];
    }
    cout << endl;
    }
}

void Matrix::printSize()
{
  cout << newSize << endl;
}

int Matrix::getSize()
{
  return newSize;
}

float Matrix::determinant()
{
  float det=0,sign=1,dummy[N][N];
  int m,n;
  if (newSize == 1) 
    det = newMatrix[0][0];
  else {
    det=0;
    for(int k=0;k<newSize;k++) {
      m=0;
      n=0;
      for(int i=0;i<newSize;i++) {
	for(int j=0;j<newSize;j++) {
	  dummy[i][j]=0;
	  if(i!=0 && j!=k) {
	    dummy[m][n]=newMatrix[i][j];
	    if(n<(newSize-2))
	      n++;
	    else {
	      n=0;
	      m++;
	    }
	  }
	}
      }
      det=det+sign*(newMatrix[0][k]*dummyDeterminant(dummy,newSize-1));
      sign=-1*sign;
    }
  }
  return det;
}

float Matrix::dummyDeterminant(float sqmatrix[N][N],int size)
{
  float det=0,sign=1,dummy[N][N];
  int m,n;
  if (size == 1) 
    det = sqmatrix[0][0];
  else {
    det=0;
    for(int k=0;k<size;k++) {
      m=0;
      n=0;
      for(int i=0;i<size;i++) {
	for(int j=0;j<size;j++) {
	  dummy[i][j]=0;
	  if(i!=0 && j!=k) {
	    dummy[m][n]=sqmatrix[i][j];
	    if(n<(size-2))
	      n++;
	    else {
	      n=0;
	      m++;
	    }
	  }
	}
      }
      det=det+sign*(sqmatrix[0][k]*dummyDeterminant(dummy,size-1));
      sign=-1*sign;
    }
  }
  return det;
}

void Matrix::cofactor(float fac[N][N])
{
  float b[N][N];
  int p,q,m,n,i,j;
  for(q=0;q<newSize;q++) {
    for(p=0;p<newSize;p++) {
      m=0;
      n=0;
      for(i=0;i<newSize;i++) {
	for(j=0;j<newSize;j++) {
	  b[i][j]=0;
	  if(i!=q && j!=p) {
	    b[m][n]=newMatrix[i][j];
	    if(n<(newSize-2))
	      n++;
	    else {
	      n=0;
	      m++;
	    }
	  }
	}
      }
      fac[q][p]=pow(-1,q+p)*dummyDeterminant(b,newSize-1);
    }
  }
}

void Matrix::inverse(float inv[N][N])
{
  int i,j;
  float b[N][N],fac[N][N],det;
  cofactor(fac);
  for(i=0;i<newSize;i++)
    for(j=0;j<newSize;j++)
      b[i][j]=fac[j][i];

  det=determinant();
  inv[i][j]=0;
  
  if (det != 0)
    for(i=0;i<newSize;i++)
      for(j=0;j<newSize;j++)
	inv[i][j]=b[i][j]/det;
  else
    cerr << "Error! Matrix is not invertible!" << endl;     
}

void Matrix::product(float product[N][N])
{
  int dim[4];
  float matrix1[N][N],matrix2[N][N];
  //initialize product to zero
  for (int i = 0; i <= N; i++)
    for (int j = 0; j <= N; j++)
      product[i][j]=0;
  //gets correct matrix dimensions
  while(1)
    {
      cout << "Enter inner and outer dimensions of the first matrix: " << endl;
      cin >> dim[0] >> dim[1];
      cout << "Enter inner and outer dimensions of the second matrix: " << endl;
      cin >> dim[2] >> dim[3];
      if (dim[1]!=dim[2])
	  cerr << "Error! Invalid matrix dimensions!" << endl;
      else break;
    }
  //gets the matrices
  cout << "Enter the first matrix:" << endl; 
  for(int j=0; j<dim[0]; j++)//loops through columns
    for(int i=0; i<dim[1]; i++)//loops through rows
      cin >> matrix1[j][i];
  cout << "Enter the second matrix:" << endl;
  for(int j=0; j<dim[2]; j++)//loops through columns
    for(int i=0; i<dim[3]; i++)//loops through rows
      cin >> matrix2[j][i];
  cout << setprecision(3);

  //multiplies the matricies and writes the result into product
  for (int row = 0; row < dim[0]; row++){
    for (int col = 0; col < dim[3]; col++){
      // Multiply the row of A by the column of B to get the row, column of product.
      for (int inner = 0; inner < dim[1]; inner++){
	product[row][col] += matrix1[row][inner] * matrix2[inner][col];
      }
    }
  }
}
