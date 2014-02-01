#include "random_array.h"
/*function fills in the array arr[] with two zeros and a one in random order. That's were the 
'randomness' of the whole simulation cames from*/
void random_array_function(int * arr1)
{
 int j;
 for (j = 0; j < 3; j++) 
	{
 	arr1[j] = 0;
	}
 struct timeval tv;
 gettimeofday(&tv, NULL);
 srand(tv.tv_usec+tv.tv_sec);
 int index = rand() % 3;
 arr1[index] = 1;


/*while loop prints out the initial values behind the doors*/
 printf("The values behind the doors are: ");
 int i=0;
 while (i<3)
 	{
	if (arr1[i] == 1)
 		printf("-Car-\t"); else
		printf("-Goat-\t");
 	i++;
 	} 
 printf("\n");

}
