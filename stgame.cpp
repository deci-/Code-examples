#include <iostream>
#include <sys/time.h>
#include <ctime>
#include <stdlib.h>
#include <cmath>
//St. Petersburg game simulator

using namespace std;

int main()
{
  int num,price,counter=0,i=0,sum=0,max_counter=0,k=0,l=0,expence;
  float profit;
  struct timeval time;
  gettimeofday(&time,NULL);
  srand((time.tv_sec * 1000) + (time.tv_usec / 1000));//seed for rand()
  cout << "Enter number of simulations ";
  cin >> num;
  cout << "Enter a price of a ticket: ";
  cin >> price;
  while (i<num){
    while (1){
      k++;
      if (rand()%2 == 1)
	break;
      l++;
      counter++;
    }
    if (counter > 0)
      sum+=pow(2,counter);//how much money i had to pay off
    i++;
    if (max_counter < counter)
      max_counter = counter;
    counter = 0;
  }
  expence=price*num;//how much money did people spend
  profit= (float) sum/num;
  cout << "profit " << profit << endl;
  cout << "max_counter " << max_counter << endl;
  cout << "probability " << (float) l/k << endl;
  cout << "profit " << expence-sum  << endl;
  return 0;
}

