#include <iostream>
using namespace std;

#define random(x)(rand()%x)

void quicksort(int* A, int left, int right)  //int[] A编译不能通过
{
    if (left >= right)
        return;
    int l = left, r = right, key = A[left];
    while(l < r)
    {

        while(l < r && A[r] >= key) r--;
        A[l] = A[r];
        while(l < r &&  A[l] <= key) l++;
        A[r] = A[l];
    }
    A[l] = key;
    quicksort(A, left, l);
    quicksort(A, l+1, right);
}


int main()
{
    int A[4];
    A[0]= 9;
    A[1]=8;
    A[2]=1;
    A[3]=4;
    quicksort(A, 0,3);
    for (int i = 0; i < 4; i++)
        cout << A[i] << " ";
    system("pause");
    return 0;
}
