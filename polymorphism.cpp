#include <iostream>
//An example of using inheritance, polymorphism and virtual functions

using namespace std;

class Boundary{
public:
  Boundary() {};
  ~Boundary() {};
  virtual void get_info() const {};
};

class Point : public Boundary{
private:
  int x,y,p;
public:
  Point(int,int,int);
  ~Point() {};
  void get_info() const;
};

Point::Point(int xorg,int yorg,int pot){
  x=xorg;
  y=yorg;
  p=pot;
}

void Point::get_info() const{
  cout<<x << " " << y << " " << p << " " << endl;
}

int main(){
  Boundary * b_ptr = new Point(5, 5, 10); 
  b_ptr->get_info();
  delete b_ptr;

  return 0;
}
