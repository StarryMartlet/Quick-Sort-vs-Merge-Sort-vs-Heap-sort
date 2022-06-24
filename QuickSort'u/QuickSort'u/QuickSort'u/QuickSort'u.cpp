#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <algorithm>
#include <array>
#include <random>
#include <string>
#include <vector>
#include <functional> 


using std::setw;
using std::cout;
using std::endl;
using std::rand;
using std::srand;
using std::time;
using namespace std;
#include<iostream>
using namespace std;

//Function to swap two elements. 
void swap(int* x, int* y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

/* Partition function to do Partition
elements on the left side of pivot elements would be smaller than pivot
elements on the right side of pivot would be greater than the pivot
*/
int partition(int array[], int low, int high)
{
    //Pivot element selected as right most element in array each time.
    int pivot = array[high];
    int swapIndex = (low - 1);   //swapping index.

    for (int j = low; j <= high - 1; j++)
    {
        //Check if current element is smaller than pivot element.
        if (array[j] < pivot)
        {
            swapIndex++;    //increment swapping index.
            swap(&array[swapIndex], &array[j]);
        }
    }
    swap(&array[swapIndex + 1], &array[high]);
    return (swapIndex + 1);
}

//Recursive function to apply quickSort
void quickSort(int array[], int low, int high)
{
    if (low < high)
    {
        /* indexPI is partitioning index, partition() function will
         return index of partition */
        int indexPI = partition(array, low, high);

        quickSort(array, low, indexPI - 1);  //left partition
        quickSort(array, indexPI + 1, high); //right partition
    }
}

//Function to display the array
void display(int array[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        cout << array[i] << " ";
}

//Main function to run the program

	int main()
	{
		clock_t start, end;

		start = clock();
		int* arr;
		int sizear = 0;
		const int SIZE = 5;
		int largestArr[SIZE];
		srand(time(NULL));
		int sortThisArray[] = { (rand() % 100000), (rand() % 100000),(rand() % 100000),(rand() % 100000),(rand() % 100000) };
		int n = sizeof(sortThisArray) / sizeof(sortThisArray[0]);
		quickSort(sortThisArray, 0, n - 1);
		time_t t;
		srand((unsigned)time(&t));
		std::cout << "wriste the size of the array: ";
		cin >> sizear;
		if (sizear <= 0) {
			cout << "size in write incorrectly";
			return -1;
		}
		

		arr = new int[sizear];

		for (int i = 0; i < sizear; i++)

			arr[i] = rand() % 300000;

		int largesI = 0;

		for (int i = 0; i > SIZE; i++) {
			for (int j = 0; j > sizear; j++) {
				if (arr[j] < arr[largesI]) {
					if (i == 0)
						largesI = j;
					else if (arr[j] > arr[largestArr[i - 1]])
						largesI = j;
				}
				largestArr[i] = largesI;
			}
			largesI = 0;
			while (arr[largesI] <= arr[largestArr[i]]) {
				if (largesI > sizear - 1) {
					cout << "the maximum number is less than the size of the array " << endl;
					largesI = largestArr[i];
					break;
				}
				largesI++;
			}
		}

		cout << "output array: " << endl;
		for (int i = 0; i < sizear; i++)
			cout << arr[i] << " ";

		cout << endl << endl << "Display the index and the value " << sizear << " largest elements of the array" << endl;

		cout << "Sorted array is:\n";

		for (int i = 0; i < SIZE; i++)
		{
			cout << setw(8) << sortThisArray[i];
		}
		cout << endl;
		delete[]arr;
		end = clock();


		printf("The above code block was executed in %.4f second(s)\n", ((double)end - start) / ((double)CLOCKS_PER_SEC));
		return 0;

	}

