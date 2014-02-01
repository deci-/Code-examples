#include "random_array.h"
/*Monty Hall game simulation by Paulius Vaitkunas. Type in make monty to compile it and 
./simulator.sh to run a simulation of 5 games(initially). You can change the number of simulations that 
you make and the choice of the door and wheather to switch in the simulator (see a comment in simulator.sh*/

int main (int argc, char *argv[]) 
{
 char line[80], answer[3];
 char answ[5];
 int choice; /*choice of a door(1/2/3)*/
 int doorvalue, doorvalue1, doorvalue2, doorvalue3; /*value behind the door that is chosen (0/1)*/
 int arr[3];
 random_array_function(arr);

 sscanf(argv[2], "%s", answ);
 doorvalue1 = arr[0];
 doorvalue2 = arr[1];
 doorvalue3 = arr[2];
 choice = atoi(argv[1]);
 if (choice == 1)
	doorvalue = doorvalue1; else
 if (choice == 2)
	doorvalue = doorvalue2; else
 if (choice == 3)
	doorvalue = doorvalue3;
	
 
 if ((answ[0] == 'n') && (doorvalue == 1))
	{
	printf("Your prize - a car\n");
	exit(0);
	} else
 if ((answ[0] == 'n') && (doorvalue == 0))
	{
	printf("Your prize - a goat\n");
	exit(1);
	} else
 if (answ[0] == 'y')
	{
	if ((choice == 1 && doorvalue == 0) || (choice == 2 && doorvalue == 0) || (choice == 3 && doorvalue == 0))
		{
		printf("Your prize - a car\n"); /*player cannot lose at this point since the host would open the remaining door with a goat and the player would choose the door which is left and it would always be a door with a car behind*/
		exit(0);
		} else
		if ((choice == 1 && doorvalue == 1) || (choice == 2 && doorvalue == 1) || (choice == 3 && doorvalue == 1))
		{
		printf("Your prize - a goat\n"); /*player has no chance in winning a car after this choice since he had chosen the door with a car behind and decided to switch*/
		exit(1);
		}

	}
	
	  
}

