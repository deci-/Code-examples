#include "project_header.h"

extern int N;

void generateMesh(float **mesh, char **bmesh)
{
    // Boundary b;
  Boundary *b_ptr=NULL;
  string instruction;
  while (!cin.eof()) {
    cin >> instruction;     
    if (instruction == "Point")
      b_ptr = new Point();
    else if (instruction == "Circle") 
      b_ptr = new Circle();
    else if (instruction == "Rectangle") 
      b_ptr = new Rectangle();
    else if (instruction == "Line") 
      b_ptr = new Line();
    else if (instruction == "break")
      break;	
    else
      cerr << "Error in the instructions file!" << endl;
    
    b_ptr->injectInto(mesh, bmesh);
    b_ptr->~Boundary();
  } 
  delete b_ptr;
}

void Point::injectInto (float **mesh, char **bmesh) 
{
  bmesh[x_origin][y_origin]='#';
  mesh[x_origin][y_origin]=potential;
}

void Circle::injectInto (float **mesh, char **bmesh)
{
  int x,y,p; //used by circle plotting algorithm below
  p=3-2*radius;
  x=0;
  y=radius;
  
  mesh[x_origin][y_origin+radius]=potential;
  mesh[x_origin][y_origin-radius]=potential;
  mesh[x_origin+radius][y_origin]=potential;
  mesh[x_origin-radius][y_origin]=potential;
 
  bmesh[x_origin][y_origin+radius]='#';
  bmesh[x_origin][y_origin-radius]='#';
  bmesh[x_origin+radius][y_origin]='#';
  bmesh[x_origin-radius][y_origin]='#';  

  while (x<=y){
    x++;
    if(p<0){
      p+=4*x+6;
    }
    else{
      p+=4*(x-y)+10;
      y--;
    }
    mesh[x_origin+x][y_origin+y]=potential;
    mesh[x_origin+x][y_origin-y]=potential;
    mesh[x_origin-x][y_origin+y]=potential;
    mesh[x_origin-x][y_origin-y]=potential;
    mesh[x_origin+y][y_origin+x]=potential;
    mesh[x_origin-y][y_origin+x]=potential;
    mesh[x_origin+y][y_origin-x]=potential;
    mesh[x_origin-y][y_origin-x]=potential;
   
    bmesh[x_origin+x][y_origin+y]='#';
    bmesh[x_origin+x][y_origin-y]='#';
    bmesh[x_origin-x][y_origin+y]='#';
    bmesh[x_origin-x][y_origin-y]='#';
    bmesh[x_origin+y][y_origin+x]='#';
    bmesh[x_origin-y][y_origin+x]='#';
    bmesh[x_origin+y][y_origin-x]='#';
    bmesh[x_origin-y][y_origin-x]='#';  
}

  for (int i=0; i<=radius; i++){
    for (int j=0; j<=radius; j++){    
      if (bmesh[x_origin+i][y_origin+j]!='#'){
	mesh[x_origin+i][y_origin+j]=potential;
	mesh[x_origin+i][y_origin-j]=potential;
	mesh[x_origin-i][y_origin+j]=potential;
	mesh[x_origin-i][y_origin-j]=potential;

	bmesh[x_origin+i][y_origin+j]='#';
	bmesh[x_origin+i][y_origin-j]='#';
	bmesh[x_origin-i][y_origin+j]='#';
	bmesh[x_origin-i][y_origin-j]='#';
      }
      else break;      
    }
  }
}

void Rectangle::injectInto (float **mesh, char **bmesh) 
{  
  for (int x = ( x_origin ); x < ( x_origin + height ); x++ )
    for (int y = ( y_origin); y < ( y_origin + width ); y++ ){
      mesh[x][y]=potential;
      bmesh[x][y]='#';
    }
}

void Line::injectInto (float **mesh, char **bmesh) 
{
  switch (choice) {   
  case 1:
    //horizontal line
    for (int y=0;y<N;y++){
      mesh[row][y] = potential;
      bmesh[row][y] = '#';
    }
    break;
  case 2:
    //vertical line line
    for (int x=0;x<N;x++) {
      mesh[x][column] = potential;
      bmesh[x][column] = '#';
    }
    break;
  case 3:
    //right diagonal line below main diagonal
    for (int x=0;x<N;x++) {
      for (int y=0;y<N;y++) {
	if (x==y+start) {
	  mesh[x][y] = potential;
	  bmesh[x][y] = '#';
	}
      }
    }
    break;
  case 4:
    //right diagonal line above main diagonal
    for (int x=0;x<N;x++) {
      for (int y=0;y<N;y++) {
	if (y==x+start) {
	  mesh[x][y] = potential;
	  bmesh[x][y] = '#';
	}
      }
    }
    break;
  case 5:
    //left diagonal line above main diagonal
    for (int x=0;x<=N/2;x++) {
      mesh[x][start] = potential;
      bmesh[x][start] = '#';
      start = start-1;
    }
    break;
  case 6:
    //left diagonal line below main diagonal
    for (int x=N/2;x<=N;x++) {
      mesh[x][start] = potential;
      bmesh[x][start] = '#';
      start = start-1;
    }
    break;
  }
}
