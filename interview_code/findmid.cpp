#include <iostream>
#include <stdlib.h>  //rand
#include <algorithm> //swap

#define random(x)(rand()%x)

using namespace std;

int findMid(int* A, int left, int right, int key_index)
{
    int l = left, r = right, key;
    swap(A[l], A[random(r-l+1)+l]);
    key = A[l];
    while( l < r)
    {
        while (l < r && A[r] >= key) r--;
        A[l] = A[r];
        while (l < r && A[l] <= key) l++;
        A[r] = A[l];
    }
    A[l] = key;
    if (l == key_index)
        return A[l];
    else if (l > key_index)
        return findMid(A, left, l-1, key_index);
    else
        return findMid(A, l+1, right, key_index);
}

int find(int* A, int Asize)
{
    if (Asize%2==1)
        return findMid(A, 0, Asize-1, Asize/2);
    else
        return (findMid(A, 0, Asize-1, Asize/2) + findMid(A, 0, Asize-1, Asize/2-1))/2;
}
int main()
{
    int A[4];
    A[0]= 9;
    A[1]=8;
    A[2]=1;
    A[3]=4;
    cout << find(A, 3) << " ";
    cout << find(A, 4);
    return 0;
}
