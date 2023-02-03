#include <iostream>


int arr_index = 0 ;
static int ibit = 8 * sizeof(int);

int main() 
{
	int size_of_arr = 0;
	int size = 0;
	int index = 0;


	std::cout << "Enter the size of the array in bits: ";
	std::cin >> size_of_arr;
	size = (size_of_arr/ibit) + 1;//count of array elements 
	unsigned int *arr =  new unsigned int[size]  ;

	for(;;)
	{			
		std::cout << "Enter the index of the bit You want to change in the range of 0 to " << (size_of_arr -1) << std::endl;
		std::cin >> index;

		if (index < 0 || index > (size_of_arr -1))
		
			continue;
		

		arr_index = (index/ibit) ;//which elemt of arr we want to change
		std::cout << "Press s to set or r to reset the bit " << std::endl;
		char command ;
		std::cin >> command;
		int res1=0;
		int res2=0;
		if(command == 's')
		{
	    	res1=arr[arr_index] | (1 << index);
            std::cout << res1 << std::endl;
	        arr[arr_index] = res1;
		}

   		else if (command == 'r')
		{
		    res2=arr[arr_index] & ~  (1 << index);
            std::cout << res2 << std::endl;
		    arr[arr_index] = res2;
		}	
		else 
		{	
		 continue;
		}

		std::cout << "Press x to exit or any other key to recalculate" << std::endl;
		char userSelection = '\0';
		std::cin >> userSelection;
		if (userSelection == 'x') 
			break;


	}
	    delete [] arr;
	    std::cout << "Goodbye!" << std::endl;



	return 0;

}
