#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>
//The program counts how many chars are there in this source code file excluding blanks and prints out the output.

int main()
{
  using namespace std;
  string filecontent;
  int num=0,i;
  ifstream inf ("fileletters.cpp");//open file for reading
  if (!inf)//check if file was sucessfully opened
    {
      // Print an error and exit
      cerr << "Error! fileletters.cpp could not be opened for reading!" << endl;
      exit(1);//exit with a nonzero status
    }
  else
    {
      while(!inf.eof())//checks if file hasn't ended yet
	{	
	  getline(inf, filecontent);//takes a line from the file
	  for (i=0; i<filecontent.size(); i++)//loops through a line of code
		 if(filecontent.at(i) != ' ')
		   num++;//counts a letter in if it is not a whitespace
	}
    }
  cout << "Number of letters in file fileletters.cpp (excluding blanks) is " <<
    num << endl;
  return 0;
}
