#include <iostream>
#include <fstream>//file manip
#include <cmath>//math,abs
#include <cstring>//strings
#include <cstdlib>
#include <ctime>//time
using namespace std;

#ifndef BOUNDARY_H
#define BOUNDARY_H

class Boundary{
 public:
  ~Boundary() {}
  void virtual injectInto (float **mesh, char **bmesh) {};
};

class Point : public Boundary {
 private:
  int x_origin;
  int y_origin;
  float potential; 
  
 public:
  Point() {
    cin >> x_origin >> y_origin >> potential;
  }
  ~Point() {};
  void injectInto (float **mesh, char **bmesh);
};

class Circle : public Boundary {
 private:
  int x_origin;
  int y_origin;
  int radius;
  float potential;
 public:
  Circle() {
    cin >> x_origin  >> y_origin >> radius >> potential;
  }
  ~Circle() {};
  void injectInto (float **mesh, char **bmesh);
};

class Rectangle : public Boundary {
 private:
  int x_origin;
  int y_origin;
  int height;
  int width;
  float potential; 
 public:
  Rectangle() { 
    cin >> x_origin >> y_origin >> height >> width >> potential;
  }
  ~Rectangle() {};
  void injectInto (float **mesh, char **bmesh);
};

class Line : public Boundary {
 private:
  int column;
  int row;
  int start;
  int choice;
  float potential; 
 public:
  Line() { 
    cin >> column >> row >> start >> choice >> potential;
  }
  ~Line() {};
  void injectInto (float **mesh, char **bmesh);
};

#endif

//function prototypes
void algorithm(float **,char**,float);
void generateMesh(float**,char**);
