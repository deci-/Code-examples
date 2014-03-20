#include <stdio.h>
#include <string.h>

//generic c swap function that swaps 'size' number of bytes
//in the two addresses passed to it
void swap(void*,void*,int);

int main()
{
  //simple call
  int x=55, y=12;
  swap(&x,&y,sizeof(int));

  //more complicated (correct) call
  char *husband = strdup("Fred");
  char *wife = strdup("Wilma");
  swap(&husband,&wife,sizeof(char*));

  //bad (incorrect) call
  swap(husband,wife,sizeof(char*));
  //prints "Husband is Freda, Wife is Wilm"

  printf("x=%d, y=%d\n",x,y);
  printf("Husband is %s, Wife is %s\n",husband, wife);
 
  return 0;
}

void swap(void *vp1, void *vp2, int size)
//@args addresses of the things you want swapped
//size - number of bytes to be swapped
{
  char buffer[size];//setting enough space to hold 'size' byte
  memcpy(buffer,vp1,size);
  memcpy(vp1,vp2,size);
  memcpy(vp2,buffer,size);
}
