#include <iostream>
#include <ctime>
#include <iomanip>

#include <cstdlib>


using std::setw;
using std::cout;
using std::endl;
using std::rand;
using std::srand;
using std::time;
using namespace std;
void merge(int*, int, int, int);
void merge_sort(int* arr, int low, int high)
{
    int mid;
    if (low < high) {
        //divide the array at mid and sort independently using merge sort
        mid = (low + high) / 2;
        merge_sort(arr, low, mid);
        merge_sort(arr, mid + 1, high);
        //merge or conquer sorted arrays
        merge(arr, low, high, mid);
    }
}
// Merge sort 
void merge(int* arr, int low, int high, int mid)
{
    int i, j, k, c[50];
    i = low;
    k = low;
    j = mid + 1;
    while (i <= mid && j <= high) {
        if (arr[i] > arr[j]) {  //if (arr[i] > arr[j])  descending!!!
            c[k] = arr[i];
            k++;
            i++;
        }
        else {
            c[k] = arr[j];
            k++;
            j++;
        }
    }
    while (i <= mid) {
        c[k] = arr[i];
        k++;
        i++;
    }
    while (j <= high) {
        c[k] = arr[j];
        k++;
        j++;
    }
    for (i = low; i < k; i++) {
        arr[i] = c[i];
    }
}
// read input array and call mergesort
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
	merge_sort(sortThisArray, 0, n - 1);
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

