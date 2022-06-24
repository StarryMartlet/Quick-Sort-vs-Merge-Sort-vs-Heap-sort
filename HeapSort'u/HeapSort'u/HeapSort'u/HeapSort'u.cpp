#include <iostream>
#include <ctime>
#include <iomanip>

#include <cstdlib>

using std::print;
using std::setw;
using std::cout;
using std::endl;
using std::rand;
using std::srand;
using std::time;

#include <iostream>
#include <vector>

int parent(int i)
{
    return (i - 1) / 2;
}
int left(int i)
{
    if (i == 0)
        return 1;
    else
        return 2 * i;
}
int right(int i)
{
    if (i == 0)
        return 2;
    else
        return 2 * i + 1;
}
void min_heapify(std::vector<int>& A, int i, int heapsize)
{
    int smallest;
    int l = left(i);
    //std::cout << "left = " << l << std::endl;
    int r = right(i);
    //std::cout << "right = " << r << std::endl;
    if (l <= heapsize && A[l] < A[i])
        smallest = l;
    else
        smallest = i;
    //std::cout << "smallest = " << smallest << std::endl;
    if (r <= heapsize && A[r] < A[smallest])
        smallest = r;
    if (smallest != i) {
        print(A);
        exchange(A, i, smallest);
        min_heapify(A, smallest, heapsize);
    }
}
void build_min_heap(std::vector<int>& A)
{
    int heapsize = A.size() - 1;
    for (int i = (A.size() - 1) / 2; i >= 0; i--)
        min_heapify(A, i, heapsize);
}
void heapsort(std::vector<int>& A)
{
    int heapsize = A.size() - 1;
    build_min_heap(A);
    std::cout << "heapsort after buildmaxheap" << std::endl;
    print(A);
    for (int i = A.size() - 1; i > 0; i--) {
        exchange(A, 0, i);
        heapsize--;
        std::cout << "heapsize = " << heapsize << std::endl;
        min_heapify(A, 0, heapsize);
    }
}
int main()
{
    std::vector<int> B;
    fill(B, 5);
    print(B);
    heapsort(B);
    print(B);
    return 0;
}